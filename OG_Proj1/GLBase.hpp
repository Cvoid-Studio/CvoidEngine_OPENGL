#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <cmath>
#pragma comment(lib,"GLAUX.LIB")
#pragma comment(lib,"GlU32.Lib")
#pragma comment(lib,"OpenGL32.Lib")

#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/GLAUX.H>


class GLBase
{
public:
	GLBase();
	~GLBase();


	int RenderScene();

private:
	float angle = 0.0f;
};


GLBase::GLBase()
{
}

GLBase::~GLBase()
{
}

//========================================================//
//================== Function Methods ====================//

int GLBase::RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();			// Reset the Current View Matrix

	gluLookAt(0.0f, 0.0f, 0.0f,
			  0.0f, 0.0f, -10.0f,
			  1.0f, 0.0f, 0.0f);

	angle = angle + 0.2f;
	if (angle >= 360.0f)
		angle = 0.0f;
	glTranslatef(0.0f, 0.0f, -5.0f);
	//glRotatef(angle, 1.0f, 1.0f, 1.0f);

	
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glEnd();

	glRotatef(-2 * angle, 1.0f, 1.0f, 1.0f);
	glColor4f(1.0f, 1.0f, 0.0f, 0.5f);
	glCullFace(GL_FRONT);
	glBegin(GL_QUADS);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);
	glEnd();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glScalef(sinf(angle) / 2 + 1.f, sinf(angle) / 2 + 1.f, sinf(angle) / 2 + 1.f);
	glColor3f(0.0f, 0.0f, 1.0f);
	
	glBegin(GL_POLYGON);
	glVertex3f(1.2f, 1.2f, 1.2f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);
	glEnd();

	
	
	return 0;
}






