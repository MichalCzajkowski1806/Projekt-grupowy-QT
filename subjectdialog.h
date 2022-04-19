#ifndef SUBJECTDIALOG_H
#define SUBJECTDIALOG_H

#include <QDialog>

namespace Ui {
class SubjectDialog;
}

class SubjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SubjectDialog(QWidget *parent = nullptr);
    ~SubjectDialog();

private slots:
    void on_pk_clicked();

    void on_ppk_clicked();


private:
    Ui::SubjectDialog *ui;
};

#endif // SUBJECTDIALOG_H
