lib := libuthread.a
objs := sem.o queue.o thread.o tps.o
CC := gcc
CFLAGS := -Wall -Werror -g
DEPFLAGS = -MMD -MF $(@:.o=.d)
deps := $(patsubst %.o,%.d,$(objs))
-include $(deps)

%.o: %.c
	@echo "CC	$@"
	$(Q)$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $< $(DEPFLAGS)

clean:
	@echo "CLEAN	$(CUR_PWD)"
	$(Q)rm -rf $(objs) $(deps) $(targets)

.PHONY: clean $(libuthread)
