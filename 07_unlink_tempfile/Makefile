TARGET=ulink
OBJ=$(patsubst %, %.o, $(TARGET))
CFLAGS=-g -Wall -Werror
CFLAGS += -std=c99

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -Wl,-Map=$(TARGET).map
	objdump -S $(TARGET) > $(TARGET).lst

clean:
	rm -rf *.o $(TARGET) *.lst *.map
