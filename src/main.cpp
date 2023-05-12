#include <GL/glut.h>

float xPosition = -10;

void render(void); //first time display is called


void init()
{

  glClearColor(0.0,0.0,0,0.0);

}

void reshape(int w, int h)
{

  glViewport(0,0, w,h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
//  gluOrtho2D(-10,10,-10,10); //world position views

  gluPerspective(60,1, 2.0,50.0); //world position views
  glMatrixMode(GL_MODELVIEW);


}


void timer(int)
{

  glutPostRedisplay(); //calls display function again
  int side = 1; //left  == 1, right == 0




  glutTimerFunc(1000/60, timer, 0);

}


int main(int argc, char ** argv) 
{

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  glutCreateWindow("Simple GLUT Application");
  glutDisplayFunc(render); //order matters. This is done after the window is created


//  glutTimerFunc(0,timer,0);


  glutReshapeFunc(reshape);
  init();
  glutMainLoop();


}


void AddPoint(double x,double y, double z)
{


  glBegin(GL_POINT);
  glVertex3f(x, y,z);
  glEnd();
}
void render(void)
{

  //clear first
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity(); //reset Matrix

  glTranslatef(5,0,-50);

  //draw stuff
  glPointSize(10);

  AddPoint(1.0,1.0,0);

  glBegin(GL_POLYGON);
  //why does order matter?
  glVertex3f(-1.0, 1.0,0);
  glVertex3f(1.0,0,0);
  glVertex3f(-1.0,-1.0,0);

  glEnd();


  //display
  glutSwapBuffers(); //need this to display on the screen

}
