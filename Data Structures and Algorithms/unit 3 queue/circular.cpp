#include <iostream>

using namespace std;

class CircularQueue
{
private:
    int rear, front;
    int size;
    int *arr;
    int itemCount;

public:
    CircularQueue(int x)
    {
        front = rear = -1;
        size = x;
        arr = new int[size];
    }

    bool isFull()
    {
        if ((rear + 1) % size == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    	void makeQueueEmpty(){
		front = -1;
		rear = -1;
		cout<<"The queue has been cleared"<<endl;
	}

    void enQueue(int num)
    {
        if (isFull())
        {
            cout << "Queue is full!" << endl;
            return;
        }
        else if (isEmpty())
        {
            rear = 0;
            front = 0;
            arr[rear] = num;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = num;
        }
    }

    void deQueue()
    {
        int element;
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
        }
        else if (front == rear)
        {
            cout << "The dequeued element is" << arr[front];
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }
    void displayQueue()
    {
        int i;
        if (isEmpty())
        {
            cout << endl
                 << "Queue is Empty!!" << endl;
        }
        else
        {
            cout << endl
                 << "Front = " << front;
            cout << endl
                 << "Queue elements : ";
            for (i = front; i != rear; i=(i+1)%size)
                cout << arr[i] << "\t";
            cout<<arr[rear];
            cout << endl
                 << "Rear = " << rear << endl;
        }
    }
};
int main()
{
    int ch;
    char c;
    int arr_size;
    cout<<"Enter queue size: ";
    cin>>arr_size;
    cout << "1) Make queue empty" << endl;
    cout << "2) Insert element to queue" << endl;
    cout << "3) Delete element from queue" << endl;
    cout << "4) Display all the elements of queue" << endl;
    CircularQueue myq(arr_size);
    do
    {
        cout << "Enter your choice : " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            myq.makeQueueEmpty();
            break;
        case 2:
            cout << "Enter the element to insert : ";
            int num;
            cin >> num;
            myq.enQueue(num);
            break;
        case 3:
            myq.deQueue();
            break;
        case 4:
            myq.displayQueue();
            break;
        default:
            cout << "Invalid choice" << endl;
        }
        cout<<"Enter choice(y/n): ";
        cin>>c;
    } while (c == 'y');
    return 0;
}
