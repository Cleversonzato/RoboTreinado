#pragma once
#include <QtCore\qobject.h>
#include <QtWidgets\qwidget.h>
#include <QtWidgets\QVBoxLayout>
#include <QtWidgets\qpushbutton.h>

//Classe mãe para controla o programa orientado a eventos
class Controlador :	public QWidget
{
	Q_OBJECT
public:
	Controlador();
	~Controlador();

protected:
	static void iniciaJanela(QWidget*, QVBoxLayout*); //inicializa a janela principal

protected slots:	
	
	void slotMudaMenu();
	void escolhePasta();
	QVBoxLayout* centraliza;
	void cliqueMudaMenu(QPushButton*);
	void cliqueSair(QPushButton*);
	
	//void cliqueContinuar(QPushButton*);
	
};

