#ifndef STUDENT_H
#define STUDENT_H
#include <QString>

class Student
{
public:

    //Konstruktor
    Student(QString i_imie, QString i_nazw,int i_nrAlb,double i_srednia1,double i_srednia2);

    //Destruktor
    ~Student();


    //Settery
    void setImie( QString i_imie);
    void setNazwisko(QString i_nazw);
    void setNr_Albumu(int i_nrAlb);
    void setSrednia1(double i_srednia);
    void setSrednia2(double i_srednia);
    void obliczDodatkowe();
    void setOcena(double i_ocena);
    //Gettery
    QString getImie(){return imie;}
    QString getNazwisko(){return nazwisko;}
    int getNr_Albumu(){return nr_Albumu;}
    int getIle_dodatkowych(){return ilosc_dodatkowych;}
    double getSrednia1(){return srednia1;}
    double getSrednia2(){return srednia2;}
    int oblicz_ilosc_pytan();
    double getOcena(){return ocena;}
private:
    QString imie;
    QString nazwisko;
    int nr_Albumu;
    int ilosc_dodatkowych=0;
    double srednia1;
    double srednia2;
    double ocena;;
};

#endif // STUDENT_H
