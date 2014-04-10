#include "EmployeeListModel.h"

EmployeeListModel::EmployeeListModel()
{
}

EmployeeListModel::~EmployeeListModel()
{
}

int EmployeeListModel::rowCount(const QModelIndex &parent) const
{
    return employees.size();
}

QVariant EmployeeListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= employees.size())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        Employee *e = employees.at(index.row());
        return QVariant(QString::fromStdString(e->getFirstName() + " " + e->getLastName() + " - " + e->getEmployer()));
    }
    else
    {
        return QVariant();
    }
}

QVariant EmployeeListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return "Column " + QString::number(section);
    else
        return "Row " + QString::number(section);
}

bool EmployeeListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        employees.replace(index.row(), value.value<Employee*>());
        emit dataChanged(index, index);
        return true;
    }

    return false;
}

void EmployeeListModel::addEmployee(QString fname, QString lname, QString employer)
{
    int index;
    if (employees.size() == 0)
        index = 0;
    else
        index = employees.size() - 1;
    beginInsertRows(QModelIndex(), index, index);
    employees.append(new Employee(fname.toStdString(), lname.toStdString(), employer.toStdString()));
    endInsertRows();
}

void EmployeeListModel::removeEmployee(int index)
{
    if (employees.size() > 0 && index >= 0 && index < employees.size())
    {
        beginRemoveRows(QModelIndex(), index, index);
        employees.removeAt(index);
        endRemoveRows();
    }
}
