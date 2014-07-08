CFLAGS=-g -MMD -I ./include

# binaries
LIB_SRC=$(shell ls libs/*.c)
SRCS= $(LIB_SRC) src/test.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

# Output
OUT_DIR = build
OUT_OBJS=$(addprefix $(OUT_DIR)/, $(OBJS))
DEPS = $(patsubst %.o, %.d, $(OUT_OBJS))

# Build Rules
TARGET=test

$(OUT_DIR)/$(TARGET): $(OUT_OBJS)
	$(CC) -o $@ $^

$(OUT_DIR)/%.o:%.c
	mkdir -p $(dir $@)
	@echo $^
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OUT_DIR)

-include $(DEPS)
