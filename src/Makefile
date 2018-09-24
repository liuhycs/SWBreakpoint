SRCS = software_breakpoint.cpp vm_emulator.cpp libbreakpoint.cpp

DEPS = $(SRCS) $(INCS)

#CXX = g++ 
CXX = clang++ 

CFLAGS +=-g -O2 -DNDEBUG -fno-omit-frame-pointer -Wall -Werror --std=c++11 -shared -fPIC 

XED2_ROOT = /home/hongyuliu/workspace/intelxed2/balib/lib/xed2
XED2_LIBS = -L$(XED2_ROOT)/lib -lxed 
XED2_INC = $(XED2_ROOT)/include

INCLUDE_DIRS = -I. -I$(XED2_INC) -I$(XED2_INC)/xed
LIBS = $(XED2_LIBS) -lelf -lpthread -ldl 
RPATH = -Wl,-rpath,$(XED2_ROOT)/lib

TARGETS = libbreakpoint.so

all: $(TARGETS)

$(TARGETS): $(DEPS)
	$(CXX) $(CFLAGS) $(INCLUDE_DIRS) $(SRCS) -o $(TARGETS) $(LIBS) $(RPATH)

clean:
	rm -f $(TARGETS)


