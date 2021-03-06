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

#define TWO_PI	(2*M_PI)

//Color Parameters.
#define RED 0
#define GREEN 1
#define BLUE 2
#define YELLOW 3

//Window Parameters.
#define WINDOW_HEIGHT 768
#define WINDOW_WIDTH 1024
#define SCOREBOARD_Y_OFFSET 580
#define SCOREBOARD_X_OFFSET 10
#define MSSA 1

//Keyboard Parameters.
#define MOVE_LEFT 'a'
#define MOVE_RIGHT 'd'
#define MOVE_FOREWARDS 'w'
#define MOVE_BACKWARDS 's'
#define REMOVE_SINGLE_CUBE 'q'
#define REMOVE_ALL_CUBES 'e'
#define DROP_CUBES 'r'
#define SPACEBAR ' '
#define SWITCH_LIGHTNING 'l'
#define SWITCH_CAMERA 'c'
#define KEY_ESC 27
#define ANTI_ALLISING 'i'
#define SWITCH_CHARACTER 'm'
#define JUMP 'j'

//Mouse Parameters.
#define MOUSE_SENSITIVITY 0.25
#define KEYBORAD_SENSITIVITY 5.0
#define CAMERA_SPEED 0.1
#define MOUSE_POSITION_X 250;
#define MOUSE_POSITION_Y 250;
#define ENABLE_MOUSE_MOVEMENT 0
#define LOCK_MOUSE_Y 1
#define ENABLE_MOUSE_WHEEL 1

//Game Prameters.
#define NUM_LIGHTS 4
#define CAMERA_MODE_FPS 0
#define CAMERA_MODE_TPS 1
#define SPOT_LIGHTNING_MODE 1
#define TORCH_LIGHTNING_MODE 2
#define FOV 50
#define HUMAN_MODEL 1
#define SNOWMAN_MODEL 2

//Player Parameters.
#define STARTING_LIVES 3
#define STARTING_SCORE 50

//Cube struct.
typedef struct {
	int exists = false;
	int canBreak = false;
	int toGive = 0;
	float color[3];
} Cube;

//Player Data struct.
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

//Flashlight Data struct.
typedef struct {
	GLfloat  position[4];
	GLfloat  spotDirection[3];
	float cutOff;
} Flashlight;

//Spotlight Parameters.
GLfloat lightAmbient[] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat lightDiffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat lightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat whiteLight[] = { 0.1f, 0.1f, 0.1f, 0.1f };
GLfloat sourceLight[] = { 1.0f };

//Spotlight Positions.
GLfloat spotlights[NUM_LIGHTS][4];

Cube ***cubes;
CCamera Camera;
Flashlight flashlight;
PlayerData Player;

int N;
float angle;
int lightning;
int animateDrop;
int DEBUG;
int mssa;
int camera;
int mousePositionX;
int mousePositionY;
float fov;
int character;
int animationState;
int animationDirection;

//FPS Declarations.
float frameCount = 0;
int currentTime;
int previousTime = 0;
float fps;

//Function Prototypes.
void debug();
void calculateFPS();
void generateRandomColor(float* color);
void setPoint(float x, float y, float z);
void drawGrid();
void drawCube(float x, float y, float z, float r, float g, float b);
void drawLevels();
void setAvailableCubes(Cube *c);
void addCube();
void switchCharacter();
void drawSnowman();
void toggleAnimation(int _dir);
void drawHuman();
void drawCharacter();
void removeCube(int _all);
void getAvailabeCubes();
void drawScore();
void drawSpotLightningMode();
void drawTorchLightningMode();
void drawLights();
void kickCube();
void resetCamera();
void restart();
void renderScene();
void idle();
void windowDisplay();
void gameOver();
void fall(float newPosX, float newPosY, float newPosZ);
void jump();
void dropCubes();
void switchLight();
void switchCamera();
void antiAllising();
void initFirstLevelCubeColors();
void initPlayer();
void initGame();
void initLights();
void initGl();
void windowReshape(GLsizei width, GLsizei height);
void windowKey(unsigned char key, int x, int y);
void windowMouseClick(int button, int state, int x, int y);
void windowMouseMovement(int x, int y);
void allocateSpace();
void displayMenu();
void loadDefaultParameters();
void initGlut(int *argc, char **argv);
void initGlutFunctions();
void initUserInput();
int getRotation();
int * calculateNextCubePosition(int currentBoxX, int currentBoxY, int currentBoxZ);
int climb(float newPosX, float newPosY, float newPosZ);
int checkMove(float newPosX, float newPosY, float newPosZ);
