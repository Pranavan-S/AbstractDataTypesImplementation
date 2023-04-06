#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class Stack{
    private:
        Node* top;

    public:
        Stack() {
            top = nullptr;
        }

        bool isEmpty() {
            if (top == nullptr){
                return true;
            }
            return false;
        }

        void push(int data) {
            Node* temp = new Node(data);
            temp->next = top;
            this->top = temp;
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow.\n";
                return -1;
            }
            Node* temp = top;
            top = top->next;
            return temp->data;
        }

        int stackTop() {
            if (isEmpty()) {
                cout << "Stack is empty.\n";
                return -1;
            }
            return top->data;
        }
        void display(){
            if (this->isEmpty()){
                cout<<"Stack is empty\n";
            }
            Node* currentNode = top;
            cout<<"[";
            while (currentNode != nullptr){
                cout<<currentNode->data<<", ";
                currentNode = currentNode->next;
            }
            cout<<"]"<<endl;
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