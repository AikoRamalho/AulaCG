#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif 

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
void display()
{
	//   DESENHA A BANDEIRA DE CUBA (sem estrela)
	glColor3f(0, 0, 0.321);
	glBegin(GL_QUADS);
	glVertex2f(-1, 0.6);
	glVertex2f(-1, 1);
	glVertex2f(1, 1);
	glVertex2f(1, 0.6);

	glVertex2f(-1, -0.2);
	glVertex2f(-1, 0.2);
	glVertex2f(1, 0.2);
	glVertex2f(1, -0.2);

	glVertex2f(-1, -1);
	glVertex2f(-1, -0.6);
	glVertex2f(1, -0.6);
	glVertex2f(1, -1);
	glEnd();

	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-1, 1);
	//glColor3f(0, 1, 0); <= Isso aqui faz escolher uma cor para cada vértice
	glVertex2f(-0.25 , 0);
	//glColor3f(0, 0, 1);
	glVertex2f(-1, -1);
	glEnd();
	
}