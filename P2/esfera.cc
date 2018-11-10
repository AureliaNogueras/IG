#include "esfera.h"

//*************************************************************************
// clase esfera
//*************************************************************************

_esfera::_esfera(float radio, int latitud, int longitud)
{

vector<_vertex3f> perfil;
_vertex3f aux;

// Creación del perfil

aux.x=0.0; aux.y=-1.0; aux.z=0.0;
perfil.push_back(aux);
float tam = radio/latitud;
for (float i=tam; i<radio; i=i+tam){
    aux.x = i; aux.y=-sqrt(1-aux.x*aux.x); aux.z=0.0;
    perfil.push_back(aux);
}

aux.x=radio; aux.y=0.0; aux.z=0.0;
perfil.push_back(aux);

for (float i=radio-tam; i>0; i=i-tam){
    aux.x = i; aux.y=sqrt(1-aux.x*aux.x); aux.z=0.0;
    perfil.push_back(aux);
}

aux.x=0.0; aux.y=1.0; aux.z=0.0;
perfil.push_back(aux);

_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;
int i,j;

// tratamiento de los vértices
num_aux=perfil.size()-2;
vertices.resize(num_aux*longitud+2); 

// Vértices del perfil más el superior y el inferior (sin repeticiones)

vertices[0] = perfil[0];

vertices[num_aux*longitud+1] = perfil[perfil.size()-1];

for (j=0;j<longitud;j++)
  {for (i=0;i<num_aux;i++)
     {
      vertice_aux.x=perfil[i+1].x*cos(2.0*M_PI*j/(1.0*longitud))+
                    perfil[i+1].z*sin(2.0*M_PI*j/(1.0*longitud));
      vertice_aux.z=-perfil[i+1].x*sin(2.0*M_PI*j/(1.0*longitud))+
                    perfil[i+1].z*cos(2.0*M_PI*j/(1.0*longitud));
      vertice_aux.y=perfil[i+1].y;
      vertices[i+1+j*num_aux]=vertice_aux;
     }
  }

// tratamiento de las caras 

for (j=0;j<longitud;j++)
  {for (i=1;i<num_aux;i++)
     {cara_aux._0=i+((j+1)%longitud)*num_aux;
      cara_aux._1=i+1+((j+1)%longitud)*num_aux;
      cara_aux._2=i+1+j*num_aux;
      caras.push_back(cara_aux);
      
      cara_aux._0=i+1+j*num_aux;
      cara_aux._1=i+j*num_aux;
      cara_aux._2=i+((j+1)%longitud)*num_aux;
      caras.push_back(cara_aux);
     }
  }

  // Parte superior de la esfera
  for (i=num_aux;i<(longitud*num_aux)+num_aux;i=i+num_aux){ 
      cara_aux._0=i%(num_aux*longitud)+num_aux;
      cara_aux._1=i;
      cara_aux._2=num_aux*longitud+1;
      caras.push_back(cara_aux);
  }

  // Parte inferior de la esfera
  for (i=1;i<longitud*num_aux;i=i+num_aux){ 
      cara_aux._0=(i+num_aux)%(num_aux*longitud);
      cara_aux._1=i;
      cara_aux._2=0;
      caras.push_back(cara_aux);
  }

}