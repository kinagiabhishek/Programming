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
    StudentDatabase(){
    }
    /**
     * Add a student into the database (Duplicate Ids not allowed)
     */
    void addStudentRecord(int id, string firstName, string lastName, char grade){
        if(idList.count(id)>0){
            cout<<"Id already present, please try again!"<<endl;
            cout<<"Failed!"<<endl;
        }else{
            Student s(id,firstName,lastName,grade);
            db.push_back(s);
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
        for(int i=0;i<db.size();++i){
            if(db[i].id==id){
                db[i].grade=grade;
                cout<<"Success!"<<endl;
                return;
            }
        }
        cout<<"Id incorrect, try again"<<endl;
        cout<<"Failed!"<<endl;
    }
    /**
     * Delete a student for a given ID
     */
    void deleteRecordId(int id){
        for(auto i=db.begin();i!=db.end();++i){
            if(i->id==id){
                db.erase(i);
                cout<<"Success!"<<endl;
                break;
            }
        }
    }
    /**
     * Delete student(s) for a given first Name
     */
    void deleteRecordFirstName(string firstName){
        vector<int> tmpList;
        for(auto i=db.begin();i!=db.end();++i){
            if(i->id==id){
                db.erase(i);
                cout<<"Success!"<<endl;
                break;
            }
        }
    }
    /**
     * Delete student(s) for a given last Name
     */
    void deleteRecordLastName(int id){
        for(auto i=db.begin();i!=db.end();++i){
            if(i->id==id){
                db.erase(i);
                cout<<"Success!"<<endl;
                break;
            }
        }
    }
};