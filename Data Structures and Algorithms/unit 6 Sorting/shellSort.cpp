#include<iostream>
#include<math.h>
using namespace std;

void readArray(int *arr,int size);
void displayArray(int *arr, int size);
void shellSort(int *arr, int size);

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
    shellSort(arr,size);
    cout<<"The sorted array is: "<<endl;
    displayArray(arr,size);
    return 0;
}

void readArray(int *arr, int size){
  for(int i=0;i<size;i++){
    cin>>arr[i];
  }
}

void displayArray(int *arr, int size){
  for(int i=0;i<size;i++){
    cout<<arr[i]<<"\t";
  }
  cout<<endl;
}

void shellSort(int *arr,int size){
    int i,j,temp, gap = floor(size/2);
    while(gap>0){
        for(i=gap;i<size;i++){
            temp = arr[i];
            j = i;
            while(j>=gap && arr[j-gap]>temp){
                arr[j] = arr[j-gap];
                j = j-gap;
            }
            arr[j] = temp;
        }
        gap = floor(gap/2);
    }
}