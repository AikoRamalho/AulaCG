#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif 

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define PI 3.14159265f
#include<math.h>
#include<time.h>


float f(float x)
{
	return -sin(x*PI);
}

//Funcao para desenhar na tela
void display()
{



	//Define a cor de fundo
	glClearColor(0.1, 0.1, 0.1, 1); // R, G, B, A de 0 a 1 (alpha) 

									//Limpa a tela com a cor definida no GlClearColor
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glVertex2f(0, -1);
	glVertex2f(0, 1);
	glEnd();

	static float t = 0;
	t += 0.05;
	glBegin(GL_LINE_STRIP);
	for (float x = -1; x <= 1; x += 0.01)
	{
		float y = f(x + t);
		glColor3f((y + 1) / 2.0f, 0, 0);
		glVertex2f(x, y);
	}

	glEnd();



	//executa os comandos
	glutSwapBuffers();

	glutPostRedisplay(); //chama a display em loop
}
