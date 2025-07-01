// Given an array nums of size n which may contain duplicate elements, return a list of pairs where each pair contains a unique element from the array and its frequency in the array.
// You may return the result in any order, but each element must appear exactly once in the output.
// Examples:
// Input: nums = [1, 2, 2, 1, 3]
// Output: [[1, 2], [2, 2], [3, 1]]
// Explanation:
// - 1 appears 2 times
// - 2 appears 2 times
// - 3 appears 1 time
// Order of output can vary.


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<pair<int, int>> frequencyPairs(const vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    vector<pair<int, int>> result;
    for (const auto& entry : freq) {
        result.push_back({entry.first, entry.second});
    }

    return result;
}
int main() {
    vector<int> nums = {1, 2, 2, 1, 3};
    vector<pair<int, int>> output = frequencyPairs(nums);

    for (const auto& p : output) {
        cout << "[" << p.first << ", " << p.second << "]\n";
    }

    return 0;
}
