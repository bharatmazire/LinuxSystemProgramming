ifndef BASE_DIR
	BASE_DIR = ../
else
	BASE_DIR = $1
endif

-include $(BASE_DIR)makefile.inc

INCLUDE_DIR = $(BASE_DIR)include
STATIC_LIB = libmath.a						
DYNAMIC_LIB = libmath.so					

all : $(STATIC_LIB) $(DYNAMIC_LIB)

$(STATIC_LIB) : math.o stat.o					
	ar -rcs $(STATIC_LIB) math.o stat.o	

$(DYNAMIC_LIB) : math.o stat.o
	$(C_COMPILER) -shared -fPIC -o $(DYNAMIC_LIB) math.o stat.o

math.o : math.c
	$(C_COMPILER) -fPIC -I $(INCLUDE_DIR) -c math.c -o math.o

stat.o : stat.c
	$(C_COMPILER) -fPIC -I $(INCLUDE_DIR) -c stat.c -o stat.o

clean : 
	rm -vf *.o
