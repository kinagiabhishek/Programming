#include <bits/stdc++.h>
using namespace std;
struct Student{
    int id;
    string firstName;
    string lastName;
    char grade;
    Student();
    Student(int id,string firstName="",string lastName="",char grade='D'):
    id{id},firstName{firstName},lastName{lastName},grade{grade}{};
};