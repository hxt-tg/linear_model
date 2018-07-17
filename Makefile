CC = gcc
CFLAG = -o2
LIB_H = read.h dataset.h errors.h misc.h
LIB_OBJ = read.o dataset.o errors.o
OBJ = $(LIB_OBJ) test.o

.PHONY: clean cleanall all
all: clean

$(OBJ): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

test: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o test

cleanall: clean
	-rm -f test

clean:
	-rm -f *.o

