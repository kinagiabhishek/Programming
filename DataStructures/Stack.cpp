/** Implementing a basic Integer Stack using a fixed size Array
 * Author : Abhishek Kinagi
 */
#include<bits/stdc++.h>
#define N 1000000
using namespace std;
class Stack{
private:
    int* A;
    int top;
public:
    /**
     * Constructor to initialize Stack
     */
    Stack():A{new int[N]},top{-1}{};
    /**
     * Push element at the top of stack
     */
    void push(int num){
        if(top==N-1){
            cout<<"Stack is Full, Operation Failed"<<endl;
            return;
        }
        A[++top]=num;
    }
    /**
     * Pop the top element from the Stack, and return it
     */
    int pop(){
        if(top==-1){
            cout<<"Stack is Empty, Operation Failed"<<endl;
            return 0;
        }
        return A[top--];
    }
    /**
     * Check if stack is empty
     */
    bool isEmpty(){
        return top==-1;
    }
    /**
     * Get the top element present on the stack
     */
    int topElement(){
        if(top==-1){
            cout<<"Stack is Empty, Operation Failed"<<endl;
            return 0;
        }
        return A[top];
    }
    /**
     * Get size of stack
     */
    int size(){
        return top+1;
    }
};
int main(){
    Stack s;
    bool menu=true;
    char choice;
    int num;
    while(menu){
        cout<<"Welcome to Integer Stack!"<<endl;
        cout<<"Select operation:"<<endl;
        cout<<"a.Push"<<endl;
        cout<<"b.Pop"<<endl;
        cout<<"c.Top"<<endl;
        cout<<"d.Size"<<endl;
        cout<<"e.isEmpty"<<endl;
        cout<<"f.Quit"<<endl;
        cin>>choice;
        switch(choice){
            case 'a':
                    cout<<"Please enter an element:";
                    cin>>num;
                    s.push(num);
                    break;
            case 'b':
                    num=s.pop();
                    cout<<num<<endl;
                    break;
            case 'c':
                    num=s.topElement();
                    cout<<num<<endl;
                    break;
            case 'd':
                    cout<<s.size()<<endl;
                    break;
            case 'e':
                    if(s.isEmpty())
                        cout<<"Stack is empty"<<endl;
                    else
                        cout<<"Stack is not empty"<<endl;
                    break;
            case 'f':
                    cout<<"Good Bye!"<<endl;
                    menu=false;
                    break;
            default:
                    cout<<"Invalid choice, please choose again"<<endl;
                    break;
        }
    }
    return 0;
}