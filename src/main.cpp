#include "main.h"

void debug() {
	if (DEBUG) return;
	int currentBoxX = (int)Player.positionX;
	int currentBoxY = (int)Player.positionY;
	int currentBoxZ = (int)Player.positionZ;
	printf("Current Box : X : %d Y : %d Z : %d\n", currentBoxX, currentBoxY, currentBoxZ);
	printf("Player Position : X : %f, Y : %f, Z : %f\n", Player.positionX, Player.positionY, Player.positionZ);
	printf("Player Eye Direction : %f\n", Player.eyeDirection);
	printf("Lightning %d\n", lightning);
	printf("Camera %d\n", camera);
	printf("Anti Allising %d\n", mssa);
	printf("Character %d\n", character);
	printf("Animation State %d\n", animationState);
}

void calculateFPS() {
	//  Increase frame count
	frameCount++;
	//  Get the number of milliseconds since glutInit called
	//  (or first call to glutGet(GLUT ELAPSED TIME)).
	currentTime = glutGet(GLUT_ELAPSED_TIME);
	//  Calculate time passed
	int timeInterval = currentTime - previousTime;

	if (timeInterval > 1000)
	{
		//  calculate the number of frames per second
		fps = frameCount / (timeInterval / 1000.0f);
		//  Set time
		previousTime = currentTime;
		//  Reset frame count
		frameCount = 0;
	}
}

void generateRandomColor(float* color) {
	if (color[0] == 1.0f && color[1] == 0.0f && color[2] == 1.0f) return;
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(0, 3);
	int random_integer = uni(rng);

	if (random_integer == RED) {
		color[0] = 1.0f;
		color[1] = 0.0f;
		color[2] = 0.0f;
	}
	else if (random_integer == GREEN) {
		color[0] = 0.0f;
		color[1] = 1.0f;
		color[2] = 0.0f;
	}
	else if (random_integer == BLUE) {
		color[0] = 0.0f;
		color[1] = 0.0f;
		color[2] = 1.0f;
	}
	else if (random_integer == YELLOW) {
		color[0] = 1.0f;
		color[1] = 1.0f;
		color[2] = 0.0f;
	}
	else {
		color[0] = 0.0f;
		color[1] = 0.0f;
		color[2] = 0.0f;
	}
}

void drawGrid() {
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	for (GLfloat i = 0; i <= N; i += 1) {
		glVertex3f(i, 0, 0);
		glVertex3f(i, 0, (GLfloat)N);
		glVertex3f((GLfloat)N, 0, i);
		glVertex3f(0, 0, i);
	}
	glEnd();
	glPopMatrix();
}

void drawCube(float x, float y, float z, float r, float g, float b) {
	/*
	glPushMatrix();
	setPoint(x, y, z);
	glColor3f(r, g, b);
	glutSolidCube(1.0);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCube(1.0);
	glPopMatrix();
	*/

	glPushMatrix();
	setPoint(x, y, z);
	//Draw edges for the cube.
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, -0.0f);
	glEnd();

	//Draw Cube
	glBegin(GL_QUADS);

	// Top face
	glColor3f(r, g, b);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glEnd();

	// Front face
	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glEnd();

	// Right face
	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glEnd();

	// Left face
	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glEnd();

	// Bottom face
	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glEnd();

	// Back face
	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, -0.0f);
	glEnd();
	glPopMatrix();

}

void switchCharacter() {
	if (camera == CAMERA_MODE_FPS) return;
	if (character == HUMAN_MODEL) character = SNOWMAN_MODEL;
	else character = HUMAN_MODEL;
}

void drawSnowman() {
	setPoint(Player.positionX, floor(Player.positionY), Player.positionZ);

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glRotatef(180, 0, 0, 1);
	glRotatef(Player.eyeDirection, 0, 0, 1);

	// Draw body (a 20x20 spherical mesh of radius 0.75 at height 0.75)
	glColor3f(0.83f, 0.83f, 0.83f); // set drawing color to white
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.3f);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	// Draw the head (a sphere of radius 0.25 at height 1.75)
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.7f); // position head
	glutSolidSphere(0.15, 20, 20); // head sphere

								   // Draw Eyes (two small grey spheres)
	glColor3f(0.22f, 0.22f, 0.22f); // eyes are black
	glPushMatrix();
	glTranslatef(0.0f, -0.12f, 0.10f); // lift eyes to final position
	glPushMatrix();
	glTranslatef(-0.05f, 0.0f, -0.0f);
	glutSolidSphere(0.05, 10, 10); // right eye
	glPopMatrix();
	glPushMatrix();
	glTranslatef(+0.05f, 0.0f, 0.0f);
	glutSolidSphere(0.05, 10, 10); // left eye
	glPopMatrix();
	glPopMatrix();

	// Draw Nose (the nose is an orange cone)
	glColor3f(1.0, 0.5, 0.5); // nose is orange
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0); // rotate to point along -y
	glutSolidCone(0.08, 0.3, 10, 2); // draw cone
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}

int getRotation() {
	int rotation[] = { -20, -15, -10, -5, 0, 5, 10, 15, 20 };
	return rotation[animationState];
}

void toggleAnimation(int _dir) {
	if (camera == CAMERA_MODE_FPS) return;

	if (_dir == 0) {
		if (animationState == 8) animationDirection = -1;
		else if (animationState == 0) animationDirection = 1;
		if (animationDirection == 1) animationState++;
		else animationState--;
	}
	else {
		if (animationState == 8) animationDirection = 1;
		else if (animationState == 0) animationDirection = -1;
		if (animationDirection == 1) animationState--;
		else animationState++;
	}
}

void drawHuman() {
	setPoint(Player.positionX, floor(Player.positionY), Player.positionZ);
	glRotatef(Player.eyeDirection, 0, 1, 0);
	glColor3f(0.023, 0.13, 0.32);
	int rotation = getRotation();
	//Model Begin
	glPushMatrix();
	//Legs Begin
	glPushMatrix();
	//Left leg Begin
	glPushMatrix();
	glTranslatef(0.0, 0.5, 0.0);
	glTranslatef(-0.0625, 0.0, 0.0);
	glRotatef(rotation, 1, 0, 0);
	glColor3f(0.023, 0.13, 0.32);
	for (int i = 0; i < 5; i++) {
		glutSolidCube(0.1);
		glTranslatef(0.0, -0.1, 0.0);
	}
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);

	glutSolidCube(0.1);
	glPopMatrix();
	glPopMatrix();
	//Left leg End

	//Right Leg Begin
	glColor3f(0.023, 0.13, 0.32);
	glPushMatrix();
	glTranslatef(0.0, 0.5, 0.0);
	glTranslatef(+0.0625, 0.0, 0.0);
	glRotatef(rotation*(-1.), 1, 0, 0);

	glColor3f(0.023, 0.13, 0.32);
	for (int i = 0; i < 5; i++) {
		glutSolidCube(0.1);
		glTranslatef(0.0, -0.1, 0.0);
	}
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glutSolidCube(0.1);
	glPopMatrix();
	glPopMatrix();
	//Right leg End
	glPopMatrix();
	//Legs End

	glTranslatef(0.0, 0.5, 0.0);
	//Body Begin
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(-0.125f, -0.125f, +0.125f);
	glVertex3f(+0.125f, -0.125f, +0.125f);
	glVertex3f(-0.125f, 0.375f, +0.125f);
	glVertex3f(+0.125f, 0.375f, +0.125f);
	glEnd();

	glColor3f(0.72, 0.72, 0.72);
	glutSolidCube(0.25);
	glTranslatef(0.0, 0.25, 0.0);
	glutSolidCube(0.25);
	glPopMatrix();
	//Body End

	//Right Hand Begin
	glPushMatrix();
	glColor3f(0.55, 0.55, 0.55);
	glTranslatef(0.15625, 0.340, 0.0);

	glRotatef(rotation, 1, 0, 0);
	for (int i = 0; i < 6; i++) {
		glutSolidCube(0.0625);
		glTranslatef(0.0, -0.0625, 0.0);
	}
	glPopMatrix();
	//Right Hand End

	//Left Hand Begin
	glPushMatrix();
	glColor3f(0.55, 0.55, 0.55);
	glTranslatef(-0.15625, 0.340, 0.0);
	glRotatef(rotation*(-1.), 1, 0, 0);
	for (int i = 0; i < 6; i++) {
		glutSolidCube(0.0625);
		glTranslatef(0.0, -0.0625, 0.0);
	}
	glPopMatrix();
	//Left Hand End

	//Neck Begin
	glTranslatef(0.0, 0.375, 0.0);
	glPushMatrix();
	glColor3f(1.0, 0.87, 0.74);
	glutSolidCube(0.100);
	glTranslatef(0.0, 0.125, 0.0);
	glutSolidCube(0.100);
	glPopMatrix();
	//Neck End

	//Head Begin
	glTranslatef(0.0, 0.15, 0.0);
	glPushMatrix();
	glutSolidSphere(0.125, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//Model End
}

void drawCharacter()
{
	if (camera == CAMERA_MODE_FPS) return;
	if (character == HUMAN_MODEL) drawHuman();
	else if (character == SNOWMAN_MODEL) drawSnowman();
}

void drawLevels() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (cubes[i][k][j].exists) {
					drawCube((float)i, (float)k, (float)j, cubes[i][k][j].color[0], cubes[i][k][j].color[1], cubes[i][k][j].color[2]);
				}
			}
		}
	}
}

void drawScore() {
	if (lightning != 0) glDisable(GL_LIGHTING);
	std::ostringstream oss;

	oss << "Score: " << Player.score
		<< "  Lives: " << Player.lives
		<< "  Available Cubes: " << Player.availableCubes
		<< "  Current Position:  x: " << (int)Player.positionX + 1
		<< "  y: " << (int)Player.positionY + 1
		<< "  z: " << (int)Player.positionZ + 1
		<< "  Eye Direction: " << (int)Player.eyeDirection
		<< "  FPS: " << fps;
	std::string s = oss.str();

	int length = s.length();

	glColor3f(0, 1, 0);
	glMatrixMode(GL_PROJECTION);
	double matrix[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();

	glRasterPos2i(SCOREBOARD_X_OFFSET, SCOREBOARD_Y_OFFSET);

	for (int i = 0; i < length; i++) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)s[i]);
	}

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}

void drawSpotLightningMode() {
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight);

	for (int i = 0; i < NUM_LIGHTS; i++) {
		int lt = GL_LIGHT1 + i;
		glEnable(lt);
		glLightfv(lt, GL_POSITION, spotlights[i]);
		glLightfv(lt, GL_SPECULAR, lightSpecular);
		glLightfv(lt, GL_DIFFUSE, lightDiffuse);
		glLightfv(lt, GL_AMBIENT, lightAmbient);
	}
}

void drawTorchLightningMode() {
	flashlight.position[0] = Player.positionX - 1;
	flashlight.position[1] = 0;
	flashlight.position[2] = Player.positionZ - 1;
	flashlight.position[3] = 0.0f;
	SF3dVector viewDirection = Camera.getViewDirection();
	GLfloat direction[3];
	direction[0] = viewDirection.x;
	direction[1] = viewDirection.y;
	direction[2] = viewDirection.z;

	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, sourceLight);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT0, GL_POSITION, flashlight.position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 25.0);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, -2.0);
}

void drawLights() {
	if (lightning == SPOT_LIGHTNING_MODE) {
		glDisable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		drawSpotLightningMode();
	}
	else if (lightning == TORCH_LIGHTNING_MODE) {
		for (int i = 0; i < NUM_LIGHTS; i++) {
			int lt = GL_LIGHT1 + i;
			glDisable(lt);
		}
		glEnable(GL_LIGHTING);
		drawTorchLightningMode();
	}
	else glDisable(GL_LIGHTING);
}

void setPoint(float x, float y, float z) {
	glTranslatef(0.0f, 0.0f, 0.0f);
	glTranslatef((GLfloat)x, (GLfloat)y, (GLfloat)z);
}

//Returns the next squere in front of the player
int * calculateNextCubePosition(int currentBoxX, int currentBoxY, int currentBoxZ) {
	static int r[3];

	if (Player.eyeDirection > -45 && Player.eyeDirection < 45) currentBoxZ--;
	else if (Player.eyeDirection > 45 && Player.eyeDirection < 135) currentBoxX--;
	else if (Player.eyeDirection > 135 && Player.eyeDirection < 225) currentBoxZ++;
	else if (Player.eyeDirection > 225 && Player.eyeDirection < 315) currentBoxX++;
	else if (Player.eyeDirection == 45 || Player.eyeDirection == -315) { currentBoxX--; currentBoxZ--; }
	else if (Player.eyeDirection == 135 || Player.eyeDirection == -225) { currentBoxX--; currentBoxZ++; }
	else if (Player.eyeDirection == 225 || Player.eyeDirection == -135) { currentBoxZ++; currentBoxX++; }
	else if (Player.eyeDirection == 315 || Player.eyeDirection == -45) { currentBoxX++; currentBoxZ--; }
	else if (Player.eyeDirection > -360 && Player.eyeDirection < -315) currentBoxZ--;
	else if (Player.eyeDirection > -315 && Player.eyeDirection < -225) currentBoxX--;
	else if (Player.eyeDirection > -225 && Player.eyeDirection < -135) currentBoxZ++;
	else if (Player.eyeDirection > -135 && Player.eyeDirection < -45) currentBoxX++;
	else if (Player.eyeDirection > 315 && Player.eyeDirection < 360) currentBoxZ--;

	r[0] = currentBoxX;
	r[1] = currentBoxY;
	r[2] = currentBoxZ;

	return r;
}

void resetCamera() {
	if (camera == CAMERA_MODE_TPS) {
		switchCamera();
		Camera = CCamera();
		Camera.Move(F3dVector(Player.positionX, Player.positionY, Player.positionZ));
		switchCamera();
	}
	else {
		Camera = CCamera();
		Camera.Move(F3dVector(Player.positionX, Player.positionY, Player.positionZ));
	}
}

//Returns the player to the initial position
void restart() {
	Player.positionX = (float)round(N / 2);
	Player.positionZ = (float)round(N / 2);
	Player.positionY = 1.5f;
	Player.eyeDirection = 0.0f;
	resetCamera();
}

//Called every time the player falls into the void
void gameOver() {
	if (Player.lives == 1) {
		Player.gameOver = true;
		exit(1);
	}
	Player.lives--;
	restart();
	windowDisplay();
}

void fall(float newPosX, float newPosY, float newPosZ) {
	int fallTo = 0;

	for (int i = (int)newPosY; i >= 0; i--) {
		if (cubes[(int)newPosX][i][(int)newPosZ].exists) {
			fallTo = i + 1;
			break;
		}
	}
	float drop = newPosY - (float)fallTo;
	int pointFactor = (int)abs(drop) - 1;
	Player.score -= (pointFactor * 5);
	Camera.Move(F3dVector(0.0f, -drop, 0.0f));
	Player.positionY = (float)fallTo;
	if (Player.positionY == 0) gameOver();
}

int climb(float newPosX, float newPosY, float newPosZ) {
	int count = 0;
	int climbTo = -1;

	for (int i = (int)newPosY; i < N; i++) {
		if (cubes[(int)newPosX][i][(int)newPosZ].exists) count++;
		else {
			climbTo = i;
			break;
		}
	}
	if (count == 2) return false;
	Camera.Move(F3dVector(0.0f, 1.0f, 0.0f));
	Player.positionY = (float)climbTo;
	Player.score += 5;
	if (Player.positionY == N - 1) {
		Player.score += 100;
		Player.lives++;
	}
	return false;
}

void jump() {
	int * nextPos = calculateNextCubePosition((int)Player.positionX, (int)Player.positionY - 1, (int)Player.positionZ);
	nextPos = calculateNextCubePosition(nextPos[0], nextPos[1], nextPos[2]);
	if (!cubes[nextPos[0]][nextPos[1]][nextPos[2]].exists) return;

	Player.positionX -= (float)sin(angle) * (float)2.0;
	Player.positionZ -= (float)cos(angle) * (float)2.0;
	Camera.Move(F3dVector(-(float)sin(angle) * (float)2.0, 0, -(float)cos(angle) * (float)2.0));

}

int checkMove(float newPosX, float newPosY, float newPosZ) {
	if (newPosX > N || newPosX < 0 || newPosZ > N || newPosZ < 0) return false; //Prevents Player to move outside the grid
	if (cubes[(int)newPosX][(int)newPosY][(int)newPosZ].exists) {
		return climb(newPosX, newPosY, newPosZ);
	}
	if (!cubes[(int)newPosX][(int)newPosY - 1][(int)newPosZ].exists) {
		fall(newPosX, newPosY, newPosZ);
	}
	return true;
}

void kickCube() {
	int * nextPos = (int *)malloc(3 * sizeof(int)); //Next Cube Position
	int * lastPos = (int *)malloc(3 * sizeof(int)); //last Cube Position
	int * current = (int *)malloc(3 * sizeof(int));
	int cubeCount = 0;

	current[0] = (int)Player.positionX;
	current[1] = (int)Player.positionY;
	current[2] = (int)Player.positionZ;

	while (current[0] < N && current[1] >= 0 && current[2] >= 0 && current[2] < N)
	{
		nextPos = calculateNextCubePosition(current[0], current[1], current[2]);
		if (!cubes[nextPos[0]][nextPos[1]][nextPos[2]].exists) {
			lastPos[0] = nextPos[0];
			lastPos[1] = nextPos[1];
			lastPos[2] = nextPos[2];
			break;
		}
		cubeCount++;
		current[0] = nextPos[0];
		current[1] = nextPos[1];
		current[2] = nextPos[2];
	}

	current[0] = (int)Player.positionX;
	current[1] = (int)Player.positionY;
	current[2] = (int)Player.positionZ;

	if (DEBUG) {
		printf("Current Point : %d %d %d  Target Point : %d %d %d \n", current[0], current[1], current[2], lastPos[0], lastPos[1], lastPos[2]);
		printf("Count = %d\n", cubeCount);
	}

	Cube *tempArray = (Cube *)malloc(cubeCount * sizeof(Cube));
	int i = 0;

	current = calculateNextCubePosition((int)Player.positionX, (int)Player.positionY, (int)Player.positionZ);

	while (i < cubeCount) {
		tempArray[i].color[0] = cubes[current[0]][current[1]][current[2]].color[0];
		tempArray[i].color[1] = cubes[current[0]][current[1]][current[2]].color[1];
		tempArray[i].color[1] = cubes[current[0]][current[1]][current[2]].color[1];
		tempArray[i].exists = cubes[current[0]][current[1]][current[2]].exists;
		current = calculateNextCubePosition(current[0], current[1], current[2]);
		i++;
	}

	current = calculateNextCubePosition((int)Player.positionX, (int)Player.positionY, (int)Player.positionZ);
	current = calculateNextCubePosition(current[0], current[1], current[2]);

	i = 0;
	while (i < cubeCount) {
		cubes[current[0]][current[1]][current[2]].color[0] = tempArray[i].color[0];
		cubes[current[0]][current[1]][current[2]].color[1] = tempArray[i].color[1];
		cubes[current[0]][current[1]][current[2]].color[2] = tempArray[i].color[2];
		cubes[current[0]][current[1]][current[2]].exists = tempArray[i].exists;
		current = calculateNextCubePosition(current[0], current[1], current[2]);
		i++;
	}

	current = calculateNextCubePosition((int)Player.positionX, (int)Player.positionY, (int)Player.positionZ);
	generateRandomColor(cubes[current[0]][current[0]][current[0]].color);
	cubes[current[0]][current[1]][current[2]].exists = false;
}

void dropCubes() {
	int flag = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = N - 1; k >= 1; k--) {
				if (cubes[i][k][j].exists && !cubes[i][k - 1][j].exists) {
					float * color = cubes[i][k][j].color;
					cubes[i][k][j].exists = false;
					cubes[i][k - 1][j].exists = true;
					cubes[i][k - 1][j].color[0] = color[0];
					cubes[i][k - 1][j].color[1] = color[1];
					cubes[i][k - 1][j].color[2] = color[2];
					flag = true;
					windowDisplay();
				}
			}
		}
	}
	if (flag) Player.score += 10;

	animateDrop = false;
}

void addCube() {
	if (Player.availableCubes == 0) return;
	int * point = calculateNextCubePosition((int)Player.positionX, (int)Player.positionY, (int)Player.positionZ);

	while (1) {
		if (!cubes[point[0]][point[1]][point[2]].exists) break;
		if (point[1] == N) return;
		point[1]++;
	}
	Player.availableCubes--;
	generateRandomColor(cubes[point[0]][point[1]][point[2]].color);
	cubes[point[0]][point[1]][point[2]].exists = true;
	cubes[point[0]][point[1]][point[2]].canBreak = true;
	setAvailableCubes(&cubes[point[0]][point[1]][point[2]]);
	Player.score += 5;
}

void removeCube(int _all) {
	int * point = calculateNextCubePosition((int)Player.positionX, (int)Player.positionY, (int)Player.positionZ);

	if (!_all) {
		if (Player.score < 20) return;
		cubes[point[0]][point[1]][point[2]].exists = false;
	}
	else {
		if (Player.score < 20) return;
		for (int i = 0; i < N; i++) {
			cubes[point[0]][i][point[2]].exists = false;
		}
		Player.score -= 20;
		Player.lives++;
	}
}

void setAvailableCubes(Cube *c) {
	float * color = c->color;
	if (color[0] == 1.0f && color[1] == 0.0f && color[2] == 0.0f) {
		c->toGive = 2;
	}
	else if (color[0] == 0.0f && color[1] == 1.0f && color[2] == 0.0f) {
		c->toGive = 3;
	}
	else if (color[0] == 0.0f && color[1] == 0.0f && color[2] == 1.0f) {
		c->toGive = 0;
	}
	else if (color[0] == 1.0f && color[1] == 1.0f && color[2] == 0.0f) {
		c->toGive = 1;
	}
}

void getAvailabeCubes() {
	if (Player.score < 5) return;
	Cube *c = &cubes[(int)Player.positionX][(int)Player.positionY - 1][(int)Player.positionZ];
	if (c->toGive == 0) return;
	Player.availableCubes++;
	c->toGive--;
	if (c->toGive == 0) {
		cubes[(int)Player.positionX][(int)Player.positionY - 1][(int)Player.positionZ].color[0] = 0.0f;
		cubes[(int)Player.positionX][(int)Player.positionY - 1][(int)Player.positionZ].color[1] = 0.0f;
		cubes[(int)Player.positionX][(int)Player.positionY - 1][(int)Player.positionZ].color[2] = 1.0f;
	}
	else if (c->toGive == 1) {
		cubes[(int)Player.positionX][(int)Player.positionY - 1][(int)Player.positionZ].color[0] = 1.0f;
		cubes[(int)Player.positionX][(int)Player.positionY - 1][(int)Player.positionZ].color[1] = 1.0f;
		cubes[(int)Player.positionX][(int)Player.positionY - 1][(int)Player.positionZ].color[2] = 0.0f;
	}
	else if (c->toGive == 2) {
		cubes[(int)Player.positionX][(int)Player.positionY - 1][(int)Player.positionZ].color[0] = 1.0f;
		cubes[(int)Player.positionX][(int)Player.positionY - 1][(int)Player.positionZ].color[1] = 0.0f;
		cubes[(int)Player.positionX][(int)Player.positionY - 1][(int)Player.positionZ].color[2] = 0.0f;
	}
	Player.score -= 5;

}

void switchLight() {
	if (lightning == TORCH_LIGHTNING_MODE) {
		lightning = 0;
	}
	else {
		lightning++;
	}
}

void switchCamera() {
	if (camera == CAMERA_MODE_FPS) {
		Camera.MoveForwards((GLfloat)2);
		Camera.RotateX(-20);
		Camera.Move(F3dVector(0.0f, 1.0f, 0.0f));
	}
	else if (camera == CAMERA_MODE_TPS) {
		Camera.RotateX(+20);
		Camera.MoveForwards((GLfloat)-2);
		Camera.Move(F3dVector(0.0f, -1.0f, 0.0f));
	}
	camera = !camera;
}

void antiAllising() {
	if (mssa) glEnable(GLUT_MULTISAMPLE);
	else glDisable(GLUT_MULTISAMPLE);
}

void renderScene() {
	drawGrid();
	drawLevels();
	drawCharacter();
	drawScore();
	drawLights();

}

void idle() {
	calculateFPS();
}

void windowDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	Camera.Render();
	renderScene();
	antiAllising();
	glFlush();
	glutSwapBuffers();
}

void windowReshape(GLsizei width, GLsizei height) {
	GLfloat light_position[] = { 0, 0, 0, 1 };
	if (width == 0 || height == 0) return;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, (GLdouble)width / (GLdouble)height, 0.0001, 30); //pws vlepw
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void windowKey(unsigned char key, int x, int y) {
	if (Player.gameOver) return;
	switch (key) {
	case KEY_ESC:
		exit(1);
		break;
	case MOVE_LEFT:
		if (camera == CAMERA_MODE_FPS) {
			Player.eyeDirection += KEYBORAD_SENSITIVITY;
			Camera.RotateY((GLfloat)KEYBORAD_SENSITIVITY);
		}
		else {
			Player.eyeDirection += KEYBORAD_SENSITIVITY;
			Camera.Orbit((GLfloat)Player.eyeDirection, KEYBORAD_SENSITIVITY, Player.positionX, Player.positionZ);
		}
		if (Player.eyeDirection == 360 || Player.eyeDirection == -360) Player.eyeDirection = 0;
		angle = (float)(Player.eyeDirection * PI) / 180.0f;
		break;
	case MOVE_RIGHT:
		if (camera == CAMERA_MODE_FPS) {
			Player.eyeDirection -= KEYBORAD_SENSITIVITY;
			Camera.RotateY((GLfloat)-KEYBORAD_SENSITIVITY);
		}
		else {
			Player.eyeDirection -= KEYBORAD_SENSITIVITY;
			Camera.Orbit((GLfloat)Player.eyeDirection, -KEYBORAD_SENSITIVITY, Player.positionX, Player.positionZ);
		}

		if (Player.eyeDirection == 360 || Player.eyeDirection == -360) Player.eyeDirection = 0;
		angle = (float)(Player.eyeDirection * PI) / 180.0f;
		break;
	case MOVE_FOREWARDS:
		if (checkMove(Player.positionX - (float)sin(angle) * (float)CAMERA_SPEED,
			Player.positionY,
			Player.positionZ - (float)cos(angle) * (float)CAMERA_SPEED))
		{
			Player.positionX -= (float)sin(angle) * (float)CAMERA_SPEED;
			Player.positionZ -= (float)cos(angle) * (float)CAMERA_SPEED;
			toggleAnimation(0);
			Camera.Move(F3dVector(-(float)sin(angle) * (float)CAMERA_SPEED, 0, -(float)cos(angle) * (float)CAMERA_SPEED));
		}
		break;
	case MOVE_BACKWARDS:
		if (checkMove(Player.positionX + (float)sin(angle) * (float)CAMERA_SPEED,
			Player.positionY,
			Player.positionZ + (float)cos(angle) * (float)CAMERA_SPEED))
		{
			Player.positionX += (float)sin(angle) * (float)CAMERA_SPEED;
			Player.positionZ += (float)cos(angle) * (float)CAMERA_SPEED;
			toggleAnimation(1);
			Camera.Move(F3dVector((float)sin(angle) * (float)CAMERA_SPEED, 0, (float)cos(angle) * (float)CAMERA_SPEED));
		}
		break;
	case SPACEBAR:
		getAvailabeCubes();
		break;
	case REMOVE_SINGLE_CUBE:
		removeCube(false);
		break;
	case REMOVE_ALL_CUBES:
		removeCube(true);
		break;
	case DROP_CUBES:
		animateDrop = true;
		dropCubes();
		break;
	case SWITCH_LIGHTNING:
		switchLight();
		break;
	case ANTI_ALLISING:
		mssa = !mssa;
		break;
	case SWITCH_CAMERA:
		switchCamera();
		break;
	case SWITCH_CHARACTER:
		switchCharacter();
		break;
	case JUMP:
		jump();
		break;
	default:
		printf("Pressing %d doesn't to nothing.\n", key);
		break;
	}
	if (!animateDrop)windowDisplay();
	debug();
}

void windowMouseClick(int button, int state, int x, int y) {
	if (Player.gameOver) return;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		addCube();
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		kickCube();
	}
	else if (button == 3 && state == GLUT_UP && ENABLE_MOUSE_WHEEL) {
		fov -= 0.5;
	}
	else if (button == 4 && state == GLUT_UP && ENABLE_MOUSE_WHEEL) {
		fov += 0.5;
	}
	windowDisplay();
	debug();
}

void windowMouseMovement(int x, int y) {
	if (x < mousePositionX) {
		if (camera == CAMERA_MODE_FPS) {
			Player.eyeDirection += MOUSE_SENSITIVITY;
			Camera.RotateY((GLfloat)MOUSE_SENSITIVITY);
		}
		else {
			Player.eyeDirection += MOUSE_SENSITIVITY;
			Camera.Orbit((GLfloat)Player.eyeDirection, MOUSE_SENSITIVITY, Player.positionX, Player.positionZ);
		}
		if (Player.eyeDirection == 360 || Player.eyeDirection == -360) Player.eyeDirection = 0;
		angle = (float)(Player.eyeDirection * PI) / 180.0f;
	}
	else {
		if (camera == CAMERA_MODE_FPS) {
			Player.eyeDirection -= MOUSE_SENSITIVITY;
			Camera.RotateY((GLfloat)-MOUSE_SENSITIVITY);
		}
		else {
			Player.eyeDirection -= MOUSE_SENSITIVITY;
			Camera.Orbit((GLfloat)Player.eyeDirection, -MOUSE_SENSITIVITY, Player.positionX, Player.positionZ);
		}

		if (Player.eyeDirection == 360 || Player.eyeDirection == -360) Player.eyeDirection = 0;
		angle = (float)(Player.eyeDirection * PI) / 180.0f;
	}
	if (y < mousePositionY && !LOCK_MOUSE_Y) {
		Camera.RotateX((GLfloat)MOUSE_SENSITIVITY);
	}
	else if (!LOCK_MOUSE_Y) {
		Camera.RotateX((GLfloat)-MOUSE_SENSITIVITY);
	}
	windowDisplay();
	mousePositionX = x;
	mousePositionY = y;
}

void allocateSpace() {
	cubes = (Cube ***)malloc(N * sizeof(Cube **));

	if (cubes == NULL) {
		printf("Error\n");
		exit(0);
	}

	for (int i = 0; i < N; i++) {
		cubes[i] = (Cube **)malloc(N * sizeof(Cube *));
		if (cubes[i] == NULL) {
			printf("Error\n");
			exit(0);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cubes[i][j] = (Cube *)malloc(N * sizeof(Cube));
			if (cubes[i][j] == NULL) {
				printf("Error\n");
				exit(0);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cubes[i][j][k].color[0] = 1.0f;
				cubes[i][j][k].color[1] = 1.0f;
				cubes[i][j][k].color[1] = 1.0f;
				cubes[i][j][k].exists = false;
				cubes[i][j][k].canBreak = false;
			}
		}
	}
}

void displayMenu() {
	char input[10];

	puts("Give grid size: ");
	fgets(input, 10, stdin);

	int size = atoi(input);
	printf("Selected size : %d\n", size);
	puts("Enable debug? [y/n] :");

	while (1) {
		fgets(input, 10, stdin);
		if (input[0] == 'y' || input[0] == 'n') break;
	}

	if (input[0] == 'y') DEBUG = 1;
	N = size;
}

void loadDefaultParameters() {
	lightning = 0;
	animateDrop = false;
	DEBUG = 0;
	mssa = 1;
	camera = CAMERA_MODE_FPS;
	mousePositionX = MOUSE_POSITION_X;
	mousePositionY = MOUSE_POSITION_Y;
	fov = FOV;
	character = HUMAN_MODEL;
	animationState = 4;
	animationDirection = 1;
}

void initGl() {
	glClearColor(0.56f, 0.66f, 0.82f, 1);
	glClearDepth(5.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
}

void initGlut(int *argc, char **argv) {
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Fotis Mitropoulos 2486 Assignment1");
}

void initGlutFunctions() {
	glutDisplayFunc(&windowDisplay);
	glutReshapeFunc(&windowReshape);
	glutIdleFunc(&idle);
}

void initUserInput() {
	glutKeyboardFunc(&windowKey);
	glutMouseFunc(&windowMouseClick);
	if (ENABLE_MOUSE_MOVEMENT) glutPassiveMotionFunc(&windowMouseMovement);
}

void initLights() {
	spotlights[0][0] = (GLfloat)N;
	spotlights[0][1] = (GLfloat)N;
	spotlights[0][2] = (GLfloat)N;
	spotlights[0][3] = 1.0f;

	spotlights[1][0] = 0.0f;
	spotlights[1][1] = (GLfloat)N;
	spotlights[1][2] = (GLfloat)N;
	spotlights[1][3] = 1.0f;

	spotlights[2][0] = (GLfloat)N;
	spotlights[2][1] = (GLfloat)N;
	spotlights[2][2] = 0.0f;
	spotlights[2][3] = 1.0f;

	spotlights[3][0] = 0.0f;
	spotlights[3][1] = (GLfloat)N;
	spotlights[3][2] = 0.0f;
	spotlights[3][3] = 1.0f;
}

void initPlayer() {
	Player.lives = STARTING_LIVES;
	Player.gameOver = false;
	Player.score = STARTING_SCORE;
	Player.positionX = (float)round(N / 2);
	Player.positionZ = (float)round(N / 2);
	Player.positionY = 1.5f;
	Player.eyeDirection = 0.0f;
}

void initGame() {
	initLights();
	initFirstLevelCubeColors();
	Camera.Move(F3dVector(Player.positionX, Player.positionY, Player.positionZ));
}

void initFirstLevelCubeColors() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			generateRandomColor(cubes[i][0][j].color);
			cubes[i][0][j].exists = true;
			cubes[i][0][j].canBreak = true;
			setAvailableCubes(&cubes[i][0][j]);
		}
	}
	int center = (int)round(N / 2.0);
	cubes[center][0][center].color[0] = 1.0f;
	cubes[center][0][center].color[1] = 0.0f;
	cubes[center][0][center].color[2] = 1.0f;
	cubes[center][0][center].exists = true;
	cubes[center][0][center].canBreak = false;
	cubes[center][0][center].toGive = 0;
}

int main(int argc, char **argv) {
	displayMenu();
	allocateSpace();
	initGlut(&argc, argv);
	initGl();
	initPlayer();
	initGame();
	loadDefaultParameters();
	initGlutFunctions();
	initUserInput();
	glutMainLoop();
	return 0;
}
