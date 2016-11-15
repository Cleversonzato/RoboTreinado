#include "stdafx.h"
#include "IU.h"
#include "moc_IU.cpp"


IU::IU():
	janela (new QWidget) //note que n�o � necess�rio desalocar pois o QT faz isso implicitamente)
{
	menuInicial();
	janela->show();
}


IU::~IU()
{
}

void IU::menuInicial()
{
	//inicializan��o dos widgets 	
	QWidget *menu = new QWidget(IU::janela);
	menu->setMinimumSize(500, 400);
	QRadioButton *selecaoInicial1 = new QRadioButton("Treinar o identificador");
	selecaoInicial1->setMaximumSize(200, 30);
	QRadioButton *selecaoInicial2 = new QRadioButton("Avaliar o identificador");
	selecaoInicial2->setMaximumSize(200, 30);
	QPushButton *continuar = new QPushButton("Continuar");
	continuar->setMaximumSize(150, 30);
	QPushButton *sair = new QPushButton("Sair");
	continuar->setMaximumSize(150, 30);
	QString local = "C:/Users/cleve/Documents/Visual Studio 2015/RoboTreinado/RoboTreinado/brain.png";
	QPixmap *imagem = new QPixmap(local);
	QLabel *moldura = new QLabel();
	moldura->setPixmap(*imagem);
	moldura->setScaledContents(true);
	moldura->setMaximumSize(300, 250);
	
	/*organiza��o o layout*/
	QVBoxLayout *organizacao = new QVBoxLayout;
	organizacao->setAlignment(Qt::AlignHCenter);	
	menu->setLayout(organizacao);
	organizacao->addWidget(moldura);
	organizacao->addWidget(selecaoInicial1);
	organizacao->addWidget(selecaoInicial2);
	QHBoxLayout *organizaBotao = new QHBoxLayout;
	organizacao->addLayout(organizaBotao);
	organizaBotao->addWidget(continuar);
	organizaBotao->addWidget(sair);

	/*Parte l�gica dos bot�es*/
	QObject::connect(sair, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));

}