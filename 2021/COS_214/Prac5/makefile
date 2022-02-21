##########################################################################
#
#	@author Dylan Kapnias
#
#	@description A makefile for C++ compilation with an automatic
#				 dependency creation. 
#
##########################################################################


###############################################
# Change these variables to your specifications
###############################################
# Test variable. 0 = no unit testing. 1 = yes unit testing
TEST := 0
# Setting shell
SHELL := /bin/bash
# Setting compiler
CC := g++
# Linker
LD := g++
# Target file of compilation
TARGET := Main
# Name of archive without extension
ARCHNAME := prac5
# Archive excludes
A_EXC := ./.priv cf.sh
# Source file path
SORUCEDIR := src
# Include file path
INCDIR := inc
# Object file path
OBJECTDIR := obj
# Dependency file path
DEPSDIR := dep
# Log directory
LOGS := .logs
###############################################
# End of variables
###############################################


###############################################
# Generating based off Source files 
###############################################
# Source files
SOURCES := $(wildcard $(SORUCEDIR)/*.cpp)
# Object files
OBJECTS := $(patsubst %.cpp, $(OBJECTDIR)/%.o, $(notdir $(SOURCES)))
# Dependency files
DEPS := $(patsubst %.cpp, $(DEPSDIR)/%.d, $(notdir $(SOURCES)))
# All created directories used
ALLDIRS := $(OBJECTDIR) $(DEPSDIR) $(LOGS)
###############################################
# End of generation 
###############################################


###############################################
# Setting flags
###############################################
# List of all flags tags
CPPFLAGS := \
-g \
-Wall \
-Wextra \
-pedantic \
-Weffc++
# List of dependency flags
DEPFLAGS = \
-MT \
$@ \
-MD \
-MP \
-MF \
$(DEPSDIR)/$*.d.tmp
#List of linking flags
LINKFLAGS := \
# List of archive exclude flags
A_EXC_FLAGS := $(addprefix --exclude=,$(A_EXC))
# List of flags for unit testing
TESTFLAGS := \
-pthread \
-lgtest \
-lgtest_main
###############################################
# End of flags 
###############################################


###############################################
# Setting the strings to use for compilation
###############################################
# Compile string
# COMPILE.cpp = $(CC) $(DEPFLAGS) $(CPPFLAGS) -c -o $@ -I /usr/src/googletest/googletest/include
COMPILE.cpp = $(CC) $(DEPFLAGS) $(CPPFLAGS) -c -o $@
# Link string
LINK.o = $(LD) $(LINKFLAGS) -o $@
# Post compilation string
POSTCOMPILE = mv -f $(DEPSDIR)/$*.d.tmp $(DEPSDIR)/$*.d
###############################################
# End of string setting 
###############################################


# '@' makes the command that is being run only display it's output and not itself.

# Entry point for makefile
all: $(ALLDIRS) $(TARGET)
	@echo "======================="
	@echo "All done."
	@echo "======================="

# Creating all required directories
$(ALLDIRS):
	@mkdir -p $@

# Linking with a list of rules:
# $@ expands into the rule's target
# $^ expands into the rule's dependencies
$(TARGET): $(OBJECTS)
	@echo "======================="
	@echo "Linking the target $@"
	@echo "======================="

ifeq ($(TEST), 1)
	@$(LINK.o) $^ $(TESTFLAGS)
else
	@$(LINK.o) $^
endif

	@echo "-- Linking finished. --"

# Compiling with a pattern rule:
# $(OBJECTDIR)/%.o: $(SORUCEDIR)/%.cpp is saying create a .o file for every .cpp file
# $@ is the pattern matched target
# $< is the pattern matched dependency
$(OBJECTDIR)/%.o: $(SORUCEDIR)/%.cpp
$(OBJECTDIR)/%.o: $(SORUCEDIR)/%.cpp $(DEPSDIR)/%.d
	@echo "======================="
	@echo "Compiling $<."
	@echo "======================="
	@$(COMPILE.cpp) $< > $(LOGS)/$(basename $(notdir $@)).log 2>&1
	@$(POSTCOMPILE)

# Dependecy rules (.PRECIOUS stops the target from being deleted if make happens to be interrupted during the recipe)
.PRECIOUS: $(DEPSDIR)/%.d
$(DEPSDIR)/%.d: ;

# Setting the includes
-include $(DEPS)

# Cleaning directories of compiled files
.PHONY: clean
clean:
	@rm -f $(TARGET)
	@rm -fr $(ALLDIRS)
	@echo "======================="
	@echo "Cleaning done"
	@echo "======================="

# Running executable
.PHONY: run
run:
	@echo "======================="
	@echo "Running ./$(TARGET)."
	@echo "======================="
	@./$(TARGET)

# Display error logs in one less command
.PHONY: errt
errt:
	@find $(LOGS) -type f -exec less '{}' +;

# Display error logs in seperate less commands
.PHONY: errs
errs:
	@find $(LOGS) -type f -exec less '{}' \;

# Archive
.PHONY: dist
dist:
	@tar $(A_EXC_FLAGS) -zcvf $(ARCHNAME).tar.gz *
	@echo "======================="
	@echo "Tarball created."
	@echo "======================="

# Help
.PHONY: help
help:
	@echo "======================="
	@echo "Help Section."
	@echo "======================="
	@echo "Commands :- (make) : (make run) : (make clean) : (make dist) : (make errt) : (make errs)"
	@echo ""
	@echo "make :- Compiles and links all the files in the specified directories."
	@echo ""
	@echo "make run :- Runs the target executable, i.e TARGET."
	@echo ""
	@echo "make clean :- Removes all directories and files created during make."
	@echo ""
	@echo "make dist :- Archives all files in the projects root directory, excluding the files specified, i.e A_EXC."
	@echo ""
	@echo "make errt :- Shows all error logs in one consecutive less command."
	@echo "make errs :- Shows all error logs in multiple less commands."