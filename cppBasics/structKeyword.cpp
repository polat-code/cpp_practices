#include <iostream>
#include <string>
using namespace std;

struct {
    int myNumber;
    string myString;
} myStruct;


void structKeywordMethod() {
    myStruct.myNumber = 12;
    myStruct.myString = "hello world";
    cout << myStruct.myNumber << endl;
    cout << myStruct.myString << endl;
}

