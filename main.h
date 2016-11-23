#pragma once
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <string> 
#include <sstream>
#include <random>
#include "camera.h"

#ifndef M_PI
#define M_PI 3.14159265
#endif

#ifdef _WIN32
#define OS 1
#else
#define OS 0
#endif

#define TWO_PI	(2*M_PI)

//Color Parameters
#define RED 0
#define GREEN 1
#define BLUE 2
#define YELLOW 3

//Window Parameters
#define WINDOW_HEIGHT 768
#define WINDOW_WIDTH 1024
#define SCOREBOARD_Y_OFFSET 580
#define SCOREBOARD_X_OFFSET 10
#define MSSA 1

//Keyboard Parameters
#define MOVE_LEFT 'a'
#define MOVE_RIGHT 'd'
#define MOVE_FOREWARDS 'w'
#define MOVE_BACKWARDS 's'
#define REMOVE_SINGLE_CUBE 'q'
#define REMOVE_ALL_CUBES 'e'
#define DROP_CUBES 'r'
#define SPACEBAR ' '
#define SWITCH_LIGHTNING 'l'
#define KEY_ESC 27
#define ANTI_ALLISING 'i'

//Mouse Parameters
#define MOUSE_SENSITIVITY 0.1
#define KEYBORAD_SENSITIVITY 5.0
#define CAMERA_SPEED 0.1
#define MOUSE_POSITION_X 250;
#define MOUSE_POSITION_Y 250;
#define ENABLE_MOUSE_MOVEMENT 0

//Game Prameters
#define NUM_LIGHTS 4
#define CAMERA_MODE_FPS 0
#define CAMERA_MODE_TPS 1
#define SPOT_LIGHTNING_MODE 1
#define TORCH_LIGHTNING_MODE 2

//Player Parameters
#define STARTING_LIVES 3
#define STARTING_SCORE 50
#define INITIAL_POSITION_X 5
#define INITIAL_POSITION_Y 2
#define INITIAL_POSITION_Z 5

//Cube struct
typedef struct {
	int exists = false;
	int canBreak = false;
	int toGive = 0;
	float color[3];
} Cube;

//Player Data struct;
typedef struct {
	float positionX;
	float positionY;
	float positionZ;
	float eyeDirection;

	int lives;
	int score;
	int availableCubes;

	int gameOver = false;
} PlayerData;

typedef struct {
	GLfloat  position[4];
	GLfloat  spotDirection[3];
	float cutOff;
} Flashlight;

//Spotlight Prameters
GLfloat lightAmbient[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat lightDiffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat lightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat whiteLight[] = { 0.2f, 0.2f, 0.2f, 0.2f };
GLfloat sourceLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };

//Cube cubes[N][N][N];
Cube ***cubes;
CCamera Camera;
Flashlight flashlight;
PlayerData Player;

//Spotlight Positions
GLfloat spotlights[NUM_LIGHTS][4];

int N;
float angle;
int lightning = 0;
int animateDrop = false;
int DEBUG = 0;
int mssa = 1;
int mousePositionX = MOUSE_POSITION_X;
int mousePositionY = MOUSE_POSITION_Y;

//FPS Declarations
float frameCount = 0;
int currentTime;
int previousTime = 0;
float fps;

//Function Prototypes
void debug();
void calculateFPS();
void generateRandomColor(float* color);
void setPoint(int x, int y, int z);
void drawGrid();
void drawCube(float x, float y, float z, float r, float g, float b);
void drawLevels();
void setAvailableCubes(Cube *c);
void addCube();
void removeCube(int _all);
void getAvailabeCubes();
void drawScore();
void drawSpotLightningMode();
void drawTorchLightningMode();
void drawLights();
void kickCube();
void restart();
void renderScene();
void idle();
void windowDisplay();
void gameOver();
void fall(float newPosX, float newPosY, float newPosZ);
void dropCubes();
void switchLight();
void antiAllising();
void initializeFirstLevelCubeColors();
void initializePlayer();
void initializeGame();
void initLights();
void initGl();
void windowReshape(GLsizei width, GLsizei height);
void windowKey(unsigned char key, int x, int y);
void windowMouseClick(int button, int state, int x, int y);
void windowMouseMovement(int x, int y);
void allocateSpace();
void displayMenu();
int * calculateNextCubePosition(int currentBoxX, int currentBoxY, int currentBoxZ);
int climb(float newPosX, float newPosY, float newPosZ);
int checkMove(float newPosX, float newPosY, float newPosZ);