CC = gcc
CFLAGS = -Wall -Wextra -O3
LDFLAGS = 

# Source files
SRCS = cpu_loop.c gpu_shader.c
OBJS = $(SRCS:.c=.o)
TARGETS = $(SRCS:.c=)

.PHONY: all clean

all: $(TARGETS)

cpu_loop: cpu_loop.o
	$(CC) $(LDFLAGS) -o $@ $<

gpu_shader: gpu_shader.o
	$(CC) $(LDFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGETS) 