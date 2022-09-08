#include<iostream>

using namespace std;

void readArray(int *arr, int size);
void displayArray(int *arr,int size);
void selectionSort(int *arr, int size);
void swap(int *a, int *b);

int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array: ";
    readArray(arr,size);
    cout<<"The elements of the array are: "<<endl;
    displayArray(arr,size);
    selectionSort(arr,size);
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

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int size){
    int i,j,min;
    for(i = 0;i<size-1;i++){
        min = i;
        for ( j = i+1; j < size; j++){
           if(arr[j]<arr[min])
                min = j; 
        }
        swap(&arr[i],&arr[min]);
    }
}