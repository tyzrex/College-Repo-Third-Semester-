//linked list implement stack

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class Stack{
private:
    Node *top;
public:
    Stack(){top = NULL;}
    void push(int x);
    int pop();
    void Display();
};

void Stack::push(int x){
    Node *temp = new Node;
    if(temp == NULL)
        cout << "Stack is full" << endl;
    else{
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}

int Stack::pop(){
    int x = -1;
    if(top == NULL)
        cout << "Stack is empty" << endl;
    else{
        x = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
    }
    return x;
}

void Stack::Display(){
    Node *p = top;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.Display();
    cout << stk.pop() << endl;
    stk.Display();
    return 0;
}