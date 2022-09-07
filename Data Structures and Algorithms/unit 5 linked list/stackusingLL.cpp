//make a class for linked list

#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
};

//stack implementation using linked list
class Stack{
private:
    Node *top;
public:
    Stack(){top = NULL;}
    void push(int x);
    int pop();
    void Display();
};

//push in stack 
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

//pop in stack
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

//display stack
void Stack::Display(){
    Node *p = top;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

//driver code
int main()
{
    int choice;
    char ch;
    Stack stk;
    do{
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<"1) Push in stack"<<endl;
        cout<<"2) Pop in stack"<<endl;
        cout<<"3) Display stack"<<endl;
        cout<<"4) Exit"<<endl;

        switch(choice){
            case 1:
                int x;
                cout<<"Enter element to push: ";
                cin>>x;
                stk.push(x);
                break;

            case 2:
                stk.pop();
                break;

            case 3:
                stk.Display();
                break;
            
            default:
                cout<<"Enter valid number";
        }
        cout<<"Do you want to continue? (y/n): ";
        cin>>ch;
    }while (ch == 'y' || ch == 'Y');
    return 0;
}

