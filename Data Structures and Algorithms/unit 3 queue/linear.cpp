#include <iostream>
 
#define MAX_SIZE 5
using namespace std;
 
class Queue {
  private:
    int myqueue[MAX_SIZE], front, rear;
 
  public:
    Queue() {
      front = -1;
      rear = -1;
    }
 
  bool isFull() {
    if (front == 0 && rear == MAX_SIZE - 1) {
      return true;
    }
    return false;
  }
 
  bool isEmpty() {
    if (front == -1) return true;
    else return false;
  }
 
	void makeQueueEmpty(){
		front = -1;
		rear = -1;
		cout<<"The queue has been cleared"<<endl;
	}
 
  void enQueue(int value) {
    if (isFull()) {
      cout << endl << "Queue is full!!";
    } else {
      if (front == -1) front = 0;
      rear++;
      myqueue[rear] = value;
    }
  }
  int deQueue() {
    int value;
    if (isEmpty()) {
      cout << "Queue is empty!!" << endl;
      return (-1);
    } else {
      value = myqueue[front];
      if (front >= rear) { //only one element in queue
        front = -1;
        rear = -1;
      } else {
        front++;
      }
      cout << endl << "Deleted => " << value << " from myqueue";
      return (value);
    }
}
 
  /* Function to display elements of Queue */
  void displayQueue() {
    int i;
    if (isEmpty()) {
      cout << endl << "Queue is Empty!!" << endl;
    } else {
      cout << endl << "Front = " << front;
      cout << endl << "Queue elements : ";
      for (i = front; i <= rear; i++)
        cout << myqueue[i] << "\t";
      cout << endl << "Rear = " << rear << endl;
    }
  }
};
int main() {
	 int ch;
     char c;
	cout<<"1) Make queue empty"<<endl;
   cout<<"2) Insert element to queue"<<endl;
   cout<<"3) Delete element from queue"<<endl;
   cout<<"4) Display all the elements of queue"<<endl;
   cout<<"5) Exit"<<endl;
  Queue myq;
 do {
      cout<<"\nEnter your choice : "<<endl;
      cin>>ch;
      switch (ch) {
         case 1: myq.makeQueueEmpty();
         break;
         case 2: 
		 	cout<<"Enter the element to insert: ";
		 	int num;
		 	cin>>num;
		 	myq.enQueue(num);
         break;
         case 3: myq.deQueue();
         break;
         case 4: myq.displayQueue();
         break;
         default: cout<<"Invalid choice"<<endl;
      }
      cout<<"Do you want to continue? (y/n)"<<endl;
   } while (cin>>c && c=='y');
  return 0;
}