/** Implementing the student database using an Array
 * Author : Abhishek Kinagi
 */
#include <bits/stdc++.h>
using namespace std;

class Student{
    int id;
    string name;
    
};

class StudentDatabase{
private:
    int* A;
    int size;
public:
    Array(){
        A = new int[10000000000];
        size=0;
    }
    int get(int i){
        if(i>=0 && i<size){
            return A[i];
        }
        return NULL;
    }

};