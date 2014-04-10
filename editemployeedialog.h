#ifndef EDITEMPLOYEEDIALOG_H
#define EDITEMPLOYEEDIALOG_H

#include <QDialog>
#include "Employee.h"

namespace Ui {
class EditEmployeeDialog;
}

class EditEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditEmployeeDialog(QWidget *parent, Employee *employee);
    ~EditEmployeeDialog();

private slots:
    void on_cancelButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::EditEmployeeDialog *ui;
    Employee *employee;
};

#endif // EDITEMPLOYEEDIALOG_H
