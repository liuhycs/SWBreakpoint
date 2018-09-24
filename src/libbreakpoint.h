/*
 * =====================================================================================
 *
 *       Filename:  libbreakpoint.h
 *
 *    Description:  
 *
 *         Author:  Hongyu Liu 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "software_breakpoint.h"

void SetBreakpoint(void* addr, pid_t thread_id, callback_sa_sigaction func);

void RemoveBreakpoint(void* addr);
