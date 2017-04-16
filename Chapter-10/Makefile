# c flag
CFLAG=-std=c99 -Wall
# delete files
RM=rm -rf

# make build
build:
	@echo Compiling chapter 10 codes...
	$(CC) $(CFLAG) signal.c -o signal
	$(CC) $(CFLAG) getpwnam.c -o getpwnam
	$(CC) $(CFLAG) read_time.c -o read_time
	$(CC) $(CFLAG) sig_mask.c -o sig_mask
	$(CC) $(CFLAG) sigpending.c -o sigpending
.PHONY: clean

clean:
	$(RM) signal getpwnam read_time sig_mask sigpending
