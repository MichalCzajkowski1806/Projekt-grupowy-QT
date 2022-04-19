#include "subjectdialog.h"
#include "ui_subjectdialog.h"

SubjectDialog::SubjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SubjectDialog){ ui->setupUi(this); }

SubjectDialog::~SubjectDialog(){ delete ui; }

void SubjectDialog::on_pk_clicked(){ SubjectDialog::accept(); }

void SubjectDialog::on_ppk_clicked(){ SubjectDialog::reject(); }




