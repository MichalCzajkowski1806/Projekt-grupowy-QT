#include "student.h"
#include <QDebug>
Student::Student(QString i_imie, QString i_nazw, int i_nrAlb,double i_srednia1,double i_srednia2)
{
    setImie(i_imie);
    setNazwisko(i_nazw);
    setNr_Albumu(i_nrAlb);
    setSrednia1(i_srednia1);
    setSrednia2(i_srednia2);
    obliczDodatkowe();
}

Student::~Student(){}

void Student::setImie(QString i_imie){ imie=i_imie; }
void Student::setNazwisko(QString i_nazw){ nazwisko=i_nazw; }
void Student::setNr_Albumu(int i_nrAlb){ nr_Albumu=i_nrAlb; }
void Student::setSrednia1(double i_srednia){ srednia1=i_srednia; }
void Student::setSrednia2(double i_srednia){ srednia2=i_srednia; }
void Student::setOcena(double i_ocena){ ocena=i_ocena; }

void Student::obliczDodatkowe()
{
    int pyt_1=0;
    int pyt_2=0;

    if(srednia1>2.0&&srednia1<=5.0){
        pyt_1 = (srednia1 - 3.0) / 0.5;
    }
    else pyt_1=0;

    if(srednia2>2.0&&srednia2<=5.0){
        pyt_2 = (srednia2 - 3.0) / 0.5;
    }else pyt_2=0;

    ilosc_dodatkowych=pyt_1+pyt_2;
}






