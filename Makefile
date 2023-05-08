CC = gcc
EDCFLAGS = -Wall -fPIC -O3 -std=c99 -I include/ $(CFLAGS)

OS=$(shell uname -s)
ifeq ($(OS),Darwin)
	LIBEXT= dylib
	EDCFLAGS:= $(EDCFLAGS)
	EDLDFLAGS:= $(EDLDFLAGS)
	LINKOPTIONS:= -dynamiclib -single_module
	RMDIR=rmdir
	ECHO=echo
	TRUE=TRUE
else
	LIBEXT= so
	LINKOPTIONS:= -shared
	RMDIR=rmdir -v
	ECHO=/bin/echo -e
	TRUE=true
endif
TARGETLIB= libtestlib.$(LIBEXT)

all: $(TARGETLIB) test

test: $(TARGETLIB) example/test.o
	$(CC) $(EDCFLAGS) -o $@.out $^ -L. -ltestlib

$(TARGETLIB): src/testlib.o
	$(CC) $(LINKOPTIONS) -o $@ $^

%.o: %.c
	$(CC) $(EDCFLAGS) -c $< -o $@

clean:
	rm -f $(TARGETLIB) example/test.o src/testlib.o test.out