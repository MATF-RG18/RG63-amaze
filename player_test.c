#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdbool.h>
#include<math.h>

//variables for width and depth
static int window_width, window_height;
int move = 0;
int ind = 0;

//callback functions
static void on_display(void);
static void on_reshape(int width, int height);
static void on_keyboard(unsigned char key, int x, int y);
static void on_timer(int value);

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
    glutKeyboardFunc(on_keyboard);

    //color that cleans the view
    glClearColor(0.75, 0.75, 0.75, 0);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 0);

    //making the lines bolder
    glLineWidth(3);
    glEnable(GL_DEPTH_TEST);



    //entering the main loop
    glutMainLoop();

	return 0;
}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        //we exit the game
        exit(0);
        break;

    
    case 'w':
    case 'W':
        {
            glutTimerFunc(20, on_timer, 0);
            break;
        }
    }
}

static void on_timer(int value){
    if(value == 0)
    {
    if(ind == 1 && move <= -15)
	ind = 0;
   	else if(ind == 1)
   	move -=1;
    else if(move < 15)
    move +=1;
	else if(move >= 15)
	ind = 1;
	

    glutPostRedisplay();
    glutTimerFunc(20, on_timer, 0);

    }


}

void on_display(void){

    //this whole section brings light to our MAZE
    GLfloat light_position[] = {1, 0, 1, 0};

    GLfloat light_ambient[] = {0, 0, 0, 1};

    GLfloat light_diffuse[] = {1, 1, 1, 1};

    GLfloat light_specular[] = {1, 1, 1, 1};

    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
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
    gluLookAt(10, 10, 3,
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
    GLfloat ambient_coeffs[] = { 0.1, 0.1, 0.1, 1};
    GLfloat diffuse_coeffs_White[] = { 1, 1, 1, 1};
    GLfloat diffuse_coeffs_Brown[] = { 0.2, 0.098, 0, 1};
    GLfloat specular_coeffs[] = { 0, 0, 0, 1};
    GLfloat shininess = 10;
    float mat_ambient_Silver[] ={ 0.19225f, 0.19225f, 0.19225f, 1.0f };
	float mat_diffuse_Silver[] ={ 0.50754f, 0.50754f, 0.50754f, 1.0f};
	float mat_specular_Silver[] ={0.508273f, 0.508273f, 0.508273f, 1.0f };
	float shine_Silver = 51.2f;
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Silver);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Silver);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Silver);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Silver);

    //Fenrys

    //body
    glPushMatrix();

    glTranslatef(0, 0, 1.2);
    glScalef(2.6, 4, 1.7);
    glutSolidCube(1);

    glPopMatrix();

    //tail
    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(move, 0, 0, 1);
    glTranslatef(0, 0, -1.7);
    glTranslatef(0, -2.5, 1.2);
    glRotatef(25, 1, 0, 0);
    glScalef(0.6, 2.5, 0.6);
    glutSolidCube(1);

    glPopMatrix();

    //legs
    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(-1, -1, 0);
    glScalef(0.5, 0.5, 3);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(-move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(-1, 1, 0);
    glScalef(0.5, 0.5, 3);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(-move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(1, -1, 0);
    glScalef(0.5, 0.5, 3);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(1, 1, 0);
    glScalef(0.5, 0.5, 3);
    glutSolidCube(1);

    glPopMatrix();

    //head
    glPushMatrix();

    glTranslatef(0, 2.5, 2.2);
    glScalef(0.8, 0.8, 0.8);
    glRotatef(-5, 1, 0, 0);


    //base
    glPushMatrix();

    glTranslatef(0, -0.5, 0.5);
    glScalef(2, 2, 2);   
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0.3, 0);
    glScalef(1, 3, 1);  
    glutSolidCube(1);

    glPopMatrix();

    //ears
    glPushMatrix();

    glTranslatef(0.6, -0.5, 1.5);
    glScalef(0.5, 0.5, 0.6);
   
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.6, -0.5, 1.5);
    glScalef(0.5, 0.5, 0.6);
   
    glutSolidCube(1);
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