#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdbool.h>
#include<math.h>
#include "DEER.h"

//const static float pi = 3.14159265358979323846;
//variables for width and depth
static int window_width, window_height;
//the incremental move variable
extern int move = 0;
//This really gets the deer going
int force_push = 0, side_force_push = 0;
//support indicator for deer-walking animation 
int ind = 0;
//position of the deer in the MAZE matrix
int deer_i = -1, deer_j = 1;
//this tells us if the deer is in motion
int deer_motion = 0;
//how the deer turns
int deer_rotation = 0;
//last deer direction, this helps me navigate the matrix better
// w = 0, s = 1, a = 2, d = 3
int last_deer_direction = 0;
//camera indicators vertical w,s and horizontal a,d this helps move the camera
int ind_v = 1, ind_h = 0;
//maze matrix
int M[51][51];
int i=0, j=0;

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
    glEnable(GL_DEPTH_TEST);

    //making the lines bolder
    glLineWidth(3);


    //entering the main loop
    glutMainLoop();

	return 0;
}

void on_display(void){

    //this whole section brings light to our MAZE

    GLfloat light_position[] = {200.0f, 300.0f, 100.0f, 0.0f};

    GLfloat light_ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};

    GLfloat light_diffuse[] = {1, 1, 1, 1};

    GLfloat light_specular[] = {0.9, 0.9, 0.9, 1};

    
    
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

	//cleaning out the color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//setting the view
    glViewport(0, 0,window_width, window_height);

    //Setting the angle, width-height ratio, near and far clipping plain
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, window_width/(float)window_height, 4, 1500);

    //implementing the camera, when the deer turns it shifts with him, ind_h and ind_v regulate the shift
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(deer_i*2-ind_v*4+(0.1*force_push), deer_j*2-ind_h*4+(0.1*side_force_push), 5,
    	     deer_i*2+(0.1*force_push)+2*ind_v, deer_j*2+(0.1*side_force_push)-0.01 + 2*ind_h, 2,
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

    GLfloat diffuse_coeffs_B[] = { 0, 0, 0.7, 1};

    GLfloat diffuse_coeffs_G[] = { 0, 0.7, 0, 1};

    GLfloat diffuse_coeffs_R[] = { 0.7, 0, 0, 1}; 

    GLfloat diffuse_coeffs_W[] = { 0.7, 0.7, 0.7, 1}; 

    GLfloat ambient_coeffs_B[] = { 0, 0, 0.7, 1};

    GLfloat ambient_coeffs_G[] = { 0, 0.7, 0, 1};

    GLfloat ambient_coeffs_R[] = { 0.7, 0, 0, 1}; 

    GLfloat ambient_coeffs_W[] = { 0.7, 0.7, 0.7, 1}; 



    //floor
    glColor3f(0.5,0.5,0.5);
    glPushMatrix();

    glTranslatef(50, 50, 0);
    glScalef(102, 102, 0.2);
    glutSolidCube(1);

    glPopMatrix();

    float mat_ambient_Brass[] ={ 0.329412f, 0.223529f, 0.027451f,1.0f };
    float mat_diffuse_Brass[] ={ 0.780392f, 0.568627f, 0.113725f, 1.0f };
    float mat_specular_Brass[] ={ 0.992157f, 0.941176f, 0.807843f, 1.0f };
    float shine_Brass = 27.8974f;
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_Brass);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_Brass);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_Brass);
    glMaterialf(GL_FRONT, GL_SHININESS, shine_Brass);

    //sand
    glPushMatrix();

    glTranslatef(0, 0, -2);
    glScalef(102000, 102000, 1);
    glutSolidCube(1);

    glPopMatrix();

    //file pointer
    FILE *fp;
    fp = fopen("MAZE.txt", "r");

    //I wrote a matrix with ones and zeroes
    //1 - there is a wall there 0 - there is no wall there
    //here we scan that matrix from a file
    for(i=0; i<50; i++){
        for(j=0; j<50; j++){
       if (!fscanf(fp, " %d", &M[i][j])) 
           break;
      }
    }
    
    fclose(fp);  

    //here we draw the maze
    for(i=0; i<50; i++){
        for(j=0; j<50; j++){
            if(M[i][j] == 1){
                if(i <=25 && j <= 25)
                {
                glColor3f(0,0,1);
                glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_B);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_B);
                }
                else if(i <=25 && j > 25)
                {
                glColor3f(0,1,0);
                glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_G);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_G);
                }
                else if(i >25 && j <= 25)
                {
                glColor3f(1,0,0);
                glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_R);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_R);
                }
                else if(i >25 && j > 25)
                {
                glColor3f(1,1,1);
                glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_W);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_W);
                }

                glPushMatrix();

                glTranslatef(2*i, 2*j, 5);
                glScalef(2, 2, 10);
                glutSolidCube(1);

                glPopMatrix();
            }
        }
    }

    //everything is okay, beacuse our protagonist is here
    //force_push and side_force_push propel our deer forward but the deer_i and deer_j truly place him 
    //they represent his place in the grand scheme of things(the MAZE Matrix)
    //deer_rotation makes him turn
    glPushMatrix();

    glTranslatef(deer_i*2+(0.1*force_push), deer_j*2+(0.1*side_force_push), 0.5);
    glRotatef(-90 + deer_rotation, 0, 0, 1);
    glScalef(0.3, 0.3, 0.3);
    DEER();
    
    glPopMatrix();

    // the picture gets drawn
    glutSwapBuffers();
	}

	//when we reshape the window this function activates
static void on_reshape(int width, int height){
     window_width = width;
     window_height = height;
}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        //we exit the game
        exit(0);
        break;

//the movement section WORKS it WORKS I don't know how I don't know WHY but it WORKS, please don't look at it
    case 'w':
    case 'W':
        {
            //last_deer_direction tells us with way the deer is facing
            //according to that fact we know where to move within the matrix
            //I can't explain it with words better, but I can draw a neat picture to elaborate :D(if anyone cares)
            //here the deer is facing forward if another w is pressed he should go forward
            if(last_deer_direction == 0){
            //the deer moves forward if the path is clear
                if(M[deer_i+1][deer_j] == 0)
                    {
                    deer_motion = 1;
                    ind_v = 1;
                    ind_h = 0;                    
                    glutTimerFunc(20, on_timer, 0);
                    }
            }
            //here the deer is facing backwards if w is pressed
            // he should continue going backwards because thats his forward now
            //and so on for every key pressed [a, d...]
            else if(last_deer_direction == 1){
                if(M[deer_i-1][deer_j] == 0)
                    {
                    deer_motion = 1;
                    ind_v = -1;
                    ind_h = 0;                    
                    glutTimerFunc(20, on_timer, 1);
                    }
            }
            else if(last_deer_direction == 2){
                if(M[deer_i][deer_j+1] == 0)
                    {
                    deer_motion = 1;
                    ind_v = 0;
                    ind_h = 1;
                    glutTimerFunc(20, on_timer, 2);
                    }
            }
            else if(last_deer_direction == 3){
                if(M[deer_i][deer_j-1] == 0)
                    {
                    deer_motion = 1;
                    ind_v = 0;
                    ind_h = -1;
                    glutTimerFunc(20, on_timer, 3);
                    }
            }
            
            break;
        }
    case 's':
    case 'S':
        {
            if(last_deer_direction == 0){
            if(M[deer_i-1][deer_j] == 0){
            deer_motion = 1;
            ind_v = -1;
            ind_h = 0;
            glutTimerFunc(20, on_timer, 1);
            }
            }
            else if(last_deer_direction == 1){
            if(M[deer_i+1][deer_j] == 0){
            deer_motion = 1;
            ind_v = 1;
            ind_h = 0;
            glutTimerFunc(20, on_timer, 0);
            }
            }
            else if(last_deer_direction == 2){
                if(M[deer_i][deer_j-1] == 0)
                    {
                    deer_motion = 1;
                    ind_v = 0;
                    ind_h = -1;
                    glutTimerFunc(20, on_timer, 3);
                    }
            }
            else if(last_deer_direction == 3){
                if(M[deer_i][deer_j+1] == 0)
                    {
                    deer_motion = 1;
                    ind_v = 0;
                    ind_h = 1;
                    glutTimerFunc(20, on_timer, 2);
                    }
            }
            
            break;
        }
    case 'a':
    case 'A':
        {
            if(last_deer_direction == 0){
            if(M[deer_i][deer_j+1] == 0){
            deer_motion = 1;
            ind_h = 1;
            ind_v = 0;
            glutTimerFunc(20, on_timer, 2);
            }
            }
            else if(last_deer_direction == 1){
            if(M[deer_i][deer_j-1] == 0){
            deer_motion = 1;
            ind_h = -1;
            ind_v = 0;
            glutTimerFunc(20, on_timer, 3);
            }
            }
            else if(last_deer_direction == 2){
            if(M[deer_i-1][deer_j] == 0){
            deer_motion = 1;
            ind_h = 0;
            ind_v = -1;
            glutTimerFunc(20, on_timer, 1);
            }
            }
            else if(last_deer_direction == 3){
            if(M[deer_i+1][deer_j] == 0){
            deer_motion = 1;
            ind_h = 0;
            ind_v = 1;
            glutTimerFunc(20, on_timer, 0);
            }
            }
            
            break;
        }
    case 'd':
    case 'D':
        {
            if(last_deer_direction == 0){
            if(M[deer_i][deer_j-1] == 0){
            deer_motion = 1;
            ind_h = -1;
            ind_v = 0;
            
            glutTimerFunc(20, on_timer, 3);
            }
            }
            else if(last_deer_direction == 1){
            if(M[deer_i][deer_j+1] == 0){
            deer_motion = 1;
            ind_h = 1;
            ind_v = 0;
            
            glutTimerFunc(20, on_timer, 2);
            }
            }
            else if(last_deer_direction == 2){
            if(M[deer_i+1][deer_j] == 0){
            deer_motion = 1;
            ind_h = 0;
            ind_v = 1;
            
            glutTimerFunc(20, on_timer, 0);
            }
            }
            else if(last_deer_direction == 3){
            if(M[deer_i-1][deer_j] == 0){
            deer_motion = 1;
            ind_h = 0;
            ind_v = -1;
            
            glutTimerFunc(20, on_timer, 1);
            }
            }
            
            break;
        }
    }
}

static void on_timer(int value){

    //going forward
    if(value == 0 && deer_motion == 1)
    {
    //here we rotate the deer if rotation is required
    if(deer_rotation > 0)
    {
    deer_rotation -= 10;
    glutPostRedisplay();
    glutTimerFunc(20, on_timer, 0);
    return;
    }
    if(deer_rotation < 0)
    {
    deer_rotation += 10;
    glutPostRedisplay();
    glutTimerFunc(20, on_timer, 0);
    return;
    }
    //because of this the deer moves forward
    last_deer_direction = 0;
    if(force_push<20)
    force_push +=1;
    else{
    //when he has moved one space in the MAZE Matrix
    //we update the deer location and reset everything else
    force_push = 0;
    deer_i = deer_i + 1;
    move = 0;
    deer_motion=0;
    glutPostRedisplay();
    return;
    }
    //this gives us the walking animation
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

    //going backwards
    if(value == 1 && deer_motion == 1)
    {

    if(deer_rotation > 180)
    {
    deer_rotation -= 10;
    glutPostRedisplay();
    glutTimerFunc(20, on_timer, 1);
    return;
    }
    if(deer_rotation < 180)
    {
    deer_rotation += 10;
    glutPostRedisplay();
    glutTimerFunc(20, on_timer, 1);
    return;
    }

    last_deer_direction = 1;
    if(force_push>-20)
    force_push -=1;
    else{
    
    force_push = 0;
    deer_i = deer_i - 1;
    move = 0;
    deer_motion = 0;
    glutPostRedisplay();
    return;
    }
    if(ind == 1 && move <= -15)
    ind = 0;
    else if(ind == 1)
    move -=1;
    else if(move < 15)
    move +=1;
    else if(move >= 15)
    ind = 1;

    glutPostRedisplay();
    glutTimerFunc(20, on_timer, 1);

    }

    //going left
    if(value == 2 && deer_motion == 1)
    {

    if(deer_rotation > 90)
    {
    deer_rotation -= 10;
    glutPostRedisplay();
    glutTimerFunc(20, on_timer, 2);
    return;
    }
    if(deer_rotation < 90)
    {
    deer_rotation += 10;
    glutPostRedisplay();
    glutTimerFunc(20, on_timer, 2);
    return;
    }

    last_deer_direction = 2;
    if(side_force_push<20)
    side_force_push +=1;
    else{
    
    side_force_push = 0;
    deer_j = deer_j + 1;
    move = 0;
    deer_motion = 0;
    glutPostRedisplay();
    return;
    }
    if(ind == 1 && move <= -15)
    ind = 0;
    else if(ind == 1)
    move -=1;
    else if(move < 15)
    move +=1;
    else if(move >= 15)
    ind = 1;

    glutPostRedisplay();
    glutTimerFunc(20, on_timer, 2);

    }

    //going right
    if(value == 3 && deer_motion == 1)
    {
    if(deer_rotation > -90)
    {
    deer_rotation -= 10;
    glutPostRedisplay();
    glutTimerFunc(20, on_timer, 3);
    return;
    }
    if(deer_rotation < -90)
    {
    deer_rotation += 10;
    glutPostRedisplay();
    glutTimerFunc(20, on_timer, 3);
    return;
    }

    last_deer_direction = 3;
    if(side_force_push>-20)
    side_force_push -=1;
    else{
    
    side_force_push = 0;
    deer_j = deer_j - 1;
    move = 0;
    deer_motion = 0;
    glutPostRedisplay();
    return;
    }
    if(ind == 1 && move <= -15)
    ind = 0;
    else if(ind == 1)
    move -=1;
    else if(move < 15)
    move +=1;
    else if(move >= 15)
    ind = 1;

    glutPostRedisplay();
    glutTimerFunc(20, on_timer, 3);

    }

}