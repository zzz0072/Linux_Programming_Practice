TARGET=buf_overflow
OBJ=$(patsubst %,%.o,$(TARGET))

CFLAGS=-g -Wall -Werror -fno-stack-protector

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(TARGET) $(OBJ)
