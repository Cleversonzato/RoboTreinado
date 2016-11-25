#pragma once
#include <QtCore\qobject.h>
#include <QtWidgets\qwidget.h>
#include <QtWidgets\QVBoxLayout>
#include <QtWidgets\qfiledialog.h>
#include <string>

//Classe mãe para controla o programa orientado a eventos
class Controlador :	public QWidget
{
	Q_OBJECT
public:
	Controlador();
	~Controlador();

protected:
	static QVBoxLayout Controlador::*centraliza; //layout da janela principal no qual serão colocados todos os menus
	static QWidget* janelaPrincipal; //inicializador da janela principal

protected slots:	
	
	void slotMudaMenu();
	void escolhePasta();
	QVBoxLayout* centraliza;
	void cliqueMudaMenu(QPushButton*);
	void cliqueSair(QPushButton*);
	
	//void cliqueContinuar(QPushButton*);
	
};

