#pragma once
#include "IU.h"
#include "Controlador.h"

//primeiro menu do programa.
//herda o layout de IU e as funcionalidades de Controlador
class MenuInicial : public IU, public Controlador
{
public:
	MenuInicial();
	~MenuInicial();
};

