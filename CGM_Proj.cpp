#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <sstream>
using namespace std;

#define draw_width 180
#define draw_height 180
#define PI 3.14159265358979323846

double speed = 26;
float point_1=50,point_2=50;
bool stop_counter=false ;
double blue_ball_x = 0, blue_ball_y = 0;
double pink_ball_x = 0, pink_ball_y = 50;
double blue_ball_x_velocity = 8.0;
double blue_ball_y_velocity = 1.0;
double pink_ball_x_velocity = 10.0;
double pink_ball_y_velocity = 3.0;
int score_counter = 0;


////////////////////////////////////////////////////////////////////////////////
GLfloat white[3] = { 1.0, 1.0, 1.0 };
GLuint font;
GLubyte space[] = 
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
GLubyte letters[][13] = {
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0x66, 0x3c, 0x18}, 
{0x00, 0x00, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe}, 
{0x00, 0x00, 0x7e, 0xe7, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e}, 
{0x00, 0x00, 0xfc, 0xce, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7, 0xce, 0xfc}, 
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, 0xff}, 
{0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xff}, 
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xcf, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e}, 
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3}, 
{0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7e}, 
{0x00, 0x00, 0x7c, 0xee, 0xc6, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06}, 
{0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xe0, 0xf0, 0xd8, 0xcc, 0xc6, 0xc3}, 
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0}, 
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xdb, 0xff, 0xff, 0xe7, 0xc3}, 
{0x00, 0x00, 0xc7, 0xc7, 0xcf, 0xcf, 0xdf, 0xdb, 0xfb, 0xf3, 0xf3, 0xe3, 0xe3}, 
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e}, 
{0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe}, 
{0x00, 0x00, 0x3f, 0x6e, 0xdf, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c}, 
{0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe}, 
{0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0x7e, 0xe0, 0xc0, 0xc0, 0xe7, 0x7e}, 
{0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff}, 
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3}, 
{0x00, 0x00, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3}, 
{0x00, 0x00, 0xc3, 0xe7, 0xff, 0xff, 0xdb, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3}, 
{0x00, 0x00, 0xc3, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3}, 
{0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3}, 
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0x60, 0x30, 0x7e, 0x0c, 0x06, 0x03, 0x03, 0xff}
};
//Raster Font
void make_raster_font(void){
   GLuint i, j;
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

   font = glGenLists (128);
   for (i = 0,j = 'A'; i < 26; i++,j++) {
      glNewList(font + j, GL_COMPILE);
      glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, letters[i]);
      glEndList();
   }
   glNewList(font + ' ', GL_COMPILE);
   glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, space);
   glEndList();
 }

void init(void){
   glShadeModel (GL_FLAT);
   make_raster_font();
}

void print_str(char *s){
   char text[256];
   glPushAttrib (GL_LIST_BIT);
   glListBase(font);
   glCallLists((GLsizei) strlen(s), GL_UNSIGNED_BYTE, (GLubyte *) s);
   glPopAttrib ();
}

void game_over(){
	// disp when game is over
	   glColor3fv(white);
	   glRasterPos2i(-15, 0);
	   print_str("GAME OVER");
	   glRasterPos2i(-15, -15);
	   print_str("PRESS 'S' TO START GAME AGAIN");
	   glRasterPos2i(-15, -30);
	   print_str("YOUR SCORE IS ");
}

string score_counter_array(int a){
	int i = a;
	string out_str;
	stringstream s;
	s << i;
	out_str = s.str();
	return out_str;
}
//Making Balls
void make_ball(double c_x, double c_y, double radius){
	double steps = 30;
	double delta = 2 * PI / steps;
	glBegin(GL_TRIANGLE_FAN);
	double ang = 0;
	glVertex2f(c_x, c_y);
	for (int i = 0; i <= steps; i++){
		double x = c_x + radius * cos(ang);
		double y = c_y + radius * sin(ang);
		glVertex2f(x, y);
		ang += delta;}
	glEnd();
}

void disp(void){
    glClear(GL_COLOR_BUFFER_BIT);
	if(stop_counter==false){
		//draw breakout
	   glLineWidth(20);
		glColor3d(1,1,1);
		glBegin(GL_LINES);
			glVertex2f(-point_1,-120);
			glVertex2f(point_2,-120);
		glEnd();
		//draw border
		glLineWidth(7);
		glBegin(GL_LINE_LOOP);
		glColor3d(1,1,1);
			glVertex2d(-180,180);  
			glVertex2d( 180,180);  
			glVertex2d( 180,-180); 
			glVertex2d( -180, -180);
		glEnd();

		glColor3f(0, 1, 1);					//blue
		make_ball(blue_ball_x, blue_ball_y, 20);		//ball 1
		glColor3f(1, 0, 1);					//pink
		make_ball(pink_ball_x, pink_ball_y, 20);	//ball 2
	}
	else{
		//draw border
		glLineWidth(7);
		glBegin(GL_LINE_LOOP);
		glColor3d(1,1,1);
			glVertex2d(-180,180);  
			glVertex2d( 180,180);  
			glVertex2d( 180,-180); 
			glVertex2d( -180, -180);
		glEnd();

		game_over();
	
		// if(score_counter-2 < 0){score_counter=0;}
		// else{score_counter = score_counter - 2;}

		glColor3d(1,0,0);
		//if use array_score to disp numbers on screen
		glRasterPos2i(52, -31);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,score_counter_array(score_counter)[0]);
	}
	glFlush();
	if (stop_counter==false){
		glutPostRedisplay();
	}
}

void time_function(int val){
	// Blue Ball
	blue_ball_x += blue_ball_x_velocity;
	blue_ball_y += blue_ball_y_velocity;
	//collison with border
	if (blue_ball_x + 20 >= 175 || blue_ball_x - 20 <= -175){
		blue_ball_x_velocity *= -1;
	}
	if (blue_ball_y + 20 >= 175 || blue_ball_y - 20 <= -175){
		blue_ball_y_velocity *= -1; 
	}
	//collision with breakout
	if (blue_ball_y - 20 <= -120){
		if(blue_ball_x >= -point_1 && blue_ball_x + 20 <=point_2){
			blue_ball_y_velocity *= -1;
		}
	}
	// if (blue_ball_x + 20 >= -120 && blue_ball_x + 20 <= -175){
	// 	if(blue_ball_x >= -point_1 && blue_ball_x + 20 <=point_2){
	// 		blue_ball_y_velocity *= -1;
	// 	}
	// }
	//stop_counter game at -160 or less (Game Over)
	if (blue_ball_y - 20 <= -130){
		stop_counter=true;
	}



	// Pink Ball
	pink_ball_x += pink_ball_x_velocity;
	pink_ball_y += pink_ball_y_velocity;
	//collison with border
	if (pink_ball_x + 20 >= 175 || pink_ball_x - 20 <= -175){
		pink_ball_x_velocity *= -1;
	}
	if (pink_ball_y + 20 >= 175 || pink_ball_y - 20 <= -175){
		pink_ball_y_velocity *= -1;
		// score_counter+=1;
	}

	// //collision with breakout
	// if (pink_ball_y - 20 <= -120){
	// 	if(pink_ball_x+20>= -point_1+10 && pink_ball_x-20 <=point_2-10)
	// 		pink_ball_y_velocity *= -1;}
	// if (pink_ball_x + 20 >= -120 && pink_ball_x - 20 <= -175){
	// 	if(pink_ball_x - 20 >= -point_1 && pink_ball_x + 20 <=point_2)
	// 		pink_ball_y_velocity *= -1;}

    //collision with breakout
    if (pink_ball_y - 20 <= -120){
		if(pink_ball_x >= -point_1 && pink_ball_x + 20 <=point_2){
			pink_ball_y_velocity *= -1;
			score_counter++;
		}
	}
	// if (pink_ball_x + 20 >= -120 && pink_ball_x + 20 <= -175){
	// 	if(pink_ball_x >= -point_1 && pink_ball_x + 20 <=point_2){
	// 		pink_ball_y_velocity *= -1;
	// 	}
	// }
	//stop_counter game at -160 or less (Game Over)
	if (pink_ball_y - 20 <= -130){
		stop_counter=true;
	}

	// Game Over (if false continue else if true stop_counter)
	if (stop_counter==false)
		glutPostRedisplay();
		glutTimerFunc(40, time_function, 0);
}

void move_left(){
	if (point_1>-165){
		point_1+=speed;
		point_2-=speed;
	}
	if (point_2<-100){
		point_2+=speed;
		point_1-=speed;
	}
}

void move_right(){
	if (point_2<165){
		point_2+=speed;
		point_1-=speed;
	}
	else if (point_1>100){
		point_1+=speed;
	}
}

void keyboard_function(unsigned char key, int x, int y){
   if ( key == 27 ) exit(0); //Exit From Game
	else if ( key == 's' ){  //Start Game again
	stop_counter=false;
	score_counter=0;
	point_1=50,point_2=50;
	blue_ball_x = 0;
	blue_ball_y = 30;	
	pink_ball_x = 0;
	pink_ball_y = 50;
	blue_ball_x_velocity = 2.8;
	blue_ball_y_velocity = 0.8;
	pink_ball_x_velocity = 3.7;
	pink_ball_y_velocity = 1.2;
	glutPostRedisplay();
	glutTimerFunc(30, time_function, 0);
	}
	else if ( key == 'a' ){
		move_left(); //move left
	}
	else if ( key == 'd' ){
		move_right(); //move right
	}
	if (stop_counter == false){
		glutPostRedisplay();
	}
}

void reshape_window_function(int width, int height){
	//set the coordinates and size of the viewing area on the window
	glViewport(0, 0, width, height);
	// start modifying the projection matrix
	glMatrixMode(GL_PROJECTION);
	//glMatrixMode(GL_MODELVIEW);
	// reset the matrix
	glLoadIdentity();
	// set the displayed area
	float ratio_of_width_to_height = ((float) width) / height; //aspect ratio_of_width_to_height
	if (width > height){
		glOrtho(-draw_width * ratio_of_width_to_height, draw_width * ratio_of_width_to_height, -draw_height, draw_height, -1, 1);
	}
	else{
		glOrtho(-draw_width, draw_width, -draw_height / ratio_of_width_to_height, draw_height / ratio_of_width_to_height, -1, 1);
	}
	//set the default buffer color
	glClearColor(0, 0, 0, 1);
}

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(1000, 800);
   glutInitWindowPosition (200, 0);
   glutCreateWindow("NoFall");
   init();
   glutReshapeFunc(reshape_window_function);
   glutKeyboardFunc(keyboard_function);
   glutDisplayFunc(disp);
   glutTimerFunc(50, time_function, 0);
   glutMainLoop();
   return 0;
}