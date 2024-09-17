#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Decleration

void myFunctionDeclaration();
void myFunctionDeclarationWithParameter(string name,string surname, string password  = "default password");
void printNameAndSurname(string name, string surname);
int returnSummation(int &number1, int &number2);
void swapNumbers(int &number1, int &number2);
int plusFunc(int number1, int number2);
double plusFunc(double number1, double number2);
void tryCatchBlokDemo();


string globalVariable = "";

struct myDataType {
    int myNum;
    string myString;
};
/*
struct car {
    string brand;
    string model;
    int year{};
};
*/
enum level {
    LOW = 25,
    MEDIUM = 50,
    HIGH = 75
};

// Classes

class Computer {
    public:
        string brand;
        string model;
        string cpu;
        int Ram;
        Computer(string brand, string model, string cpu, int Ram) {
            this->brand = brand;
            this->model = model;
            this->cpu = cpu;
            this->Ram = Ram;
        }
};

class Vehicle {
    public:
        string brand = "Ford";
        void honk() {
            cout << "Tuut , tuut! \n";
        }
};


class Car: public Vehicle {
    public:
        string model = "Mustang";
};


class ClassA {
    public:
        int a;
        ClassA(int a) {
            this->a = a;
        }
};

class ClassB {
    public:
        int b;
        ClassB(int b) {
            this->b = b;
        }
};



class ClassC: public ClassA, public ClassB{
    public:
        int c;
        ClassC(int a,int b,int c) : ClassA(a), ClassB(b){
            this->a = a;
            this->b = b;
            this->c = c;
        }
        void printAllValues() {
            cout<<"a : "<< this->a << " b : " << this->b << " c : " << this->c <<endl;
        }
};




class myClass {
    public:
        int myNum;
        string myString;
        void myFunction() {
            cout << "my function is working" << endl;
        }

};

class Person {
    public:
        string name;
        string surname;
        string password;
        string getPassword() {
            return password;
        }
        string myMethod();
};

string Person::myMethod() {
    return "my method";
}

class Employee {
    // default is private
    int salary;
    public:
        int getSalary() {
            return salary;
        }
        void setSalary(int salary) {
            this->salary = salary;
        }
        Employee(int salary) {
            this->salary = salary;
        }
};

int main() {

    // random
    // Get a different random number each time the program runs
    srand(time(0));
    cout << rand() % 53 <<endl;

    // vectors

    vector<string> cars = {"Volvo","BMW","Ford","Mazda"};
    cars.push_back("Togg");
    cars.push_back("Mercedes");
    cout << cars.size() << endl;
    cout << cars.at(0) << endl;

    cout << "Cars empty : " <<  cars.empty() << endl;

    for(int i =0 ; i<cars.size(); i++) {
        cout << cars.at(i) << endl;
    }


    tryCatchBlokDemo();

    ClassC myClassC(1,2,3);
    myClassC.printAllValues();

    Car myFordCar;
    myFordCar.honk();

    Employee employee(1000);
    employee.setSalary(2000);
    cout << employee.getSalary() << endl;

    Computer computer1("Apple","Mac Air","M1",8);
    Computer computer2 = Computer("HP","H2 Series","i9",16);
    cout << computer1.brand << endl;
    cout << computer1.model << endl;
    cout << computer1.cpu << endl;
    cout << computer1.Ram << endl;

    Person person1;
    person1.name = "John";
    person1.surname = "Doe";
    person1.password = "12345";

    cout << person1.getPassword() << endl;
    cout <<person1.myMethod() << endl;


    Person person2;
    person2.name = "Martin";
    person2.surname = "Lucky";
    person2.password = "54312";

    cout << "Person 1 : " << person1.name << " " << person1.surname <<" password : " << person1.password  << endl;
    cout << "Person 2 : " << person2.name << " " << person2.surname <<" password : " << person2.password  << endl;

    myClass myClassObject;
    myClassObject.myNum = 12;
    myClassObject.myString = "my Class String";

    cout << myClassObject.myNum << endl;
    cout << myClassObject.myString << endl;

    cout << "Hello, World!" << std::endl;

    vector<string> words;
    words.emplace_back("first");
    words.emplace_back("second");
    words.emplace_back("third");
    for(const string& word : words) {
        cout << word << endl;
    }
    /*
    car myCar1;
    myCar1.brand = "BMW";
    myCar1.model = "M5 Competition";
    myCar1.year = 2022;

    car myCar2;
    myCar2.brand = "Mercedes";
    myCar2.model = "AMG E200";
    myCar2.year = 2020;

    cout << myCar1.brand << endl;
    cout << myCar1.model << endl;
    cout << myCar1.year << endl;

    cout << myCar2.brand << endl;
    cout << myCar2.model << endl;
    cout << myCar2.year << endl;
*/
    level myLevel = HIGH;
    cout << myLevel << endl;

    string food = "Food";
    string &foodRef = food;

    food = "Food 2";

    cout << foodRef << endl;
    cout << food << endl;

    string food2 = "Second Food";
    string* foodRef2 = &food2;
    cout << foodRef2 << endl;
    cout << *foodRef2 << endl;

    myFunctionDeclaration();

    string myTestName = "name";
    string surname = "surname";

    cout << myTestName << endl;
    cout << surname << endl;

    myFunctionDeclarationWithParameter(myTestName, surname);

    cout << myTestName << endl;
    cout << surname << endl;

    printNameAndSurname("Özgürhan","Polat");
    printNameAndSurname("Ahmet","Durmuş");
    printNameAndSurname("Ali","Polat");

    int number1 = 10;
    int number2 = 20;
    cout <<"Number 1 : " <<number1 << endl;
    cout <<"Number 2 : "<< number2 << endl;
    cout << returnSummation(number1,number2) <<endl;
    cout << "Number 1 new : "<< number1 << endl;
    cout << "Number 2 new : " << number2 << endl;


    int x = 12;
    int y = 15;
    cout << "x : " <<x << endl;
    cout << "y : " <<y << endl;
    swapNumbers(x,y);
    cout << "x new : " <<x << endl;
    cout << "y new : " <<y << endl;


    vector<string> words2;
    words2.emplace_back("first");
    words2.emplace_back("second");
    words2.emplace_back("third");

    cout <<"word 2 : " << words2.size() << endl;

    double valueDouble =  plusFunc(2.2,2.3);
    int valueInt = plusFunc(2,3);
    cout << valueDouble << endl;
    cout << valueInt << endl;

    globalVariable = "Global Variable Value";
    cout <<"Global Variable : "<< globalVariable << endl;

    return 0;
}


void myFunctionDeclaration() {
    cout << "My function declaration is made" << endl;
}

void myFunctionDeclarationWithParameter(string name, string surname, string password) {

    name = "Ahmet";
    surname = "Durmaz";

}
void printNameAndSurname(string name,string surname) {
    cout << "Name: " << name << endl;
    cout << "Surname: " << surname << endl;
}

int returnSummation(int &number1, int &number2) {
    number1 = number1 + 2;
    number2 = number2 + 2;

    return number1 + number2;
}

void swapNumbers(int &number1, int &number2) {
    const int temp = number1;
    number1 = number2;
    number2 = temp;
}

int plusFunc(const int number1, const int number2) {
    return number1 + number2;
}
double plusFunc(const double number1, const double number2) {
    return number1 + number2;
}

void tryCatchBlokDemo() {
    try {
        int num = 10;
        if(num == 10) {
            throw 505;
        }else {
            cout << num << endl;
        }
    }catch (int num) {
        cout << "Exception caught: " << num << endl;
    }
}
