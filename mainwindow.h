#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "student.h"
#include <QMessageBox>
#include <QVector>
#include <QRadioButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Program;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr,Program *app=nullptr);
    ~MainWindow();


    void PK();

    void wyczyscComboBox();
    void wczytajUczestnika(Student* i_student);

    //Dodanie uczestników do comboBoxa
    void ustawComboBox(QString text);


    //Zakonczenie egzaminu dla pojedynczego uczestnika
    void zakoncz();
    void wyczysc();


    void ustawPytania(int arg, int tem);

    void set_ocena();

    void brakUczestnikow();

    void enable();
private slots:


    void on_losujPytania_clicked();
    void on_actionUczestnikow_triggered();
    void on_actionPytania_triggered();


    void on_comboBox_activated(int index);


    void on_zla_1_clicked();
    void on_zla_2_clicked();
    void on_zla_3_clicked();
    void on_zla_5_clicked();

    void on_dobra_1_clicked();
    void on_dobra_2_clicked();
    void on_dobra_3_clicked();
    void on_dobra_4_clicked();
    void on_dobra_5_clicked();

    void on_srednia_1_clicked();
    void on_srednia_2_clicked();



    void on_comboBox_currentIndexChanged(int index);
    void on_B1_valueChanged(int arg1);
    void on_B2_valueChanged(int arg1);
    void on_B3_valueChanged(int arg1);
    void on_B4_valueChanged(int arg1);
    void on_zla_4_clicked();



    void on_zakoncz_clicked();

    void on_dobra_6_clicked();

    void on_srednia_3_clicked();

    void on_zla_6_clicked();

    void on_B5_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    Program *mainApp=nullptr;
    bool czyJest_Uczestnik=false;
    bool czyWylosowano_Pytania=false;
    int indexUczestnika;
    double uzyskanaOcena=0;
    bool czyPK=0;
    int pytania;

    //Poprzednie wartości spinboxow
    int poprzednia_b1 = 0;
    int poprzednia_b2 = 0;
    int poprzednia_b3 = 0;
    int poprzednia_b4 = 0;
    int poprzednia_b5 = 0;

    QVector<QRadioButton*>radio_buttony;
};
#endif // MAINWINDOW_H
