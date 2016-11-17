#include "stdafx.h"
#include "IU.h"
#include "moc_IU.cpp"
#include <iostream>


IU::IU():
	janela (new QWidget) //note que não é necessário desalocar pois o QT faz isso implicitamente)
{
	janela->show();
}


IU::~IU()
{
}

void IU::menuSelecionar()
{
	//inicializanção dos widgets 	
	QWidget *menuInicial = new QWidget(janela);
	menuInicial->setMinimumSize(500, 400);
	menuAtual = menuInicial;
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
	menuInicial->setLayout(organizacao);
	organizacao->addWidget(moldura);
	organizacao->addWidget(selecaoInicial1);
	organizacao->addWidget(selecaoInicial2);
	QHBoxLayout *organizaBotao = new QHBoxLayout;
	organizacao->addLayout(organizaBotao);
	organizaBotao->addWidget(continuar);
	organizaBotao->addWidget(sair);

	/*Parte lógica dos botões*/
	cliqueSair(sair);
	cliqueMudaMenu(continuar);

	menuInicial->show();

}


void IU::menuTreinar()
{
	//qwidgets
	QWidget *menuTreinar = new QWidget(IU::janela);
	menuTreinar->setMinimumSize(500, 400);
	menuAtual = menuTreinar;
	QPushButton *voltar = new QPushButton("Voltar");
	voltar->setMaximumSize(150, 30);
	QPushButton *sair = new QPushButton("Sair");
	voltar->setMaximumSize(150, 30);

	//layout
	QHBoxLayout *organizaBotao = new QHBoxLayout;
	menuTreinar->setLayout(organizaBotao);
	organizaBotao->addWidget(voltar);
	organizaBotao->addWidget(sair);

	//logica dos botões
	cliqueMudaMenu(voltar);
	cliqueSair(sair);

	menuTreinar->show();

}

void IU::menuAvaliar()
{
	//qwidgets
	QWidget *menuAvaliar = new QWidget(IU::janela);
	menuAvaliar->setMinimumSize(500, 400);
	menuAtual = menuAvaliar;
	QPushButton *voltar = new QPushButton("Voltar");
	voltar->setMaximumSize(150, 30);
	QPushButton *sair = new QPushButton("Sair");
	voltar->setMaximumSize(150, 30);

	//layout
	QHBoxLayout *organizaBotao = new QHBoxLayout;
	menuAvaliar->setLayout(organizaBotao);
	organizaBotao->addWidget(voltar);
	organizaBotao->addWidget(sair);

	//logica dos botões
	cliqueMudaMenu(voltar);
	cliqueSair(sair);

	menuAvaliar->show();
}

void IU::cliqueMudaMenu(QPushButton* botao)
{

	connect(botao, SIGNAL(released()), this, SLOT(slotMudaMenu()));

}

void IU::cliqueSair(QPushButton* sair)
{
	QObject::connect(sair, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
}

void IU::slotMudaMenu()
{
	if (selecaoInicial1 == 0) {
		menuAtual->close();
		menuSelecionar(); 
	}
	else if (selecaoInicial2->isChecked()) {
			menuAtual->close();
			selecaoInicial1 = 0;
			selecaoInicial2 = 0;
			menuAvaliar();
	}
	else if(selecaoInicial1->isChecked()) {
		menuAtual->close();
		selecaoInicial1 = 0;
		selecaoInicial2 = 0;
		menuTreinar();
	}

}