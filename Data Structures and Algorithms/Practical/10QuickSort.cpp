#include <iostream>
using namespace std;

void quick_sort(int arr[], int left, int right)
{
  // base case: if the left index is greater than or equal to the right index, the subarray is already sorted
  if (left >= right)
    return;

  // choose the pivot element
  int pivot = arr[(left + right) / 2];

  // partition the array around the pivot element
  int i = left;
  int j = right;
  while (i <= j)
  {
    // find the next element from the left that is greater than the pivot
    while (arr[i] < pivot)
      i++;

    // find the next element from the right that is less than the pivot
    while (arr[j] > pivot)
      j--;

    // if the left index is less than or equal to the right index, swap the elements and update the indices
    if (i <= j)
    {
      swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }

  // recursively sort the subarrays
  quick_sort(arr, left, j);
  quick_sort(arr, i, right);
}


int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  quick_sort(arr, 0, n - 1);

  cout << "Sorted array: \n";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}