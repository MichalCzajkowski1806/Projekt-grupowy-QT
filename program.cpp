#include "program.h"
#include "mainwindow.h"
#include <QDebug>
#include <QFileDialog>
Program::Program(QObject *parent) : QObject(parent)
{
    data=new Dane();
}


int Program::oknoWyboru_Przedmiotu()
{
    SubjectDialog Dialog;
    Dialog.setModal(true);
    int temp= Dialog.exec();
    return temp;

}

void Program::usunUczestnika(int i_index)
{
    data->zapiszWynik(i_index);
    data->usunUczestnika(i_index);
}



void Program::zwrocUczestnika(int index)
{
    Student* temp=data->getUczestnik(index);
    GUI->wczytajUczestnika(temp);
}


void Program::wczytajUczestnikow()
{   
    QString fileName= QFileDialog::getOpenFileName(nullptr,"Wybierz plik","","Plik tekstowy (*.txt)");
    data->wczytajUczestnikow(fileName);
    ustawComboBox();

}

void Program::wczytajPytania()
{
    QString fileName= QFileDialog::getOpenFileName(nullptr,"Wybierz plik","","Plik tekstowy (*.txt)");
    data->wczytajPytania(fileName);
}

void Program::ustawComboBox()
{
    GUI->wyczyscComboBox();
    data->getLista_Uczestnikow();
    for(auto elem :  data->getLista_Uczestnikow())
    {

        GUI->ustawComboBox(elem->getImie()+" "+elem->getNazwisko());
    }
}





QVector <Pytanie*> Program::losujPytania(int ile_blok1,int ile_blok2,int ile_blok3,int ileSrednie,int ileZaawansowane)
{
    QVector <Pytanie*>wylosowanePytania= data->losujPytania(ile_blok1, ile_blok2, ile_blok3,ileSrednie, ileZaawansowane);
    return wylosowanePytania;
}

void Program::ustawOcene(int i_index,double i_ocena)
{
    data->ustawOcene(i_index,i_ocena);
}

void Program::zapiszWynik(int i_index){ data->zapiszWynik(i_index); }

