#include "IU.h"


IU::IU() :
	janela() //note que não é necessário desalocar pois o QT faz isso implicitamente)
{
	janela->setBaseSize(620, 480);
	menuInicial = new QWidget(janela);
	selecaoInicial = new QRadioButton(menuInicial);
	continuar = new QPushButton(menuInicial);

	janela->show();
}


IU::~IU()
{
}
