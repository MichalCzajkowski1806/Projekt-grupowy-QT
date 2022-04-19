#include "dane.h"
#include <QDebug>
#include <QFileDialog>
Dane::Dane()
{
    QTime time = QTime::currentTime();
    srand((uint)time.msec());
}
void Dane::wczytajUczestnikow(QString i_fileName)
{

    uczestnicy.clear();
    QFile egzaminowani;
    egzaminowani.setFileName(i_fileName);

    if(egzaminowani.open(QIODevice::ReadOnly)){

        QTextStream dane(&egzaminowani);

        while(!dane.atEnd()){

            QString linia = dane.readLine();

            QStringList temp = linia.split(";");




            if(temp.size()==5){
                Student* uczestnik = new Student(temp[0],temp[1],temp[2].toInt(),temp[3].toDouble(),temp[4].toDouble());
                uczestnicy.push_back(uczestnik);
            }
            else{

                Student* uczestnik = new Student(temp[0],temp[1],temp[2].toInt(),temp[3].toDouble(),0.0);
                uczestnicy.push_back(uczestnik);
            }
        }

        //temp[0]Imie
        //temp[1]Nazwisko
        //temp[2]nr albumu
        //temp[3]srednia 1 sem
        //temp[4]srednia 2 sem



    }
    egzaminowani.close();
}

void Dane::wczytajPytania(QString i_fileName)
{
    pytaniaB1.clear();
    pytaniaB2.clear();
    pytaniaB3.clear();
    pytaniaZaawansowane.clear();
    pytaniaSrednie.clear();

    QFile pytania;
    pytania.setFileName(i_fileName);

    if(pytania.open(QIODevice::ReadOnly)){

        QTextStream dane(&pytania);

        while(!dane.atEnd()){

            QString linia = dane.readLine();

            QStringList temp = linia.split(";");

            Pytanie* pytanie=new Pytanie(temp[0].toInt(),temp[1]);
            //temp[0] numer bloku
            //temp[1] tresc pytania


            switch(pytanie->getBlok())
            {
            case 1:
                pytaniaB1.push_back(pytanie);
                break;

            case 2:
                pytaniaB2.push_back(pytanie);
                break;

            case 3:
                pytaniaB3.push_back(pytanie);
                break;

            case 4:
                pytaniaZaawansowane.push_back(pytanie);
                break;

            case 5:
                pytaniaSrednie.push_back(pytanie);
                break;
            }

        }
    }

    pytania.close();

}

QVector <Pytanie*> Dane::losujPytania(int ile_blok1,int ile_blok2,int ile_blok3,int ileSrednie,int ileZaawansowane)
{      
    QVector <Pytanie*>wylosowanePytania;

    for(int i=0;i<ile_blok1;i++){
        int max=pytaniaB1.size();
        int index= rand() % max--;
        bool znaleziono = false;
        for(Pytanie* pyt:wylosowanePytania){
            if(pytaniaB1[index]==pyt){
                ile_blok1++;
                znaleziono = true;
                break;
            }
        }

        if(znaleziono == false){
            wylosowanePytania.push_back(pytaniaB1[index]);
            std::swap(pytaniaB1[index],pytaniaB1[max]);
        }
    }


    for(int i=0;i<ile_blok2;i++){
        int max=pytaniaB2.size();
        int index= rand() % max--;
        bool znaleziono = false;
        for(Pytanie* pyt:wylosowanePytania){
            if(pytaniaB2[index]==pyt){
                ile_blok2++;
                znaleziono = true;
                break;
            }
        }
        if(znaleziono == false){
            wylosowanePytania.push_back(pytaniaB2[index]);
            std::swap(pytaniaB2[index],pytaniaB2[max]);
        }
    }

    for(int i=0;i<ile_blok3;i++){
        int max=pytaniaB3.size();
        int index= rand() % max--;
        bool znaleziono = false;
        for(Pytanie* pyt:wylosowanePytania){
            if(pytaniaB3[index]==pyt){
                ile_blok3++;
                znaleziono = true;
                break;
            }
        }
        if(znaleziono == false){
            wylosowanePytania.push_back(pytaniaB3[index]);
            std::swap(pytaniaB3[index],pytaniaB3[max]);
        }
    }

    for(int i=0;i<ileZaawansowane;i++){
        int max=pytaniaZaawansowane.size();
        int index= rand() % max--;
        bool znaleziono = false;
        for(Pytanie* pyt:wylosowanePytania){
            if(pytaniaZaawansowane[index]==pyt){
                ileZaawansowane++;
                znaleziono = true;
                break;
            }
        }
        if(znaleziono == false){
            wylosowanePytania.push_back(pytaniaZaawansowane[index]);
            std::swap(pytaniaZaawansowane[index],pytaniaZaawansowane[max]);
        }
    }

    for(int i=0;i<ileSrednie;i++){
        int max=pytaniaSrednie.size();
        int index= rand() % max--;
        bool znaleziono = false;
        for(Pytanie* pyt:wylosowanePytania){
            if(pytaniaSrednie[index]==pyt){
                ileSrednie++;
                znaleziono = true;
                break;
            }
        }
        if(znaleziono == false){
            wylosowanePytania.push_back(pytaniaSrednie[index]);
            std::swap(pytaniaSrednie[index],pytaniaSrednie[max]);
        }
    }

    return wylosowanePytania;
}

int Dane::getIloscUczestnikow(){return uczestnicy.size();}

Student *Dane::getUczestnik(int i_index){return uczestnicy[i_index];}

QVector<Student *> Dane::getLista_Uczestnikow(){return uczestnicy;}

void Dane::usunUczestnika(int i_index)
{
    delete uczestnicy[i_index];
    uczestnicy.removeAt(i_index);
}
void Dane::ustawOcene(int i_index, double i_ocena){ uczestnicy[i_index]->setOcena(i_ocena); }

void Dane::zapiszWynik(int i_index)
{


    QFile zdali("./Wyniki/zdali.txt");
    QFile nie_zdali("./Wyniki/nie_zdali.txt");


    QDir wyniki("./Wyniki");

    if (!wyniki.exists()){
        wyniki.mkdir(wyniki.absolutePath());
    }




    if(zdali.open(QIODevice::Append)&&nie_zdali.open(QIODevice::Append)){


        QTextStream outStream_zdali(&zdali);
        QTextStream outStream_nie_zdali(&nie_zdali);



        if(uczestnicy[i_index]->getOcena()>=3.0){

            outStream_zdali << uczestnicy[i_index]->getImie() + " " + uczestnicy[i_index]->getNazwisko() + " "
                               + QString::number(uczestnicy[i_index]->getNr_Albumu()) + " "
                               + "Ocena : "+ QString::number(uczestnicy[i_index]->getOcena())+'\n'; //  +getOcena() ;

        }
        else{

            outStream_nie_zdali << uczestnicy[i_index]->getImie() + ";"
                                   + uczestnicy[i_index]->getNazwisko() + ";"
                                   +QString::number(uczestnicy[i_index]->getNr_Albumu())+ ";"
                                   + QString::number(uczestnicy[i_index]->getSrednia1())+ ";"
                                   + QString::number(uczestnicy[i_index]->getSrednia2()) + '\n';

        }
    }


    zdali.close();
    nie_zdali.close();

}




