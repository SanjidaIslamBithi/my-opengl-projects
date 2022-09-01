#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
	/* clear all pixels */
	glClear(GL_COLOR_BUFFER_BIT);

	/*glClear (GL_COLOR-BUFFER_BIT); => THIS LINE IS USED TO CLEAR IF ANY COLOR/ PIXEL WAS THERE BEFORE*/

	/* draw white polygon (rectangle) with corners at
	 * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	 */
	glColor3f(1.0, 1.0, 1.0);
	// gl is used in most cases of functions of open gl; color indicates colors
	// 3f indicates 3 parameter and f indicates floating point
	// RGB =(RED, GREEN, BLUE)
	// RANGE OF VALUE CAN BE HERE (0-1)

	glBegin(GL_QUADS); // Begin quadrilateral coordinates
	// Begin means start
	// QUADS MEANS  we are ready to draw quadrilateral something

	// Trapezoid
	glVertex3f(0.05f, 0.05f, 0.0f);
	glVertex3f(0.35f, 0.05f, 0.0f);
	glVertex3f(0.40f, 0.35f, 0.0f);
	glVertex3f(0.00f, 0.35f, 0.0f);
	// vertex means how many part are there; 3 means 3 quadrant, f floating point
	// 3quadrent means (x, y, z) values
	// instead of 3 quadrent we can only do 2 quadrent x,y for making 2D shape,
	// if we put 3 values in here we can draw 3D shape, but if we put z=0 in each time we can make it 2D shape{in case of useing 3 quadrent)

	glEnd(); // End quadrilateral coordinates

	glBegin(GL_TRIANGLES); // Begin triangle coordinates

	// Pentagon
	glColor3f(1.0, 0.0, 1.0);
	// just changing color to know its true shape

	glVertex3f(0.5f, 0.05f, 0.0f);
	glVertex3f(0.75f, 0.05f, 0.0f);
	glVertex3f(0.5f, 0.35f, 0.0f);

	glColor3f(1.0, 1.0, 0.0);
	// just changing color to know its true shape

	glVertex3f(0.5f, 0.35f, 0.0f);
	glVertex3f(0.75f, 0.05f, 0.0f);
	glVertex3f(0.75f, 0.35f, 0.0f);

	glColor3f(0.0, 1.0, 0.0);
	// just changing color to know its true shape

	glVertex3f(0.5f, 0.35f, 0.0f);
	glVertex3f(0.75f, 0.35f, 0.0f);
	glVertex3f(0.63f, 0.50f, 0.0f);
	// pentagon ends here
	// pentagon is mainly created with 3 triangles

	// Triangle
	glVertex3f(0.30f, 0.65f, 0.0f);
	glVertex3f(0.60f, 0.65f, 0.0f);
	glVertex3f(0.45, 0.85f, 0.0f);

	glEnd(); // End triangle coordinates

	glFlush();
}
void init(void)
{
	/* select clearing (background) color */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	/* initialize viewing values */
	glMatrixMode(GL_PROJECTION); // it isan initialization to make the taken value in matrix mode
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -10.0, 10.0);
	// glOrtho means making limit of graph paper (graph paper size)
	//(x-lower value, x-upper value, y-lower value, y-upper value, z-lower value, z-upper value ) z value is not needed
}
/*
 * Declare initial window size, position, and display mode
 * (single buffer and RGBA). Open window with "hello"
 * in its title bar. Call initialization routines.
 * Register callback function to display graphics.
 * Enter main loop and process events.
 */
int main(int argc, char **argv)
{
	glutInit(&argc, argv);						 // glut initialization
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // which type of display will be there
	glutInitWindowSize(600, 600);				 // it make the result value shape sized
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hello"); // giving a name to the window
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0; /* ISO C requires main to return int. */
}
