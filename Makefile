CC=gcc
CFLAGS=-Iinclude
ifeq ($(OS), Windows_NT) # Windows
	DELETE=del
else
	DELETE=rm
	ifeq ($(UNAME_S), Darwin) # MacOS 
		CFLAGS += -D OSX
	else # Linux
	endif
endif

all: travelExpenses
travelExpenses:
	$(CC) $(CFLAGS) src/*.c -o build/travelExpenses
clean:
	$(DELETE) build/**