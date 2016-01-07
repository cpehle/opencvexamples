SRC=main.cpp
OBJ=main.o
LDFLAGS=-lopencv_core -lopencv_highgui -lopencv_imgproc
.SUFFIXES:  .cpp .o

camerain: main.o
	c++ $(LDFLAGS) $(OBJ) -o camerain

%.o: %.cpp
	c++ $< -c -o $@

