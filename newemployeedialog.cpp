#include "newemployeedialog.h"
#include "ui_newemployeedialog.h"
#include <QMessageBox>

NewEmployeeDialog::NewEmployeeDialog(QWidget *parent, QString *fname, QString *lname, QString *employer) :
    QDialog(parent),
    ui(new Ui::NewEmployeeDialog)
{
    ui->setupUi(this);
    this->fname = fname;
    this->lname = lname;
    this->employer = employer;
}

NewEmployeeDialog::~NewEmployeeDialog()
{
    delete ui;
}

void NewEmployeeDialog::on_cancelButton_clicked()
{
    close();
}

void NewEmployeeDialog::on_addButton_clicked()
{
    QString fnameFieldText = ui->firstNameField->text();
    QString lnameFieldText = ui->lastNameField->text();
    QString employerFieldText = ui->employerTextField->text();
    if (fnameFieldText != "" && lnameFieldText != "")
    {
        fname->clear();
        fname->append(fnameFieldText);
        lname->clear();
        lname->append(lnameFieldText);
        employer->clear();
        employer->append(employerFieldText);
        close();
    }
    else
    {
        QMessageBox::warning(this, "Alert!", "All fields are required!");
    }
}
