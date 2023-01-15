#include<iostream>

using namespace std;

class Stack{
    class Node{
        public:
            int data;
            Node *next;

            Node(int data){
                this->data = data;
                this->next = NULL;
            }
    };
    Node *top;
    public:
    Stack(){
        top = NULL;
    }  

    void push(int data){
        Node *newNode = new Node(data);
        if(top == NULL){
            top = newNode;
            return;
        }
        else{
            newNode->next = top;
            top = newNode;
        }
    }

    void pop(){
        Node *current = top;
        if(top == NULL){
            cout<<"Stack is empty!\n";
            return;
        }
        else{
            Node *toDel = top;
            top = top->next;
            delete toDel;
        }
    }

    void display(){
        Node *current = top;
        if(top == NULL){
            cout<<"Stack is empty!\n";
            return;
        }
        else{
            while(current != NULL){
                cout<<current->data<<"\n";
                current = current->next;
            }
            cout<<endl;
        }
    }
};

int main(){
    Stack s;
    int choice, data;
    cout<<"1. Push\n2. Pop\n3. Display\n4. Exit\n";
    while(1){
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter data: ";
                cin>>data;
                s.push(data);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                exit(0);
            default:
                cout<<"Invalid choice!\n";
        }
    }
    return 0;
}