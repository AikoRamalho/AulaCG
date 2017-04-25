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

//Funcao para desenhar na tela
void display()
{

	static float t = 0;
	t += 0.005;

	static float u = 0;
	u += 0.002f;

	//Define a cor de fundo
	glClearColor(0, 0, 0, 1); // R, G, B, A de 0 a 1 (alpha) 

	//Limpa a tela com a cor definida no GlClearColor
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0, 0);
	drawCircle(1);


	glColor3f(1, 1, 1);

	 time_t tNow = time(nullptr);
	struct tm* tmNow = localtime(&tNow);

	float angS = PI / 30 * tmNow->tm_sec;
	float angM = PI / 30 * tmNow->tm_min + angS / 60;
	float angH = PI / 6 * tmNow->tm_hour + angM / 12;



	//tracinhos das horas
	glLineWidth(7);
	glBegin(GL_LINES);
	for (float ang = 0; ang <= 2 * PI; ang += PI/6)
	{
		float x = 1*sin(ang);
		float y = 1*cos(ang);
		glVertex2f(x, y);

		x = 0.88*sin(ang);
		y = 0.88*cos(ang);
		glVertex2f(x, y);
	}
	glEnd();


	//tracinho dos minutos
	glLineWidth(1);
	glBegin(GL_LINES);
	for (float ang = 0; ang <= 2*PI; ang += PI/30)
	{
		float x = 1 * sin(ang);
		float y = 1 * cos(ang);
		glVertex2f(x, y);

		x = 0.88 * sin(ang);
		y = 0.88 * cos(ang);
		glVertex2f(x, y);
	}
	glEnd();

	//Ponteiro das horas
	glLineWidth(3);
	glBegin(GL_LINES);
	{
		//float x = 0.6 * sin(PI/3);
		//float y = 0.6 * cos(PI / 3);
		//glVertex2f(x, y);

		//x = 0 * sin(PI / 3);
		//y = 0 * cos(PI / 3);
		//glVertex2f(x, y);
		glColor3f(1, 1, 1);
		glVertex2f(0, 0);
		glVertex2f(0.65*sin(angH), 0.65*cos(angH));
	}
	glEnd();

	//Ponteiros dos minutos
	glLineWidth(3);
	glBegin(GL_LINES);
	{
		// float x = 1 * sin(PI/2);
		// float y = 1 * cos(PI/2);
		// glVertex2f(x, y)


		glColor3f(1, 1, 1);
		glVertex2f(0, 0);
		glVertex2f(0.85 * sin(angM), 0.85 * cos(angM));
	}
	glEnd();

	//Ponteiro dos segundos
	glLineWidth(1);
	glBegin(GL_LINES);
	{
		// float x = 1 * sin(PI/2);
		// float y = 1 * cos(PI/2);
		// glVertex2f(x, y)

		glColor3f(1, 0, 0);
		glVertex2f(0, 0);
		glVertex2f(0.9*sin(angS), 0.9*cos(angS));
	}
	glEnd();


	glColor3f(1, 1, 1);
	drawCircle2(0.05);

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