#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
private:
    std::string firstname, lastname, employer;

public:
    Employee() {}
    Employee(std::string fname, std::string lname, std::string em)
    {
        firstname = fname;
        lastname = lname;
        employer = em;
    }

    std::string getFirstName() const { return firstname; }
    std::string getLastName() const { return lastname; }
    std::string getEmployer() const { return employer; }

    void setFirstName(std::string fname) { firstname = fname; }
    void setLastName(std::string lname) { lastname = lname; }
    void setEmployer(std::string em) { employer = em; }
};

Q_DECLARE_METATYPE(Employee*)

#endif // EMPLOYEE_H
