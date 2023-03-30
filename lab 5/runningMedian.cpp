#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void print_median(priority_queue<int>& max_heap, priority_queue<int, vector<int>, greater<int>>& min_heap) {
    if (max_heap.size() > min_heap.size()) {
        cout <<"median is: "<< max_heap.top() << endl;
    } else if (max_heap.size() < min_heap.size()) {
        cout <<"median is: "<< min_heap.top() << endl;
    } else {
        cout << (max_heap.top() + min_heap.top()) / 2.0 << endl;
    }
}

void add_number(int number, priority_queue<int>& max_heap, priority_queue<int, vector<int>, greater<int>>& min_heap) {
    if (max_heap.empty() || number < max_heap.top()) {
        max_heap.push(number);
    } else {
        min_heap.push(number);
    }

    if (max_heap.size() > min_heap.size() + 1) {
        min_heap.push(max_heap.top());
        max_heap.pop();
    } else if (min_heap.size() > max_heap.size() + 1) {
        max_heap.push(min_heap.top());
        min_heap.pop();
    }
}

int main() {
    priority_queue<int> max_heap; // stores the smaller half of the numbers
    priority_queue<int, vector<int>, greater<int>> min_heap; // stores the larger half of the numbers

    // read in numbers until the end of input is reached
    int number;
    while (cin >> number) {
        add_number(number, max_heap, min_heap);
        print_median(max_heap, min_heap);
    }

    return 0;
}
