INCLUDE_DIR = ../include
STATIC_LIB = libmath.a						
DYNAMIC_LIB = libmath.so					

all : $(STATIC_LIB) $(DYNAMIC_LIB)

$(STATIC_LIB) : math.o stat.o					
	ar -rcs $(STATIC_LIB) math.o stat.o	

$(DYNAMIC_LIB) : math.o stat.o
	gcc -shared -fPIC -o $(DYNAMIC_LIB) math.o stat.o

math.o : math.c
	gcc -fPIC -I $(INCLUDE_DIR) -c math.c -o math.o

stat.o : stat.c
	gcc -fPIC -I $(INCLUDE_DIR) -c stat.c -o stat.o

clean : 
	rm -vf *.o			
