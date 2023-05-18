#include <GL/glut.h>
#include <cmath>

// Initial window dimensions
int windowWidth = 800;
int windowHeight = 600;

// Rotation angles
float rotationX = 0.0f;
float rotationY = 0.0f;

// Translation offset
float translationZ = -5.0f;
float translationX = 0.0f;
float translationY = 0.0f;

// Mouse tracking variables
int lastMouseX = 0;
int lastMouseY = 0;
bool isMouseDragging = false;

// Mouse tracking variables
int lastMouseZoomX = 0;
int lastMouseZoomY = 0;
bool isMouseDraggingZoom = false;

// Mouse tracking variables
int lastMousePanX = 0;
int lastMousePanY = 0;
bool isMouseDraggingPan = false;








// Function to initialize OpenGL settings
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Set clear color to black
    glEnable(GL_DEPTH_TEST);               // Enable depth testing
}

// Function to handle window resizing
void reshape(int width, int height) {
    glViewport(0, 0, width, height);  // Set the viewport to cover the entire window

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);  // Set the perspective projection

    glMatrixMode(GL_MODELVIEW);
}

// Function to handle rendering
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear color and depth buffers

    glLoadIdentity();
    gluLookAt(translationX, translationY , 5.0f + translationZ,  // Camera position
              translationX, translationY , 0.0f,                // Look-at point
              0.0f, 1.0f, 0.0f);               // Up vector

    glRotatef(rotationX, 1.0f, 0.0f, 0.0f);  // Apply rotation around x-axis
    glRotatef(rotationY, 0.0f, 1.0f, 0.0f);  // Apply rotation around y-axis
    // Render your 3D shape here
    // Example: Draw a rotating cube
    glColor3f(1.0f, 1.0f, 1.0f);
    glutWireCube(1.0f);

    glFlush();
    glutSwapBuffers();
}

// Function to handle mouse click events
void mouse(int button, int state, int x, int y) {
 
   if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            lastMousePanX = x;
            lastMousePanY = y;
            isMouseDraggingPan = true;
        } else if (state == GLUT_UP) {
            isMouseDraggingPan = false;
        }
    }




   if (button == GLUT_MIDDLE_BUTTON) {
        if (state == GLUT_DOWN) {
            lastMouseX = x;
            lastMouseY = y;
            isMouseDragging = true;
        } else if (state == GLUT_UP) {
            isMouseDragging = false;
        }
    }

    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            lastMouseZoomX = x;
            lastMouseZoomY = y;
            isMouseDraggingZoom = true;
        } else if (state == GLUT_UP) {
            isMouseDraggingZoom = false;
        }
    }




}

// Function to handle mouse motion events
void motion(int x, int y) {
    if (isMouseDragging) {
        rotationX += (y - lastMouseY) * 0.2f;
        rotationY += (x - lastMouseX) * 0.2f;
        lastMouseX = x;
        lastMouseY = y;

        glutPostRedisplay();
    }

    if (isMouseDraggingZoom) {
        translationZ += (y - lastMouseZoomY) * 0.0002f;
        lastMouseY = y;
        glutPostRedisplay();
    }

    if(isMouseDraggingPan)
    {
      translationX += (x - lastMousePanX) * 0.0005f;
      translationY += (y - lastMousePanY) * 0.0005f;
 
    }

}

// Function to handle keyboard events
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'q':
            translationZ += 0.1f;  // Move closer
            break;
        case 'e':
            translationZ -= 0.1f;  // Move further
            break;
        case 27:  // Escape key
            exit(0);
            break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Camera Movement");

    init();

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
