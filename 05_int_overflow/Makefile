TARGET=int_overflow
OBJ=$(patsubst %, %.o, $(TARGET))
CFLAGS=-g -Wall -Werror

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o $(TARGET)
