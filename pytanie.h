#ifndef PYTANIE_H
#define PYTANIE_H
#include <QString>
#include <QVector>

class Pytanie
{
public:
    Pytanie(int i, QString tr);
    ~Pytanie();

    void setBlok(int i);
    void setTresc(QString tr);

    int getBlok(){return blok;}
    QString getTresc(){return tresc;}

private:
    int blok;
    QString tresc;

};

#endif // PYTANIE_H
