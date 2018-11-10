#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

// Coordenadas Monigote
float copaSombrero[4][3] = {{-0.2,0.75,0.0},{0.2,0.75,0.0},{0.2,0.95,0.0},{-0.2,0.95,0.0}};
float alaSombrero[4][3] = {{-0.3,0.55,0.0},{0.3,0.55,0.0},{0.3,0.75,0.0},{-0.3,0.75,0.0}};
float caraMonigote[4][3] = {{-0.2,0.0,0.0},{0.2,0.0,0.0},{0.2,0.55,0.0},{-0.2,0.55,0.0}};
float orejaDerecha[4][3] = {{0.2,0.25,0.0},{0.25,0.25,0.0},{0.25,0.45,0.0},{0.2,0.45,0.0}};
float orejaIzda[4][3] = {{-0.25,0.25,0.0},{-0.2,0.25,0.0},{-0.2,0.45,0.0},{-0.25,0.45,0.0}};
float nariz[3][3] = {{-0.05,0.3,0.0},{0.05,0.3,0.0},{0.0,0.4,0.0}};
float interiorBoca[4][3] = {{-0.1,0.08,0.0},{0.1,0.08,0.0},{0.1,0.22,0.0},{-0.1,0.22,0.0}};
float cuello[4][3] = {{-0.1,-0.15,0.0},{0.1,-0.15,0.0},{0.1,0.0,0.0},{-0.1,0.0,0.0}};
float bigoteDerecho[3][3] = {{0.25,0.22,0.0},{0.05,0.24,0.0},{0.05,0.26,0.0}};
float bigoteIzdo[3][3] = {{-0.25,0.22,0.0},{-0.05,0.24,0.0},{-0.05,0.26,0.0}};
float perilla[3][3] = {{0.0,0.02,0.0},{0.05,0.04,0.0},{-0.05,0.04,0.0}};

void Ejes (int width)
{   
    glLineWidth(width);
    glBegin(GL_LINES);
       glColor3f(1.0,0.0,0.0);
       glVertex3f(-1.0,0.0,0.0);
       glVertex3f(1.0,0.0,0.0);
       glColor3f(0.0,1.0,0.0);
       glVertex3f(0.0,-1.0,0.0);
       glColor3f(1.0,1.0,0.0);
       glVertex3f(0.0,1.0,0.0);   
    glEnd();
   
       
}

// Dibujar polígono
void PoligonoSolido (float v[][3], int n, GLenum modo){
    int i;
    glPolygonMode(GL_FRONT_AND_BACK, modo);
    glBegin(GL_POLYGON);
    for (i=0;i<n;i++)
        glVertex3f(v[i][0],v[i][1],v[i][2]);
    glEnd();
}


void Circulo (GLfloat radio, GLfloat cx, GLfloat cy, GLint n, GLenum modo){
    int i;

    if (modo == GL_LINE)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else if (modo == GL_FILL)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    else
        glPolygonMode (GL_FRONT_AND_BACK, GL_POINT);

    glBegin(GL_POLYGON);
        for (i = 0; i < n; i++)
            glVertex3f(cx+radio*cos(2.0*M_PI*i/n), cy+radio*sin(2.0*M_PI*i/n), 0.0);
    glEnd();

}


void Monigote ()
{
  
 
// cara
   glLineWidth(1);
   glColor3f(1.0,0.8,0.6);
   PoligonoSolido(caraMonigote,4,GL_FILL);
   
   glColor3f(0.0,0.0,0.0);
   PoligonoSolido(caraMonigote,4,GL_LINE);

// sombrero
    // ala

    PoligonoSolido(alaSombrero,4,GL_FILL);

    // copa

    PoligonoSolido(copaSombrero,4,GL_FILL);

// orejas
    glColor3f(1.0,0.8,0.6);
    PoligonoSolido(orejaIzda,4,GL_FILL);
    PoligonoSolido(orejaDerecha,4,GL_FILL);

    glColor3f(0.0,0.0,0.0);
    PoligonoSolido(orejaIzda,4,GL_LINE);
    PoligonoSolido(orejaDerecha,4,GL_LINE);

// ojos

    glColor3f(1.0,1.0,1.0);
    Circulo(0.07,-0.1,0.45,20, GL_FILL);
    Circulo(0.07,0.1,0.45,20, GL_FILL);

    glColor3f(0.0,0.0,0.0);

    Circulo(0.07,-0.1,0.45,20, GL_LINE);
    Circulo(0.07,0.1,0.45,20, GL_LINE);

    Circulo(0.02,-0.1,0.45,20, GL_FILL);
    Circulo(0.02,0.1,0.45,20, GL_FILL);

// nariz

    PoligonoSolido(nariz,3,GL_LINE);

// boca

    Circulo(0.07,-0.1,0.15,20, GL_FILL);
    Circulo(0.07,0.1,0.15,20, GL_FILL);
    glColor3f(1.0,0.0,0.0);
    PoligonoSolido(interiorBoca,4,GL_FILL);   

// cuello

   glColor3f(1.0,0.8,0.6);
   PoligonoSolido(cuello,4,GL_FILL);
   glColor3f(0.0,0.0,0.0);
   PoligonoSolido(cuello,4,GL_LINE);

// bigote
   PoligonoSolido(bigoteIzdo,3,GL_FILL);
   PoligonoSolido(bigoteDerecho,3,GL_FILL);
  
// perilla

   PoligonoSolido(perilla,3,GL_FILL);


    
}


static void Init( )
{

   glShadeModel( GL_SMOOTH); // CON FLAT mantiene un solo color
}


static void Reshape( int width, int height )
{
    glViewport(0, 0, (GLint)width, (GLint)height);
    glOrtho (-1.0, 1.0,-1.0, 1.0, -10, 10.0);
}

static void Display( )
{

  glClearColor(0.5,0.5,0.5,0.0);
  glClear( GL_COLOR_BUFFER_BIT );
   
  
   
   Ejes(6);
   Monigote();
   
   glFlush();
}


static void Keyboard(unsigned char key, int x, int y )
{
 
  if (key==27)
      exit(0);
/* if (key=="a"){
    glShadeModel(GL_FLAT);
    Display();}*/

}


int main( int argc, char **argv )
{
   glutInit(&argc,argv);
   glutInitDisplayMode( GLUT_RGB );

   glutInitWindowPosition( 20, 100 );
   glutInitWindowSize(500, 500 );
   glutCreateWindow("Practica 0 IG");


   Init();

   glutReshapeFunc(Reshape);
   glutDisplayFunc(Display);
   glutKeyboardFunc(Keyboard);
  
   glutMainLoop( );

   return 0;
}

