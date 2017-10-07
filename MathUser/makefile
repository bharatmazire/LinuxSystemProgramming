INCLUDE_DIR = ../include
TARGET_BIN = mathuser
all : $(TARGET_BIN)

$(TARGET_BIN) : main.c printResult.c ../LibMath/math.c
	gcc -save-temps -I ../include main.c printResult.c ../LibMath/math.c -o $(TARGET_BIN)
clean : 
	rm -vf *.i *.o *.s $(TARGET_BIN)
