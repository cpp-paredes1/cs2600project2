CC=gcc
CFLAGS=-Iinclude
ifeq ($(OS), Windows_NT) # Windows
	DELETE=del
	DELPATH=build\\**
else
	DELETE=rm
	DELPATH=build/**
	ifeq ($(UNAME_S), Darwin) # MacOS 
		CFLAGS += -D OSX
	else # Linux
	endif
endif

all: travelExpenses
travelExpenses:
	$(CC) $(CFLAGS) src/*.c -o build/travelExpenses
clean:
	$(DELETE) $(DELPATH)