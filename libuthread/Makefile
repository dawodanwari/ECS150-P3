# Target library
lib := libuthread.a
objs := sem.o queue.o thread.o tps.o
CC := gcc
CFLAGS := -Wall -Werror -g

# Generate dependencies
DEPFLAGS = -MMD -MF $(@:.o=.d)

# Include dependencies
deps := $(patsubst %.o,%.d,$(objs))
-include $(deps)

all: $(lib)

## TODO: Phase 1 and Phase 2
