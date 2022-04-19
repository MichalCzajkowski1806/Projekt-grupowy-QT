#ifndef DANE_H
#define DANE_H
#include "student.h"
#include "pytanie.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>

class Dane
{
public:
    Dane();


    void wczytajUczestnikow(QString i_fileName);
    void wczytajPytania(QString i_fileName);
    QVector <Pytanie*> losujPytania(int ile_blok1,int ile_blok2,int ile_blok3,int ileSrednie,int ileZaawansowane);



    int getIloscUczestnikow();
    Student* getUczestnik(int i_index);
    QVector <Student*> getLista_Uczestnikow();


    void usunUczestnika(int i_index);
    void ustawOcene(int i_index,double i_ocena);

    void zapiszWynik(int i_index);

private:

    QVector <Student*> uczestnicy;
    QVector <Pytanie*>pytaniaB1;
    QVector <Pytanie*>pytaniaB2;
    QVector <Pytanie*>pytaniaB3;
    QVector <Pytanie*>pytaniaSrednie;
    QVector <Pytanie*>pytaniaZaawansowane;




};

#endif // DANE_H
