#include <iostream> 
using namespace std;

// Class: user-defined data typed that is blueprint for objects
class Student {
    // Encapsulation: binding together data and functions that manipulates them.
    // Information hiding: access modifiers: Private, Protected, Public.
    protected: 
        string firstname;
        string lastname;
    public:
        string classid;

        // Polymorphism: provision of a single interface to entities of different types
        // Overloading: functions with same name but different behavior may exist.  
        Student(string newfirstname, string newlastname, string newclassid) {
            firstname = newfirstname;
            lastname = newlastname;
            classid = newclassid;
            cout << "Student: \tNew Student " << firstname << " created! " << endl;
        }

        Student() {
            firstname = "Default";
            lastname = "Wong";
            classid = "1A";
            cout << "Student: \tStudent with default data created! " << endl;
        }

        void getInfo() {
            // Information hiding - only show part of the data. 
            cout << "getInfo: \t"  << firstname << " " << lastname[0] << " from F" << classid[0] << endl;
        }

        void setClass(string newclassid) {
            if (isdigit(newclassid[0]) and isalpha(newclassid[1]) and newclassid[2] == '\0') {
                classid = newclassid;
                cout << "setClass: \tClass of " << firstname << " is updated as " << newclassid << "!" << endl;
            }
            else {
                cout << "setClass: \tWrong format for new class " << newclassid <<"! Please confirm! " << endl;
            }
        }
};

// Inheritance: (relationship between different classes) reuse code from other classes.
class ICTStudent: public Student {
    private:
        string elective;

    public:
        ICTStudent(string newfirstname, string newlastname, string newclassid, string newelective) {
            firstname = newfirstname;
            lastname = newlastname;
            classid = newclassid;
            elective = newelective;
            cout << "ICTStudent: \tStudent renamed as " << firstname << "! " << endl;
        }
        void getElective() {
            cout << "getElective: \t" << elective;
        }
};

int main () {
    // Objects
    Student dex("Dex", "Wong", "8A");
    Student sample;

    // Abstraction: Call without knowing the algorithm behind
    dex.getInfo();
    sample.getInfo();

    // dex.firstname = "NEW";   // Not allowed
    // dex.classid = "9A";      // Allowed
    dex.setClass("B9");
    dex.setClass("9B");
    dex.getInfo();

    // Inheritance
    ICTStudent coder("Coder", "Wong", "9A", "Programming");
    coder.getInfo();
    coder.getElective();
}