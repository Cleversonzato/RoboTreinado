#include "stdafx.h"
#include "IU.h"
#include "moc_IU.cpp"
#include <iostream>


IU::IU()
{	
	menuSelecionar();
}


IU::~IU()
{
}

void IU::menuSelecionar()
{
	//inicializanção dos widgets 	
	QWidget *menuInicial = new QWidget(IU::janela);
	IU::menuAtual = menuInicial;
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
	centraliza->addWidget(menuInicial);
	centraliza->setAlignment(menuInicial, Qt::AlignHCenter);
	QVBoxLayout *organizaSelecao = new QVBoxLayout;
	menuInicial->setLayout(organizaSelecao);		
	organizaSelecao->addWidget(moldura);
	organizaSelecao->setAlignment(moldura, Qt::AlignHCenter);
	organizaSelecao->addWidget(IU::selecaoInicial1);
	organizaSelecao->setAlignment(IU::selecaoInicial1, Qt::AlignHCenter);
	organizaSelecao->addWidget(IU::selecaoInicial2);
	organizaSelecao->setAlignment(IU::selecaoInicial2, Qt::AlignHCenter);
	QHBoxLayout *organizaBotao = new QHBoxLayout;
	organizaSelecao->addLayout(organizaBotao);
	organizaSelecao->setAlignment(organizaBotao, Qt::AlignHCenter);
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
	IU::menuAtual = menuTreinar;
	QRadioButton *positivo = new QRadioButton("Banco de imagens positvas");
	QRadioButton *negativo = new QRadioButton("Banco de imagens negativas");
	QPushButton *pasta = new QPushButton("Alterar");
	pasta->setMaximumSize(150, 25);
	QPushButton *confirma = new QPushButton("Comece!");
	confirma->setMaximumSize(500, 25);
	QPushButton *voltar = new QPushButton("Voltar");
	voltar->setMaximumSize(150, 25);
	QPushButton *sair = new QPushButton("Sair");
	voltar->setMaximumSize(150, 25);	

	//layout
	IU::centraliza->addWidget(menuTreinar);
	IU::centraliza->setAlignment(menuTreinar, Qt::AlignHCenter);
	QVBoxLayout *organizaTreino = new QVBoxLayout;
	organizaTreino->setAlignment(Qt::AlignHCenter);
	menuTreinar->setLayout(organizaTreino);
	QHBoxLayout *organizaCaminhoT = new QHBoxLayout;
	organizaTreino->addLayout(organizaCaminhoT);
	organizaCaminhoT->setContentsMargins(0, 0, 0, 20);
	organizaCaminhoT->addWidget(pasta);
	organizaCaminhoT->addWidget(caminho);

	organizaTreino->addWidget(positivo);
	organizaTreino->addWidget(negativo);
	organizaTreino->addWidget(confirma);
	QHBoxLayout *organizaBotao = new QHBoxLayout;
	organizaTreino->addLayout(organizaBotao);
	organizaBotao->setContentsMargins(0, 40, 0, 0);
	organizaBotao->addWidget(voltar);
	organizaBotao->addWidget(sair);

	//logica dos botões
	cliqueMudaMenu(voltar);
	cliqueSair(sair);
	
	QObject::connect(pasta, &QPushButton::released, this, &IU::escolhePasta);


	menuTreinar->show();

}

void IU::menuAvaliar()
{
	//qwidgets
	QWidget *menuAvaliar = new QWidget(IU::janela);
	IU::menuAtual = menuAvaliar;
	QRadioButton *positivo = new QRadioButton("Teste com imagens positvas");
	QRadioButton *negativo = new QRadioButton("Teste com imagens negativas");
	QPushButton *pasta = new QPushButton("Alterar");
	pasta->setMaximumSize(150, 25);
	QPushButton *confirma = new QPushButton("Comece!");
	confirma->setMaximumSize(500, 25);
	QPushButton *voltar = new QPushButton("Voltar");
	voltar->setMaximumSize(150, 25);
	QPushButton *sair = new QPushButton("Sair");
	voltar->setMaximumSize(150, 25);

	//layout
	IU::centraliza->addWidget(menuAvaliar);
	IU::centraliza->setAlignment(menuAvaliar, Qt::AlignHCenter);
	QVBoxLayout *organizaTreino = new QVBoxLayout;
	organizaTreino->setAlignment(Qt::AlignHCenter);
	menuAvaliar->setLayout(organizaTreino);
	QHBoxLayout *organizaCaminhoT = new QHBoxLayout;
	organizaTreino->addLayout(organizaCaminhoT);
	organizaCaminhoT->setContentsMargins(0, 0, 0, 20);
	organizaCaminhoT->addWidget(pasta);
	organizaCaminhoT->addWidget(caminho);

	organizaTreino->addWidget(positivo);
	organizaTreino->addWidget(negativo);
	organizaTreino->addWidget(confirma);
	QHBoxLayout *organizaBotao = new QHBoxLayout;
	organizaTreino->addLayout(organizaBotao);
	organizaBotao->setContentsMargins(0, 40, 0, 0);
	organizaBotao->addWidget(voltar);
	organizaBotao->addWidget(sair);

	//logica dos botões
	cliqueMudaMenu(voltar);
	cliqueSair(sair);

	QObject::connect(pasta, &QPushButton::released, this, &IU::escolhePasta);


	menuAvaliar->show();
}



