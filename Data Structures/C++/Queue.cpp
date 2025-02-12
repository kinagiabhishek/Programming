/** Implementing a basic Integer Circular Queue using a fixed size Array
 * Author : Abhishek Kinagi
 */
#include<bits/stdc++.h>
#define N 10000000
using namespace std;
class Queue{
private:
    int* A;
    int front;
    int back;
    bool empty;
public:
    /**
     * Constructor to initialize Queue
     */
    Queue():A{new int[N]},front{0},back{-1},empty{true}{};
    /**
     * Push element at the end of queue
     */
    void push(int num){
        if(!empty && (back+1)%N==front){
            cout<<"Queue is Full, Operation Failed"<<endl;
            return;
        }
        back=(back+1)%N;
        A[back]=num;
        empty=false;
    }
    /**
     * Pop the top element from the Stack, and return it
     */
    int pop(){
        if(empty){
            cout<<"Queue is Empty, Operation Failed"<<endl;
            return 0;
        }
        int ret=A[front];
        // Single element present in queue, set the queue to empty
        if(front==back)
            empty=true;
        front=(front+1)%N;
        return ret;
    }
    /**
     * Get the front element of the queue
     */
    int frontElement(){
        if(empty){
            cout<<"Queue is Empty, Operation Failed"<<endl;
            return 0;
        }
        return A[front];
    }
    /**
     * Get the back element of the queue
     */
    int backElement(){
        if(empty){
            cout<<"Queue is Empty, Operation Failed"<<endl;
            return 0;
        }
        return A[back];
    }
    /**
     * Get size of queue
     */
    int size(){
        if(empty)
            return 0;
        if(back>=front)
            return (back-front+1);
        if(front>back)
            return (N-(front-back-1)); 
        return -1;
    }
    /**
     * Check if queue is empty
     */
    bool isEmpty(){
        return empty;
    }
};
int main(){
    Queue q;
    bool menu=true;
    char choice;
    int num;
    while(menu){
        cout<<"Welcome to Integer Queue!"<<endl;
        cout<<"Select operation:"<<endl;
        cout<<"a.Push"<<endl;
        cout<<"b.Pop"<<endl;
        cout<<"c.Front"<<endl;
        cout<<"d.Back"<<endl;
        cout<<"e.Size"<<endl;
        cout<<"f.isEmpty"<<endl;
        cout<<"g.Quit"<<endl;
        cin>>choice;
        switch(choice){
            case 'a':
                    cout<<"Please enter an element:";
                    cin>>num;
                    q.push(num);
                    break;
            case 'b':
                    num=q.pop();
                    cout<<num<<endl;
                    break;
            case 'c':
                    num=q.frontElement();
                    cout<<num<<endl;
                    break;
            case 'd':
                    num=q.backElement();
                    cout<<num<<endl;
                    break;
            case 'e':
                    cout<<q.size()<<endl;
                    break;
            case 'f':
                    if(q.isEmpty())
                        cout<<"Queue is empty"<<endl;
                    else
                        cout<<"Queue is not empty"<<endl;
                    break;
            case 'g':
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