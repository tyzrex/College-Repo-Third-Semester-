#include<iostream>

using namespace std;

void readArray(int *arr, int size);
void displayArray(int *arr, int size);
int sequentialSearch(int *arr, int element, int size);

int main(){
  int size,element;
  cout<<"Enter the size of the array: ";
  cin>>size;
  int arr[size];
  readArray(arr,size);
  displayArray(arr,size);
  cout<<"\nEnter the element that you are searching for: ";
  cin>>element;
  int res = sequentialSearch(arr,element,size);
  if(res==-1){
    cout<<"Element not found in the given array!";
  }
  else{
    cout<<"Element: "<<element<<" found at the position: " <<res;
  }
  return 0;
}

void readArray(int *arr, int size){
  cout<<"Enter the elements of the array: \n"; 
  for(int i=0;i<size;i++){
        cin>>arr[i];
    }
}

void displayArray(int *arr,int size){
  cout<<"The entered array is: \n";
  for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
}

int sequentialSearch(int *arr, int element,int size){
  for (int i = 0; i < size; i++) {
   if(arr[i]==element){
      return i+1;
    }       
  }
  return -1;
}
