//We were told to mark code we took from somewhere,
// I'm not sure how to mark down a friend teaching me 
//almost everything, he also told me to look at his code for inspiration
// - so I did just that his repository is RG14-nerdbot-arena 
#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdbool.h>
#include<math.h>
#include "DEER.h"
#include "Fenrys.h"
#include "Kaang.h"
#include "Whirly.h"
#include "Abraxos.h"
#include "Keyboard.h"
#include "Encounter.h"
#include "image.h"
#include "Sword_and_shield.h"
#include "Powers.h"

#define FILENAME0 "brick4_b.bmp"
#define FILENAME1 "sand_2.bmp"

static GLuint names[2];

//variables for width and depth
extern int window_width = 0, window_height = 0;

//the incremental move variable
extern int move = 0;

//support indicator for deer-walking animation 
int ind = 0;

//wolf animation parameters
extern int wolf_move = 0;
int wolf_ind = 0;
//patrolling parametors - they are used for every antagonist not just the wolf
int wolf_location = 0;
int wolf_rotation = 0;
int back_route = 0;

//Kaang animation
extern int Kaang_move = 0;
int Kaang_ind = 0;

//Whirly animation
extern int Whirly_move = 0;

//Abraxos animatoin
extern int Abraxos_move = 0;
int Abraxos_ind = 0;

//This really gets the deer going
int force_push = 0, side_force_push = 0;
//position of the deer in the MAZE matrix
extern int deer_i = -1, deer_j = 1;

//this tells us if the deer is in motion
extern int deer_motion = 0;

//how the deer turns
int deer_rotation = 0;

//last deer direction, this helps me navigate the matrix better
// w = 0, s = 1, a = 2, d = 3
extern int last_deer_direction = 0;

//camera indicators vertical w,s and horizontal a,d this helps move the camera
extern int ind_v = 1, ind_h = 0;

//maze matrix
int M[51][51];
int i=0, j=0;

//Encounter indicator - Encounter is a brief mini-game where you fight one of the antagonists
extern int En_ind = 0;

//deer encounter position - how the deer moves while in the Encounter
extern int deer_en_pos_v = 0;
extern int deer_en_pos_h = 0;

//indicator for my constant on_timer functions
extern int first_time_main_ind = 1;

//indicator that the game is over - mostly useless now (but I had big plans for it, alas ran out of time)
int end = 0;

//maze antagonist status indicators - 0 - the antagonist is drawn in the maze, 1 - he is not
int dead_Fenrys_1 = 0;
int dead_Fenrys_2 = 0;
int dead_Fenrys_3 = 0;
int dead_Kaang_1 = 0;
int dead_Kaang_2 = 0;
int dead_Kaang_3 = 0;
int dead_Whirly_1 = 0;
int dead_Whirly_2 = 0;
int dead_Whirly_3 = 0;
int dead_Abraxos_1 = 0;
int dead_Abraxos_2 = 0;
int dead_Abraxos_3 = 0;


//callback functions
static void on_display(void);
static void on_reshape(int width, int height);
extern void on_timer(int value);
static void on_timer_wolf(int value);
static void on_timer_Kaang(int value);
static void on_timer_Abraxos(int value);

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
    glutTimerFunc(20, on_timer_wolf, 0);
    glutTimerFunc(20, on_timer_Kaang, 0);
    glutTimerFunc(20, on_timer_Abraxos, 0);

    //color that cleans the view
    glClearColor(0.75, 0.75, 0.75, 0);
    //Enable depth
    glEnable(GL_DEPTH_TEST);
    //Enable normalization of vectors
    glEnable(GL_NORMALIZE);

    //making the lines bolder
    glLineWidth(3);


    //entering the main loop
    glutMainLoop();

	return 0;
}

void on_display(void){
    if(En_ind == 0){

    if(deer_i == 49 && deer_j == 1){
        end = 1;
        printf("%d\n", end);
        printf("Game Over! You Won!\n");
        exit(0);
    }

    if(first_time_main_ind == 1){
    glutTimerFunc(20, on_timer_wolf, 0);
    glutTimerFunc(20, on_timer_Kaang, 0);
    glutTimerFunc(20, on_timer_Abraxos, 0);
    first_time_main_ind = 0;
    }
    //this segment is copied directly from a 'cas 7 - textures' code 
    //I dont understand it fully just the bits i need to make it work
    glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV,
              GL_TEXTURE_ENV_MODE,
              GL_REPLACE);

    Image * image;

    image = image_init(0, 0);

    image_read(image, FILENAME0);

    glGenTextures(2, names);

    glBindTexture(GL_TEXTURE_2D, names[0]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    glBindTexture(GL_TEXTURE_2D, 0);

    image_read(image, FILENAME1);

    glBindTexture(GL_TEXTURE_2D, names[1]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    glBindTexture(GL_TEXTURE_2D, 0);

    image_done(image);

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

 

    //material parameters for the walls
    //Blue
    GLfloat diffuse_coeffs_B[] = { 0, 0, 0.7, 1};
    GLfloat ambient_coeffs_B[] = { 0, 0, 0.7, 1};

    //Green
    GLfloat diffuse_coeffs_G[] = { 0, 0.7, 0, 1};
    GLfloat ambient_coeffs_G[] = { 0, 0.7, 0, 1};

    //Red
    GLfloat diffuse_coeffs_R[] = { 0.7, 0, 0, 1}; 
    GLfloat ambient_coeffs_R[] = { 0.7, 0, 0, 1}; 

    //White
    GLfloat diffuse_coeffs_W[] = { 0.7, 0.7, 0.7, 1}; 
    GLfloat ambient_coeffs_W[] = { 0.7, 0.7, 0.7, 1}; 

    GLfloat specular_coeffs[] = { 0.5, 0.5, 0.5, 1};
    GLfloat shininess = 15;

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    //MAZE ground
    glBindTexture(GL_TEXTURE_2D, names[0]);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-1, -1, 0);

        glTexCoord2f(120, 0);
        glVertex3f(101, 0, 0);

        glTexCoord2f(120, 60);
        glVertex3f(101, 101, 0);

        glTexCoord2f(0, 60);
        glVertex3f(0, 101, 0);
    glEnd();

    //outer sand land
    glBindTexture(GL_TEXTURE_2D, 0);

        glBindTexture(GL_TEXTURE_2D, names[1]);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-500, -500, -0.2);

        glTexCoord2f(1200, 0);
        glVertex3f(500, -500, -0.2);

        glTexCoord2f(1200, 600);
        glVertex3f(500, 500, -0.2);

        glTexCoord2f(0, 600);
        glVertex3f(-500, 500, -0.2);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);

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

    //here we draw the maze - different sections of the MAZE have different colors
    for(i=0; i<50; i++){
        for(j=0; j<50; j++){
            if(M[i][j] == 1){
                //here we pick the color of our wall block
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

                //the wall block gets made and pushed to a correct position 
                glPushMatrix();

                //the MAZE matrix helps place the wall block - only where the matrix value is 1
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
    glScalef(0.2, 0.2, 0.2);
    DEER();
    
    glPopMatrix();

    //walking into a patrolled ground means there is gonna be an encounter
    //the deer coordinates tell us if we entered that ground
    if(deer_i == 14 && (deer_j >= 2 && deer_j <= 16) && dead_Fenrys_1 == 0){
        //Encounter starts
        En_ind = 1;
        //the Foe is no longer drawn in the MAZE
        dead_Fenrys_1 = 1;
 
    }
    if(deer_i == 5 && (deer_j >= 6 && deer_j <= 18) && dead_Fenrys_2 == 0){
        dead_Fenrys_2 = 1;        
        En_ind = 1;
    }
    if(deer_i == 22 && (deer_j >= 9 && deer_j <= 20) && dead_Fenrys_3 == 0){
        dead_Fenrys_3 = 1;
        En_ind = 1;
    }
    if(deer_i == 1 && (deer_j >= 26 && deer_j <= 37) && dead_Kaang_1 == 0){
        dead_Kaang_1 = 1;
        En_ind = 1;
    }

    if(deer_i == 14 && (deer_j >= 37 && deer_j <= 49) && dead_Kaang_2 == 0){
        dead_Kaang_2 = 1;
        En_ind = 1;
    }

    if((deer_i >= 15 && deer_i <= 28) && deer_j == 41 && dead_Kaang_3 == 0){
        dead_Kaang_3 = 1;
        En_ind = 1;
    }
    if(deer_i == 29 && (deer_j >= 30 && deer_j <= 42) && dead_Whirly_1 == 0){
        dead_Whirly_1 = 1;
        En_ind = 1;
    }

    if((deer_i >= 32 && deer_i <= 43) && deer_j == 41 && dead_Whirly_2 == 0){
        dead_Whirly_2 = 1;
        En_ind = 1;
    }
    if(deer_i == 48 && (deer_j >= 27 && deer_j <= 39) && dead_Whirly_3 == 0){
        dead_Whirly_3 = 1;
        En_ind = 1;
    }
    if((deer_i >= 30 && deer_i <= 41) && deer_j == 1 && dead_Abraxos_1 == 0){
        dead_Abraxos_1 = 1;  
        En_ind = 1;
    }

    if(deer_i == 47 && (deer_j >= 1 && deer_j <= 12) && dead_Abraxos_2 == 0){
        dead_Abraxos_2 = 1;
        En_ind = 1;
    }

    if((deer_i >= 36 && deer_i <= 44) && deer_j == 16 && dead_Abraxos_3 == 0){
        dead_Abraxos_3 = 1;
        En_ind = 1;
    }


    //here we have our antagonists they pretty much just walk through the MAZE
    //if there was an encounter the foe doesnt get drawn anymore
    //Wolf #1
    if(dead_Fenrys_1 == 0){
    glPushMatrix();

    //the wolf is moved into position and set to patrolling
    glTranslatef(28, 4 + 0.2*wolf_location, 0.5);
    glRotatef(0 + wolf_rotation, 0, 0, 1);
    glScalef(0.3, 0.3, 0.3);
    draw_wolf();
    
    glPopMatrix();
    }
    if(dead_Fenrys_2 == 0)
    {
    //Wolf #2
    glPushMatrix();

    glTranslatef(10,14 + 0.2*wolf_location, 0.5);
    glRotatef(0 + wolf_rotation, 0, 0, 1);
    glScalef(0.3, 0.3, 0.3);
    draw_wolf();
    
    glPopMatrix();
    }
    if(dead_Fenrys_3 == 0)
    {
    //Wolf #3
    glPushMatrix();

    glTranslatef(44,18 + 0.2*wolf_location, 0.5);
    glRotatef(0 + wolf_rotation, 0, 0, 1);
    glScalef(0.3, 0.3, 0.3);
    draw_wolf();
    
    glPopMatrix();
}
    //Kaang #1
    if(dead_Kaang_1 == 0){
    glPushMatrix();

    glTranslatef(2, 52 + 0.2*wolf_location, 0.5);
    glRotatef(0 + wolf_rotation, 0, 0, 1);
    glScalef(0.25, 0.25, 0.25);
    draw_Kaang();
    
    glPopMatrix();
}
    //Kaang #2
    if(dead_Kaang_2 == 0){
    glPushMatrix();

    //it says wolf everywhere but we can pretend it says something different
    glTranslatef(28, 74 + 0.2*wolf_location, 0.5);
    glRotatef(0 + wolf_rotation, 0, 0, 1);
    glScalef(0.25, 0.25, 0.25);
    draw_Kaang();
    
    glPopMatrix();
}
    //Kaang #3
    if(dead_Kaang_3 == 0){
    glPushMatrix();

    glTranslatef(30 + 0.2*wolf_location, 82, 0.5);
    glRotatef(-90 + wolf_rotation, 0, 0, 1);
    glScalef(0.25, 0.25, 0.25);
    draw_Kaang();
    
    glPopMatrix();
}
    //Whirly #1
    if(dead_Whirly_1 == 0){
    glPushMatrix();

    glTranslatef(58, 52 + 0.2*wolf_location, 0.5);
    glRotatef(0 + wolf_rotation, 0, 0, 1);
    glScalef(0.15, 0.15, 0.3);
    draw_Whirly();
    
    glPopMatrix();
}
    //Whirly #2
    if(dead_Whirly_2 == 0){
    glPushMatrix();

    glTranslatef(64 + 0.2*wolf_location, 82, 0.5);
    glRotatef(-90 + wolf_rotation, 0, 0, 1);
    glScalef(0.15, 0.15, 0.3);
    draw_Whirly();
    
    glPopMatrix();
}
    //Whirly #3
    if(dead_Whirly_3 == 0){
    glPushMatrix();

    glTranslatef(96, 54 + 0.2*wolf_location, 0.5);
    glRotatef(0 + wolf_rotation, 0, 0, 1);
    glScalef(0.15, 0.15, 0.3);
    draw_Whirly();
    
    glPopMatrix();
}
    //Abraxos #1
    if(dead_Abraxos_1 == 0){
    glPushMatrix();

    glTranslatef(66 + 0.2*wolf_location, 2, 0.5);
    glRotatef(-90 + wolf_rotation, 0, 0, 1);
    glScalef(0.17, 0.17, 0.17);
    draw_Abraxos();
    
    glPopMatrix();
}
    //Abraxos #2
    if(dead_Abraxos_2 == 0){
    glPushMatrix();

    glTranslatef(94, 2 + 0.2*wolf_location, 0.5);
    glRotatef(0 + wolf_rotation, 0, 0, 1);
    glScalef(0.17, 0.17, 0.17);
    draw_Abraxos();
    
    glPopMatrix();
}
    //Abraxos #3
    if(dead_Abraxos_3 == 0){
    glPushMatrix();

    glTranslatef(72 + 0.2*wolf_location, 32, 0.5);
    glRotatef(-90 + wolf_rotation, 0, 0, 1);
    glScalef(0.17, 0.17, 0.17);
    draw_Abraxos();
    
    glPopMatrix();
}

    }
    //this is where we start the Encounter
    //based on the deer location we know witch encounter started
    //because foes never leave their designated territories
    if(En_ind == 1){
        if(deer_i<25 && deer_j<25)
        Encounter(1);
        if(deer_i<25 && deer_j>=25)
        Encounter(2);
        if(deer_i>=25 && deer_j>=25)
        Encounter(3);
        if(deer_i>=25 && deer_j<25)
        Encounter(4);
        
    }


    // the picture gets drawn
    glutSwapBuffers();
	
}


	//when we reshape the window this function activates
static void on_reshape(int width, int height){
     window_width = width;
     window_height = height;
}

static void on_timer_Abraxos(int value){
    //standard walking animation used everywhere
    if(value == 0 && En_ind == 0){
    if(Abraxos_ind == 1 && Abraxos_move <= -15)
    Abraxos_ind = 0;
    else if(Abraxos_ind == 1)
    Abraxos_move -=1;
    else if(Abraxos_move < 15)
    Abraxos_move +=1;
    else if(Abraxos_move >= 15)
    Abraxos_ind = 1; 
    

    glutPostRedisplay();
    glutTimerFunc(20, on_timer_Abraxos, 0);

    }

}

static void on_timer_wolf(int value){
    if(En_ind == 0){
    //walking animation
    if(wolf_ind == 1 && wolf_move <= -15)
    wolf_ind = 0;
    else if(wolf_ind == 1)
    wolf_move -=2;
    else if(wolf_move < 15)
    wolf_move +=2;
    else if(wolf_move >= 15)
    wolf_ind = 1; 

    //patroling animation
    if(wolf_location < 84 && back_route == 0){
        wolf_location += 1;
        glutPostRedisplay();
    }
    else if(wolf_location >= 84 && back_route == 0){
        back_route = 1;
        wolf_rotation = -180;
    }
    else if(wolf_location > 0 && back_route == 1)
    {
        wolf_location -= 1;
        glutPostRedisplay();
    }
    else if(wolf_location <= 0 && back_route == 1){
        back_route = 0;
        wolf_rotation = 0;
    }
    
    glutPostRedisplay();
    glutTimerFunc(40, on_timer_wolf, 0);
    }  
}

static void on_timer_Kaang(int value){
//whirly move animation
    Whirly_move += 1;
//Kaang walking animation
if(En_ind == 0){
    if(value == 0)
    {
    if(Kaang_ind == 1 && Kaang_move <= -30)
    Kaang_ind = 0;
    else if(Kaang_ind == 1)
    Kaang_move -=1;
    else if(Kaang_move < 30)
    Kaang_move +=1;
    else if(Kaang_move >= 30)
    Kaang_ind = 1;
    

    glutPostRedisplay();
    glutTimerFunc(20, on_timer_Kaang, 0);
}

    }


}


extern void on_timer(int value)
{
    //this walking animation is so convoluted... What was I thinking

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
