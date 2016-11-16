#pragma once
#include <QtCore\qobject.h>
#include <QtWidgets\qapplication.h>
#include <QtWidgets\qwidget.h>
#include <QtWidgets\qradiobutton.h>
#include <QtWidgets\qpushbutton.h>
#include <QtWidgets\qboxlayout.h>
#include <QtWidgets\qlabel.h>

 


/*classe de interface do usuário */

class IU : public QWidget
{
	Q_OBJECT
public:
	IU();
	~IU();
		
private:
	QWidget* janela; //janela de IU principal/mãe
	QWidget* menu; //janela de menu
	QRadioButton *selecaoInicial1;
	QRadioButton *selecaoInicial2;

	void menuInicial();
	void menuTreinar();
	void menuAvaliar();
	
private slots:
	void slotProximo();

};
