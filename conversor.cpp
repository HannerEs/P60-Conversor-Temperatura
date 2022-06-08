#include "conversor.h"
#include "ui_conversor.h"

Conversor::Conversor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Conversor)
{
    ui->setupUi(this);
    // conectar el dial a centighrados con el slot de esta clase
    connect(ui->inCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2fahr(int)));
    connect(ui->inFahr, SIGNAL(valueChanged(int)),
            this, SLOT(cent2cent(int)));
}

Conversor::~Conversor()
{
    delete ui;
}

void Conversor::cent2fahr(int grados)
{
    int f = (grados * 9.0/5) +32;
    ui->inFahr->setValue(f);
}

void Conversor::fahr2cent(int grados)
{
    int c = (grados -32) * 5.0/9;
    ui->inCent->setValue(c);
}

