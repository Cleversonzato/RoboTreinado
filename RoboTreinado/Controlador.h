#pragma once
#include <QtCore\qobject.h>
#include <QtWidgets\qwidget.h>
#include <QtWidgets\QVBoxLayout>
#include <QtWidgets\qfiledialog.h>
#include <string>

//Classe m�e para controla o programa orientado a eventos
class Controlador :	public QWidget
{
	Q_OBJECT
public:
	Controlador();
	~Controlador();

	static QVBoxLayout *dentroDaJanela; //layout da janela principal no qual ser�o colocados todos os menus

private:
	static void iniciaJanela(); //inicializador da janela principal

protected slots:	
	
	void slotMudaMenu();
	void escolhePasta();
	QVBoxLayout* centraliza;
	void cliqueMudaMenu(QPushButton*);
	void cliqueSair(QPushButton*);
	
	//void cliqueContinuar(QPushButton*);
	
};

