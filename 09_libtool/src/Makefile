LIBTOOL=libtool
SRCS = test.c
OBJS = $(patsubst %.c, %.o, $(SRCS)) ../libs/libb.la ../libs/liba.la
CFLAGS = -I$(INC_DIR)
CC = gcc

TARGET=test

$(TARGET): $(OBJS)
	$(LIBTOOL) --mode=link $(CC) $(CFLAGS) -o $@ $(OBJS)

%.o:%.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) -c $^

clean:
	rm -rf $(OBJS) .libs *.lo $(TARGET)
