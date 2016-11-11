#pragma once
#include <QtWidgets\qwidget.h>
#include <QtCore\qcoreapplication.h>
#include <QtWidgets\qradiobutton.h>
#include <QtWidgets\qpushbutton.h>

/*classe de interface do usu�rio */

class IU
{
	Q_OBJECT
public:
	IU();
	~IU();


private:
	QWidget *janela; //janela de IU principal/m�e
	QWidget *menuInicial;
	QRadioButton *selecaoInicial;
	QPushButton *continuar;

};

