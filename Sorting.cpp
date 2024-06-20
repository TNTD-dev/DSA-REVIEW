#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// Selection sort
void Selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[min] > a[j]) min = j;
        }

        if (min != i) swap(a[min], a[i]);
    }
}
// Interchange sort
void Interchange_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) swap(a[i], a[j]);
        }
    }
}
// Bubble sort
void Bubble_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false) break;
    }
}

// Insertion sort
void Insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;

    }
}

void BinaryInsertion_sort(int a[], int n) {
    int l, r;
    for (int i = 1; i < n; i++) {
        int l = 0, r = i - 1;
        int key = a[i];
        while (l <= r) {
            int mid = (l + r) / 2;
            if (key < a[mid]) r = mid - 1;
            else l = mid + 1;
        }
        for (int j = i - 1; j >= l; j--) {
            a[j + 1] = a[j];
        }
        a[l] = key;
    }
}

// Heap sort
void heapify(int arr[], int N, int i)
{

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && arr[l] > arr[largest])
        largest = l;

    if (r < N && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}
void Build_heap(int arr[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
}
void Heap_sort(int arr[], int N)
{
    Build_heap(arr, N);
    for (int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


// Quick sort
void Quick_sort(int a[], int left, int right)
{
    int i, j, pivot;
    pivot = a[(left + right) / 2];
    i = left, j = right;

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    if (left < j)  Quick_sort(a, left, j);
    if (i < right) Quick_sort(a, i, right);
}

void Quick_sort(int a[], int n) {
    Quick_sort(a, 0, n - 1);
}

// Merge sort
void merge(int array[], int const left, int const mid,
    int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne
        && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void Merge_sort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    Merge_sort(array, begin, mid);
    Merge_sort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
void Merge_sort(int a[], int n)
{
    Merge_sort(a, 0, n - 1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a[] = { 5,7,9,8,1,4,3,2,0 };
    int n = sizeof(a) / sizeof(a[0]);
    Merge_sort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";

    return 0;
}