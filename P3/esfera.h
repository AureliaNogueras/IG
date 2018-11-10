#ifndef _ESFERA
#define _ESFERA

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>
#include "objetos_B3.h"

//*************************************************************************
// clase esfera
//*************************************************************************

class _esfera: public _triangulos3D{
public:

	_esfera(float radio=1,int latitud=8, int longitud=20);
};

#endif
