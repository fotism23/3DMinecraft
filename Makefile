all:
	g++ -o Assignment1.out -std=c++11 main.cpp camera.cpp -lglut -lGLU -lGL
clean:
	rm	*.o
