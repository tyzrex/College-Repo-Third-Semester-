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

void selectionSort(int *arr, int size){
    for(int i=0; i<size-1; i++){
        int min = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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
    selectionSort(arr, size);
    cout<<"Array after sorting: ";
    displayArray(arr, size);
    return 0;
}
