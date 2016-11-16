#include "stdafx.h"
#include "IU.h"
#include "moc_IU.cpp"
#include <iostream>


IU::IU():
	janela (new QWidget) //note que não é necessário desalocar pois o QT faz isso implicitamente)
{
	menuInicial();
	janela->show();
}


IU::~IU()
{
}

void IU::menuInicial()
{
	//inicializanção dos widgets 	
	menu = new QWidget(janela);
	menu->setMinimumSize(500, 400);
	selecaoInicial1 = new QRadioButton("Treinar o identificador");
	selecaoInicial1->setMaximumSize(200, 30);
	selecaoInicial2 = new QRadioButton("Avaliar o identificador");
	selecaoInicial2->setMaximumSize(200, 30);
	QPushButton *continuar = new QPushButton("Continuar");
	continuar->setMaximumSize(150, 30);
	QPushButton *sair = new QPushButton("Sair");
	sair->setMaximumSize(150, 30);
	QString local = "./brain.png";
	QPixmap *imagem = new QPixmap(local);
	QLabel *moldura = new QLabel();
	moldura->setPixmap(*imagem);
	moldura->setScaledContents(true);
	moldura->setMaximumSize(300, 250);
	
	/*organização o layout*/
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

	/*Parte lógica dos botões*/
	QObject::connect(sair, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
	QObject::connect(continuar, &QPushButton::released, this, &IU::slotProximo);
	
}

void IU::slotProximo()
{
	if (selecaoInicial1->isChecked()) {
		menu->close();
		menuTreinar();
	}
	else if (selecaoInicial2->isChecked()) {
		menu->close();
		menuAvaliar();
	}
}

void IU::menuTreinar()
{
	QWidget *menuTreinar = new QWidget(IU::janela);
	menu->setMinimumSize(500, 400);
	QPushButton *voltar = new QPushButton("Sair", menuTreinar);
	voltar->setMaximumSize(150, 30);
}

void IU::menuAvaliar()
{
	QWidget *menuAvaliar = new QWidget(IU::janela);
	menu->setMinimumSize(500, 400);
	QPushButton *voltar = new QPushButton("Sair", menuAvaliar);
	voltar->setMaximumSize(150, 30);
}