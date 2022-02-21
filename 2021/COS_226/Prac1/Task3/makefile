# Setting shell (Not on wsl)
# SHELL=/bin/

# Class to run
BINARY := Main

# Target file of compilation (if running javac in separate lines put main last)
CLASSES := Counter.class MyThread.class PetersonLock.class Main.class

# Log directory
LOGS := .logs

# Input arguments
INPUT := 8

# '@' makes the command that is being run only display it's output and not itself.
# Entry point for makefile
all: $(LOGS) $(CLASSES)
	@echo "All done."

# Log files directory created if not present
$(LOGS):
	@mkdir -p $@

# Class file creation with a pattern rule:
# %.class: %.java is saying create a .class file for every .java file
# $@ is the pattern matched target
# $< is the pattern matched dependency
%.class: %.java
	javac $<
	@echo "Class '$@' created."

# Cleaning directory of compiled files
clean:
	@rm -f $(CLASSES)
	@rm -fr $(LOGS)
	@echo "Cleaning done"

# Running executable
run:
	@echo "Running $(BINARY)."
	@java $(BINARY)

# Running executable with input var
i_run:
	@echo "Running $(BINARY)."
	@java $(BINARY) $(INPUT)

# Display error logs in one less command
errt:
	@find $(LOGS) -type f -exec less '{}' +;

# Display error logs in seperate less commands
errs:
	@find $(LOGS) -type f -exec less '{}' \;