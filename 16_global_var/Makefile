TARGET=glvar
SRCS=var_1.c var_2.c main.c
OBJS=$(patsubst %.c, %.o, $(SRCS))
CFLAGS=-g

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

test: $(TARGET)
	objdump -t $(OBJS) $(TARGET)
	nm -A $(OBJS) $(TARGET)
	./$(TARGET)

clean:
	rm $(TARGET) $(OBJS)
