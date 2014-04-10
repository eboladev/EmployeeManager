#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newemployeedialog.h"
#include "editemployeedialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    employeeListModel = new EmployeeListModel();
    ui->employeeListView->setModel(employeeListModel);
    ui->employeesListLabel->setText(QString::number(employeeListModel->rowCount()) + " employees");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addEmployeeButton_clicked()
{
    QString fname, lname, employer;
    NewEmployeeDialog *dialog = new NewEmployeeDialog(this, &fname, &lname, &employer);
    dialog->exec();
    fname = fname.left(1).toUpper() + fname.mid(1).toLower();
    lname = lname.left(1).toUpper() + lname.mid(1).toLower();
    employeeListModel->addEmployee(fname, lname, employer);
    ui->employeesListLabel->setText(QString::number(employeeListModel->rowCount()) + " employees");
}

void MainWindow::on_deleteEmployeeButton_clicked()
{
    QModelIndexList selList = ui->employeeListView->selectionModel()->selectedIndexes();
    foreach(QModelIndex index, selList)
    {
        employeeListModel->removeEmployee(index.row());
    }
    ui->employeesListLabel->setText(QString::number(employeeListModel->rowCount()) + " employees");
}

void MainWindow::on_editEmployeeButton_clicked()
{
    Employee *e = employeeListModel->getEmployee(ui->employeeListView->selectionModel()->currentIndex().row());
    EditEmployeeDialog *dialog = new EditEmployeeDialog(this, e);
    dialog->exec();
}
