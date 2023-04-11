# Output filename
TARGET = MyExecutable

#! DON'T TOUCH
# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g
LINKS = -lSDL2 -lSDL2_image #-lm
# Files
OBJECTS_DIR = obj
SRC_DIR = primitives
SRCS = $(filter-out $(SRC_DIR)/_structs.h, $(wildcard $(SRC_DIR)/*.c))
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJECTS_DIR)/%.o,$(SRCS))
#! DON'T TOUCH


# make clean -> Delete all object files and the executable
# make -> Compile the .c/.h files to object files, then executable
# make soft -> Delete all object files
# make valid -> Valgrind, then times the code
# make exec -> Execute the file
# make full -> Does all the above in this exact order
.PHONY: all clean soft valid exec full

all: $(TARGET)
$(TARGET): $(OBJS) main.c
	$(CC) $(CFLAGS) $^ -o $@ $(LINKS)
$(OBJECTS_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(LINKS)
$(OBJECTS_DIR):
	mkdir -p $(OBJECTS_DIR)

clean:
	rm -rf $(TARGET) $(OBJECTS_DIR)

soft:
	rm -rf $(OBJECTS_DIR)

valid:
	echo "\nValgrind :" ; ~/scaffold/tools/valgrind.sh ; echo "\nDuration :" ; ~/scaffold/tools/time.sh

exec:
	./MyExecutable

full:
	make clean -s ; make -s ; make soft -s ; make valid  -s ; echo "" ; make exec -s