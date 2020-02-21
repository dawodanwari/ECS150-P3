lib := libuthread.a
objs := sem.o queue.o thread.o tps.o
CC := gcc
CFLAGS := -Wall -Werror -g

ifneq ($(V),1)
Q = @
endif

all: $(libuthread) $(programs)

deps := $(patsubst %.o,%.d,$(objs))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

%.o: %.c
	@echo "CC	$@"
	$(Q)$(CC) $(CFLAGS) -c -o $@ $< $(DEPFLAGS)

clean:
	@echo "clean"	
	$(Q)rm -rf $(objs) $(deps) $(targets)

.PHONY: clean $(libuthread)
