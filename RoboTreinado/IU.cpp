#include "stdafx.h"
#include "IU.h"
#include "moc_IU.cpp"
#include <iostream>


IU::IU():
	janela (new QWidget) //note que não é necessário desalocar pois o QT faz isso implicitamente)
{
	janela->setMinimumSize(400, 400);
	centraliza = new QVBoxLayout;
	janela->setLayout(centraliza);
	janela->show();
	caminhoFotos = new QString;
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
	QRadioButton *positivo = new QRadioButton ("Banco de imagens positvas");
	QRadioButton *negativo = new QRadioButton("Banco de imagens negativas");
	QPushButton *pasta = new QPushButton("Alterar");
	pasta->setMaximumSize(150, 25);
	QPushButton *confirma = new QPushButton("Comece!");
	confirma->setMaximumSize(500, 25);
	QPushButton *voltar = new QPushButton("Voltar");
	voltar->setMaximumSize(150, 25);
	QPushButton *sair = new QPushButton("Sair");
	voltar->setMaximumSize(150, 25);
	QLineEdit *caminho = new QLineEdit;
	caminho->setMinimumSize(200, 20);
		
	//layout
	IU::centraliza->addWidget(menuTreinar);
	IU::centraliza->setAlignment(menuTreinar, Qt::AlignHCenter);
	QVBoxLayout *organizaTreino = new QVBoxLayout;
	organizaTreino->setAlignment(Qt::AlignHCenter);
	menuTreinar->setLayout(organizaTreino);
	QHBoxLayout *organizaCaminho = new QHBoxLayout;
	organizaTreino->addLayout(organizaCaminho);
	organizaCaminho->setContentsMargins(0, 0, 0, 20);
	organizaCaminho->addWidget(pasta);
	organizaCaminho->addWidget(caminho);
	
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
	

	QObject::connect(pasta, SIGNAL(released()), this, SLOT(pegaPasta()));
	
	//caminho->repaint();
	//qApp->processEvents();
	menuTreinar->show();

}

void IU::menuAvaliar()
{
	//qwidgets
	QWidget *menuAvaliar = new QWidget(IU::janela);
	menuAvaliar->setMinimumSize(500, 400);
	IU::menuAtual = menuAvaliar;
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

void IU::pegaPasta()
{
	*IU::caminhoFotos = QFileDialog::getOpenFileName(this);		
	
}