#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <iomanip>
using namespace std;
using namespace std::chrono;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

void printArray(vector<int> &arr, int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
vector<int> generateRandomArray(int size) {
vector<int> arr;
srand(time(NULL)); // Initialize the random number generator with the current time

for (int i = 0; i < size; i++) {
    arr.push_back(rand()); // Generate a random number and add it to the vector
}

return arr;}



int main() {
    //vector<int> arr = { 10, 7, 8, 9, 1, 5 };
    //int n = arr.size();
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;
    vector<int> arr= generateRandomArray(n);
    
    auto start = high_resolution_clock::now();
    quicksort(arr, 0, n - 1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    double duration_sec = duration.count() / 1000000.0; 


    //cout << "Sorted array: \n";
    //printArray(arr, n);
    cout << "Time taken by quicksort: " << fixed << setprecision(6) << duration_sec << " seconds" << endl;


    return 0;
}
