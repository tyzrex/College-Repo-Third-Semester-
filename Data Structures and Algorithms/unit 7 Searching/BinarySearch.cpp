#include<iostream>

using namespace std;

void getArray(int *arr, int size);
void displayArray(int *arr, int size);
int binarySearch(int *arr, int element, int size);

int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    getArray(arr, size);
    displayArray(arr, size);
    int element;
    cout << "\nEnter the element that you are searching for: ";
    cin >> element;
    int res = binarySearch(arr, element, size);
    if(res == -1){
        cout << "Element not found in the given array!";
    }
    else{
        cout << "Element: " << element << " found at the position: " << res;
    }
    return 0;
}

void getArray(int *arr, int size){
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
}

void displayArray(int *arr, int size){
    cout << "The entered array is: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

int binarySearch(int *arr, int element, int size){
    int low = 0;
    int high = size - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == element){
            return mid + 1;
        }
        else if(arr[mid] < element){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}