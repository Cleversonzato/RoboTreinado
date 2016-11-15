#pragma once
#include <QtCore\qobject.h>
#include <QtWidgets\qapplication.h>
#include <QtWidgets\qwidget.h>
#include <QtWidgets\qradiobutton.h>
#include <QtWidgets\qpushbutton.h>
#include <QtWidgets\qboxlayout.h>
#include <QtWidgets\qlabel.h>

 


/*classe de interface do usuário */

class IU
{
	//Q_OBJECT
public:
	IU();
	~IU();
		
private:
	QWidget *janela; //janela de IU principal/mãe

	void menuInicial();

signals:
public slots:

};
