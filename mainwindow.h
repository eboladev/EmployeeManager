#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "EmployeeListModel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addEmployeeButton_clicked();

    void on_deleteEmployeeButton_clicked();

    void on_editEmployeeButton_clicked();

private:
    Ui::MainWindow *ui;
    EmployeeListModel *employeeListModel;
};

#endif // MAINWINDOW_H
