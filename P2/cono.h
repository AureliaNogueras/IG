#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>
#include "objetos_B2.h"

//*************************************************************************
// clase cono
//*************************************************************************

class _cono: public _triangulos3D{
public:

	_cono(float radio=1,float altura=1, int num=10);
};
