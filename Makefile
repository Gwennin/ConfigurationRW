DEBUG=yes
CC=g++
AR=ar
ARFLAGS=-q
SHARED=no
ifeq ($(DEBUG),yes)
ifeq ($(SHARED),yes)
	CCFLAGS=-g -fPIC
else
	CCFLAGS=-g
endif
else
ifeq ($(SHARED),yes)
	CCFLAGS=-fPIC
else
	CCFLAGS=
endif
endif
CCSHAREDFLAG=-shared
EXEC=ConfigurationRW
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)
ifeq ($(DEBUG),yes)
	@echo "Génération en mode debug"
else
	@echo "Génération en mode release"
endif
ifeq ($(SHARED),yes)
	@echo "Génération en mode dynamique"
else
	@echo "Génération en mode statique"
endif

$(EXEC): $(OBJ)
ifeq ($(SHARED),no)
	@$(AR) $(ARFLAGS) lib$(EXEC).a $(OBJ)
else
	@$(CC) $(CCSHAREDFLAG) $(CCFLAGS) $(OBJ) -o lib$(EXEC).so
endif

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CCFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf lib$(EXEC).*
