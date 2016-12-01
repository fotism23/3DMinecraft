#include <GL/glut.h>	
#include "math.h"
#include <iostream>

#define PI 3.1415265359
#define PIdiv180 3.1415265359/180.0

#define CAMERA_RADIUS 2

//Note: All angles in degrees

struct SF3dVector {
	GLfloat x,y,z;
};

struct SF2dVector {
	GLfloat x,y;
};

class CCamera {
private:
	SF3dVector Position;
	/*
	Not used for rendering the camera, but for "moveforwards"
	So it is not necessary to "actualize" it always. It is only
	actualized when ViewDirChanged is true and moveforwards is called
	*/
	SF3dVector ViewDir;		
	bool ViewDirChanged;
	GLfloat RotatedX, RotatedY, RotatedZ;	
	void GetViewDir ( void );
public:
	//inits the values (Position: (0|0|0) Target: (0|0|-1) )
	CCamera();
	void Render ( void );	
	//executes some glRotates and a glTranslate command
	//Note: You should call glLoadIdentity before using Render
	void Orbit( GLfloat Angle, GLfloat offset, GLfloat positionX, GLfloat positionZ);
	void Move ( SF3dVector Direction );
	void RotateX ( GLfloat Angle );
	void RotateY ( GLfloat Angle );
	void MoveForwards ( GLfloat Distance );
	SF3dVector getViewDirection();
};

SF3dVector F3dVector ( GLfloat x, GLfloat y, GLfloat z );
SF3dVector AddF3dVectors ( SF3dVector * u, SF3dVector * v);
void AddF3dVectorToVector ( SF3dVector * Dst, SF3dVector * V2);
