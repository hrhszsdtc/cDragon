# Project: cDragon
# Makefile created by Dev-C++ 5.11

CPP      = g++.exe
CC       = gcc.exe
WINDRES  = windres.exe
OBJ      = main.o
LINKOBJ  = main.o
LIBS     = -L"D:/Dev-Cpp/MinGW64/lib" -L"D:/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib" -static-libgcc
INCS     = -I"D:/Dev-Cpp/MinGW64/include" -I"D:/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"D:/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include"
CXXINCS  = -I"D:/Dev-Cpp/MinGW64/include" -I"D:/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"D:/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include" -I"D:/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include/c++"
BIN      = cDragon.exe
CXXFLAGS = $(CXXINCS) -std=c++11
CFLAGS   = $(INCS) -std=c++11
RM       = rm.exe -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

main.o: main.cpp
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS)
