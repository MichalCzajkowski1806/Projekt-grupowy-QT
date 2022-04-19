#include "pytanie.h"
#include <QFile>
#include <QDebug>

Pytanie::Pytanie(int i,QString tr)
{
    setBlok(i);
    setTresc(tr);
}

Pytanie::~Pytanie(){}

void Pytanie::setBlok(int i){ blok=i; }
void Pytanie::setTresc(QString tr){ tresc=tr; }

