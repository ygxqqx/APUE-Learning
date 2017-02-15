# c flag
CFLAG=-std=c99 -Wall
# delete files
RM=rm -rf

# make build
build:
	@echo Compiling chapter 5 codes...
	$(CC) $(CFLAG) getc.c -o getc
	$(CC) $(CFLAG) fgets.c -o fgets
	$(CC) $(CFLAG) buf.c -o buf

.PHONY: clean

clean:
	$(RM) getc fgets buf