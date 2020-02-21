
lib := libuthread.a
objs := sem.o queue.o thread.o tps.o
CC := gcc
CFLAGS := -Wall -Werror -g
DEPFLAGS = -MMD -MF $(@:.o=.d)

ifneq ($(V),1)
Q = @
endif

all:
<\t>$(libuthread) $(progs)

deps := $(patsubst %.o,%.d,$(objs))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)
%.o: %.c
	@echo "CC	$@"
	$(Q)$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $< $(DEPFLAGS)

clean:
	@echo "CLEAN	$(CUR_PWD)"
	$(Q)rm -rf $(objs) $(deps) $(targets)

.PHONY: clean $(libuthread)
