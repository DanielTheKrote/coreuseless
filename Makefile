CC=gcc
SRCDIR=src

OUTDIR=bin
CFLAGS=-Wall -Werror -std=gnu99
LDFLAGS=
SOURCES=$(wildcard $(SRCDIR)/*.c)
EXECUTABLES=$(patsubst $(SRCDIR)%.c,$(OUTDIR)%,$(SOURCES))

.PHONY=clean all
all: $(OUTDIR) $(EXECUTABLES)

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(OUTDIR)/%: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -r $(OUTDIR)
