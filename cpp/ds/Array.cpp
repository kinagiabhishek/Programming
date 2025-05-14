/** Implementing the student database using an Array
 * Author : Abhishek Kinagi
 */
#include <bits/stdc++.h>
#include "Student.h"
using namespace std;

class StudentDatabase{
private:
    vector<Student> db;
    unordered_map<int,bool> idList;
public:
    /**
     * Constructor
     */
    StudentDatabase(){}
    /**
     * print selected student(s) for a given list
     */
    void printRecords(vector<Student> list){
        for(Student s:list){
            cout<<"Id:"<<s.id<<endl;
            cout<<"First Name:"<<s.firstName<<endl;
            cout<<"Last Name:"<<s.lastName<<endl;
            cout<<"Grade:"<<s.grade<<endl;
        }
    }
    /**
     * print all students
     */
    void printAllRecords(){
        printRecords(db);
    }
    /**
     * Get size of database
     */
    int getSize(){
        return db.size();
    }
    /**
     * Add a student into the database (Duplicate Ids not allowed)
     */
    void addStudentRecord(int id, string firstName, string lastName, char grade){
        if(idList.count(id)>0){
            cout<<"Id already present, please try again!"<<endl;
            cout<<"Failed!"<<endl;
        }else if(!validateGrade(grade)){
            cout<<"Invalid grade, please try again!"<<endl;
            cout<<"Failed!"<<endl;
        }
        else{
            Student s(id,firstName,lastName,grade);
            db.push_back(s);
            idList[id]=true;
            cout<<"Success!"<<endl;
        }
    }
    /**
     * Modify student's first Name, for a given ID
     */
    void modifyRecordFirstName(int id, string firstName){
        for(int i=0;i<db.size();++i){
            if(db[i].id==id){
                db[i].firstName=firstName;
                cout<<"Success!"<<endl;
                return;
            }
        }
        cout<<"Id incorrect, try again"<<endl;
        cout<<"Failed!"<<endl;
    }
    /**
     * Modify student's last Name, for a given ID
     */
    void modifyRecordLastName(int id, string lastName){
        for(int i=0;i<db.size();++i){
            if(db[i].id==id){
                db[i].lastName=lastName;
                cout<<"Success!"<<endl;
                return;
            }
        }
        cout<<"Id incorrect, try again"<<endl;
        cout<<"Failed!"<<endl;
    }
    /**
     * Modify student's Grade, for a given ID
     */
    void modifyRecordGrade(int id, char grade){
        if(validateGrade(grade)){
            for(int i=0;i<db.size();++i){
                if(db[i].id==id){
                    db[i].grade=grade;
                    cout<<"Success!"<<endl;
                    return;
                }
            }
            cout<<"Id incorrect, try again"<<endl;
            cout<<"Failed!"<<endl;
        }else{
            cout<<"Invalid grade, please try again!"<<endl;
            cout<<"Failed!"<<endl;
        }
        
    }
    /**
     * Delete a student for a given ID
     */
    void deleteRecordId(int id){
        for(auto i=db.begin();i!=db.end();++i){
            if(i->id==id){
                idList.erase(i->id);
                db.erase(i);
                cout<<"Success!"<<endl;
                return;
            }
        }
        cout<<"Id incorrect, try again"<<endl;
        cout<<"Failed!"<<endl;
    }
    /**
     * Delete student(s) for a given first Name
     */
    void deleteRecordFirstName(string firstName){
        vector<int> tmpList;
        for(auto i=db.begin();i!=db.end();++i){
            if(i->firstName==firstName){
                tmpList.push_back(i->id);
            }
        }
        for(int i:tmpList){
            deleteRecordId(i);
        }
    }
    /**
     * Delete student(s) for a given last Name
     */
    void deleteRecordLastName(string lastName){
        vector<int> tmpList;
        for(auto i=db.begin();i!=db.end();++i){
            if(i->lastName==lastName){
                tmpList.push_back(i->id);
            }
        }
        for(int i:tmpList){
            deleteRecordId(i);
        }
    }
    /**
     * Search student(s) for a give Id
     */
    void searchId(int id){
        vector<Student> tmp;
        for(Student s:db)
            if(s.id==id)
                tmp.push_back(s);
        printRecords(tmp);
    }
    /**
     * Search student(s) for a give first Name
     */
    void searchFirstName(string firstName){
        vector<Student> tmp;
        for(Student s:db)
            if(s.firstName==firstName)
                tmp.push_back(s);
        printRecords(tmp);
    }
    /**
     * Search student(s) for a give last Name
     */
    void searchLastName(string lastName){
        vector<Student> tmp;
        for(Student s:db)
            if(s.lastName==lastName)
                tmp.push_back(s);
        printRecords(tmp);
    }
    /**
     * Validate a given grade
     */
    bool validateGrade(char grade){
        if(grade>=65 && grade<=70)
            return true;
        else
            return false;
    }
};

int main(){
    StudentDatabase SDB;
    bool menu=true;
    char choice;
    int id;
    string firstName;
    string lastName;
    char grade;
    while(menu){
        cout<<"Welcome to Student Database!"<<endl;
        cout<<"Select operation:"<<endl;
        cout<<"a.Add a student"<<endl;
        cout<<"b.Modify a student's first name"<<endl;
        cout<<"c.Modify a student's last name"<<endl;
        cout<<"d.Modify a student's grade"<<endl;
        cout<<"e.Delete a student for a given ID"<<endl;
        cout<<"f.Delete a student(s) for a given first name"<<endl;
        cout<<"g.Delete a student(s) for a given last name"<<endl;
        cout<<"h.Search a student for a given ID"<<endl;
        cout<<"i.Search a student(s) for a given first name"<<endl;
        cout<<"j.Search a student(s) for a given last name"<<endl;
        cout<<"k.Print all students"<<endl;
        cout<<"l.Get size of database"<<endl;
        cout<<"q.Quit Program"<<endl;
        cin>>choice;
        switch(choice){
            case 'a':
            cout<<"Please enter ID"<<endl;
            cin>>id;
            cout<<"Please enter first name"<<endl;
            cin>>firstName;
            cout<<"Please enter last name"<<endl;
            cin>>lastName;
            cout<<"Please enter grade"<<endl;
            cin>>grade;
            SDB.addStudentRecord(id,firstName,lastName,grade);
            break;
            case 'b':
            cout<<"Please enter ID"<<endl;
            cin>>id;
            cout<<"Please enter new first name"<<endl;
            cin>>firstName;
            SDB.modifyRecordFirstName(id,firstName);
            break;
            case 'c':
            cout<<"Please enter ID"<<endl;
            cin>>id;
            cout<<"Please enter new last name"<<endl;
            cin>>lastName;
            SDB.modifyRecordLastName(id,lastName);
            break;
            case 'd':
            cout<<"Please enter ID"<<endl;
            cin>>id;
            cout<<"Please enter new grade"<<endl;
            cin>>grade;
            SDB.modifyRecordGrade(id,grade);
            break;
            case 'e':
            cout<<"Please enter ID"<<endl;
            cin>>id;
            SDB.deleteRecordId(id);
            break;
            case 'f':
            cout<<"Please enter first name"<<endl;
            cin>>firstName;
            SDB.deleteRecordFirstName(firstName);
            break;
            case 'g':
            cout<<"Please enter last name"<<endl;
            cin>>lastName;
            SDB.deleteRecordLastName(lastName);
            break;
            case 'h':
            cout<<"Please enter ID"<<endl;
            cin>>id;
            SDB.searchId(id);
            break;
            case 'i':
            cout<<"Please enter first name"<<endl;
            cin>>firstName;
            SDB.searchFirstName(firstName);
            break;
            case 'j':
            cout<<"Please enter last name"<<endl;
            cin>>lastName;
            SDB.searchLastName(lastName);
            break;
            case 'k':SDB.printAllRecords();
                     break;
            case 'l':
            SDB.getSize();
            break;
            case 'q':menu=false;
                     break;
            default:cout<<"Invalid choice, please choose again"<<endl;
                    break;
        }
    }   
    return 0;
}