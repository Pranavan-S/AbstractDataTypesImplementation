#include<iostream>
using namespace std;

class Stack{
    private:
        int arr[100];
        int top;
    public:
        Stack(){
            top = -1;
        }

        bool isEmpty(){
            if (top == -1){
                return true;
            }
            return false;
        }

        bool isFull(){
            if (top == 99){
                return true;
            }
            return false;
        }

        void push(int data){
            if (this->isFull()){
                cout<<"Stack Overflow.\n";
                return;
            }
            arr[++top] = data;
        }

        int pop(){
            if (this->isEmpty()){
                cout<<"Stack Underflow.\n";
                return -1 ;
            }
            return arr[top--];
        }

        int stackTop(){
            if (this->isEmpty()){
                cout << "Stack is Empty.\n";
                return -1;
            }
            return arr[top];
        }

        void display(){
            if (this->isEmpty()){
                cout<<"Stack is Empty.\n";
                return;
            }
            cout<<"[";
            for (int i=0;i<this->top;i++){
                cout<<arr[i]<<", ";
            }
            cout<<"]"<<endl;
            return;
        }
};

int main(){
    Stack stack;
    stack.push(8);
    stack.push(10);
    stack.push(5);
    stack.push(11);
    stack.push(15);
    stack.push(23);
    stack.push(6);
    stack.push(18);
    stack.push(20);
    stack.push(17);
    stack.display();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();
    stack.push(4);
    stack.push(30);
    stack.push(3);
    stack.push(8);
    stack.display();
    return 0;
}