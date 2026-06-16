#include<iostream>
#include<fstream>

using namespace std;

struct Student
{
    int roll;
    float marks;
};

int main()
{
    // // Writing
    // int age = 20;

    // ofstream file("data_binary.bin", ios::binary);

    // file.write((char*)&age, sizeof(age));

    // file.close();


    // // Reading

    ifstream file("data_binary.bin", ios::binary);

    // int a = 10;
    // int b = 20;
    // int c = 30;

    // file.write((char*)&a, sizeof(a));
    // file.write((char*)&b, sizeof(b));
    // file.write((char*)&c, sizeof(c));

    // int a,b,c;

    // file.read((char*)&a, sizeof(a));
    // file.read((char*)&b, sizeof(b));
    // file.read((char*)&c, sizeof(c));

    // cout << a << " " << b << " " << c;
    

    // Writing objects/structures in files
    // struct Student s;
    // s.roll = 1; s.marks = 92.5;
    // file.write((char*)&s, sizeof(s));

    // // Reading objs/structs in file
    // struct Student s;

    // file.read((char*)&s, sizeof(s));

    // cout << s.roll << endl;
    // cout << s.marks;

    

    // Student s1 = {1, 90};
    // Student s2 = {2, 80};
    // Student s3 = {3, 70};

    // file.write((char*)&s1, sizeof(Student));
    // file.write((char*)&s2, sizeof(Student));
    // file.write((char*)&s3, sizeof(Student));

    // // file contains [Student1][Student2][Student3]

    // // Reading until eof

    Student s;

    // while(file.read((char*)&s, sizeof(Student))) {
    //     cout << s.roll << " "
    //         << s.marks << endl;
    // }

    // // jump directly / random access (IMP)
    // file.seekg(2 * sizeof(Student));
    // file.read((char*)&s, sizeof(s));

    // cout << s.roll << " " << s.marks << endl;
    // file.close();

    return 0;
}