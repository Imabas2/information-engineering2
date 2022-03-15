#include <iostream>
#include <vector>
using namespace std;




class Student {
    string name;
    string surname;
    int albumNumber = 0;
    vector<float> grades;

public:
    Student(string newName) {
        name = newName;
    }

    Student(string newName, string newSurname, int newAlbumNumber) {
        name = newName;
        surname = newSurname;
        albumNumber = newAlbumNumber;
    }

    void set_name(string newName) { // setter
        name = newName;

    }
    void set_surname(string newsurname) { // setter
        surname = newsurname;

    }
    void set_albumNumber(int new_albumNumber) { // setter
        albumNumber = new_albumNumber;

    }
     void set_grades(vector<float> new_grades) { // setter
            grades = new_grades;
    }

     void add_new_grade(float new_grade) { // setter
            grades.push_back(new_grade);
    }

    void student_summary(){
        cout << "student data!" << endl;
        cout << "First Name: " << name << endl;
        cout << "Surname: " << surname <<endl;
        cout << "Album number: " << albumNumber << endl;
        cout << "Grades: " << endl;
        float sum = 0.0;
        for(auto grade : grades)
        {
            sum = sum + grade;
            cout << grade << endl;
        }
        cout<<"The sum of the grades: " <<sum<<endl;
        float mean=sum/grades.size();
        cout<<"The mean of the grades is: "<<mean<<endl;
        if(mean>=2.0){
            cout<<"You have pass:"<<endl;
        }
        else
        {
            cout<<" Sorry! you have failed "<<endl;
        }
       }





};

int main()
{
    string name;
    string surname;
    int albumNumber = 0;
    vector<float> grades;
    float grade;

    cout<<"Enter name"<< endl;
    cin>>name;
    cout<<"Enter surname"<< endl;
    cin>>surname;
    cout<<"Enter Album number:" << endl;
    cin>>albumNumber;
    cout<<"Enter 5 grades:" << endl;

    for(int i=0; i<3; i++)
    {
    cout<< i << " grade:" << endl;
    cin>>grade;
    grades.push_back(grade);
    }
    Student student1(name, surname, albumNumber);
    student1.set_grades(grades);
    student1.student_summary();
    return 0;
}
