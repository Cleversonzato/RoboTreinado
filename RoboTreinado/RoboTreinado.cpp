// RoboTreinado.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <QtWidgets\qapplication.h>

#include "MenuInicial.h"



int main(int argc, char *argv[])
{
	
	QApplication treinamento(argc, argv);
	MenuInicial *comece = new MenuInicial;

	return treinamento.exec();

}