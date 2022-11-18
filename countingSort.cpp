/**
 *
 * Counting Sort, a non-comparrison based sorting algorithm
 * that is stable and has better comoutational complexity (O(n+k))
 * than comparisson based sorting algorithms suck as merge sort or 
 * quicksort because of the prooven lower bound of O(n log n)
 * 
 * 
 * to note that in the case that the n keys are in the range of 0-n
 * then the algorithm has O(n) complexity.
 * 
 */

#include <iostream>

void print(int* arr, int s)
{
    for(int i=0; i<s; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int findMax(int* arr, int n)
{
    int max = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int* arr, int n)
{
    int k = findMax(arr,n);
    int* A = new int[n];
    int* B = new int[n];
    int* C = new int[k];

    A = arr;

    for(int i = 0; i < k + 1; i++)
    {
        C[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        C[A[i] - 1] += 1;
    }

    for(int i = 1; i < n; i++)
    {
        C[i] += C[i - 1];
    }

    for(int i = n - 1; i >= 0; i--)
    {
        B[C[A[i] - 1] - 1] = A[i];
        C[A[i] - 1] -= 1;
    }
    print(B,n);

    
}



int main(int argc, char** argv)
{

    std::cout << "Counting Sort showcase" << std::endl;

    int Array[10] = {10,3,6,2,8,2,3,9,5,1};
    std::cout << "Unsorted array: "; print(Array,10);
    std::cout << "Sorted array: "; countingSort(Array,10); std::cout << std::endl;

    return 0;
}