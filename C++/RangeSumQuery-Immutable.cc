// Given an integer array nums, find the sum of the elements
// between indices i and j (i ≤ j), inclusive.

// Example:
// Given nums = [-2, 0, 3, -5, 2, -1]

// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3
// Note:
// You may assume that the array does not change.
// There are many calls to sumRange function.

class NumArray {
    vector<int> table;
public:
    NumArray(vector<int> &nums) {
        table.push_back(0);
        for (int n : nums) {
            table.push_back(table.back() + n);
        }
    }

    int sumRange(int i, int j) {
        return table[j + 1] - table[i];
    }
};
