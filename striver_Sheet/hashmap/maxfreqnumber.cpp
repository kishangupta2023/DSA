// Given an array of n integers, find the most frequent element in it i.e., the element that occurs the maximum number of times. If there are multiple elements that appear a maximum number of times, find the smallest of them.
// Examples:
// Input: arr = [1, 2, 2, 3, 3, 3]
// 
// Output:3
// Explanation: The number 3 appears the most (3 times). It is the most frequent element.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

int mostFrequentElement(const vector<int>& arr) {
    unordered_map<int, int> freq;
    int maxFreq = 0;
    int result = INT_MAX;

    for (int num : arr) {
        freq[num]++;
        int currentFreq = freq[num];

        if (currentFreq > maxFreq) {
            maxFreq = currentFreq;
            result = num;
        } else if (currentFreq == maxFreq) {
            result = min(result, num); // choose the smaller number in case of tie
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 3, 3,4,4,4};
    cout << mostFrequentElement(arr) << endl; // Output: 3
    return 0;
}
