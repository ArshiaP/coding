// https://practice.geeksforgeeks.org/problems/heap-sort/1#
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
 public:
  // Heapify function to maintain heap property.
  void heapify(int arr[], int n, int i) {
    int heapify = 0;
    n = n - i;
    int k = 0;
    while (!heapify and k * 2 + 1 < n) {
      int left = k * 2 + 1;
      int right = left + 1;
      if (right < n) {
        int m = max(arr[k], max(arr[left], arr[right]));
        if (m == arr[k]) {
          heapify = 1;
        } else if (m == arr[left]) {
          swap(arr[k], arr[left]);
          k = left;
        } else {
          swap(arr[k], arr[right]);
          k = right;
        }
      } else {
        int m = max(arr[k], arr[left]);
        if (m == arr[k]) {
          heapify = 1;
        } else {
          swap(arr[k], arr[left]);
          k = left;
        }
      }
    }
  }

 public:
  // Function to build a Heap from array.
  void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
      int k = i;
      int heapify = 0;
      while (!heapify and k * 2 + 1 < n) {
        int left = k * 2 + 1;
        int right = left + 1;
        if (right < n) {
          int m = max(arr[k], max(arr[left], arr[right]));
          if (m == arr[k]) {
            heapify = 1;
          } else if (m == arr[left]) {
            swap(arr[k], arr[left]);
            k = left;
          } else {
            swap(arr[k], arr[right]);
            k = right;
          }
        } else {
          int m = max(arr[k], arr[left]);
          if (m == arr[k]) {
            heapify = 1;
          } else {
            swap(arr[k], arr[left]);
            k = left;
          }
        }
      }
    }
  }

 public:
  // Function to sort an array using Heap Sort.
  void heapSort(int arr[], int n) {
    buildHeap(arr, n);

    for (int i = 0; i < n; i++) {
      swap(arr[0], arr[n - 1 - i]);
      heapify(arr, n, i + 1);
    }
  }
};

// { Driver Code Starts.
/* Function to print an array */
void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// Driver program to test above functions
int main() {
  int arr[1000000], n, T, i;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  Solution ob;
  ob.heapSort(arr, n);
  printArray(arr, n);

  return 0;
}
// } Driver Code Ends