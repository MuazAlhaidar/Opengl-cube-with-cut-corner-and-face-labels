// Name: Muaz Alhaidar
//
// Description: ~
// The project consists of two phases:  
// 1. Modeling the cube with a corner cut-off. The labels are written on the three faces. Each face is modeled as a polygon so that you can write the label on it.
// 2. Option of implementing the camera class specified in the section 7.3. of the text.(WAS NOT ACCOMPLISH) | Using the camera, generate the following two views: Single and Multiple. 
//
// Date: 11/25/2019

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glut.h>

// Used to Store values of window for Viewports
static int width;
static int height;

GLuint theCube;

void drawCubeFaceName(GLfloat textx, GLfloat texty, GLfloat textz, GLfloat angle,GLfloat xAxis, GLfloat yAxis, GLfloat zAxis, const char* givenText) {

	glPushMatrix();

		glPushAttrib(GL_LINE_BIT);

			glColor3f(1.0f, 1.0f, 1.0f); // Line color is WHITE

			glLineWidth(4.0); // Line width is 4

			glRotatef(angle, xAxis, yAxis, zAxis); // Rotate the text around a chosen axis

			glTranslatef(textx, texty, textz); // Translate text in the desired direction

			glScalef(0.003f, 0.003f, 0.003f); // Scale text down

			for (const char* c = givenText; *c; c++)		// Print text
				glutStrokeCharacter(GLUT_STROKE_ROMAN, *c); // 

		glPopAttrib();									

	glPopMatrix();
}

void drawCubeTop(void) {

	glBegin(GL_POLYGON); // Top Face of Cube

		glColor3f(1.0f, 0.0f, 0.0f); // Turns this face RED

		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);

		glVertex3f(0.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);

		glVertex3f(1.0f, 1.0f, -1.0f);

	glEnd();
}

void drawCubeBottom(void) {

	glBegin(GL_POLYGON); // Bottmom Face of Cube

		glColor3f(0.0f, 1.0f, 0.0f); // Turns this face GREEN

		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);

	glEnd();
}

void drawCubeRight(void) {

	glBegin(GL_POLYGON); // Right Face Side of Cube

		glColor3f(0.0f, 0.0f, 1.0f); // Turns this face BLUE

		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);

		glVertex3f(1.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 1.0f);

		glVertex3f(1.0f, -1.0f, 1.0f);

	glEnd();
}

void drawCubeLeft(void) {

	glBegin(GL_POLYGON); // Left Face Side of Cube

		glColor3f(0.5f, 0.5f, 0.0f); // Turns this face YELLOW

		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);

		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

	glEnd();
}

void drawCubeFront(void) {

	glBegin(GL_POLYGON); // Front Face of Cube

		glColor3f(0.0f, 0.5f, 0.5f); // Turns this face TURQOISE

		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, 0.0f, 1.0f);

		glVertex3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);

		glVertex3f(-1.0f, -1.0f, 1.0f);

	glEnd();
}

void drawCubeBack(void) {

	glBegin(GL_POLYGON); // Back Face of Cube

		glColor3f(0.5f, 0.0f, 0.5f); // Turns this face PURPLE

		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);

		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);

	glEnd();
}

void drawCubeCutCorner(void) {

	glBegin(GL_POLYGON); // Cut Corner Face of Cube

		glColor3f(1.0f, 1.0f, 1.0f); // Turns this face WHITE

		glVertex3f(1.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);

		glVertex3f(0.0f, 1.0f, 1.0f);

	glEnd();
}

void drawCubeLabels(void) {
	//				  x			y			z			angle of rotation	xAxis	yAxis	zAxis	Text to Write
	drawCubeFaceName(-0.6f,		-0.25f,		1.01f,		0.0f,				0.0f,	0.0f,	0.0f,	"FRONT");  // Write "FRONT" at the front of cube
	drawCubeFaceName(-0.5f,		-0.25f,		1.01f,		90.0f,				0.0f,	1.0f,	0.0f,	"RIGHT"); // Write "RIGHT" at the right of cube
	drawCubeFaceName(-0.6f,		-0.25f,		1.01f,		-90.0f,				1.0f,	0.0f,	0.0f,	"TOP");  // Write "TOP" at the top of cube
}

void drawCubeWithCutCorner(void) {

	drawCubeTop();
	drawCubeBottom();
	drawCubeFront();
	drawCubeBack();
	drawCubeRight();
	drawCubeLeft();
	drawCubeCutCorner();

	drawCubeLabels();
}

void myInit(void) {

	theCube = glGenLists(1);

	glNewList(theCube, GL_COMPILE);

		drawCubeWithCutCorner();

	glEndList();

	glClearColor(0.3f, 0.3f, 0.3f, 0.0f);  // Set the background color to NEUTRAL GRAY
}

void polarView(float distance, double z_angle, double x_angle, double y_angle) {

	glTranslatef(0.0, 0.0, distance);
	glRotated(z_angle, 0.0, 0.0, 1.0);
	glRotated(x_angle, 1.0, 0.0, 0.0);
	glRotated(y_angle, 0.0, 1.0, 0.0);
}

static void setSingleView(void) {

	glClear(GL_COLOR_BUFFER_BIT);

	// Set Viewport to fill window
	glViewport(0, 0, width, height);

	glLoadIdentity();

	// Position camera (4,4,15) Set point of focus (0,0,0)
	polarView(4.0f, 0.0, 45.0, -45.0);

	glCallList(theCube);

	// Display the cube
	glutSwapBuffers();

	///////////////// Z-Buffer ///////////////

	// Enable depth test
	glEnable(GL_DEPTH_TEST);

	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	///////////////// Z-Buffer ///////////////

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (width <= height)
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat)height / (GLfloat)width, 2.0 * (GLfloat)height / (GLfloat)width, -10.0, 100.0);
	else
		glOrtho(-2.0 * (GLfloat)width / (GLfloat)height, 2.0 * (GLfloat)width / (GLfloat)height, -2.0, 2.0, -10.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
}

static void setMultiView(void) {

	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_CULL_FACE);
	// Top Left View
	glViewport(0, height / 2, width / 2, height/2);
	glLoadIdentity();
	gluLookAt(0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
	//polarView(4.0f, 0.0, 90.0, 0.0);
	glCallList(theCube);
	glDisable(GL_CULL_FACE);

	glEnable(GL_CULL_FACE);
	// Top Right View
	glViewport(width / 2, height / 2, width/2, height/2);
	glLoadIdentity();
	gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//polarView(4.0f, 0.0, 45.0, -45.0);
	glCallList(theCube);
	glDisable(GL_CULL_FACE);

	glEnable(GL_CULL_FACE);
	// Bottom Left View
	glViewport(0, 0, width / 2, height / 2);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//polarView(4.0f, 0.0, 0.0, 0.0);
	glCallList(theCube);
	glDisable(GL_CULL_FACE);

	glEnable(GL_CULL_FACE);
	// Bottom Right View
	glViewport(width / 2, 0, width/2, height / 2);
	glLoadIdentity();
	gluLookAt(3.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//polarView(4.0f, 0.0, 0.0, -90.0);
	glCallList(theCube);
	glDisable(GL_CULL_FACE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (width <= height)
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat)height / (GLfloat)width, 2.0 * (GLfloat)height / (GLfloat)width, -10.0, 100.0);
	else
		glOrtho(-2.0 * (GLfloat)width / (GLfloat)height, 2.0 * (GLfloat)width / (GLfloat)height, -2.0, 2.0, -10.0, 100.0);

	glMatrixMode(GL_MODELVIEW);

	glutSwapBuffers();
}

void reshape(int w, int h) {

	width = w;
	height = h;

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {

	// User's View Choice
	short choice;
	
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	
	glutInitWindowSize(800, 800);			// window size
	glutInitWindowPosition(800, 200);		// distance from the top-left screen

	// Display Menu
	std::cout << "!_Single View\n2_Multi View\n";
	std::cin >> choice;

	while (choice > 2 || choice < 1) {

		std::cin.clear();
		std::cin.ignore(10000,'\n');

		std::cout << "Error: Please Enter Either 1 or 2!\n";
		std::cin >> choice;
	}

	std::cout << "Warning: the window will be empty until you click the window\n";
	std::cout << "Click on the window to display\n";

	if (choice == 1) {
		// Display if SINGLE VIEW
		glutCreateWindow("Muaz Alhaidar PROG-3 Cube Model with Corner Cut-off SINGLE VIEW");	// message displayed on top bar window
	}
	else {
		// Display if MULTI VIEW
		glutCreateWindow("Muaz Alhaidar PROG-3 Cube Model with Corner Cut-off MULTI VIEW");		// message displayed on top bar window
	}

	myInit();

	glutReshapeFunc(reshape);

	if (choice == 1) {

		// Display SINGLE VIEW
		glutDisplayFunc(setSingleView);
	}
	else if (choice == 2) {

		// Display MULTI VIEW
		glutDisplayFunc(setMultiView);
	}

	glutMainLoop();

	return 0;
}