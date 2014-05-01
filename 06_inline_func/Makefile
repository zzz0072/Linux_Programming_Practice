TARGET=inline_test
OBJ=$(patsubst %, %.o, $(TARGET))
CFLAGS=-g -Wall -Werror

ifneq ($(GNU_C_TEST),Y)
	CFLAGS += -std=c99
endif

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -Wl,-Map=$(TARGET).map
	objdump -S $(TARGET) > $(TARGET).lst

clean:
	rm -rf *.o $(TARGET) *.lst *.map
