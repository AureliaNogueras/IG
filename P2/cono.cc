#include "cono.h"

//*************************************************************************
// clase cono
//*************************************************************************

_cono::_cono(float radio, float altura, int num)
{

vector<_vertex3f> perfil;
_vertex3f aux;

// Creación del perfil del cono

aux.x=0.0; aux.y=altura/2; aux.z=0.0;
perfil.push_back(aux);
aux.x=radio; aux.y=-altura/2; aux.z=0.0;
perfil.push_back(aux);

int j;
_vertex3f vertice_aux;
_vertex3i cara_aux;

// tratamiento de los vértices


// Vértices de la base más el punto superior
vertices.resize(num+1); 
vertice_aux.x = 0.0;
vertice_aux.y = perfil[0].y;
vertice_aux.z = 0.0;
vertices[0] = vertice_aux;

for (j=1;j<num+1;j++)
  {
  vertice_aux.x=perfil[1].x*cos(2.0*M_PI*j/(1.0*num))+
                perfil[1].z*sin(2.0*M_PI*j/(1.0*num));
  vertice_aux.z=-perfil[1].x*sin(2.0*M_PI*j/(1.0*num))+
                perfil[1].z*cos(2.0*M_PI*j/(1.0*num));
  vertice_aux.y=perfil[1].y;
  vertices[j]=vertice_aux;
  }

// tratamiento de las caras 

for (j=0;j<num;j++)
  {
  cara_aux._0=((j+1)%num)+1;
  cara_aux._1=j+1;
  cara_aux._2=0;
  caras.push_back(cara_aux);
  }
  
     
 // tapa inferior
if (fabs(perfil[1].x)>0.0)
  {
    vertices.resize(num+2); 
    vertice_aux.x=0.0;
    vertice_aux.z=0.0;
    vertice_aux.y=perfil[1].y;
    vertices[num+1] = vertice_aux;
    for (j=0;j<num;j++){ 
      cara_aux._0=((j+1)%num)+1;
      cara_aux._1=j+1;
      cara_aux._2=num+1;
      caras.push_back(cara_aux);
    }
  }
 
}