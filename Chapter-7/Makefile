# c flag
CFLAG=-std=c99 -Wall
# delete files
RM=rm -rf

# make build
build:
	@echo Compiling chapter 7 codes...
	$(CC) $(CFLAG) atexit.c -o atexit
	$(CC) $(CFLAG) echo.c -o echo
.PHONY: clean

clean:
	$(RM) atexit echo
