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
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.Display();
    cout << q.dequeue() << endl;
    q.Display();
    return 0;
}

