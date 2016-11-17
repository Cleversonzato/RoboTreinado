#pragma once
#include <QtCore\qobject.h>
#include <QtGui\qpaintdevice.h>
#include <QtWidgets\qapplication.h>
#include <QtWidgets\qwidget.h>
#include <QtWidgets\qradiobutton.h>
#include <QtWidgets\qpushbutton.h>
#include <QtWidgets\qboxlayout.h>
#include <QtWidgets\qlabel.h>

/*
#include <QtGui\qpainter.h>
#include <QtGui\qpaintdevice.h>
#include <QtGui\qpagedpaintdevice.h>
#include <QtGui\qpaintdevicewindow.h>
#include <QtGui\qpaintengine.h>*/



/*classe de interface do usuário */

class IU : public QWidget
{
	Q_OBJECT
public:
	IU();
	~IU();

	void menuSelecionar();
	void menuTreinar();
	void menuAvaliar();
		
private:
	QWidget* janela; //janela de IU principal/mãe
	QWidget* menuAtual =0; //janela de menu
	QRadioButton *selecaoInicial1 =0;
	QRadioButton *selecaoInicial2 =0;

	void cliqueMudaMenu(QPushButton*);
	void cliqueSair(QPushButton*);

private slots:
	void slotMudaMenu();

};
