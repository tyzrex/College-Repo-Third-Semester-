#include<iostream>

using namespace std;

class Stack{
    private:
        int num;
        int top;
        int * arr;

    public:
        Stack(int size){
            num = size;
            arr = new int [size];
            top = -1;
        }    

        bool isFull(){
            if(top == num-1){
                return true;
            }
            return false;
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }
            return false;
        }

        void push(int elem){
            if(isFull()){
                cout<<"Stack is full!\n";
                return;
            }
            top++;
            arr[top] = elem;
        }

        void pop(){
            if(isEmpty()){
                cout<<"The stack is empty!\n";
                return;
            }
            else{
                int temp;
                temp = arr[top];
                top--;
                cout<<"The popped item is: "<<temp<<endl;
            }
        }

        void display(){
            if(isEmpty()){
                cout<<"Stack is Empty!\n";
            }
            cout<<"Stack: \n";            
            for(int i = top; i >= 0 ; i--){
                cout<<arr[i]<<"\n";
            }
        }

        int peek(){
            return arr[top];
        }
};

int main(){
	int choice;
    int size;
    cout<<"Enter the size of stack: ";
    cin>>size;
    Stack s(size);
        cout<<"Menu driven program to peform the following stack operation:"<<endl;
		cout<<"1.Press 1 for push operation"<<endl;
		cout<<"2.Press 2 for pop operation"<<endl;
		cout<<"3.Press 3 for peek operation"<<endl;
		cout<<"4.Press 4 for display item in stack"<<endl;
        cout<<"5.Press 5 to exit"<<endl;
	do{
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				int x;
				cout<<"Enter element to push: ";
				cin>>x;
				s.push(x);
				break;
				
			case 2:
				s.pop();
				break;
				
			case 3:
				s.peek();
                cout<<"The top element is: "<<s.peek()<<endl;
				break;
			
			case 4:
				s.display();
				break;

            case 5:
                break;    
			
			default:
				cout<<"Wrong choice try again.";
		}	
	}while(choice != 5);
	return 0;
}
