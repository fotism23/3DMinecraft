all:
	g++ -o Assignment1.out -std=c++11 src/main.cpp src/camera.cpp -lglut -lGLU -lGL
clean:
	rm	*.o
