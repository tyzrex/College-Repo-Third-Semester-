#include<iostream>

using namespace std;

void readArray(int *arr, int size);
void displayArray(int *arr,int size);
void insertionSort(int *arr, int size);

int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array: ";
    readArray(arr,size);
    cout<<"The elements of the array are: "<<endl;
    displayArray(arr,size);
    // shell sort algorithm
    insertionSort(arr,size);
    cout<<"\nThe sorted array is: "<<endl;
    displayArray(arr,size);
    return 0;
}

void readArray(int *arr, int size){
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
}

void displayArray(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
}

void insertionSort(int *arr, int size){
    int i,j,key;
    for(i=1;i<size;i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}