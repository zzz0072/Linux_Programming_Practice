LIBTOOL=libtool
SRCS = liba.c libb.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
CFLAGS = -I$(INC_DIR)
CC = gcc

TARGET=liba.la libb.la

all: $(OBJS) $(TARGET)

liba.la: liba.lo
	$(LIBTOOL) --mode=link $(CC) $(CFLAGS) -o $@ $^

libb.la: libb.lo
	$(LIBTOOL) --mode=link $(CC) $(CFLAGS) -o $@ $^ -rpath /usr/local/lib

%.o:%.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) -c $^

clean:
	rm -rf $(OBJS) .libs *.lo $(TARGET) *.a
