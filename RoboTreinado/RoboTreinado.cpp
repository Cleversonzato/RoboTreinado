// RoboTreinado.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <QtWidgets\qapplication.h>
#include <QtGui\qpaintdevice.h>
#include <QtGui\qpixmap.h>
#include <QtGui\qguiapplication.h>
#include <QtGui\qpaintdevice.h>

#include "IU.h"
#include <iostream>


int main(int argc, char *argv[])
{
	std::cout << "1";
	QApplication treinamento(argc, argv);
	IU treinador;
	treinador.menuSelecionar();
	std::cout << "2";
	return treinamento.exec();

}