#include<iostream>

using namespace std;

class Queue{
    class Node{
        public:
            int data;
            Node *next;

            Node(int data){
                this->data = data;
                this->next = NULL;
            }
    };
    
    Node *front;
    Node *rear;

    public:
        Queue(){
            front = NULL;
            rear = NULL;
        }

        void enQueue(int data){
            Node *newNode = new Node(data);
            if(front == NULL){
                front = newNode;
                rear = newNode;
            }
            else{
                rear->next = newNode;
                rear = newNode;
            }        
        }

        void deQueue(){
            Node *current = front;
            if(front == NULL){
                cout<<"Queue is empty!\n";
                return;
            }
            else{
                Node *toDel = front;
                front = front->next;
                delete toDel;
            }
        }

        void display(){
            Node *current = front;
            if(front == NULL){
                cout<<"Queue is empty!\n";
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
    Queue q;
    int choice, data;
    cout<<"1. Enqueue an element: \n";
    cout<<"2. Dequeue an element: \n";
    cout<<"3. Display the queue: \n";
    cout<<"4. Exit: \n";
    do{
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the element to be inserted: ";
                cin>>data;
                q.enQueue(data);
                break;
            case 2:
                q.deQueue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice!\n";
        }
    }while(choice != 4);
    return 0;
}