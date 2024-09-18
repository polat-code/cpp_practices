#include <iostream>
#include <vector>
using namespace std;


class Student {
    private:
        int rollNo,age;
        string name;
    public:
        Student(int stdRollNo, int stdAge,string stdName) {
            rollNo = stdRollNo;
            age = stdAge;
            name = stdName;
        }
        Student() {

        }
        int getRollNo() {
            return rollNo;
        }
        void setRollNo(int stdRollNo) {
            rollNo = stdRollNo;
        }
        int getAge() {
            return age;
        }
        void setAge(int stdAge) {
            age = stdAge;
        }
        string getName() {
                return name;
        }
        void setName(string stdName) {
            name = stdName;
        }
};
// create new Student function
void createNewStudent(vector<Student> &students);
void displayStudents(vector<Student> &students);
void searchStudent(vector<Student> &students);
void updateStudent(vector<Student> &students);
void deleteStudent(vector<Student> &students);

int main() {
    vector<Student> students;
    bool isExit = false;
    //students.push_back(Student(1,20,"Ali"));

    while (!isExit) {
        int option;
        cout << "--------------------------------" <<endl;
        cout << "User Management System" <<endl;
        cout << "--------------------------------" <<endl;
        cout <<"1. Add New Student"<<endl;
        cout <<"2. Display All Students"<<endl;
        cout <<"3. Search Student"<<endl;
        cout <<"4. Update Student"<<endl;
        cout <<"5. Delete Student"<<endl;
        cout <<"6. Exit"<<endl;
        cout <<"Enter your option: ";
        cin >> option;
        switch(option) {
            case 1:
                createNewStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                searchStudent(students);
                break;
            case 4:
                updateStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                isExit = true;
                break;
            default:
                cout << endl <<"Invalid Option" << endl <<endl;
                break;
        }

    }


    return 0;
}

void createNewStudent(vector<Student> &students) {
    int rollNo,age;
    string name;
    cout<<"Enter roll number:";
    cin>>rollNo;
    cout<<"Enter age:";
    cin>>age;
    cout<<"Enter name:";
    cin>>name;
    // check If there is already user.
    for(int i=0;i<students.size();i++) {
        if(students[i].getName()==name) {
            cout<<"Already exist user:";
            return;
        }
    }
    Student newStudent(rollNo,age,name);
    students.push_back(newStudent);

    cout<<"Student created successfully!"<<endl << endl;
}
void displayStudents(vector<Student> &students) {
    cout << "------Student list-----"<<endl;
    if(students.empty()) {
        cout <<"No Student found!"<<endl;
        return;
    }
    for(int i=0;i<students.size();i++) {
        cout<< endl <<  "Name: " << students.at(i).getName() << ", Roll No: " << students.at(i).getRollNo()<< ", Age: " << students.at(i).getAge() <<endl <<endl;
    }
}
void searchStudent(vector<Student> &students) {
    int rollNo;
    cout << "Enter roll number:" << endl;
    cin>>rollNo;
    for(int i=0;i<students.size();i++) {
        if(students.at(i).getRollNo()==rollNo) {
            cout<<"Student found!"<<endl;
            return;
        }
    }
    cout<<"Student not found!"<<endl;
}
void updateStudent(vector<Student> &students) {
    int rollNo;
    bool isNotFound = true;
    cout << "Enter roll number:" << endl;
    cin>>rollNo;
    for(int i=0;i<students.size();i++) {
        if(students.at(i).getRollNo()==rollNo) {
            cout<<"Student found successfully!"<<endl;
            int age;
            string name;
            cout<<"Enter new age:";
            cin>>age;
            cout<<"Enter new name:";
            cin>>name;
            students.at(i).setAge(age);
            students.at(i).setName(name);
            cout<<"Student updated successfully!"<<endl;
            isNotFound = false;
        }
    }
    if(isNotFound) {
        cout << "Student not found!"<<endl;
    }
}

void deleteStudent(vector<Student> &students) {
    int rollNo;
    bool isNotFound = true;
    cout << "Enter roll number:" << endl;
    cin>>rollNo;
    for(int i=0;i<students.size();i++) {
        if(students.at(i).getRollNo()==rollNo) {
            students.erase(students.begin()+i);
            cout<< "Roll No : " << rollNo <<" student deleted successfully!"<<endl;
            isNotFound = false;
        }
    }
    if(isNotFound) {
        cout << "Student not found!"<<endl;
    }
}