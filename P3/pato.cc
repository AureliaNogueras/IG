#include "pato.h"

//************************************************************************
// objeto articulado: pato
//************************************************************************

_cabeza::_cabeza()
{
// perfil para la cabeza
vector<_vertex3f> perfil;
_vertex3f aux;
aux.x=0.01;aux.y=-0.075;aux.z=0.0;
perfil.push_back(aux);
aux.x=0.01;aux.y=0.075;aux.z=0.0;
perfil.push_back(aux);
pelo.parametros(perfil,12,1);
altura=0.5;
};

void _cabeza::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{

glPushMatrix();
glTranslatef(-0.125,0.125,0.25);
glScalef(0.05,0.05,0.05);
ojo_izda.draw(modo, 0, 0, 0, 0, 0, 0.2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(0.125,0.125,0.25);
glScalef(0.05,0.05,0.05);
ojo_dcha.draw(modo, 0, 0, 0, 0, 0, 0.2, grosor);
glPopMatrix();

glPushMatrix();
glScalef(0.5,altura,0.5);
cabeza.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0,0.0,0.25+0.1);
glScalef(0.2,0.05,0.2);
pico_arriba.draw(modo, 1, 0.5, 0, 1, 1, 0, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0,0.075+altura/2,0.125);
pelo.draw(modo, 0, 0, 0, 0, 0, 0.2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(0.1,0.075+altura/2,0.125);
pelo.draw(modo, 0, 0, 0, 0, 0, 0.2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.1,0.075+altura/2,0.125);
pelo.draw(modo, 0, 0, 0, 0, 0, 0.2, grosor);
glPopMatrix();
}

//************************************************************************

_pico::_pico()
{

};

void _pico::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
glPushMatrix();
glTranslatef(0.0,-0.05,0.25+0.1);
glScalef(0.2,0.05,0.2);
pico_abajo.draw(modo, 1, 0.5, 0, 1, 1, 0, grosor);
glPopMatrix();

}

//************************************************************************

_cuello::_cuello()
{
altura = 0.2;
};

void _cuello::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
glPushMatrix();
glScalef(0.2,0.2,0.2);
cuello.draw(modo, 1, 1, 0, 1, 0.5, 0, grosor);
glPopMatrix();

}

//************************************************************************

_tronco::_tronco()
{
altura=0.5;


};

void _tronco::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
glPushMatrix();
glScalef(0.5,0.5,0.75);
tronco.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(0,0.25,-0.75/2.0+0.1);
glScalef(0.5,0.2,0.2);
cola.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();


}
//************************************************************************

_ala_izda::_ala_izda()
{
};

void _ala_izda::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
glPushMatrix();
glTranslatef(-0.25-0.175,0.1,0);
glScalef(0.35,0.05,0.2);
ala_izda.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();


}

//************************************************************************

_ala_dcha::_ala_dcha()
{
};

void _ala_dcha::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{

glPushMatrix();
glTranslatef(0.25+0.175,0.1,0);
glScalef(0.35,0.05,0.2);
ala_dcha.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

}
//************************************************************************

_patas::_patas()
{
// perfil para una pata
vector<_vertex3f> perfil;
_vertex3f aux;
aux.x=0.12;aux.y=-0.075;aux.z=0.0;
perfil.push_back(aux);
aux.x=0.1;aux.y=0.075;aux.z=0.0;
perfil.push_back(aux);
pata.parametros(perfil,12,1);
altura = 0.15;
};

void _patas::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
glPushMatrix();
pata.draw(modo, 1, 0.5, 0, 1, 1, 0, grosor);
glPopMatrix();

}


//************************************************************************

_pato::_pato()
{
giro_cabeza=0.0;
giro_cabeza_max=65.0;
giro_cabeza_min=-65.0;

giro_agachar_cabeza=0.0;
giro_agachar_max=25.0;
giro_agachar_min=-25.0;

giro_pico=0.0;
giro_pico_max=25.0;
giro_pico_min=0.0;

giro_ala_izda=0.0;
giro_ala_izda_max=15.0;
giro_ala_izda_min=-15.0;

giro_ala_dcha=0.0;
giro_ala_dcha_max=15.0;
giro_ala_dcha_min=-15.0;
};

void _pato::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
glPushMatrix();

cuerpo.draw(modo,r1, g1, b1, r2, g2, b2, grosor);

glPushMatrix();
glRotatef(giro_ala_izda,0,0,1);
ala_izda.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glRotatef(giro_ala_dcha,0,0,1);
ala_dcha.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.125,(-cuerpo.altura-patas.altura)/2.0,0.0);
patas.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(0.125,(-cuerpo.altura-patas.altura)/2.0,0.0);
patas.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0,(cuerpo.altura+cuello.altura)/2.0,0.275);
cuello.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0,cuello.altura+(parte_superior.altura+cuerpo.altura)/2.0,0.275);
glRotatef(giro_cabeza,0,1,0);
glRotatef(giro_agachar_cabeza,1,0,0);
parte_superior.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0,cuello.altura+(parte_superior.altura+cuerpo.altura)/2.0,0.275);
glRotatef(giro_cabeza,0,1,0);
glRotatef(giro_agachar_cabeza,1,0,0);
glRotatef(giro_pico,1,0,0);
pico.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();



glPopMatrix();

};




