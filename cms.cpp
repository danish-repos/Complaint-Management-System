#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <sstream>
using namespace std;

//--------------------------------------------------------------------

// Classes
class Teacher;
class Employee;
class Complaint;
class User;
class Department;
class Manager;
class CampusDirector;
class Admin;
class ComplaintSystem;

//--------------------------------------------------------------------
class Complaint
{

private:
    int complaintID;
    int teacherID;
    int departmentID;
    vector<int> employees;
    string status;
    string assignedTime;
    string description;
    string feedback;

public:
    //Constructor
    Complaint();
    Complaint(int , int , int , vector<int> , string , string , string , string );

    //Setters
    void setcomplaintID(int );
    void setTeacher(int );
    void setEmployees(vector<int> );
    void setDept(int );
    void setStatus(string );
    void setTime();
    void setTimefilehandling(string );
    void setDesc(string );
    void setFeedback(string );

    //Getters
    int getcomplaintID();
    int getTeacher();
    vector<int> getEmployees();
    string getStatus();
    string getDescription();
    string getTime();
    string getFeedback();
    int getDept();
    
    void addEmployee(int );
    friend ostream &operator<<(ostream &out, const Complaint &obj);
};

Complaint:: Complaint()
{
        complaintID = 0;
        teacherID = -1;
        departmentID = -1;
        status = " ";
        assignedTime = " ";
        description = " ";
        feedback = " ";
}
    
Complaint::Complaint(int complaintID, int teacherID, int dept, vector<int> employees, string status, string time, string description, string feedback)
    {
        this->complaintID = complaintID;
        this->teacherID = teacherID;
        this->departmentID = dept;
        this->employees = employees;
        this->status = status;
        this->assignedTime = time;
        this->description = description;
        this->feedback = feedback;
    }
    
void Complaint:: setcomplaintID(int id)
{
    complaintID = id;
}
    
void Complaint:: setTeacher(int input)
{
    teacherID = input;
}
    
void Complaint:: setEmployees(vector<int> input)
{
    employees = input;
}

void Complaint:: setDept(int input)
{
    departmentID = input;
}

void Complaint:: setStatus(string input)
{
    status = input;
}

void Complaint:: setTime()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
    auto str = oss.str();
    assignedTime = str;
  
}

void Complaint:: setTimefilehandling(string input)
{
    assignedTime = input;
}

void Complaint:: setDesc(string input)
{
    description = input;
}

void Complaint:: setFeedback(string input)
{
    feedback = input;
}

int Complaint:: getcomplaintID()
{
    return complaintID;
}

int Complaint:: getTeacher()
{
    return teacherID;
}

vector<int> Complaint:: getEmployees()
{
    return employees;
}

string Complaint:: getStatus()
{
    return status;
}

string Complaint:: getDescription()
{
    return description;
}

string Complaint:: getTime()
{
    return assignedTime;
}

string Complaint:: getFeedback()
{
    return feedback;
}

int Complaint:: getDept()
{
    return departmentID;
}

void Complaint:: addEmployee(int emp)
{
    employees.push_back(emp);
}

ostream &operator<<(ostream &out, const Complaint &obj)
{
    out << "complaintID::" << obj.complaintID << endl;
    out << "teacherID::" << obj.teacherID << endl;
    vector<int> temp = obj.employees;
    vector<int>::iterator it;
    cout << "Assigned Employees employeeID" << endl;
    for (it = temp.begin(); it != temp.end(); it++)
        cout << *it << endl;
    out << "Status::" << obj.status << endl;
    out << "Dept::";
    if (obj.departmentID == 1)
        out << "IT" << endl;
    else if (obj.departmentID == 2)
        out << "Accounts" << endl;
    else if (obj.departmentID == 3)
        out << "Admin" << endl;
    out << "Desc::" << obj.description << endl;
    out << "Assigned Time::" << obj.assignedTime << endl;
    out << "Feedback::" << obj.feedback << endl;

    return out;
}

//-------------------------------------------------------------------------------------------------------------------------------

class User
{
    string username;
    string password;
    string name;

public:
    //Constructor
    User(string  = " ", string  = " ", string  = " ");

    //Setters
    void setUsername(string );
    void setPassword(string );
    void setName(string );

    //Getters
    string getUsername();
    string getPassword();
    string getName();
};

User :: User(string username = " ", string password = " ", string name = " ") : username(username), password(password), name(name)
{
}

void User :: setUsername(string input)
{
    username = input;
}

void User :: setPassword(string input)
{
    password = input;
}

void User :: setName(string input)
{
    name = input;
}

string User :: getUsername()
{
    return username;
}

string User :: getPassword()
{
    return password;
}

string User :: getName()
{
    return name;
}

//-------------------------------------------------------------------------------------------------------------------------------

class Teacher : public User
{
    int teacherID;
    vector<Complaint *> complaints;

public:
    //Constructor
    Teacher(int  = 0, string  = " ", string  = " ", string  = " ");

    //Setters
    void setteacherID(int );
    void setComplaints(vector<Complaint *> );

    //Getters
    int getteacherID();
    vector<Complaint *> getComplaints();

    Complaint fileComplaint(int );
    void addComplaint(Complaint *);
    void viewComplaint();
    void giveFeedback();
};

Teacher :: Teacher(int teacherID = 0, string username = " ", string password = " ", string name = " ") : User(username, password, name)
{
    this->teacherID = teacherID;
}

void Teacher :: setteacherID(int id)
{
    teacherID = id;
}

int Teacher :: getteacherID()
{
    return this->teacherID;
}

void Teacher :: setComplaints(vector<Complaint *> input)
{
    complaints = input;
}

vector<Complaint *> Teacher :: getComplaints()
{
    return this->complaints;
}

Complaint Teacher :: fileComplaint(int id)
{
    cin.ignore();
    string description;
    cout << "Enter description" << endl;
    getline(cin, description);
    cout << "Choose department 1-3" << endl;
    int choice = 0;
    cin >> choice;
    while (choice < 1 || choice > 3)
    {
        cout << "Enter again" << endl;
        cin >> choice;
    }
    Complaint obj;
    obj.setcomplaintID(++id);
    obj.setDept(choice);
    obj.setDesc(description);
    obj.setStatus("New");
    obj.setFeedback(" ");
    obj.addEmployee(-1);
    return obj;
}

void Teacher :: addComplaint(Complaint *obj)
{
    complaints.push_back(obj);
}

void Teacher :: viewComplaint()
{
    vector<Complaint *>::iterator it;
    int idx = 1;
    for (it = complaints.begin(); it != complaints.end(); it++)
    {
        cout << "Complaint::" << idx << endl;
        idx++;
        cout << (**it);
    }
}

void Teacher :: giveFeedback()
{
    vector<Complaint *>::iterator it;
    int indexes[200];
    int k = 0;
    int idx = 0;
    for (it = complaints.begin(); it != complaints.end(); it++)
    {
        if ((*it)->getStatus() == "Done")
        {
            cout << "Complaint::" << k << endl;
            cout << (**it);
            indexes[k] = idx;
            k++;
        }
        idx++;
    }
    cout << "Choose complaint to give feedback 0-" << k - 1 << endl;
    int choice = -1;
    cin >> choice;
    while (choice < 0 || choice >= k)
    {
        cout << "enter again" << endl;
        cin >> choice;
    }
    cout << "Enter detailed feedback" << endl;
    string feedback;
    getline(cin, feedback);
    complaints[indexes[choice]]->setFeedback(feedback);
    cout << "Enter feedback 1 or 2" << endl;
    cout << "1.Satisfied" << endl;
    cout << "2.Dissatisfied" << endl;
    int choice2 = 0;
    cin >> choice2;
    while (choice2 != 1 && choice2 != 2)
    {
        cout << "Enter again" << endl;
        cin >> choice;
    }
    if (choice2 == 1)
        complaints[indexes[choice]]->setStatus("Closed");
    else
        complaints[indexes[choice]]->setStatus("Open");
}

//-------------------------------------------------------------------------------------------------------------------------------

class Employee : public User
{
    int employeeID;
    int departmentID;
    vector<Complaint *> assignedComplaints;

public:
    //Constructors
    Employee();
    Employee(int , vector<Complaint *> , string , string , string );

    //Setters
    void setemployeeID(int );
    void setComplaints(vector<Complaint *> );
    void setDeptid(int );

    //Setters
    int getemployeeID();
    vector<Complaint *> getComplaints();
    int getdeptid();

    void addComplaint(Complaint *);
    void changeStatus();
    void viewAllComplaints();
};


Employee :: Employee()
{
}

Employee :: Employee(int employeeID, vector<Complaint *> com, string username, string password, string name) : User(username, password, name)
{
    this->employeeID = employeeID;
    assignedComplaints = com;
}

void Employee :: setemployeeID(int id)
{
    employeeID = id;
}

void Employee :: setComplaints(vector<Complaint *> Com)
{
    assignedComplaints = Com;
}

void Employee :: setDeptid(int id)
{
    departmentID = id;
}

void Employee :: addComplaint(Complaint *com)
{
    assignedComplaints.push_back(com);
}

int Employee :: getemployeeID()
{
    return employeeID;
}

vector<Complaint *> Employee :: getComplaints()
{
    return assignedComplaints;
}

int Employee :: getdeptid()
{
    return departmentID;
}

void Employee :: changeStatus()
{
    vector<Complaint *>::iterator it;
    int indexes[200];
    int k = 0;
    int idx = 0;
    for (it = assignedComplaints.begin(); it != assignedComplaints.end(); it++)
    {
        if ((*it)->getStatus() == "Assigned")
        {
            cout << "Complaint::" << k << endl;
            cout << **it;
            indexes[k] = idx;
            k++;
        }
        idx++;
    }
    cout << "Choose complaint to change status 0-" << k - 1 << endl;
    int choice = -1;
    cin >> choice;
    while (choice < 0 || choice >= k)
    {
        cout << "enter again" << endl;
        cin >> choice;
    }
    assignedComplaints[indexes[choice]]->setStatus("Resolved");
}

void Employee :: viewAllComplaints()
{
    vector<Complaint *>::iterator it;
    int idx = 1;
    for (it = assignedComplaints.begin(); it != assignedComplaints.end(); it++)
    {
        cout << "Complaint::" << idx << endl;
        idx++;
        cout << (**it);
    }
}

//-------------------------------------------------------------------------------------------------------------------------------



class Department
{
    int departmentID;
    string name;
    vector<Employee *> employees;
    int managerID;

public:
    //Constructor
    Department();

    //Setters
    void setdepartmentID(int );
    void setName(string );
    void setEmployees(vector<Employee *> );
    void setmanagerID(int );

    //Getters
    vector<Employee *> getEmployees();
    int getmanagerID();
    int getdepartmentID();
    string getName();
};

Department :: Department()
{
}

void Department :: setdepartmentID(int id)
{
    departmentID = id;
}

void Department :: setName(string name)
{
    this->name = name;
}

void Department :: setEmployees(vector<Employee *> employees)
{
    this->employees = employees;
}

vector<Employee *> Department :: getEmployees()
{
    return employees;
}

void Department :: setmanagerID(int id)
{
    managerID = id;
}

int Department :: getmanagerID()
{
    return managerID;
}

int Department :: getdepartmentID()
{
    return departmentID;
}

string Department :: getName()
{
    return name;
}

//-------------------------------------------------------------------------------------------------------------------------------


class Manager : public User
{
    int managerID;    
    Department *dept;
    vector<Complaint *> complaints;

public:
    //Constructor
    Manager();

    //Setters
    void setmanagerID(int );
    void setDept(Department *);
    void setComplaints(vector<Complaint *> );

    //Getters
    int getmanagerID();
    Department *getDept();
    vector<Complaint *> getcomplaints();


    void addComplaint(Complaint *com);
    void viewAllComplaints();
    void AssignComplaints();
    void closeComplaint();
};


Manager :: Manager()
{
}

void Manager :: setmanagerID(int id)
{
    managerID = id;
}

void Manager :: setDept(Department *input)
{
    dept = input;
}

void Manager :: setComplaints(vector<Complaint *> com)
{
    complaints = com;
}

int Manager :: getmanagerID()
{
    return managerID;
}

Department *Manager :: getDept()
{
    return dept;
}

vector<Complaint *> Manager :: getcomplaints()
{
    return complaints;
}

void Manager :: addComplaint(Complaint *com)
{
    complaints.push_back(com);
}

void Manager :: viewAllComplaints()
{
    vector<Complaint *>::iterator it;
    int idx = 1;
    for (it = complaints.begin(); it != complaints.end(); it++)
    {
        cout << "Complaint::" << idx << endl;
        idx++;
        cout << (**it);
    }
}

void Manager :: AssignComplaints()
{
    vector<Complaint *>::iterator it;
    int indexes[200];
    int k = 0;
    int idx = 0;
    for (it = complaints.begin(); it != complaints.end(); it++)
    {
        if ((*it)->getStatus() == "New" || (*it)->getStatus() == "Open") // open for complaints with negative feedback
        {
            cout << "Complaint::" << k << endl;
            cout << (**it);
            indexes[k] = idx;
            k++;
        }
        idx++;
    }
    cout << "Choose complaint to assign employees 0-" << k - 1 << endl;
    int choice = -1;
    cin >> choice;
    while (choice < 0 || choice >= k)
    {
        cout << "enter again" << endl;
        cin >> choice;
    }
    complaints[indexes[choice]]->setStatus("Assigned");
    int employeeIDx = 0;
    cout << "Choose employees and press -1 to stop" << endl;
    vector<Employee *> employees = dept->getEmployees();
    vector<Employee *>::iterator iter;
    for (iter = employees.begin(); iter != employees.end(); iter++)
    {
        cout << employeeIDx << ":";
        cout << (*iter)->getName() << endl;
        employeeIDx++;
    }
    int choice2 = -2;
    while (choice2 != -1)
    {
        cin >> choice2;
        if (choice2 == -1)
            break;
        employees[choice2]->addComplaint(complaints[indexes[choice]]);
        complaints[indexes[choice]]->addEmployee(employees[choice2]->getemployeeID());
    }
    complaints[indexes[choice]]->setTime();
}

void Manager :: closeComplaint()
{
    vector<Complaint *>::iterator it;
    int indexes[200];
    int k = 0;
    int idx = 0;
    for (it = complaints.begin(); it != complaints.end(); it++)
    {
        if ((*it)->getStatus() == "Resolved")
        {
            cout << "Complaint::" << k << endl;
            cout << **it;
            indexes[k] = idx;
            k++;
        }
        idx++;
    }
    cout << "Choose complaint to change status 0-" << k - 1 << endl;
    int choice = -1;
    cin >> choice;
    while (choice < 0 || choice >= k)
    {
        cout << "enter again" << endl;
        cin >> choice;
    }
    complaints[indexes[choice]]->setStatus("Done");
}

//-------------------------------------------------------------------------------------------------------------------------------

class Admin : public User
{
    int adminID;

public:
    //Constructor
    Admin();

    //Setters
    void setadminID(int );

    //Getters
    int getadminID();

    //Add
    Teacher addTeacher(int );
    Employee addEmployee(int );
    Manager addManager(int , vector<Department> );

    //Remove
    void removeTeacher(vector<Teacher> &);
    void removeEmployee(vector<Employee> &);
    void removeManager(vector<Manager> &);
};

Admin :: Admin()
{
}

void Admin :: setadminID(int input)
{
    adminID = input;
}

int Admin :: getadminID()
{
    return adminID;
}

Teacher Admin :: addTeacher(int id)
{
    cout << "Enter name" << endl;
    string name;
    cin >> name;
    cout << "Enter username" << endl;
    string username;
    cin >> username;
    cout << "Enter password" << endl;
    string password;
    cin >> password;
    Teacher obj;
    obj.setName(name);
    obj.setUsername(username);
    obj.setPassword(password);
    obj.setteacherID(++id);
    return obj;
}

Employee Admin :: addEmployee(int id)
{
    cout << "Enter name" << endl;
    string name;
    cin >> name;
    cout << "Enter username" << endl;
    string username;
    cin >> username;
    cout << "Enter password" << endl;
    string password;
    cin >> password;
    cout << "Enter depatment id" << endl;
    cout << "1.IT" << endl;
    cout << "2.Accounts" << endl;
    cout << "3.Admin" << endl;
    int departmentID;
    cin >> departmentID;
    Employee obj;
    obj.setName(name);
    obj.setUsername(username);
    obj.setPassword(password);
    obj.setemployeeID(++id);
    obj.setDeptid(departmentID);
    return obj;
}

Manager Admin :: addManager(int id, vector<Department> dept)
{
    cout << "Enter name" << endl;
    string name;
    cin >> name;
    cout << "Enter username" << endl;
    string username;
    cin >> username;
    cout << "Enter password" << endl;
    string password;
    cin >> password;
    cout << "Enter depatment id" << endl;
    cout << "1.IT" << endl;
    cout << "2.Accounts" << endl;
    cout << "3.Admin" << endl;
    int departmentID;
    cin >> departmentID;
    departmentID--;
    Manager obj;
    obj.setName(name);
    obj.setUsername(username);
    obj.setPassword(password);
    obj.setmanagerID(++id);
    obj.setDept(&(dept[departmentID]));
    return obj;
}

void Admin :: removeTeacher(vector<Teacher> &teachers)
{
    vector<Teacher>::iterator it;
    int idx = 0;
    for (it = teachers.begin(); it != teachers.end(); it++)
    {
        cout << "Teacher::" << idx << endl;
        idx++;
        cout << (*it).getName()<<endl;
    }
    cout << "Enter teacher to be removed" << endl;
    int choice;
    cin >> choice;
    teachers.erase(teachers.begin() + choice);
}

void Admin :: removeEmployee(vector<Employee> &employees)
{
    vector<Employee>::iterator it;
    int idx = 0;
    for (it = employees.begin(); it != employees.end(); it++)
    {
        cout << "Employee::" << idx << endl;
        idx++;
        cout << (*it).getName()<<endl;
    }
    cout << "Enter employee to be removed" << endl;
    int choice;
    cin >> choice;
    employees.erase(employees.begin() + choice);
}

void Admin :: removeManager(vector<Manager> &managers)
{
    vector<Manager>::iterator it;
    int idx = 0;
    for (it = managers.begin(); it != managers.end(); it++)
    {
        cout << "Manager::" << idx << endl;
        idx++;
        cout << (*it).getName()<<endl;
    }
    cout << "Enter manager to be removed" << endl;
    int choice;
    cin >> choice;
    managers.erase(managers.begin() + choice);
}

//-------------------------------------------------------------------------------------------------------------------------------


class CampusDirector : public User
{
public:
    //Constructor
    CampusDirector();

    void GenerateReport(vector<Department> , vector<Complaint> );
};

CampusDirector :: CampusDirector()
{
}

void CampusDirector :: GenerateReport(vector<Department> dept, vector<Complaint> com)
{
    vector<Department>::iterator it;
    for (it = dept.begin(); it != dept.end(); it++)
    {
        cout << it->getName() << endl;
        int departmentID = it->getdepartmentID();
        vector<Complaint>::iterator it1;
        int idx = 1;
        for (it1 = com.begin(); it1 != com.end(); it1++)
        {
            if (it1->getDept() == departmentID)
            {
                cout << "Complaint::" << idx << endl;
                cout << *it1;
                idx++;
            }
        }
        cout << "This department received a total of " << --idx << " complaints." << endl;
    }
}

//-------------------------------------------------------------------------------------------------------------------------------

class ComplaintSystem
{
    vector<Teacher> teachers;
    vector<Employee> employees;
    vector<Manager> managers;
    vector<Admin> admins;
    CampusDirector director;
    vector<Department> departments;
    vector<Complaint> complaints;

public:

    //Loading all the files
    void initializer();

    //Saving all the files
    void exit();

    //Menu
    void logger();

    //Panels
    void teacherPanel();
    void employeePanel();
    void managerPanel();
    void adminPanel();
    void directorPanel();

    //Loading the files
    void loadComplaints();
    void loadTeachers();
    void loadEmployees();
    void loadDepartments();
    void loadManagers();
    void loadAdmins();
    void loadDirector();

    //Updating the files
    void saveDirector();
    void saveComplaints();
    void saveTeachers();
    void saveEmployees();
    void saveDepartments();
    void saveManagers();
    void saveAdmins();
};

void ComplaintSystem :: initializer()
{
    loadComplaints();
    loadTeachers();
    loadEmployees();
    loadDepartments();
    loadManagers();
    loadAdmins();
    loadDirector();
    logger();
}

void ComplaintSystem :: exit()
{
    saveComplaints();
    saveTeachers();
    saveEmployees();
    saveDepartments();
    saveManagers();
    saveAdmins();
    saveDirector();
}

void ComplaintSystem :: logger()
{
    int choice = -1;
    while (choice != 6)
    {
        cout << "welcome to  ComplaintSystem" << endl;
        cout << "You are?" << endl;
        cout << "1.Teacher" << endl;
        cout << "2.Employee" << endl;
        cout << "3.Manager" << endl;
        cout << "4.Campus Director" << endl;
        cout << "5.Admin" << endl;
        cout << "6.EXIT" << endl;
        cout << "Enter your choice 1-6" << endl;
        cin >> choice;
        while (choice <= 0 || choice > 6)
        {
            cout << "Enter your choice 1-6" << endl;
            cin >> choice;
        }
        if (choice == 1)
            teacherPanel();
        else if (choice == 2)
            employeePanel();
        else if (choice == 3)
            managerPanel();
        else if (choice == 4)
            directorPanel();
        else if (choice == 5)
            adminPanel();
        else if (choice == 6)
        {
            exit();
            break;
        }
    }
}

void ComplaintSystem :: teacherPanel()
{
    string username, password;
    cout << "Enter username" << endl;
    cin >> username;
    cout << "Enter password" << endl;
    cin >> password;
    Teacher *teacher;
    int loggedin = 0;
    vector<Teacher>::iterator it;
    for (it = teachers.begin(); it != teachers.end(); it++)
    {
        if (it->getUsername() == username && it->getPassword() == password)
        {
            teacher = &(*it);
            cout << "Logged IN" << endl;
            loggedin = 1;
            break;
        }
    }
    if (loggedin == 1)
    {
        int choice = -1;
        while (choice != 4)
        {
            cout << "1.File Complaint" << endl;
            cout << "2.View Complaint" << endl;
            cout << "3.Give Feedback Of Complaint" << endl;
            cout << "4.LogOut" << endl;
            cout << "Enter your choice 1-4" << endl;
            cin >> choice;
            while (choice <= 0 || choice > 4)
            {
                cout << "Enter your choice 1-4" << endl;
                cin >> choice;
            }
            if (choice == 1)
            {
                int lastcomplaintID = (complaints.back()).getcomplaintID();
                Complaint obj;
                obj = teacher->fileComplaint(lastcomplaintID);
                complaints.push_back(obj);
                teacher->addComplaint(&(complaints.back()));
                vector<Manager>::iterator it;
                for (it = managers.begin(); it != managers.end(); it++)
                {
                    if ((it->getDept())->getdepartmentID() == obj.getDept())
                    {
                        it->addComplaint(&(complaints.back()));
                    }
                }
            }
            else if (choice == 2)
                teacher->viewComplaint();
            else if (choice == 3)
                teacher->giveFeedback();
            else if (choice == 4)
            {
                cout << "Logged Out" << endl;
                break;
            }
        }
    }
    else
        cout << "Wrong Credentials" << endl;
}

void ComplaintSystem :: employeePanel()
{
    string username, password;
    cout << "Enter username" << endl;
    cin >> username;
    cout << "Enter password" << endl;
    cin >> password;
    Employee *employee;
    int loggedin = 0;
    vector<Employee>::iterator it;
    for (it = employees.begin(); it != employees.end(); it++)
    {
        if (it->getUsername() == username && it->getPassword() == password)
        {
            employee = &(*it);
            cout << "Logged IN" << endl;
            loggedin = 1;
            break;
        }
    }
    if (loggedin == 1)
    {
        int choice = -1;
        while (choice != 3)
        {
            cout << "1.Change Complaint Status" << endl;
            cout << "2.View Complaints" << endl;
            cout << "3.LogOut" << endl;
            cout << "Enter your choice 1-3" << endl;
            cin >> choice;
            while (choice <= 0 || choice > 3)
            {
                cout << "Enter your choice 1-3" << endl;
                cin >> choice;
            }
            if (choice == 1)
                employee->changeStatus();
            else if (choice == 2)
                employee->viewAllComplaints();
            else if (choice == 3)
            {
                cout << "Logged Out" << endl;
                break;
            }
        }
    }
    else
        cout << "Wrong Credentials" << endl;
}

void ComplaintSystem :: managerPanel()
{
    string username, password;
    cout << "Enter username" << endl;
    cin >> username;
    cout << "Enter password" << endl;
    cin >> password;
    Manager *manager;
    int loggedin = 0;
    vector<Manager>::iterator it;
    for (it = managers.begin(); it != managers.end(); it++)
    {
        if (it->getUsername() == username && it->getPassword() == password)
        {
            manager = &(*it);
            cout << "Logged IN" << endl;
            loggedin = 1;
            break;
        }
    }
    if (loggedin == 1)
    {
        int choice = -1;
        while (choice != 4)
        {
            cout << "1.Assign Complaint" << endl;
            cout << "2.View Complaints" << endl;
            cout << "3.Close Complaint" << endl;
            cout << "4.LogOut" << endl;
            cout << "Enter your choice 1-4" << endl;
            cin >> choice;
            while (choice <= 0 || choice > 4)
            {
                cout << "Enter your choice 1-4" << endl;
                cin >> choice;
            }
            if (choice == 1)
                manager->AssignComplaints();
            else if (choice == 2)
                manager->viewAllComplaints();
            else if (choice == 3)
                manager->closeComplaint();
            else if (choice == 4)
            {
                cout << "Logged Out" << endl;
                break;
            }
        }
    }
    else
        cout << "Wrong Credentials" << endl;
    
}

void ComplaintSystem :: adminPanel()
{
    string username, password;
    cout << "Enter username" << endl;
    cin >> username;
    cout << "Enter password" << endl;
    cin >> password;
    Admin *admin;
    int loggedin = 0;
    vector<Admin>::iterator it;
    for (it = admins.begin(); it != admins.end(); it++)
    {
        if (it->getUsername() == username && it->getPassword() == password)
        {
            admin = &(*it);
            cout << "Logged IN" << endl;
            loggedin = 1;
            break;
        }
    }
    if (loggedin == 1)
    {
        int choice = -1;
        while (choice != 4)
        {
            cout << "1.Add Teacher" << endl;
            cout << "2.Add Employee" << endl;
            cout << "3.Add Manager" << endl;
            cout << "4.Remove Teacher" << endl;
            cout << "5.Remove Employee" << endl;
            cout << "6.Remove Manager" << endl;
            cout << "7.LogOut" << endl;
            cout << "Enter your choice 1-7" << endl;
            cin >> choice;
            while (choice <= 0 || choice > 7)
            {
                cout << "Enter your choice 1-7" << endl;
                cin >> choice;
            }
            if (choice == 1)
            {
                int lastteacherID = (teachers.back()).getteacherID();
                Teacher obj;
                obj = admin->addTeacher(lastteacherID);
                teachers.push_back(obj);
            }
            else if (choice == 2)
            {
                int lastemployeeID = (employees.back()).getemployeeID();
                Employee obj;
                obj = admin->addEmployee(lastemployeeID);
                employees.push_back(obj);
            }
            else if (choice == 3)
            {
                int lastmanagerID = (managers.back()).getmanagerID();
                Manager obj;
                obj = admin->addManager(lastmanagerID, departments);
                managers.push_back(obj);
            }
            else if (choice == 4)
                admin->removeTeacher(teachers);
            else if (choice == 5)
                admin->removeEmployee(employees);
            else if (choice == 6)
                admin->removeManager(managers);
            else if (choice == 7)
            {
                cout << "Logged Out" << endl;
                break;
            }
        }
    }
    else
        cout << "Wrong Credentials" << endl;
    
}

void ComplaintSystem :: directorPanel()
{
    string username, password;
    cout << "Enter username" << endl;
    cin >> username;
    cout << "Enter password" << endl;
    cin >> password;
    int loggedin = 0;
    if (director.getUsername() == username && director.getPassword() == password)
        loggedin = 1;
    if (loggedin == 1)
    {
        int choice = -1;
        while (choice != 4)
        {
            cout << "1.Generate Reports" << endl;
            cout << "2.LogOut" << endl;
            cout << "Enter your choice 1-2" << endl;
            cin >> choice;
            while (choice <= 0 || choice > 2)
            {
                cout << "Enter your choice 1-2" << endl;
                cin >> choice;
            }
            if (choice == 1)
                director.GenerateReport(departments, complaints);
            else if (choice == 2)
            {
                cout << "Logged Out" << endl;
                break;
            }
        }
    }
    else
        cout << "Wrong Credentials" << endl;
}

void ComplaintSystem :: loadComplaints()
{
    int complaintID;
    int teacherID;
    int departmentID;
    vector<int> employees1;
    string status;
    string assignedTime;
    string description;
    string feedback;
    fstream input;
    char buffer[2000];
    input.open("Complaints.txt");
    while (!input.eof())
    {
        
        input >> complaintID;
        input.ignore();
        input >> teacherID;
        input.ignore();
        input >> departmentID;
        input.ignore();
        input.getline(buffer, 2000, ',');
        status = buffer;
        input.getline(buffer, 2000, ',');
        assignedTime = buffer;
        input.getline(buffer, 2000, ',');
        description = buffer;
        input.getline(buffer, 2000, ',');
        feedback = buffer;
        input.getline(buffer, 2000, '\n');
        string temp = buffer;
        stringstream ss(buffer);
        string temp1;
        while (getline(ss, temp1, ','))
            employees1.push_back(stoi(temp1));
        Complaint obj;
        obj.setcomplaintID(complaintID);
        obj.setTeacher(teacherID);
        obj.setDept(departmentID);
        obj.setFeedback(feedback);
        obj.setStatus(status);
        obj.setDesc(description);
        obj.setTimefilehandling(assignedTime);
        obj.setEmployees(employees1);
        complaints.push_back(obj);
        employees1.clear();
    }
    input.close();
}

void ComplaintSystem :: loadTeachers()
{
    string username;
    string password;
    string name;
    int teacherID;
    vector<Complaint *> complaints1;
    fstream input;
    char buffer[2000];
    input.open("Teachers.txt");
    while (!input.eof())
    {
        input >> teacherID;
        input.ignore();
        input.getline(buffer, 2000, ',');
        name = buffer;
        input.getline(buffer, 2000, ',');
        username = buffer;
        input.getline(buffer, 2000, ',');
        password = buffer;
        input.getline(buffer, 2000, '\n');
        string temp = buffer;
        stringstream ss(buffer);
        string temp1;
        while (getline(ss, temp1, ','))
        {
            int complaintID = stoi(temp1);
            vector<Complaint>::iterator it;
           
            for (it = complaints.begin(); it != complaints.end(); it++)
            {
                if (it->getcomplaintID() == complaintID)
                    complaints1.push_back(&(*it));    
            }
        }
        Teacher obj;
        obj.setName(name);
        obj.setPassword(password);
        obj.setteacherID(teacherID);
        obj.setUsername(username);
        obj.setComplaints(complaints1);
        teachers.push_back(obj);
        complaints1.clear();
    }
    input.close();
}

void ComplaintSystem :: loadEmployees()
{
    string username;
    string password;
    string name;
    int employeeID;
    int departmentID;
    vector<Complaint *> complaints1;
    fstream input;
    char buffer[2000];
    input.open("Employees.txt");
    while (!input.eof())
    {
        input >> employeeID;
        input.ignore();
        input >> departmentID;
        input.ignore();
        input.getline(buffer, 2000, ',');
        name = buffer;
        input.getline(buffer, 2000, ',');
        username = buffer;
        input.getline(buffer, 2000, ',');
        password = buffer;
      
        input.getline(buffer, 2000, '\n');
        string temp = buffer;
        stringstream ss(buffer);
        string temp1;
        while (getline(ss, temp1, ','))
        {
            int complaintID = stoi(temp1);
            vector<Complaint>::iterator it;
           
            for (it = complaints.begin(); it != complaints.end(); it++)
            {
                if (it->getcomplaintID() == complaintID)
                    complaints1.push_back(&(*it));
                
            }
        }
        Employee obj;
        obj.setName(name);
        obj.setPassword(password);
        obj.setemployeeID(employeeID);
        obj.setDeptid(departmentID);
        obj.setUsername(username);
        obj.setComplaints(complaints1);
        employees.push_back(obj);
        complaints1.clear();
    }
    input.close();
}

void ComplaintSystem :: loadDepartments()
{
    int departmentID;
    string name;
    vector<Employee *> employees1;
    int managerID;
    fstream input;
    char buffer[2000];
    input.open("Departments.txt");
    while (!input.eof())
    {
        input >> departmentID;
        input.ignore();
        input >> managerID;
        input.ignore();
        input.getline(buffer, 2000, ',');
        name = buffer;
        input.getline(buffer, 2000, '\n');
        string temp = buffer;
        stringstream ss(buffer);
        string temp1;
        while (getline(ss, temp1, ','))
        {
            int employeeID = stoi(temp1);
            vector<Employee>::iterator it;
            for (it = employees.begin(); it != employees.end(); it++)
            {
                if (it->getemployeeID() == employeeID)
                     employees1.push_back(&(*it));
            }
        }
        Department obj;
        obj.setdepartmentID(departmentID);
        obj.setmanagerID(managerID);
        obj.setName(name);
        obj.setEmployees(employees1);
        departments.push_back(obj);
        employees1.clear();
    }
    input.close();
}

void ComplaintSystem :: loadManagers()
{
    string username;
    string password;
    string name;
    int managerID;
    Department *dept;
    int departmentID;
    vector<Complaint *> complaints1;
    fstream input;
    char buffer[2000];
    input.open("Managers.txt");
    while (!input.eof())
    {
        input >> managerID;
        input.ignore();
        input >> departmentID;
        input.ignore();
        input.getline(buffer, 2000, ',');
        name = buffer;
        input.getline(buffer, 2000, ',');
        username = buffer;
        input.getline(buffer, 2000, ',');
        password = buffer;
       
        input.getline(buffer, 2000, '\n');
        string temp = buffer;
        stringstream ss(buffer);
        string temp1;
        while (getline(ss, temp1, ','))
        {
           
            int complaintID = stoi(temp1);
            vector<Complaint>::iterator it;
           
            for (it = complaints.begin(); it != complaints.end(); it++)
            {
                if (it->getcomplaintID() == complaintID)
                    complaints1.push_back(&(*it));
            }
        }
       
        vector<Department>::iterator dit;
      
        for (dit = departments.begin(); dit != departments.end(); dit++)
        {
            
            if (dit->getdepartmentID() == departmentID)
                dept = &(*dit);
        }
        Manager obj;
        obj.setName(name);
        obj.setPassword(password);
        obj.setmanagerID(managerID);
        obj.setDept(dept);
        obj.setUsername(username);
        obj.setComplaints(complaints1);
        managers.push_back(obj);
        complaints1.clear();
    }
    input.close();
}

void ComplaintSystem :: loadAdmins()
{
    string username;
    string password;
    string name;
    int adminID;
    fstream input;
    char buffer[2000];
    input.open("Admins.txt");
    while (!input.eof())
    {
       
        input >> adminID;
        input.ignore();
        input.getline(buffer, 2000, ',');
        name = buffer;
        input.getline(buffer, 2000, ',');
        username = buffer;
        input.getline(buffer, 2000, '\n');
        password = buffer;
        Admin obj;
        obj.setName(name);
        obj.setPassword(password);
        obj.setadminID(adminID);
        obj.setUsername(username);
        admins.push_back(obj);
    }
    input.close();
}

void ComplaintSystem :: loadDirector()
{
    string username;
    string password;
    string name;
    fstream input;
    char buffer[2000];
    input.open("Director.txt");
    while (!input.eof())
    {
        input.getline(buffer, 2000, ',');
        name = buffer;
        input.getline(buffer, 2000, ',');
        username = buffer;
        input.getline(buffer, 2000, '\n');
        password = buffer;
        director.setName(name);
        director.setPassword(password);
        director.setUsername(username);
    }
    input.close();
}

void ComplaintSystem :: saveDirector()
{
    ofstream output;
    output.open("Director1.txt");
    output<<director.getName()<<","<<director.getUsername()<<","<<director.getPassword()<<"\n";
}

void ComplaintSystem :: saveComplaints()
{
    ofstream output;
    output.open("Complaints1.txt");
    vector<Complaint>::iterator it;
   
    for (it = complaints.begin(); it != complaints.end(); it++)
    {
        output << it->getcomplaintID() << "," << it->getTeacher() << "," << it->getDept() << "," << it->getStatus() << "," << it->getTime() << "," << it->getDescription() << "," << it->getFeedback() << ",";
        vector<int> employees = it->getEmployees();
        if (employees.size() != 0)
        {
            vector<int>::iterator it;
            int lastemployeeID = employees.back();
            for (it = employees.begin(); it != employees.end(); it++)
            {
                if (*it == lastemployeeID)
                    output << *it;
                else
                    output << *it << ",";
            }
        }
        output << '\n';
    }
}

void ComplaintSystem :: saveTeachers()
{
    ofstream output;
    output.open("Teachers1.txt");
    vector<Teacher>::iterator it;
    for (it = teachers.begin(); it != teachers.end(); it++)
    {
        output << it->getteacherID() << "," << it->getName() << "," << it->getUsername() << "," << it->getPassword() << ",";
        vector<Complaint *> complaints2 = it->getComplaints();
        if (complaints2.size() != 0)
        {
            vector<Complaint *>::iterator it1;
            int lastcomplaintID = (*(complaints2.back())).getcomplaintID();
            for (it1 = complaints2.begin(); it1 != complaints2.end(); it1++)
            {
                if ((**it1).getcomplaintID() == lastcomplaintID)
                    output << (**it1).getcomplaintID();
                else
                    output << (**it1).getcomplaintID() << ",";
            }
        }
        else
            output << " ";
        output << '\n';
    }
}

void ComplaintSystem :: saveEmployees()
{
    ofstream output;
    output.open("Employees1.txt");
    vector<Employee>::iterator it;
    for (it = employees.begin(); it != employees.end(); it++)
    {
        output << it->getemployeeID() << "," << it->getdeptid() << "," << it->getName() << "," << it->getUsername() << "," << it->getPassword() << ",";
        vector<Complaint *> complaints2 = it->getComplaints();
        if (complaints2.size() != 0)
        {
            vector<Complaint *>::iterator it1;
            int lastcomplaintID = (*(complaints2.back())).getcomplaintID();
            for (it1 = complaints2.begin(); it1 != complaints2.end(); it1++)
            {
                if ((**it1).getcomplaintID() == lastcomplaintID)
                    output << (**it1).getcomplaintID();
                else
                    output << (**it1).getcomplaintID() << ",";
            }
        }
        else
            output << " ";
        output << '\n';
    }
}

void ComplaintSystem :: saveDepartments()
{
    ofstream output;
    output.open("Departments1.txt");
    vector<Department>::iterator it;
    for (it = departments.begin(); it != departments.end(); it++)
    {
        output << it->getdepartmentID() << "," << it->getmanagerID() << "," << it->getName() << ",";
        vector<Employee *> employees1 = it->getEmployees();
        if (employees1.size() != 0)
        {
            vector<Employee *>::iterator it1;
            int lastemployeeID = (*(employees1.back())).getemployeeID();
            for (it1 = employees1.begin(); it1 != employees1.end(); it1++)
            {
                if ((**it1).getemployeeID() == lastemployeeID)
                    output << (**it1).getemployeeID();
                else
                    output << (**it1).getemployeeID() << ",";
            }
        }
        else
            output << " ";
        output << '\n';
    }
}

void ComplaintSystem :: saveManagers()
{
    ofstream output;
    output.open("Managers1.txt");
    vector<Manager>::iterator it;
    for (it = managers.begin(); it != managers.end(); it++)
    {
        output << it->getmanagerID() << "," << (*(it->getDept())).getdepartmentID() << "," << it->getName() << "," << it->getUsername() << "," << it->getPassword() << ",";
        vector<Complaint *> complaints2 = it->getcomplaints();
        if (complaints2.size() != 0)
        {
            vector<Complaint *>::iterator it1;
            int lastcomplaintID = (*(complaints2.back())).getcomplaintID();
            for (it1 = complaints2.begin(); it1 != complaints2.end(); it1++)
            {
                if ((**it1).getcomplaintID() == lastcomplaintID)
                    output << (**it1).getcomplaintID();
                else
                    output << (**it1).getcomplaintID() << ",";
            }
        }
        else
            output << " ";
        output << '\n';
    }
}

void ComplaintSystem :: saveAdmins()
{
    ofstream output;
    output.open("Admins1.txt");
    vector<Admin>::iterator it;
    for (it = admins.begin(); it != admins.end(); it++)
    {
        output << it->getadminID() << "," << it->getName() << "," << it->getUsername() << "," << it->getPassword() << "\n";
    }
}

//-------------------------------------------------------------------------------------------------------------------------------
int main()
{
 cout << "Complaint Managment System\n" ;
 ComplaintSystem obj;
 obj.initializer();

 return 0;
}
