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
	$(CC) $(CFLAG) tmpnam.c -o tmpnam
	$(CC) $(CFLAG) mkstemp.c -o mkstemp
.PHONY: clean

clean:
	$(RM) getc fgets buf tmpnam




