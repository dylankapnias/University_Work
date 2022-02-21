###########################################################
#
# Title: Makefile Template
# Author: Dylan Kapnias (u18108467)
# Description: A makefile template for Assembly
#
###########################################################

# Setting shell
SHELL=/bin/bash

# Target file of compilation
TARGET := task1 task2 task3

# Source files
SOURCES := $(wildcard *.asm)

# Object files
OBJECTS := $(SOURCES:%.asm=%.o)

# All compiled files
CREATED := $(OBJECTS) $(TARGET)

# Log directory
LOGS := .logs

# Input file
F_INP := in.txt

# Output file
F_OUT := out.txt

# List of warning tags
WARNINGS := \
-Wall \
-Wextra \
-pedantic

# '@' makes the command that is being run only display it's output and not itself.

# Entry point for makefile
all: $(LOGS) $(TARGET)
	@echo "All done."

# Executable creation with a list of rules:
# $@ expands into the rule's target
# $^ expands into the rule's dependencies
$(TARGET): $(LOGS) $(OBJECTS)
	@ld -o $@ $(addsuffix .o,$@)
	@echo "Target '$@' created."

$(LOGS):
	@mkdir -p $@

# Object file creation with a pattern rule:
# %.o: %.cpp is saying create a .o file for every .cpp file
# $@ is the pattern matched target
# $< is the pattern matched dependency
# $(basename ??) gives the filename without extension
%.o: %.asm
	@yasm -f elf64 -g dwarf2 -l $(basename $@).lst $< > $(LOGS)/$(basename $@).log 2>&1
	@echo "Object '$@' created."

# Dependency rules to find and use changed files
add.o: add.asm
sub.o: sub.asm
mul.o: mul.asm
div.o: div.asm

# Cleaning directory of compiled files
clean:
	@rm -f $(CREATED)
	@rm -fr $(LOGS)
	@rm -f $(OBJECTS:%.o=%.lst)
	@rm -f $(F_OUT)
	@echo "Cleaning done"

# Running executable
run:
	@echo "Running ./$(TARGET)."
	@./$(TARGET) > $(F_OUT)

# Running with predetermined input all on new lines in a .txt file
s_run: $(F_INP)
	@echo "Running ./$(TARGET) with input."
	@bash run.sh | tee output.txt

$(F_INP):
	touch $@

# Display error logs in one less command
errt:
	@find $(LOGS) -type f -exec less '{}' +;

# Display error logs in seperate less commands
errs:
	@find $(LOGS) -type f -exec less '{}' \;