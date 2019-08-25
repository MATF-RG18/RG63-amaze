#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdbool.h>
#include<math.h>

#define PI 3.1415926535
#define EPSILON 0.01
//variables for width and depth
static int window_width, window_height;
int ice_blast_move = 0;
int ind = 0;

//callback functions
static void on_display(void);
static void on_reshape(int width, int height);
static void on_keyboard(unsigned char key, int x, int y);
static void on_timer(int value);
void set_normal_and_vertex(float u, float v);
void draw_object();
void lightning_mold();

void lightning_mold(){

    glPushMatrix();

    glRotatef(25, 0, 0, 1);
    glScalef(0.2, 2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glRotatef(-25, 0, 0, 1);
    glTranslatef(0, 1, 0);

    glScalef(0.2, 2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, 2.6, 0);
    glRotatef(35, 0, 0, 1);

    glScalef(0.2, 3, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, 4.1, 0);
    glRotatef(-35, 0, 0, 1);


    glScalef(0.2, 2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, 6, 0);
    glRotatef(25, 0, 0, 1);

    glScalef(0.2, 3, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, 7.5, 0);
    glRotatef(-25, 0, 0, 1);


    glScalef(0.2, 2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.2, 8.5, 0);
    glRotatef(25, 0, 0, 1);


    glScalef(0.2, 1, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

}

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
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);

    //making the lines bolder
    glLineWidth(3);
    glEnable(GL_DEPTH_TEST);
    //Enable normalization of vectors
    glEnable(GL_NORMALIZE);



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
    if(value == 0){
    ice_blast_move +=1;
/*    if(ind == 1 && move <= -15)
    ind = 0;
    else if(ind == 1)
    move -=1;
    else if(move < 15)
    move +=1;
    else if(move >= 15)
    ind = 1; 
*/	

    glutPostRedisplay();
    glutTimerFunc(30, on_timer, 0);

    }


}

void on_display(void){

    //this whole section brings light to our MAZE
    GLfloat light_position[] = {0, 1, 0, 0};

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
    gluLookAt(0.1, 15, 2,
    	     0, 4.99, 0,
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
 //   GLfloat diffuse_coeffs_Brown[] = { 0.2, 0.098, 0, 1};
    GLfloat specular_coeffs[] = { 0, 0, 0, 1};
    GLfloat shininess = 10;

	//Obsidian
	float mat_ambient_Obsidian[] ={ 0.05375f, 0.05f, 0.06625f, 0.82f };
	float mat_diffuse_Obsidian[] ={ 0.18275f, 0.17f, 0.22525f, 0.82f};
	float mat_specular_Obsidian[] ={0.332741f, 0.328634f, 0.346435f, 0.82f };
	float shine_Obsidian =38.4f ;

    //Polished copper
	float mat_ambient_Copper[] = { 0.2295f, 0.08825f, 0.0275f, 1.0f };
	float mat_diffuse_Copper[] = {0.5508f, 0.2118f, 0.066f, 1.0f };
	float mat_specular_Copper[] = {0.580594f, 0.223257f, 0.0695701f, 1.0f };
	float shine_Copper = 51.2f ;

    //material parameters
    GLfloat diffuse_coeffs_Brown[] = { 0.2, 0.098, 0, 1};

	//Ruby
	float mat_ambient_Ruby[] ={ 0.1745f, 0.01175f, 0.01175f, 0.55f };
	float mat_diffuse_Ruby[] ={0.61424f, 0.04136f, 0.04136f, 0.55f };
	float mat_specular_Ruby[] ={0.727811f, 0.626959f, 0.626959f, 0.55f };
	float shine_Ruby =76.8f ;

    //Gold
	float mat_ambient_Gold[]={ 0.24725f, 0.1995f, 0.0745f, 1.0f };
	float mat_diffuse_Gold[]={0.75164f, 0.60648f, 0.22648f, 1.0f };
	float mat_specular_Gold[] ={0.628281f, 0.555802f, 0.366065f, 1.0f };
	float shine_Gold =51.2f ;

	//Brass
	float mat_ambient_Brass[] ={ 0.329412f, 0.223529f, 0.027451f,1.0f };
	float mat_diffuse_Brass[] ={ 0.780392f, 0.568627f, 0.113725f, 1.0f };
	float mat_specular_Brass[] ={ 0.992157f, 0.941176f, 0.807843f, 1.0f };
	float shine_Brass = 27.8974f;

//GAME OVER

	//G
	glPushMatrix();

    glScalef(0.2, 0.2, 2);
    
    glutSolidCube(1);

    glPopMatrix();

   	glPushMatrix();

    glTranslatef(-0.8, 0, 0);

    glScalef(1, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();


	glPushMatrix();

    glTranslatef(-1.2, 1, -0.5);

    glScalef(0.2, 0.2, 1);
    
    glutSolidCube(1);

    glPopMatrix();


	glPushMatrix();

    //glRotatef(-25, 0, 0, 1);
    glTranslatef(-0.6, 1, -1);

    glScalef(1.3, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

   	glPushMatrix();

    //glRotatef(-25, 0, 0, 1);
    glTranslatef(-0.6, 1, 1);

    glScalef(1.3, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();
//A
	glPushMatrix();

    glRotatef(-45, 0, 1, 0);
    //glTranslatef(0, 1, 0);

    glScalef(0.2, 0.2, 2);
    
    glutSolidCube(1);

    glPopMatrix();

   	glPushMatrix();

    //glRotatef(-25, 0, 0, 1);
    glTranslatef(-0.8, 0, 0);

    glScalef(1, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();


	glPushMatrix();

    glTranslatef(-1.2, 1, -0.5);

    glScalef(0.2, 0.2, 1);
    
    glutSolidCube(1);

    glPopMatrix();


	glPushMatrix();

    glTranslatef(-0.6, 1, -1);

    glScalef(1.3, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

   	glPushMatrix();

    //glRotatef(-25, 0, 0, 1);
    glTranslatef(-0.6, 1, 1);

    glScalef(1.3, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();







/*   
//lightning

	printf("%d\n", 100%3);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Gold);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Gold);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Gold);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Gold);

    lightning_mold();

    glPushMatrix();

    glTranslatef(0, 9, 0);
    lightning_mold();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 18, 0);
    lightning_mold();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 27, 0);
    lightning_mold();

    glPopMatrix();



/*
    glPushMatrix();

    glRotatef(25, 0, 0, 1);
    glScalef(0.2, 2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glRotatef(-25, 0, 0, 1);
    glTranslatef(0, 1, 0);

    glScalef(0.2, 2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, 2.6, 0);
    glRotatef(35, 0, 0, 1);

    glScalef(0.2, 3, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, 4.1, 0);
    glRotatef(-35, 0, 0, 1);


    glScalef(0.2, 2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, 6, 0);
    glRotatef(25, 0, 0, 1);

    glScalef(0.2, 3, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, 7.5, 0);
    glRotatef(-25, 0, 0, 1);


    glScalef(0.2, 2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.2, 8.5, 0);
    glRotatef(25, 0, 0, 1);


    glScalef(0.2, 1, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();


/*    

    glPushMatrix();

    glTranslatef(-2, 7, 10);
    glRotatef(25, 0, 1, 0);
    glScalef(2.4, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-2, 7, 10);
    glRotatef(25, 0, 1, 0);
    glScalef(2.4, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-2, 7, 10);
    glRotatef(25, 0, 1, 0);
    glScalef(2.4, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-2, 7, 10);
    glRotatef(25, 0, 1, 0);
    glScalef(2.4, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();



/*
//fire ball
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Ruby);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Ruby);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Ruby);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Ruby);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Gold);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Gold);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Gold);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Gold);

	GLUquadricObj *quadObj = gluNewQuadric();
	
    glPushMatrix();
    glRotatef(200*ice_blast_move, 1, 0, 0);
    //spikes
   	glPushMatrix();


    glPushMatrix();
    glTranslatef(0, 0, 0.8);

    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-45, 0, 1, 0);
    glTranslatef(0, 0, 0.8);


    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();

    glPushMatrix();
    glRotatef(45, 0, 1, 0);
    glTranslatef(0, 0, 0.8);

    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();

    glPushMatrix();

    glRotatef(-90, 1, 0, 0);
    glRotatef(45, 0, 1, 0);
    glTranslatef(0, 0, 0.8);

    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();

    glPushMatrix();

    glRotatef(-90, 1, 0, 0);
    glRotatef(-45, 0, 1, 0);
    glTranslatef(0, 0, 0.8);

    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(0, 0, 0.8);

    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glRotatef(-45, 0, 1, 0);
    glTranslatef(0, 0, 0.8);


    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glRotatef(45, 0, 1, 0);
    glTranslatef(0, 0, 0.8);


    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, 0.8);


    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();


    glPushMatrix();
    glRotatef(180, 1, 0, 0);
    glRotatef(45, 0, 1, 0);
    glTranslatef(0, 0, 0.8);


    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();


    glPushMatrix();
    glRotatef(180, 1, 0, 0);
    glRotatef(45, 0, 1, 0);
    glTranslatef(0, 0, 0.8);


    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();


    glPushMatrix();
    glRotatef(180, 1, 0, 0);
    glTranslatef(0, 0, 0.8);


    gluCylinder(quadObj, 0.3, 0, 2 + 0.5*sin(0.2*ice_blast_move), 30, 30);
    glPopMatrix();

   	glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Ruby);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Ruby);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Ruby);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Ruby);

    glPushMatrix();
 	glutSolidSphere(1, 30, 30);
    glPopMatrix();

glPopMatrix();

/*
//kaangs wooden stick
GLUquadricObj *quadObj = gluNewQuadric();
//base

    glPushMatrix();
    //glTranslatef(0, 0, 0);
    //glRotatef(-90, 1, 0, 0);

    gluCylinder(quadObj, 0.2, 0.2, 8 + 0.4*ice_blast_move, 30, 30);
    glPopMatrix();
//handles
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Ruby);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Ruby);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Ruby);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Ruby);

    glPushMatrix();
    glTranslatef(0, 0, 0);

    gluCylinder(quadObj, 0.25, 0.25, 2, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 6 + 0.4*ice_blast_move);

    gluCylinder(quadObj, 0.25, 0.25, 2, 30, 30);
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Gold);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Gold);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Gold);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Gold);

    glPushMatrix();
    glTranslatef(0, 0, 0);

    glutSolidTorus(0.08, 0.25, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 2);

    glutSolidTorus(0.08, 0.25, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 6 + 0.4*ice_blast_move);

    glutSolidTorus(0.08, 0.25, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 8 + 0.4*ice_blast_move);

    glutSolidTorus(0.08, 0.25, 20, 20);
    glPopMatrix();


//fire ball


/*
//deer_attack
	glBegin(GL_TRIANGLES);

		glNormal3f(0, 1, 0);
        glVertex3f(0, 0, 2);
        glVertex3f(6, 0, -1);
        glVertex3f(0, 0, 0);

        glNormal3f(0, 1, 0);
        glVertex3f(0, 0, 2);
        glVertex3f(-6, 0, -1);
        glVertex3f(0, 0, 0);

    glEnd();




/*

//ice blast
    //Turquoise
	float mat_ambient_Tr[]={ 0.1f, 0.18725f, 0.1745f, 0.8f };
	float mat_diffuse_Tr[]={0.396f, 0.74151f, 0.69102f, 0.8f };
	float mat_specular_Tr[] ={0.297254f, 0.30829f, 0.306678f, 0.8f };
	float shine_Tr = 12.8f;

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Tr);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Tr);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Tr);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Tr);



    glPushMatrix();

    glRotatef(ice_blast_move*2, 0, 1, 0);

    GLUquadricObj *quadObj = gluNewQuadric();

    glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glVertex3f(0, 0, 2.5);
        glVertex3f(-0.5, 0, 4.5);
        glVertex3f(0, 0, 6.5);
        glVertex3f(0.5, 0, 4.5);

        glNormal3f(0, 1, 0);
        glVertex3f(0, 0, -2.5);
        glVertex3f(-0.5, 0, -4.5);
        glVertex3f(0, 0, -6.5);
        glVertex3f(0.5, 0, -4.5);

        glNormal3f(0, 1, 0);
        glVertex3f(2.5, 0, 0);
        glVertex3f(4.5, 0, 0.5);
        glVertex3f(6.5, 0, 0);
        glVertex3f(4.5, 0, -0.5);

        glNormal3f(0, 1, 0);
        glVertex3f(-2.5, 0, 0);
        glVertex3f(-4.5, 0, 0.5);
        glVertex3f(-6.5, 0, 0);
        glVertex3f(-4.5, 0, -0.5);

    glEnd();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glRotatef(-90, 1, 0, 0);

    gluCylinder(quadObj, 0.9, 0.9, 3+0.4*ice_blast_move, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 5+0.4*ice_blast_move, 0);
    glRotatef(90, 1, 0, 0);

    gluCylinder(quadObj, 0, 0.9, 2, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
 	
 	glutSolidSphere(1.3, 30, 30);
    glPopMatrix();

    glPopMatrix();


/*
//sword

    GLUquadricObj *quadObj = gluNewQuadric();

	glBegin(GL_TRIANGLES);

		glNormal3f(0, 1, 0);
        glVertex3f(0, 0, 8);
        glVertex3f(0.3, 0, 8);
        glVertex3f(0, 0, 8.5);

        glNormal3f(0, 1, 0);
        glVertex3f(0, 0, 8);
        glVertex3f(-0.3, 0, 8);
        glVertex3f(0, 0, 8.5);

    glEnd();

        glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 8);
        glVertex3f(0.3, 0, 8);
        glVertex3f(0.3, 0, 0);

        glNormal3f(0, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 8);
        glVertex3f(-0.3, 0, 8);
        glVertex3f(-0.3, 0, 0);

    glEnd();

    //sword handle
    glPushMatrix();
    glTranslatef(-1, 0, 0);
    glRotatef(90, 0, 1, 0);

    gluCylinder(quadObj, 0.1, 0.1, 2, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -1.5);

    gluCylinder(quadObj, 0.15, 0.15, 1.5, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1, 0, 0);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1, 0, 0);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();

    //pommel
    glPushMatrix();
    glTranslatef(0, 0, -1.5);

    glutSolidTorus(0.08, 0.2, 20, 20);
    glPopMatrix();


/*
//shield
	glBegin(GL_TRIANGLES);

		glNormal3f(1, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(1.5, 0, 4);
        glVertex3f(0, 0, 4);

        glNormal3f(-1, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(-1.5, 0,4);
        glVertex3f(0, 0, 4);

        glNormal3f(1, 1, 0);
        glVertex3f(0, 0, 4);
        glVertex3f(1.5, 0, 4);
        glVertex3f(0, 0, 6);

        glNormal3f(-1, 1, 0);
        glVertex3f(0, 0, 4);
        glVertex3f(-1.5, 0, 4);
        glVertex3f(0, 0, 6);
    glEnd();


	

    //the rim

    glPushMatrix();
    //glTranslatef(0, 1, 0.5);
    glRotatef(20.556, 0, 1, 0);

    gluCylinder(quadObj, 0.08, 0.08, 4.272, 30, 30);
    glPopMatrix();

    glPushMatrix();
    //glTranslatef(0, 1, 0.5);
    glRotatef(-20.556, 0, 1, 0);

    gluCylinder(quadObj, 0.08, 0.08, 4.272, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 0, 4);
    glRotatef(-36.87, 0, 1, 0);



    gluCylinder(quadObj, 0.08, 0.08, 2.5, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5, 0, 4);
    glRotatef(36.87, 0, 1, 0);
 


    gluCylinder(quadObj, 0.08, 0.08, 2.5, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 0, 4);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-1.5, 0, 4);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, 6);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.75, 0, 4);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.75, 0, 4);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, 3);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 4);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, 5);
 	
 	glutSolidSphere(0.15, 30, 30);
    glPopMatrix();





/*
    glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glVertex3f(0.2, 0, 0.2);
        glVertex3f(0.2, 0, -0.2);
        glVertex3f(1.5,-0.3,3.8);
        glVertex3f(1.5,-0.3,4.2);



        glNormal3f(0, 0, 1);
        glVertex3f(0, 0, 0);

        glNormal3f(0, 0, 1);
        glVertex3f(0, 0, 0);

        glNormal3f(0, 0, 1);
        glVertex3f(0, 0, 0);


    glEnd();
*/

/*
//Abraxos

	//wings
	glPushMatrix();
	glTranslatef(0, -1, 5);

	glPushMatrix();

	glRotatef(25, 0, 1, 0);

	glPushMatrix();

	glRotatef(25, 0, 0, 1);

	    glBegin(GL_TRIANGLES);

        glVertex3f(2,4,0);
        glVertex3f(2,0,10);
        glVertex3f(2,0,0);

        glVertex3f(2,0,0);
        glVertex3f(2,0,10);
        glVertex3f(-2,-5,10);
    glEnd();

    glPopMatrix();

    glPopMatrix();


	glPushMatrix();

	glRotatef(-25, 0, 1, 0);

    glPushMatrix();

	glRotatef(-25, 0, 0, 1);

	    glBegin(GL_TRIANGLES);

        glVertex3f(-2,4,0);
        glVertex3f(-2,0,10);
        glVertex3f(-2,0,0);

        glVertex3f(-2,0,0);
        glVertex3f(-2,0,10);
        glVertex3f(2,-5,10);
    glEnd();

    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Ruby);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Ruby);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Ruby);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Ruby);


	//head

	glPushMatrix();
	glTranslatef(0, 6, 10.35);
	glRotatef(-25, 1, 0, 0);

	glPushMatrix();

    glTranslatef(0, 0, 0.25);
    //glRotatef(-55, 1, 0, 0);
    glScalef(2, 3, 0.5);
    
    glutSolidCube(1);

    glPopMatrix();

    GLUquadricObj *quadObj = gluNewQuadric();
	

    //snout spike

    glPushMatrix();
    glTranslatef(0, 1, 0.5);

    gluCylinder(quadObj, 0.2, 0, 1, 30, 30);
    glPopMatrix();

	glPushMatrix();

    glTranslatef(0, -0.75, 0.5);
    //glRotatef(-55, 1, 0, 0);
    glScalef(2, 1.5, 0.5);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0.45, -0.2);
    glRotatef(-25, 1, 0, 0);
    glScalef(2, 2, 0.4);
    
    glutSolidCube(1);

    glPopMatrix();

    //fangs
	glPushMatrix();
    glTranslatef(0.7, 1.35, -0.3);

    gluCylinder(quadObj, 0, 0.1, 0.4, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.7, 1.35, -0.3);

    gluCylinder(quadObj, 0, 0.1, 0.4, 30, 30);
    glPopMatrix();

    //horns

    glPushMatrix();

    glTranslatef(1, -1.2, 0.55);
    glRotatef(-25, 0, 0, 1);
    glScalef(2, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(1.62, -2, 0.55);
    glRotatef(65, 0, 0, 1);
    glScalef(1, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-1, -1.2, 0.55);
    glRotatef(25, 0, 0, 1);
    glScalef(2, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-1.62, -2, 0.55);
    glRotatef(-65, 0, 0, 1);
    glScalef(1, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();



    glPopMatrix();

 //body
    glPushMatrix();

    glTranslatef(0, 0, 4.1);
    //glRotatef(-55, 1, 0, 0);
    glScalef(4, 8, 2);
    
    glutSolidCube(1);

    glPopMatrix();

 //legs
    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(-2.7, -2, 1.5);
    glScalef(1.5, 1.5, 6);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(-move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(-2.7, 2, 1.5);
    glScalef(1.5, 1.5, 6);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(-move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(2.7, -2, 1.5);
    glScalef(1.5, 1.5, 6);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);
    glTranslatef(2.7, 2, 1.5);
    glScalef(1.5, 1.5, 6);
    glutSolidCube(1);

    glPopMatrix();



    //tail
    glPushMatrix();
    glScalef(1, 0.5, 0.5);
    glTranslatef(0, -4, 4);

    glPushMatrix();

    
    glTranslatef(0, -7.5, 1.5);

    glRotatef(35, 1, 0, 0);
    glScalef(1, 10, 1);
 
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    
    glTranslatef(0, -15.1, 1.5);

    glRotatef(-35, 1, 0, 0);
    glScalef(1, 10, 1);
 
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    
    glTranslatef(0, -20, 5);

    glRotatef(-35, 1, 0, 0);
    glScalef(2, 3, 2);
 
    glutSolidCube(1);

    glPopMatrix();
	

    //tail spikes

    glPushMatrix();
    glTranslatef(3.3, -23, 8);

    glRotatef(-90, 1, 0, 0);
    glRotatef(-45, 0, 1, 0);
    glRotatef(-35, 1, 0, 0);
    gluCylinder(quadObj, 0, 0.5, 5, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.3, -23, 8);

    glRotatef(-90, 1, 0, 0);
    glRotatef(45, 0, 1, 0);
    glRotatef(-35, 1, 0, 0);
    gluCylinder(quadObj, 0, 0.5, 5, 30, 30);
    glPopMatrix();

    glPopMatrix();

    //neck
    glPushMatrix();

    
    glTranslatef(0, 5.5, 5.5);

    glRotatef(45, 1, 0, 0);
    glScalef(1, 5, 1);
 
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    
    glTranslatef(0, 5.5, 8.3);

    glRotatef(-45, 1, 0, 0);
    glScalef(1, 5, 1);
 
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    
    glTranslatef(0, 4.5, 10.15);

    glRotatef(45, 1, 0, 0);
    glScalef(1, 2, 1);
 
    glutSolidCube(1);

    glPopMatrix();

/*

//whirlly

    //Silver
    float mat_ambient_Silver[] ={ 0.19225f, 0.19225f, 0.19225f, 1.0f };
	float mat_diffuse_Silver[] ={ 0.50754f, 0.50754f, 0.50754f, 1.0f};
	float mat_specular_Silver[] ={0.508273f, 0.508273f, 0.508273f, 1.0f };
	float shine_Silver = 51.2f;

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Silver);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Silver);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Silver);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Silver);

    GLUquadricObj *quadObj = gluNewQuadric();
	

    //body
    glPushMatrix();
    glRotatef(move, 0, 0, 1);
    gluCylinder(quadObj, 0, 6, 12, 30, 30);
    glPopMatrix();

    //arms
    glPushMatrix();

    glTranslatef(-4, -1, 6);
    glRotatef(-125, 1, 0, 0);
    glRotatef(move, 0, 0, 1);

    
        
    gluCylinder(quadObj, 0, 2, 7, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, -1, 6);
    glRotatef(-125, 1, 0, 0);
    glRotatef(move, 0, 0, 1);
    gluCylinder(quadObj, 0, 2, 7, 30, 30);
    glPopMatrix();

    //eyes
    glPushMatrix();

    glTranslatef(2, 7, 10);
    glRotatef(-25, 0, 1, 0);
    glScalef(2.4, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-2, 7, 10);
    glRotatef(25, 0, 1, 0);
    glScalef(2.4, 0.2, 0.2);
    
    glutSolidCube(1);

    glPopMatrix();


/*

    //Kaang Kong

    
    //body and arms
    glPushMatrix();
    
    glTranslatef(0, 0, 1.7);
    glRotatef(move, 1, 0, 0);
    glTranslatef(0, 0, -1.7);

    //body
    glPushMatrix();

    glTranslatef(0, 0, 4.1);
    glRotatef(-55, 1, 0, 0);
    glScalef(4, 2, 5);
    
    glutSolidCube(1);

    glPopMatrix();


	//Arms
 
	//left
    glPushMatrix();

    glTranslatef(-2.65, 1.5, 2.5);
    glScalef(1.3, 1.5, 6);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(2.65, 1.5, 2.5);
    glScalef(1.3, 1.5, 6);
    glutSolidCube(1);

    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Copper);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Copper);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Copper);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Copper);
    glPushMatrix();

    glTranslatef(2.65, 1.5, 0);
    glScalef(1.8, 1.8, 4);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-2.65, 1.5, 0);
    glScalef(1.8, 1.8, 4);
    glutSolidCube(1);

    glPopMatrix();

    //head
    glPushMatrix();

    glTranslatef(0, 2.5, 5);
    glScalef(1.2, 1.2, 1.2);
    glRotatef(-5, 1, 0, 0);


    //base

    //lower
    glPushMatrix();

    glTranslatef(0, 0.3, 0);
    glScalef(2, 1, 1);  
    glutSolidCube(1);

    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Ruby);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Ruby);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Ruby);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Ruby);

    //upper
    glPushMatrix();

    glTranslatef(0, -0.5, 0.5);
    glScalef(2, 2, 2);   
    glutSolidCube(1);

    glPopMatrix();


    //ears
    glPushMatrix();

    glTranslatef(1.1, -0.5, 1.2);
    glScalef(0.3, 0.3, 0.5);
   
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-1.1, -0.5, 1.2);
    glScalef(0.3, 0.3, 0.5);
   
    glutSolidCube(1);
    glPopMatrix();

    //eyes
    glPushMatrix();

    glTranslatef(0.5, 0.4, 1);
    glScalef(0.2, 0.2, 0.2);  
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.5, 0.4, 1);
    glScalef(0.2, 0.2, 0.2);  
    glutSolidCube(1);

    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Obsidian);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Obsidian);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Obsidian);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Obsidian);

    glPushMatrix();

    glTranslatef(0.4, 0.5, 1);
    glScalef(0.2, 0.2, 0.2);  
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.4, 0.5, 1);
    glScalef(0.2, 0.2, 0.2);  
    glutSolidCube(1);

    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

	//back legs
    glPushMatrix();

    glTranslatef(-1, -1, 1.5);
    glScalef(1.3, 1, 4);
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(1, -1, 1.5);
    glScalef(1.3, 1, 4);
    glutSolidCube(1);

    glPopMatrix();
   
     //eyes
    glPushMatrix();

    glTranslatef(0.5, 0.5, 1);
    glScalef(0.2, 0.2, 0.2);  
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.5, 0.5, 1);
    glScalef(0.2, 0.2, 0.2);  
    glutSolidCube(1);

    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Obsidian);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_Obsidian);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Obsidian);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Obsidian);

    glPushMatrix();

    glTranslatef(0.4, 0.5, 1);
    glScalef(0.2, 0.2, 0.2);  
    glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.4, 0.5, 1);
    glScalef(0.2, 0.2, 0.2);  
    glutSolidCube(1);

    glPopMatrix();

    //nose
    glPushMatrix();

    glTranslatef(0, 1.8, 0.5);
    glScalef(0.3, 0.3, 0.3);  
    glutSolidCube(1);

    glPopMatrix();
   
    glPopMatrix();

        //tail
    glPushMatrix();

    glTranslatef(0, 0, 1.7);
    glRotatef(wolf_move, 0, 0, 1);
    glTranslatef(0, 0, -1.7);
    glTranslatef(0, -2.5, 1.2);
    glRotatef(25, 1, 0, 0);
    glScalef(0.6, 2.5, 0.6);
    glutSolidCube(1);

    glPopMatrix();
*/ 
    // the picture gets drawn
    glutSwapBuffers();
	}

	//when we reshape the window this function activates
static void on_reshape(int width, int height){
     window_width = width;
     window_height = height;
}