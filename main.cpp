#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

void bubbleSort(int A[], int n);
int partition(int A[], int low, int high);
void quickSort(int A[], int low, int high);

int main()
{
    //parameters
    int size = 100000;
    int range = 10000;
    int A[size];
    
    //load array
    for (int i = 0; i < size; i++)
    {
        A[i] = rand() % range;
    }
    
    //start clock
    auto start = high_resolution_clock::now();
    
    //sorting algorithms
    //bubbleSort(A, size);
    quickSort(A, 0, size);

    //end clock
    auto stop = high_resolution_clock::now();
    
    //get duration
    auto duration = duration_cast<microseconds>(stop - start);
    
    //display time
    cout << "Time: " << duration.count() << " μs" << endl << endl;
    
    //display array
    bool display = false;
    if (display)
    {
        for (int i = 0; i < size; i++)
        {
            cout << A[i] << " ";
        }
    }
}

void bubbleSort(int A[], int n)
{
    for (int k = 0; k < n - 1; k++)
    {
        bool swapped = false;
        for (int i = 0; i < n - k - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                swap(A[i], A[i + 1]);
                swapped = true;
            }
        }
        
        if (!swapped)
        {
            break;
        }
    }
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low;
    int j = high;
    
    while (i < j)
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        
        do
        {
            j--;
        } while (A[j] > pivot);
        
        if (i < j)
        {
            swap(A[i], A[j]);
        }
    }
    
    swap(A[low], A[j]);
    
    return j;
}

void quickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int j = partition(A, low, high);
        quickSort(A, low, j);
        quickSort(A, j + 1, high);
    }
}
