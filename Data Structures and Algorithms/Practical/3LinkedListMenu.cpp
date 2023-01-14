#include<iostream>

using namespace std;

class Node{
    public:
        Node *next;
        int data;

        Node(int val){
            data = val;
        }
};

class LinkedList{
    private:
        Node *head;

    public:
        LinkedList(){
            head = NULL;
        }

        void insertAtBeginning(int val){
            Node *newNode = new Node(val);
            if(head == NULL){
                head = newNode;
            }
            
        }
};