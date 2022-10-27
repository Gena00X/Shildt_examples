.PHONY: all run clean install uninstall

BIN=./bin
ROOT=./
OBJ=./object

NAME = main

TARGET = $(NAME).exe
COMPILATOR = g++
COMPILER_FLAGS_TARGET = -o
COMPILER_FLAGS_OBJECT = -c

all: $(TARGET)
	make install
clean:
		rm -rf $(OBJ)/*.o
		rm -rf $(TARGET)
		rm -rf *.o
		make uninstall

$(NAME).o: $(NAME).cpp 
		$(COMPILATOR) $(COMPILER_FLAGS_TARGET) $(OBJ)/$(NAME).o $(COMPILER_FLAGS_OBJECT) $(NAME).cpp  
		
$(TARGET): $(NAME).o simple_queue.cpp
		$(COMPILATOR) $(COMPILER_FLAGS_TARGET) $(TARGET) $(OBJ)/$(NAME).o simple_queue.cpp
install:
		install $(TARGET) $(BIN)

uninstall:
		rm -rf $(BIN)/$(TARGET)
		
run:
	$(BIN)/$(TARGET)
	
	
	
	
