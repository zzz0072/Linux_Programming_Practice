LIBTOOL=libtool
SRCS = liba.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
LOBJS = $(patsubst %.c, %.lo, $(SRCS))
CFLAGS = -I$(INC_DIR)
CC = gcc

TARGET=liba.la

$(TARGET): $(OBJS)
	$(LIBTOOL) --mode=link $(CC) $(CFLAGS) -o $@ $(LOBJS)

%.o:%.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) -c $^

clean:
	rm -rf $(OBJS) .libs *.lo $(TARGET) *.a
