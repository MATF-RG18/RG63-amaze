#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdbool.h>

//variables for width and depth
static int window_width, window_height;

//callback functions
static void on_display(void);
static void on_reshape(int width, int height);

int main(int argc, char** argv){

	//initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);


    //window initialization
    glutInitWindowPosition(100,100);
    glutInitWindowSize(1200,1200);
    glutCreateWindow("AMAZE");

    //calling the callback functions
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);

    //color that cleans the view
    glClearColor(0.75, 0.75, 0.75, 0);

    //making the lines bolder
    glLineWidth(3);


    //entering the main loop
    glutMainLoop();

	return 0;
}

void on_display(void){

    //this whole section brings light to our MAZE
    GLfloat light_position[] = {1, 1, 1, 0};

    GLfloat light_ambient[] = {0, 0, 0, 1};

    GLfloat light_diffuse[] = {1, 1, 1, 1};

    GLfloat light_specular[] = {0.9, 0.9, 0.9, 1};

    
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	//cleaning out the color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//setting the view
    glViewport(0, 0,window_width, window_height);

    //Setting the angle, width-height ratio, near and far clipping plain
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, window_width/(float)window_height, 1, 1500);

    //implementing the camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(10, 10, 10,
    	     0, 0, 0,
    	     0, 0, 1);


    //the coordinate system
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);                        
        glVertex3f(10,0,0);
        
        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,10,0);
        
        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,10);
    glEnd();

    //material parameters
    GLfloat ambient_coeffs[] = { 0.5, 0.5, 0.5, 1};
    GLfloat diffuse_coeffs[] = { 0.5, 0.5, 0.5, 1};
    GLfloat specular_coeffs[] = { 0.5, 0.5, 0.5, 1};
    GLfloat shininess = 15;
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    //body
    glPushMatrix();
    glTranslatef(0, 0, 2);
    glScalef(2.7, 4, 2);
    glutWireCube(1);
    glPopMatrix();

    //legs
    glPushMatrix();
    glTranslatef(-1, -1, 0);
    glScalef(0.5, 0.5, 3);
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1, 1, 0);
    glScalef(0.5, 0.5, 3);
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1, -1, 0);
    glScalef(0.5, 0.5, 3);
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1, 1, 0);
    glScalef(0.5, 0.5, 3);
    glutWireCube(1);
    glPopMatrix();

    //neck
    glPushMatrix();

    glTranslatef(0, 2, 3);
    glRotatef(-45, 1, 0, 0);
    glScalef(1, 1, 2);
   
    glutWireCube(1);
    glPopMatrix();

    //head
    glPushMatrix();
    glTranslatef(0, 3, 3.7);
    glScalef(0.7, 0.7, 0.7);
    glRotatef(-22.5, 1, 0, 0);


    //base
    glPushMatrix();

    glTranslatef(0, -0.5, 1);
    //glRotatef(-45, 1, 0, 0);
    glScalef(2, 2, 1);
   
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();

    //glTranslatef(0, 2, 3);
    //glRotatef(-45, 1, 0, 0);
    glScalef(2, 3, 1);
   
    glutWireCube(1);
    glPopMatrix();

    //ears
    glPushMatrix();

    glTranslatef(1, -0.5, 1.5);
    glRotatef(45, 0, 1, 0);
    glScalef(0.3, 0.3, 0.5);
   
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-1, -0.5, 1.5);
    glRotatef(-45, 0, 1, 0);
    glScalef(0.3, 0.3, 0.5);
   
    glutWireCube(1);
    glPopMatrix();

    //antler number 1

    glPushMatrix();
    glTranslatef(0.5, -0.5, 2);
    glPushMatrix();

    //glTranslatef(-1, -0.5, 1.5);
    //glRotatef(-45, 0, 1, 0);
    glScalef(0.3, 0.3, 1.5);
   
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 0.75);
    //glRotatef(-45, 0, 1, 0);
    glScalef(0.3, 1.5, 0.3);
   
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();
    
    glTranslatef(0, 0.75, 1.35);
    //glRotatef(-45, 0, 1, 0);
    glScalef(0.3, 0.3, 1.5);
   
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, -0.75, 1.35);
    //glRotatef(-45, 0, 1, 0);
    glScalef(0.3, 0.3, 1.5);
   
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.1, -0.75, 2.15);

    glScalef(0.25, 0.3, 0.3);
   
    glutWireTetrahedron();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.1, 0.75, 2.15);

    glScalef(0.25, 0.3, 0.3);
   
    glutWireTetrahedron();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.45, 0, 0.75);
    //glRotatef(-45, 0, 1, 0);
    glScalef(0.9, 0.3, 0.3);
   
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.9, 0, 1);
    //glRotatef(-45, 0, 1, 0);
    glScalef(0.3, 0.3, 0.9);
   
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.8, 0, 1.5);

    glScalef(0.25, 0.3, 0.3);
   
    glutWireTetrahedron();
    glPopMatrix();

    //antler number 2

    glPushMatrix();
    glTranslatef(-1, 0, 0);
    glRotatef(180, 0, 0, 1);

    glPushMatrix();

    //glTranslatef(-1, -0.5, 1.5);
    //glRotatef(-45, 0, 1, 0);
    glScalef(0.3, 0.3, 1.5);
   
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 0.75);
    //glRotatef(-45, 0, 1, 0);
    glScalef(0.3, 1.5, 0.3);
   
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();
    
    glTranslatef(0, 0.75, 1.35);
    //glRotatef(-45, 0, 1, 0);
    glScalef(0.3, 0.3, 1.5);
   
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, -0.75, 1.35);
    //glRotatef(-45, 0, 1, 0);
    glScalef(0.3, 0.3, 1.5);
   
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.1, -0.75, 2.15);

    glScalef(0.25, 0.3, 0.3);
   
    glutWireTetrahedron();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.1, 0.75, 2.15);

    glScalef(0.25, 0.3, 0.3);
   
    glutWireTetrahedron();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.45, 0, 0.75);
    //glRotatef(-45, 0, 1, 0);
    glScalef(0.9, 0.3, 0.3);
   
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.9, 0, 1);
    //glRotatef(-45, 0, 1, 0);
    glScalef(0.3, 0.3, 0.9);
   
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.8, 0, 1.5);

    glScalef(0.25, 0.3, 0.3);
   
    glutWireTetrahedron();
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

    

    // the picture gets drawn
    glutSwapBuffers();
	}

	//when we reshape the window this function activates
static void on_reshape(int width, int height){
     window_width = width;
     window_height = height;
}