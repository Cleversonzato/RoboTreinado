#pragma once

//#include <QtWidgets\qapplication.h>
#include <QtWidgets\qpushbutton.h>
#include <QtWidgets\qradiobutton.h>
#include <QtWidgets\qboxlayout.h>
#include <QtWidgets\qlineedit.h>
#include <QtCore\qstring.h>
#include <QtWidgets\qlabel.h>

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
	//widgets
	QPushButton* IU::botao(QString nomeBotao);
	QRadioButton* botaoSelecao(QString nomeBotao);
	QLabel* imagem(QString localDaImagem);
	QLineEdit* diretorio();
	//layout
	QHBoxLayout naHorizontal(QWidget* torto, QHBoxLayout* alinhamento);
	QVBoxLayout naVertical(QWidget* torto, QVBoxLayout* alinhamento);

	/*QWidget* menuAtual =0; //janela de menu
	QRadioButton *selecao1 =0;
	QRadioButton *selecao2 =0;
	QVBoxLayout *centraliza;
	QString *caminhoFotos;
	QLineEdit *caminho;*/


};


