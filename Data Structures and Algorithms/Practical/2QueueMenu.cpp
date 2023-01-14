#include <iostream>

using namespace std;

class Queue
{
private:
    int num;
    int front;
    int rear;
    int *arr;

public:
    Queue(int size)
    {
        num = size;
        arr = new int[num];
        front = rear = -1;
    }

    bool isFull()
    {
        if (rear == num - 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (rear == -1)
        {
            return true;
        }
        return false;
    }

    void enQueue(int elem)
    {
        if (isFull())
        {
            cout << "Queue is full!\n";
            return;
        }
        if (isEmpty())
        {
            rear = 0;
            front = 0;
        }
        else{
            rear++;
        }
        arr[rear] = elem;
    }

    void deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        int temp = arr[front];
        if(front>=rear){
            rear = front = -1;
        }
        front++;
        cout << "Dequeued element is: " << temp << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty! \n";
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << "\n";
    }

    void makeQueueEmpty(){
        rear = front = -1;
        return;
    }
};

int main()
{
    int ch;
    int size;
    cout<<"Enter queue size: ";
    cin>>size; 
    cout << "1) Make queue empty\n";
    cout << "2) Insert element to queue\n";
    cout << "3) Delete element from queue\n";
    cout << "4) Display all the elements of queue\n" ;
    cout << "5) Exit\n";
    Queue myq(size);
    do
    {
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            myq.makeQueueEmpty();
            break;
        case 2:
            cout << "Enter the element to insert: ";
            int num;
            cin >> num;
            myq.enQueue(num);
            break;
        case 3:
            myq.deQueue();
            break;
        case 4:
            myq.display();
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (ch!=5);
    return 0;
}