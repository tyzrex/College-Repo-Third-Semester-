#include<iostream>

using namespace std;

class LinkedList{
    class Node{
        public:
            int data;
            Node *next;

            Node(int data){
                this->data = data;
                this->next = NULL;
            }
    };

    Node *head;
    
    public:
        LinkedList(){
            head = NULL;
        }

        void insertAtBeginning(int data){
            Node *newNode = new Node(data);
            if(head == NULL){
                head = newNode;
            }else{
                newNode->next = head;
                head = newNode;
            }
        }

        void insertAtTail(int data){
            Node *newNode = new Node(data);
            if(head == NULL){
                insertAtBeginning(data);
            }
            else{
                Node *temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void insertAtPosition(int data, int position){
            Node *newNode = new Node(data);
            if(head == NULL){
                insertAtBeginning(data);
            }
            else{
                Node *temp = head;
                for(int i=1; i<position-1; i++){
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }

        void deleteAtBeginning(){
            if(head == NULL){
                cout<<"List is empty"<<endl;
            }
            else{
                Node *temp = head;
                head = head->next;
                delete temp;
            }
        }

        void deleteAtTail(){
            if(head == NULL){
                cout<<"List is empty"<<endl;
            }
            else{
                Node *temp = head;
                while(temp->next->next != NULL){
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = NULL;
            }
        }

        void deleteAtPosition(int position){
            if(head == NULL){
                cout<<"List is empty"<<endl;
            }
            else{
                Node *temp = head;
                int counter = 1;
                while(counter < position && temp->next != NULL){
                    temp = temp->next;
                    counter++;
                }
                Node *temp2 = temp->next;
                temp->next = temp->next->next;
                delete temp2;
            }
        }

        void display(){
            if(head == NULL){
                cout<<"List is empty"<<endl;
            }
            else{
                Node *temp = head;
                while(temp != NULL){
                    cout<<temp->data<<" ";
                    temp = temp->next;
                }
                cout<<endl;
            }
        }
};

int main(){
    LinkedList list;
    int choice, data, position;
    cout<<"1. Insert at beginning"<<endl;
    cout<<"2. Insert at tail"<<endl;
    cout<<"3. Insert at position"<<endl;
    cout<<"4. Delete at beginning"<<endl;
    cout<<"5. Delete at tail"<<endl;
    cout<<"6. Delete at position"<<endl;
    cout<<"7. Display"<<endl;
    cout<<"8. Exit"<<endl;
    while(1){

        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter data: ";
                cin>>data;
                list.insertAtBeginning(data);
                break;
            case 2:
                cout<<"Enter data: ";
                cin>>data;
                list.insertAtTail(data);
                break;
            case 3:
                cout<<"Enter data: ";
                cin>>data;
                cout<<"Enter position: ";
                cin>>position;
                list.insertAtPosition(data, position);
                break;
            case 4:
                list.deleteAtBeginning();
                break;
            case 5:
                list.deleteAtTail();
                break;
            case 6:
                cout<<"Enter position: ";
                cin>>position;
                list.deleteAtPosition(position);
                break;
            case 7:
                list.display();
                break;
            case 8:
                exit(0);
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}