//linked list queue

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class Queue{
private:
    Node *front;
    Node *rear;
public:
    Queue(){front = rear = NULL;}
    void enqueue(int x);
    int dequeue();
    void Display();
};

void Queue::enqueue(int x){
    Node *temp = new Node;
    if(temp == NULL)
        cout << "Queue is full" << endl;
    else{
        temp->data = x;
        temp->next = NULL;
        if(front == NULL)
            front = rear = temp;
        else{
            rear->next = temp;
            rear = temp;
        }
    }
}

int Queue::dequeue(){
    int x = -1;
    if(front == NULL)
        cout << "Queue is empty" << endl;
    else{
        x = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    return x;
}

void Queue::Display(){
    Node *p = front;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Queue q;
    int choice;
    char ch;
    cout<<"1. Enqueue"<<endl;
    cout<<"2. Dequeue"<<endl;
    cout<<"3. Display"<<endl;
    do{
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter the element to be inserted: ";
                cin>>choice;
                q.enqueue(choice);
                break;

            case 2:
                cout<<"The deleted element is: "<<q.dequeue()<<endl;
                break;

            case 3:
                q.Display();
                break;

            default:
                cout<<"Invalid choice"<<endl;
        }
        cout<<"Do you want to continue(y/n): ";
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
    return 0;
}

