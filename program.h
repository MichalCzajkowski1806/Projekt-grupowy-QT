#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>
#include "dane.h"
#include "subjectdialog.h"
class MainWindow;
class SubjectDialog;

class Program : public QObject
{
    Q_OBJECT
public:
    explicit Program(QObject *parent = nullptr);
    void setGUI(MainWindow *ui= nullptr){GUI = ui;}


    void wczytajUczestnikow();
    void wczytajPytania();
    void ustawOcene(int i_index,double i_ocena);

    void zwrocUczestnika(int index);
    QVector <Pytanie*> losujPytania(int ile_blok1,int ile_blok2,int ile_blok3,int ileSrednie,int ileZaawansowane );

      //Okno wyboru przedmiotu do egzaminowania
    int oknoWyboru_Przedmiotu();

    void usunUczestnika(int i_index);



    void otworzEgzamin(QString przedmiot);

    void ustawComboBox();   //Dodaje uczestników do comboBoxa
    void zapiszWynik(int i_index);
private:
    MainWindow *GUI= nullptr;
    Dane *data; //Instancja warstwy danych
    int index=0;

};

#endif // PROGRAM_H
