#include<iostream>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string name, int age) {
        this -> name = name;
        this -> age = age;
    }
};

class Student : public Person {
public:
    int studentId;
    Student(int studentId, string name, int age) : Person(name, age) {
        this -> studentId = studentId;
    }

    void displayStudentInfo() {
        cout << "Student id: " << this -> studentId << endl;
        cout << "Student name: " << this -> name << endl;
        cout << "Student age: " << this -> age << endl;
    }
};

int main() {
    Student s1(1, "Alice", 20);
    s1.displayStudentInfo();
}