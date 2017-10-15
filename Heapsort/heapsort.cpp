#if 0
=========================================================
*************************HEAPSORT************************
=========================================================
********************TIME COMPLEXITY**********************
BEST: Ω(n log(n)) AVERAGE: Θ(n log(n)) WORST: O(n log(n))
=========================================================
********************SPACE COMPLEXITY*********************
                       WORST: O(1)
=========================================================
A sorting algorithm that works by first organizing the data to be sorted into a special type of binary tree called a heap. 
The heap itself has, by definition, the largest value at the top of the tree, so the heap sort algorithm must also reverse the order. 
It does this with the following steps:

1. Remove the topmost item (the largest) and replace it with the rightmost leaf. The topmost item is stored in an array. 

2. Re-establish the heap.

3. Repeat steps 1 and 2 until there are no more items left in the heap. The sorted elements are now stored in an array.
#endif

#include <iostream>

void maxHeapify(int a[], int i, int n)
{
    int l, r, largest;
    l=2*i;
    r=1+l;
    if(l<n && a[l]>a[i])
        largest = l;
    else
        largest = i;
    if( r < n && a[r] > a[largest] )
        largest = r;

    if(largest != i)
    {
        int loc = std::move(a[i]);
        a[i] = std::move(a[largest]);
        a[largest] = std::move(loc);
        maxHeapify(a, largest, n);
    }
}

void buildMaxHeap(int a[], int n)
{
    for(int k = n/2 - 1; k >= 0; k--)
    {
        maxHeapify(a, k, n);
    }
}

void heapsort(int a[], int n)
{
    buildMaxHeap(a,n);
    int i;

    for(i = n - 1; i >=1; i--)
    {
        int temp = std::move(a[i]);
        a[i] = std::move(a[0]);
        a[0] = std::move(temp);

        maxHeapify(a, 0, i-1);
    }
}

int main()
{
	int n;
    std::cout << "Enter the size of the array" << std::endl;
    std::cin >> n;

    if(n < 0)
        return 1;

    int a[n];
    for(int i = 0; i < n; ++i)
    {
        std::cout << "Enter the element " << 1 + i << std::endl;
        std::cin >> a[i];
    }

    heapsort(a, n);
    std::cout << "SORTED" << std::endl;
    for(int i = 0; i < n; ++i)
        std::cout << a[i] << std::endl;

    return 0;
}
