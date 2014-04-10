#include "editemployeedialog.h"
#include "ui_editemployeedialog.h"
#include <QMessageBox>

EditEmployeeDialog::EditEmployeeDialog(QWidget *parent, Employee *employee) :
    QDialog(parent),
    ui(new Ui::EditEmployeeDialog)
{
    ui->setupUi(this);
    this->employee = employee;
    ui->fnameTextField->setText(QString::fromStdString(this->employee->getFirstName()));
    ui->lnameTextField->setText(QString::fromStdString(this->employee->getLastName()));
    ui->employerTextField->setText(QString::fromStdString(this->employee->getEmployer()));
}

EditEmployeeDialog::~EditEmployeeDialog()
{
    delete ui;
}

void EditEmployeeDialog::on_cancelButton_clicked()
{
    close();
}

void EditEmployeeDialog::on_saveButton_clicked()
{
    QString fname = ui->fnameTextField->text();
    QString lname = ui->lnameTextField->text();
    QString employer = ui->employerTextField->text();
    if (fname != "" && lname != "")
    {
        this->employee->setFirstName(fname.toStdString());
        this->employee->setLastName(lname.toStdString());
        this->employee->setEmployer(employer.toStdString());
        close();
    }
    else
    {
        QMessageBox::warning(this, "Alert!", "No fields can be blank!");
    }
}
