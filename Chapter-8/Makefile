# c flag
CFLAG=-std=c99 -Wall
# delete files
RM=rm -rf

# make build
build:
	@echo Compiling chapter 8 codes...
	$(CC) $(CFLAG) fork_child.c -o fork_child
	$(CC) $(CFLAG) vfork.c -o vfork
	$(CC) $(CFLAG) wait.c -o wait
	$(CC) $(CFLAG) waitpid.c -o waitpid
	$(CC) $(CFLAG) charatatime.c -o charatatime
	$(CC) $(CFLAG) exec.c -o exec
	$(CC) $(CFLAG) echoall.c -o echoall
.PHONY: clean

clean:
	$(RM) fork_child vfork wait waitpid charatatime exec echoall
