#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>
#include "objetos_B3.h"
#include "esfera.h"

//************************************************************************
// objeto articulado: pato
//************************************************************************

class _cabeza: public _triangulos3D
{
public:
       _cabeza();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

float altura;

protected:
_rotacion  pelo;
_cubo  cabeza;
_cubo pico_arriba;//pico_abajo;
_esfera ojo_izda;
_esfera ojo_dcha;
};

//************************************************************************

class _pico: public _triangulos3D
{
public:
       _pico();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

float altura;

protected:
_cubo pico_abajo;
};

//************************************************************************

class _cuello: public _triangulos3D
{
public:
       _cuello();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

float altura;

protected:
_cubo cuello;
};

//************************************************************************

class _tronco: public _triangulos3D
{
public:
       _tronco();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

float altura;

protected:
_piramide cola;
_cubo tronco; 

};

//************************************************************************

class _ala_izda: public _triangulos3D
{
public:
       _ala_izda();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

protected:
_cubo ala_izda;

};

//************************************************************************

class _ala_dcha: public _triangulos3D
{
public:
       _ala_dcha();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

protected:
_cubo ala_dcha;

};


//************************************************************************

class _patas: public _triangulos3D
{
public:
       _patas();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

float altura;

protected:
_rotacion pata;

};

//************************************************************************

class _pato: public _triangulos3D
{
public:
       _pato();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

float giro_cabeza;
float giro_cabeza_max;
float giro_cabeza_min;

float giro_agachar_cabeza;
float giro_agachar_max;
float giro_agachar_min;

float giro_pico;
float giro_pico_max;
float giro_pico_min;

float giro_ala_izda;
float giro_ala_izda_max;
float giro_ala_izda_min;

float giro_ala_dcha;
float giro_ala_dcha_max;
float giro_ala_dcha_min;

protected:
_pico pico;
_cabeza parte_superior;
_cuello cuello;
_tronco cuerpo;
_ala_izda ala_izda;
_ala_dcha ala_dcha;
_patas patas;

};




