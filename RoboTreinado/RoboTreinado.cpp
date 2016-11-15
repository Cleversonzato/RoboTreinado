// RoboTreinado.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <QtWidgets\qapplication.h>
#include <QtGui\qpaintdevice.h>
#include <QtGui\qpixmap.h>
#include <QtGui\qguiapplication.h>
#include <QtGui\qpaintdevice.h>

#include "IU.h"


int main(int argc, char *argv[])
{
	
	QApplication treinamento(argc, argv);
	IU treinador;


	return treinamento.exec();

}