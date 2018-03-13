EXTENSION  = shacrypt
EXTVERSION = 1.0

PG_CONFIG = pg_config

DATA = $(wildcard sql/*.sql)

MODULE_big = shacrypt

OBJS      = shacrypt.o sha512-crypt.o sha256-crypt.o

REGRESS = init sha256 sha512

all:

sha256-crypt.o: sha256.h sha256-crypt.c 
sha512-crypt.o: sha512.h sha512-crypt.c

shacrypt.o: sha256.h sha512.h shacrypt.c

PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
