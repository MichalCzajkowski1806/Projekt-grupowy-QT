#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "program.h"
#include <QTime>
#include <qglobal.h>

MainWindow::MainWindow(QWidget *parent,Program *app)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      mainApp(app)
{
    app->setGUI(this);
    ui->setupUi(this);

    ui->statusbar->showMessage("Ryta Czajkowski Bladziak");

    radio_buttony = {ui->dobra_1, ui->zla_1, ui->dobra_2, ui->zla_2, ui->dobra_3, ui->zla_3,
                     ui->dobra_4, ui->zla_4, ui->dobra_5, ui->zla_5, ui->srednia_1,
                     ui->srednia_2, ui->dobra_6, ui->zla_6, ui->srednia_3,};


    ui->pytDod->setVisible(false);
    ui->losujPytania->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->podstawowy_b1->setEnabled(false);
    ui->podstawowy_b2->setEnabled(false);
    ui->podstawowy_b3->setEnabled(false);
    ui->zaawansowany->setEnabled(false);
    ui->przyciski_zaawansowany_gora->setVisible(false);
    ui->zakoncz->setVisible(false);
    ui->sredni->setEnabled(false);


    ui->frame_dobrze_zle_2->setEnabled(false);
    ui->frame_dobrze_zle_2->hide();


    if(mainApp->oknoWyboru_Przedmiotu()==1)
        PK();
    else czyPK=0;
}

MainWindow::~MainWindow(){ delete ui;}


//Funkcja ustawiająca wyglad ekranu w zaleznosci od przedmiotu
void MainWindow::PK()
{
    czyPK=1;
    ui->blok5->setVisible(false);
    ui->sredni->setVisible(false);
    ui->buttony_4->setVisible(false);
    ui->label_3->setEnabled(false);
    ui->label_3->hide();
    ui->B5->setEnabled(false);
    ui->B5->hide();
    ui->przyciski_zaawansowany_gora->setVisible(true);
    ui->frame_dobrze_zle_2->setEnabled(true);
    ui->frame_dobrze_zle_2->show();
    ui->label_egzamin->setText("Egzamin z Programowania Komputerów");
}

void MainWindow::wczytajUczestnika(Student *i_student)
{

    ui->imie->setText(i_student->getImie()+" "+i_student->getNazwisko());
    ui->nrAlbumu->setText(QString::number(i_student->getNr_Albumu()));

    if(i_student->getSrednia2()==0.0){ ui->srednia->setText(QString::number(i_student->getSrednia1())); }
    else { ui->srednia->setText(QString::number(i_student->getSrednia1())+"/"+QString::number(i_student->getSrednia2())); }

    ui->ileDod->setText(QString::number(i_student->getIle_dodatkowych()));
    czyJest_Uczestnik=true;


    ui->B1->setRange(0, ui->ileDod->text().toInt());
    ui->B2->setRange(0, ui->ileDod->text().toInt());
    ui->B3->setRange(0, ui->ileDod->text().toInt());
    ui->B4->setRange(0, ui->ileDod->text().toInt());
    ui->B5->setRange(0, ui->ileDod->text().toInt());
    pytania = ui->ileDod->text().toInt();

}

void MainWindow::on_losujPytania_clicked()
{

    if(czyJest_Uczestnik==true&&czyWylosowano_Pytania==false){

        int pytB1= ui->B1->value()+1;
        int pytB2= ui->B2->value()+1;
        int pytB3= ui->B3->value()+1;
        int pytSrednie=ui->B5->value()+1;
        int pytZaawansowane= ui->B4->value()+1;

        if(czyPK==1){
            pytSrednie=0;
             ui->sredni->setVisible(false);
            pytZaawansowane= ui->B4->value()+2;
        }



        QVector <Pytanie*> wylosowane=mainApp->losujPytania(pytB1,pytB2,pytB3,pytSrednie,pytZaawansowane);

        for (auto elem : wylosowane) {

            switch (elem->getBlok()) {

            case 1:
                ui->blok1->append(elem->getTresc()+"\n");
                break;
            case 2:
                ui->blok2->append(elem->getTresc()+"\n");
                break;
            case 3:
                ui->blok3->append(elem->getTresc()+"\n");
                break;
            case 4:
                ui->blok4->append(elem->getTresc()+"\n");
                break;
            case 5:
                ui->blok5->append(elem->getTresc()+"\n");
                break;
            }
        }
        czyWylosowano_Pytania=true;

        ui->pytDod->setVisible(false);
        ui->comboBox->setVisible(false);
        ui->losujPytania->setVisible(false);

        ui->podstawowy_b1->setEnabled(true);
        ui->podstawowy_b2->setVisible(false);
        ui->podstawowy_b3->setVisible(false);
        ui->sredni->setVisible(false);
        ui->zaawansowany->setVisible(false);

        ui->dobra_1->setChecked(0);
        ui->dobra_2->setChecked(0);
        ui->dobra_3->setChecked(0);
        ui->dobra_4->setChecked(0);
        ui->dobra_5->setChecked(0);
    }

}

void MainWindow::ustawPytania(int arg, int tem)
{
    if (tem < arg){ pytania -= 1; }
    else if (tem > arg){ pytania += 1; }

    if(pytania < 0){ pytania = 0; }
    else if(pytania == 0)
    {
        ui->B1->setRange(0, ui->B1->value());
        ui->B2->setRange(0, ui->B2->value());
        ui->B3->setRange(0, ui->B3->value());
        ui->B4->setRange(0, ui->B4->value());
        ui->B5->setRange(0, ui->B5->value());
    }
    else
    {
        ui->B1->setRange(0, ui->ileDod->text().toInt());
        ui->B2->setRange(0, ui->ileDod->text().toInt());
        ui->B4->setRange(0, ui->ileDod->text().toInt());
        ui->B3->setRange(0, ui->ileDod->text().toInt());
        ui->B5->setRange(0, ui->ileDod->text().toInt());
    }
}

void MainWindow::set_ocena()
{
    if(czyPK == 1)
        {
            if(ui->srednia_1->isChecked() || ui->srednia_2->isChecked() || (ui->srednia_1->isChecked() && ui->zla_5->isChecked()) || (ui->zla_4->isChecked() && ui->srednia_2->isChecked()))
            {
                uzyskanaOcena = 3.5;
            }
            if(ui->dobra_4->isChecked() || ui->dobra_5->isChecked() || (ui->srednia_1->isChecked() && ui->srednia_2->isChecked()) || (ui->dobra_4->isChecked() && ui->zla_5->isChecked()) || (ui->zla_4->isChecked() && ui->dobra_5->isChecked()))
            {
                uzyskanaOcena = 4.0;
            }
            if((ui->srednia_1->isChecked() && ui->dobra_5->isChecked()) || (ui->dobra_4->isChecked() && ui->srednia_2->isChecked()))
            {
                uzyskanaOcena = 4.5;
            }
            if(ui->dobra_4->isChecked() && ui->dobra_5->isChecked())
            {
                uzyskanaOcena = 5.0;
            }
        }
    else
    {
        if(uzyskanaOcena == 3 && ui->srednia_3->isChecked())
        {
            uzyskanaOcena = 3.5;
        }
        if(uzyskanaOcena == 3 && ui->dobra_6->isChecked() && ui->srednia_2->isChecked())
        {
            uzyskanaOcena = 4.5;
        }
        if(uzyskanaOcena == 3 && ui->dobra_6->isChecked() && ui->dobra_5->isChecked())
        {
            uzyskanaOcena = 5;
        }
        if(uzyskanaOcena == 3 && ui->dobra_6->isChecked())
        {
            uzyskanaOcena = 4;
        }

    }
}

void MainWindow::on_dobra_1_clicked(){

    ui->podstawowy_b2->setEnabled(true);
    ui->podstawowy_b2->setVisible(true);
}

void MainWindow::on_dobra_2_clicked(){

    ui->podstawowy_b3->setEnabled(true);
    ui->podstawowy_b3->setVisible(true);
    ui->podstawowy_b1->setEnabled(false);
}

void MainWindow::on_dobra_3_clicked(){

    if(czyPK==1){
        ui->zaawansowany->setEnabled(true);
        ui->zaawansowany->setVisible(true);
        ui->przyciski_zaawansowany_gora->setEnabled(true);
    }
    else{
        ui->sredni->setEnabled(true);
        ui->sredni->setVisible(true);
    }
    ui->podstawowy_b2->setEnabled(false);
    uzyskanaOcena=3;
}

void MainWindow::on_dobra_4_clicked(){

    ui->podstawowy_b3->setEnabled(false);
    ui->przyciski_zaawansowany_dol->setEnabled(true);
}

void MainWindow::on_dobra_5_clicked(){

    ui->sredni->setEnabled(false);
    ui->zakoncz->setVisible(true);
}

void MainWindow::on_dobra_6_clicked(){

    ui->podstawowy_b3->setEnabled(false);
    ui->zaawansowany->setEnabled(true);
    ui->zaawansowany->setVisible(true);

}



void MainWindow::on_srednia_1_clicked(){

    ui->przyciski_zaawansowany_dol->setEnabled(true);
    ui->podstawowy_b3->setEnabled(false);
    ui->przyciski_zaawansowany_dol->setEnabled(true);
}

void MainWindow::on_srednia_2_clicked(){

    ui->zakoncz->setVisible(true);
}

void MainWindow::on_srednia_3_clicked(){}



void MainWindow::on_zla_1_clicked(){
    uzyskanaOcena=2.0;
    ui->zakoncz->setVisible(true);
    ui->podstawowy_b2->setEnabled(false);
    ui->podstawowy_b2->setVisible(false);
}

void MainWindow::on_zla_2_clicked(){
    uzyskanaOcena=2.0;
    ui->zakoncz->setVisible(true);
    ui->podstawowy_b3->setEnabled(false);
    ui->podstawowy_b3->setVisible(false);
}

void MainWindow::on_zla_3_clicked(){
    uzyskanaOcena=2.0;
    ui->zakoncz->setVisible(true);
    if(czyPK==1){
        ui->zaawansowany->setEnabled(false);
        ui->zaawansowany->setVisible(false);
        ui->przyciski_zaawansowany_gora->setEnabled(false);
    }
    else{
        ui->sredni->setEnabled(false);
        ui->sredni->setVisible(false);
    }

}
void MainWindow::on_zla_4_clicked(){ ui->przyciski_zaawansowany_dol->setEnabled(true); }

void MainWindow::on_zla_5_clicked(){ ui->zakoncz->setVisible(true); }

void MainWindow::on_zla_6_clicked()
{
    uzyskanaOcena=3.0;
    ui->zaawansowany->setEnabled(false);
    ui->zaawansowany->setVisible(false);
}


void MainWindow::on_comboBox_currentIndexChanged(int index){ ui->pytDod->setVisible(true);}

void MainWindow::on_B1_valueChanged(int arg1){

    ustawPytania(arg1, poprzednia_b1);
    poprzednia_b1 = arg1;
}

void MainWindow::on_B2_valueChanged(int arg1){

    ustawPytania(arg1, poprzednia_b2);
    poprzednia_b2 = arg1;
}

void MainWindow::on_B3_valueChanged(int arg1){

    ustawPytania(arg1, poprzednia_b3);
    poprzednia_b3 = arg1;
}

void MainWindow::on_B4_valueChanged(int arg1){

    ustawPytania(arg1, poprzednia_b4);
    poprzednia_b4 = arg1;
}

void MainWindow::on_B5_valueChanged(int arg1){

    ustawPytania(arg1, poprzednia_b5);
    poprzednia_b5 = arg1;
}


void MainWindow::on_actionUczestnikow_triggered()
{
    mainApp->wczytajUczestnikow();
    ui->comboBox->setVisible(true);
}

void MainWindow::on_actionPytania_triggered()
{
    mainApp->wczytajPytania();
    ui->losujPytania->setVisible(true);
}

void MainWindow::on_comboBox_activated(int index)
{
    mainApp->zwrocUczestnika(index);
    indexUczestnika=index;
    ui->comboBox->setEnabled(false);
    ui->zakoncz->setVisible(true);
}




void MainWindow::brakUczestnikow()
{
    if(ui->comboBox->count()==0){
        QMessageBox::information(this, "Koniec egzaminu","Egzamin zakończony, brak kolejnych uczestników!");
        QApplication::quit();
    }
}

void MainWindow::zakoncz()
{
    if(uzyskanaOcena>=3.0){
        mainApp->ustawOcene(indexUczestnika,uzyskanaOcena);

        QString status = QString("Egzamin zakończony wynikiem pozytywnym, uzyskana ocena: %1 ").arg(uzyskanaOcena);
        QMessageBox::information(this,tr("Wynik egzaminu"),status);
    }
    else{
        mainApp->ustawOcene(indexUczestnika,uzyskanaOcena);
        QMessageBox::critical(this, "Wynik egzaminu","Egzamin zakończony wynikiem negatywnym!");
    }
}
void MainWindow::wyczysc()
{
    for(QRadioButton* radio: radio_buttony)
    {
        radio->setAutoExclusive(false);
        radio->setChecked(false);
        radio->setAutoExclusive(true);
    }

    ui->blok1->clear();
    ui->blok2->clear();
    ui->blok3->clear();
    ui->blok4->clear();
    ui->blok5->clear();

    ui->imie->clear();
    ui->nrAlbumu->clear();
    ui->srednia->clear();
    ui->ileDod->clear();

    ui->B1->setValue(0);
    ui->B2->setValue(0);
    ui->B3->setValue(0);
    ui->B4->setValue(0);
    ui->B5->setValue(0);

    ui->podstawowy_b1->setVisible(true);
    ui->podstawowy_b1->setEnabled(false);
    ui->podstawowy_b2->setVisible(true);
    ui->podstawowy_b2->setEnabled(false);
    ui->podstawowy_b3->setVisible(true);
    ui->podstawowy_b3->setEnabled(false);

    if(czyPK == 0)
    {
        ui->sredni->setVisible(true);
        ui->sredni->setEnabled(false);
    }

    ui->zaawansowany->setVisible(true);
    ui->zaawansowany->setEnabled(false);

    ui->comboBox->removeItem(indexUczestnika);
    ui->comboBox->setEnabled(true);
    ui->comboBox->setVisible(true);
    ui->losujPytania->setVisible(true);

    uzyskanaOcena=0;

    czyJest_Uczestnik=false;
    czyWylosowano_Pytania=false;
}
void MainWindow::on_zakoncz_clicked()
{
    set_ocena();
    zakoncz();
    wyczysc();

    mainApp->usunUczestnika(indexUczestnika);
    brakUczestnikow();

    ui->zakoncz->setVisible(false);
    ui->zaawansowany->setEnabled(false);
}

void MainWindow::ustawComboBox(QString text){ ui->comboBox->addItem(text); }
void MainWindow::wyczyscComboBox(){ ui->comboBox->clear(); }



