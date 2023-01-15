#include<iostream>

using namespace std;

void getArray(int* arr, int size){
    for(int i=0; i<size; i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }
}

void displayArray(int* arr, int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int linearSearch(int* arr, int size, int key){
    for(int i=0; i<size; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array: ";
    getArray(arr, size);
    cout<<"Array: ";
    displayArray(arr, size);
    int key;
    cout<<"Enter the element to be searched: ";
    cin>>key;
    int index = linearSearch(arr, size, key);
    if(index == -1){
        cout<<"Element not found"<<endl;
    }
    else{
        cout<<"Element found at index "<<index<<endl;
    }
    return 0;
}