# c flag
CFLAG=-std=c99 -Wall
# delete files
RM=rm -rf

# make build
build:
	@echo Compiling chapter 11 codes...
	$(CC) $(CFLAG) pthread_create.c -o pthread_create
	$(CC) $(CFLAG) pthread_join.c -o pthread_join
.PHONY: clean

clean:
	$(RM) pthread_create pthread_join
