ifndef BASE_DIR
	BASE_DIR = ../
else
	BASE_DIR = $1
endif

-include $(BASE_DIR)makefile.inc

INCLUDE_DIR = $(BASE_DIR)include
TARGET_BIN = mathuser
LIBMATH_DIR = $(BASE_DIR)LibMath/

all : $(TARGET_BIN)

$(TARGET_BIN) : main.c printResult.c
	gcc -save-temps -I $(INCLUDE_DIR) -Wl,-rpath=$(LIBMATH_DIR) main.c printResult.c -o $(TARGET_BIN) -L $(LIBMATH_DIR) -lmath
clean : 
	rm -vf *.i *.o *.s $(TARGET_BIN)
