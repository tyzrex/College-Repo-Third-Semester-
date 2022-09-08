#include<iostream>

using namespace std;

void swap(int *a,int *b);
void readArray(int *arr, int size);
void displayArray(int *arr,int size);
void bubbleSort(int *arr, int size);

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
    bubbleSort(arr,size);
    cout<<"\nThe sorted array is: "<<endl;
    displayArray(arr,size);
    return 0;
}

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void readArray(int *arr, int size){
  for (int i = 0; i < size; i++) {
    cin>>arr[i];
  }
}

void displayArray(int* arr, int size){
  for (int i = 0; i < size; i++) {
   cout<<arr[i]<<"\t"; 
  }
}

void bubbleSort(int *arr, int size){
  for(int i=0;i<size-1;i++){
    for(int j=0;j<size-i-1;j++){
      if(arr[j]>arr[j+1]){
        swap(&arr[j],&arr[j+1]);
      }
    }
  }
}
