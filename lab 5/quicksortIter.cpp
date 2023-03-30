#include <iostream>
#include <vector>
#include <stack>
#include <random>
#include <iomanip>
#include <chrono>
using namespace std;
using namespace std::chrono;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (vec[j] < pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return i + 1;
}

void iterativeQuickSort(vector<int>& vec, int low, int high) {
    stack<pair<int, int>> stk;
    stk.push(make_pair(low, high));

    while (!stk.empty()) {
        low = stk.top().first;
        high = stk.top().second;
        stk.pop();

        int pivotIndex = partition(vec, low, high);

        if (pivotIndex - 1 > low) {
            stk.push(make_pair(low, pivotIndex - 1));
        }

        if (pivotIndex + 1 < high) {
            stk.push(make_pair(pivotIndex + 1, high));
        }
    }
}

void printVector(vector<int>& vec) {
    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << *it << " ";
    }
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
     //int n = arr.size();
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;
    vector<int> arr= generateRandomArray(n);

    auto start = high_resolution_clock::now();
    iterativeQuickSort(arr, 0, arr.size() - 1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    double duration_sec = duration.count() / 1000000.0; 
    cout << "Time taken by mergesort: " << fixed << setprecision(6) << duration_sec << " seconds" << endl;



    cout << "Sorted vector: ";
    printVector(arr);

    return 0;
}
