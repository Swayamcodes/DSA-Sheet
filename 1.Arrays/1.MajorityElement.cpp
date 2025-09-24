// LeetCode 169 - Majority Element
// Solved using Moore's Voting Algorithm
// Time: O(n), Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        // Phase 1: Find the candidate
        for (int num : nums) {
            if (count == 0) {
                candidate = num;   // new candidate
                count = 1;         // give it its first vote
            } 
            else if (num == candidate) {
                count++;           // same as candidate → vote++
            } 
            else {
                count--;           // different → cancel one vote
            }
        }

        // Phase 2: Verify the candidate (only needed if majority not guaranteed)
        int freq = 0;
        for (int num : nums) {
            if (num == candidate) freq++;
        }

        if (freq > nums.size() / 2) return candidate;
        return -1;  // if no majority exists
    }
};

// Example run
int main() {
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << sol.majorityElement(nums) << endl;
    return 0;
}


