CC     := gcc
RN     := rm -f
CFLAGS := -Wall -ggdb -O0 -fomit-frame-pointer

OBJS   := main.o cio.o ch.o
#OBJS += poly.o
ifeq ($(OS),Windows_NT)
	EXE := .exe
endif

PROG   := poly5$(EXE)

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS) $(PROG)
