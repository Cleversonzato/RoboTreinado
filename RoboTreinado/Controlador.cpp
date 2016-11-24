#include "stdafx.h"
#include "moc_Controlador.cpp"
#include "Controlador.h"


void Controlador::iniciaJanela(QWidget* janela, QVBoxLayout* centraliza) {
	janela = new QWidget; //note que não é necessário desalocar pois o QT faz isso implicitamente)
	janela->setMinimumSize(400, 400);
	centraliza = new QVBoxLayout;
	janela->setLayout(centraliza);
	janela->show();
}


Controlador::Controlador()
{	
}


Controlador::~Controlador()
{
}


void Controlador::slotMudaMenu()
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
	else if (selecaoInicial1->isChecked()) {
		menuAtual->close();
		selecaoInicial1 = 0;
		selecaoInicial2 = 0;
		menuTreinar();
	}

}

void Controlador::escolhePasta()
{
	*IU::caminhoFotos = QFileDialog::getExistingDirectory(this, tr("Escolha a PASTA onde se encontram os arquivos"));
	IU::caminho->setText(*caminhoFotos);


}

void IU::cliqueMudaMenu(QPushButton* botao)
{

	connect(botao, &QPushButton::released, this, &IU::slotMudaMenu);

}

void IU::cliqueSair(QPushButton* sair)
{
	QObject::connect(sair, &QPushButton::released, QApplication::instance(), QApplication::quit);
}


std::string IU::pegaDiretorio()
{
	std::string temp, temp2;
	temp = caminhoFotos->toLocal8Bit().constData();

	for (int i = 0; i < temp.length(); i++) {
		if (temp[i] == '/') {
			temp[i] = '\\';
			temp2 = temp.substr(i);
			temp = temp.substr(0, i + 1);
			temp = temp + temp2;
		}
	}

	std::cout << temp;
	return (temp);

};

void cliqueContinuar(QPushButton* confirma)
{
QObject::connect(confirma, &QPushButton::released, dadosProntos);
}