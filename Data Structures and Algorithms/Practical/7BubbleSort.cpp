#include<iostream>

using namespace std;

void readArray(int *arr, int size){
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
}

void displayArray(int *arr, int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int *arr, int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array: ";
    readArray(arr, size);
    cout<<"Array before sorting: ";
    displayArray(arr, size);
    bubbleSort(arr, size);
    cout<<"Array after sorting: ";
    displayArray(arr, size);
    return 0;
}