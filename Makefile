SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebacronologia $(BIN)/pruebafechahistorica

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
# Nota: Esto es solo una posible forma de compilar este proyecto. Modificar según sea necesario.

$(BIN)/pruebacronologia: $(OBJ)/pruebacronologia.o $(OBJ)/cronologia.o $(OBJ)/fechahistorica.o
	$(CXX) -o $(BIN)/pruebacronologia $(OBJ)/pruebacronologia.o $(OBJ)/cronologia.o $(OBJ)/fechahistorica.o

$(OBJ)/pruebacronologia.o : $(SRC)/pruebacronologia.cpp 
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebacronologia.o $(SRC)/pruebacronologia.cpp

$(BIN)/pruebafechahistorica: $(OBJ)/pruebafechahistorica.o $(OBJ)/fechahistorica.o
	$(CXX) -o $(BIN)/pruebafechahistorica $(OBJ)/pruebafechahistorica.o $(OBJ)/fechahistorica.o

$(OBJ)/pruebafechahistorica.o : $(SRC)/pruebafechahistorica.cpp 
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebafechahistorica.o $(SRC)/pruebafechahistorica.cpp


$(OBJ)/cronologia.o : $(SRC)/cronologia.cpp $(INC)/cronologia.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/cronologia.o $(SRC)/cronologia.cpp

$(OBJ)/fechahistorica.o : $(SRC)/fechahistorica.cpp $(INC)/fechahistorica.h 
	$(CXX) $(CPPFLAGS) -o $(OBJ)/fechahistorica.o $(SRC)/fechahistorica.cpp



# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
