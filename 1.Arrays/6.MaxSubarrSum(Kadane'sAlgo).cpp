/**
 * LeetCode 53 - Maximum Subarray
 * --------------------------------
 *
 * 📌 Problem:
 * Given an integer array nums, find the contiguous subarray (containing at least one number)
 * which has the largest sum and return its sum.
 *
 * Example:
 * Input:  [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: The subarray [4,-1,2,1] has the largest sum = 6.
 *
 * --------------------------------
 *
 * 📌 Approaches:
 *
 * 1. Brute Force
 *    - Generate all subarrays and compute sums.
 *    - Time: O(n^2) or O(n^3), Space: O(1).
 *    - ❌ Too slow.
 *
 * 2. ✅ Kadane's Algorithm (Optimal)
 *    - Maintain a running sum (currentSum).
 *    - At each index, extend the current subarray with nums[i].
 *    - Update global maximum (maxSum).
 *    - If currentSum < 0, reset it to 0 (drop the negative baggage).
 *    - Time: O(n), Space: O(1).
 *
 * --------------------------------
 *
 * 📌 Dry Run (Kadane’s Algo):
 * nums = [-2,1,-3,4,-1,2,1,-5,4]
 *
 * i=0: currentSum=-2, maxSum=-2 → reset to 0
 * i=1: currentSum=1, maxSum=1
 * i=2: currentSum=-2, maxSum=1 → reset to 0
 * i=3: currentSum=4, maxSum=4
 * i=4: currentSum=3, maxSum=4
 * i=5: currentSum=5, maxSum=5
 * i=6: currentSum=6, maxSum=6
 * i=7: currentSum=1, maxSum=6
 * i=8: currentSum=5, maxSum=6
 * ✅ Answer = 6
 *
 * --------------------------------
 *
 * 📌 Revision Notes:
 * - Kadane’s = DP disguised as Greedy.
 * - Extend or reset based on whether currentSum < 0.
 * - Two common variants:
 *   1) currentSum = max(nums[i], currentSum + nums[i]).
 *   2) Reset to 0 when currentSum < 0 (your version).
 * - Handles negative arrays by initializing maxSum = INT_MIN.
 * - Complexity: O(n) time, O(1) space.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int maxSum = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];             // extend subarray
            maxSum = max(maxSum, currentSum);  // update global max
            if (currentSum < 0) {
                currentSum = 0;                // reset if dragging down
            }
        }
        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Maximum Subarray Sum: " << sol.maxSubArray(nums) << endl;
    return 0;
}