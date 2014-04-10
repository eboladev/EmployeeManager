#ifndef EMPLOYEELISTMODEL_H
#define EMPLOYEELISTMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <QString>

#include "Employee.h"

class EmployeeListModel : public QAbstractListModel
{
    Q_OBJECT

private:
    QList<Employee*> employees;

public:
    EmployeeListModel();
    ~EmployeeListModel();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

    void addEmployee(QString fname, QString lname, QString employer);
    void removeEmployee(int index);

    Employee *getEmployee(int i) { return employees.at(i); }
};

#endif // EMPLOYEELISTMODEL_H
