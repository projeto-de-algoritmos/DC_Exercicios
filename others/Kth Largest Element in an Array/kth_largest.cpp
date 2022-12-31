#include <iostream>
#include <vector>

using namespace std;

#define Key(A) (A)
#define isLess(A, B) (Key(A) < Key(B))
#define isBigger(A, B) (Key(A) > Key(B))
#define swap(A, B) \
  {                \
    int t = A;     \
    A = B;         \
    B = t;         \
  }
#define cmpAndSwap(A, B) \
  {                      \
    if (isLess(B, A))    \
      swap(A, B);        \
  }

class Solution
{
public:
  int *arr;

  int partition(int left, int right)
  {
    int rightElement = arr[right];
    int pivot = left;
    for (int i = left; i < right; i++)
    {
      if (isBigger(arr[i], rightElement))
      {
        swap(arr[i], arr[pivot]);
        pivot++;
      }
    }
    swap(arr[pivot], arr[right]);

    return pivot;
  }

  void makeMedianSwap(int left, int right)
  {
    int mid = (left + right) / 2;

    cmpAndSwap(arr[mid], arr[right]); // Swap mid with right
    cmpAndSwap(arr[left], arr[mid]);  // Swap left with mid
    cmpAndSwap(arr[right], arr[mid]); // Swap right with mid
  }

  void quickSort(int left, int right, int k)
  {
    int pivot;
    if (left >= right)
      return;

    // for improve performance
    makeMedianSwap(left, right);

    pivot = partition(left, right);

    // Sort until k
    if (pivot >= k)
      return

          quickSort(left, pivot - 1, k);
    quickSort(pivot + 1, right, k);
  }
  int findKthLargest(vector<int> &nums, int k)
  {
    // Transforms the vector into an array
    int size = nums.size();
    arr = &nums[0];

    quickSort(0, size - 1, k);

    return arr[k - 1];
  }
};