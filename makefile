all: program

program: cuda_code.o opencv_test.cpp
	g++ -o program `pkg-config --cflags opencv4` `pkg-config --libs opencv4 cuda cudart` hologrammy.o opencv_test.cpp -I.

cuda_code.o:
	nvcc -c hologrammy.cu

clean: 
	rm -f *.o program
