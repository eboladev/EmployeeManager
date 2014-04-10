#ifndef NEWEMPLOYEEDIALOG_H
#define NEWEMPLOYEEDIALOG_H

#include <QDialog>

namespace Ui {
class NewEmployeeDialog;
}

class NewEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewEmployeeDialog(QWidget *parent, QString *fname, QString *lname, QString *employer);
    ~NewEmployeeDialog();

private slots:
    void on_cancelButton_clicked();

    void on_addButton_clicked();

private:
    Ui::NewEmployeeDialog *ui;
    QString *fname;
    QString *lname;
    QString *employer;
};

#endif // NEWEMPLOYEEDIALOG_H
