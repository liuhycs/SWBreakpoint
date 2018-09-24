/*
 * =====================================================================================
 *
 *       Filename:  libbreakpoint.cpp
 *
 *    Description:  
 *    
 *         Author: Hongyu Liu 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "libbreakpoint.h"

#include <dlfcn.h>

#include "vm_emulator.h"
#include "selfmap.h"

typedef int (*main_fn_t)(int, char**, char**);
main_fn_t real_main;

int my_main(int argc, char** argv, char** envp) {

  VmEmulator::getInstance();
  selfmap::getInstance();

  return real_main(argc, argv, envp);
}

extern "C" int __libc_start_main(main_fn_t, int, char**, void (*)(), void (*)(), void (*)(), void*) __attribute__((weak, alias("my_libc_start_main")));

extern "C" int my_libc_start_main(main_fn_t main_fn, int argc, char** argv, void (*init)(), void (*fini)(), void (*rtld_fini)(), void* stack_end) {
  auto real_libc_start_main = (decltype(__libc_start_main)*)dlsym(RTLD_NEXT, "__libc_start_main");
  real_main = main_fn;
  return real_libc_start_main(my_main, argc, argv, init, fini, rtld_fini, stack_end);
}

void SetBreakpoint(void* addr, pid_t thread_id, callback_sa_sigaction func) {
  SoftwareBreakpoint::getInstance().SetBreakpoint(addr, thread_id, func);
}

void RemoveBreakpoint(void* addr) {
  SoftwareBreakpoint::getInstance().RemoveBreakpoint(addr);
}

