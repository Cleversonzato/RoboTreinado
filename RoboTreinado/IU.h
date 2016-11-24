#pragma once

#include <QtWidgets\qapplication.h>
#include <QtWidgets\qradiobutton.h>
#include <QtWidgets\qboxlayout.h>
#include <QtWidgets\qlineedit.h>
#include <QtWidgets\qfiledialog.h>
#include <string>
//#include <algorithm>


//#include <QtCore\qcoreapplication.h>

/*
#include <QtGui\qpainter.h>
#include <QtGui\qpaintdevice.h>
#include <QtGui\qpagedpaintdevice.h>
#include <QtGui\qpaintdevicewindow.h>
#include <QtGui\qpaintengine.h>
#include <QtCore\qfile.h>
#include <QtWidgets\qlabel.h>
#include <QtGui\qpaintdevice.h>
*/


//classe de padronização do visual da interface do usuário

class IU : public QWidget
{
	
public:
	IU();
	~IU();	
		
protected:
	
	QWidget* menuAtual =0; //janela de menu
	QRadioButton *selecao1 =0;
	QRadioButton *selecao2 =0;
	QVBoxLayout *centraliza;
	QString *caminhoFotos;
	QLineEdit *caminho;


};


