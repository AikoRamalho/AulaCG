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


//circulo de fora
void drawCircle(float r)
{
	glBegin(GL_POLYGON);
	for (float ang = 0; ang <= 2 * PI; ang += 0.01f)
	{
		float x = r * sin(ang);
		float y = r * cos(ang);

		glVertex2f(x, y);
	}
	glEnd();
}


//circulo de dentro
void drawCircle2(float r)
{
	glBegin(GL_POLYGON);
	for (float ang = 0; ang <= 2 * PI; ang += 0.01f)
	{
		float x = r * sin(ang);
		float y = r * cos(ang);

		glVertex2f(x, y);
	}
	glEnd();
}

float f(float x)
{
	return -sin(x*PI);
}

//Funcao para desenhar na tela
void display()
{



	//Define a cor de fundo
	glClearColor(0.1, 0.1 , 0.1, 1); // R, G, B, A de 0 a 1 (alpha) 

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

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);

	glutCreateWindow("Aula 1");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	glutMainLoop();
}