#include "mainwindow.h"
#include "program.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Program mainProgram;
    MainWindow window(nullptr,&mainProgram);
    window.show();
    return a.exec();
}
