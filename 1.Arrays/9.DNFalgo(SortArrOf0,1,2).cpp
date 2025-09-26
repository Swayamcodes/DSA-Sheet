/**
 * LeetCode 75 - Sort Colors (Dutch National Flag Problem)
 * --------------------------------
 *
 * 📌 Problem:
 * Given an array nums with n objects colored red, white, or blue (represented as 0, 1, 2),
 * sort them in-place so that all 0s come first, followed by all 1s, then all 2s.
 *
 * Example:
 * Input:  [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 *
 * --------------------------------
 *
 * 📌 Approaches:
 *
 * 1. Two-Pass Counting Sort (Simple)
 *    - Count number of 0s, 1s, and 2s.
 *    - Rewrite the array in order.
 *    - Time: O(n), Space: O(1).
 *    - Easy but requires two passes.
 *
 * 2. ✅ One-Pass Dutch National Flag Algorithm (Optimal)
 *    - Maintain three pointers:
 *      • low: boundary after last 0.
 *      • mid: current index being checked.
 *      • high: boundary before first 2.
 *
 *    - Invariants (always true during loop):
 *      • nums[0 .. low-1] = 0
 *      • nums[low .. mid-1] = 1
 *      • nums[mid .. high] = unknown
 *      • nums[high+1 .. n-1] = 2
 *
 *    - Steps:
 *      While mid <= high:
 *      • If nums[mid] == 0 → swap(nums[low], nums[mid]), low++, mid++
 *      • If nums[mid] == 1 → mid++ (just skip)
 *      • If nums[mid] == 2 → swap(nums[mid], nums[high]), high-- (don’t mid++ because new element at mid not yet processed)
 *
 * --------------------------------
 *
 * 📌 Easy Explanation:
 * - Think of the array as three buckets: left for 0s, middle for 1s, right for 2s.
 * - Start with all numbers in the middle bucket (unknown).
 * - Scan left to right:
 *   If you see a 0 → push it left.
 *   If you see a 2 → push it right.
 *   If you see a 1 → leave it in the middle.
 * - Keep shrinking the unknown region until fully sorted.
 *
 * --------------------------------
 *
 * 📌 Dry Run:
 * Input: [2,0,2,1,1,0]
 * Start: low=0, mid=0, high=5
 * - mid=0: nums[mid]=2 → swap with nums[high] → [0,0,2,1,1,2], high=4
 * - mid=0: nums[mid]=0 → swap with nums[low] → [0,0,2,1,1,2], low=1, mid=1
 * - mid=1: nums[mid]=0 → swap with nums[low] → [0,0,2,1,1,2], low=2, mid=2
 * - mid=2: nums[mid]=2 → swap with nums[high] → [0,0,1,1,2,2], high=3
 * - mid=2: nums[mid]=1 → mid=3
 * - mid=3: nums[mid]=1 → mid=4 → stop
 * Result = [0,0,1,1,2,2]
 *
 * --------------------------------
 *
 * 📌 Revision Notes:
 * - DNF uses 3 pointers: low, mid, high.
 * - 0 → left, 1 → skip, 2 → right.
 * - One pass, in-place, O(n) time, O(1) space.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& A) {
        int n = A.size();
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high) {
            if (A[mid] == 0) {
                swap(A[mid], A[low]);
                mid++; low++;
            } else if (A[mid] == 1) {
                mid++;
            } else { // A[mid] == 2
                swap(A[mid], A[high]);
                high--;
            }
        }
    }
};

/*
// Alternate Two-Pass Counting Approach:
class Solution {
public:
    void sortColors(vector<int>& A) {
        int count0 = 0, count1 = 0, count2 = 0;
        for (int num : A) {
            if (num == 0) count0++;
            else if (num == 1) count1++;
            else count2++;
        }
        int idx = 0;
        while (count0--) A[idx++] = 0;
        while (count1--) A[idx++] = 1;
        while (count2--) A[idx++] = 2;
    }
};
*/

int main() {
    Solution sol;
    vector<int> nums = {2,0,2,1,1,0};
    sol.sortColors(nums);
    cout << "Sorted Colors: ";
    for (int x : nums) cout << x << " ";
    cout << endl; // Output: 0 0 1 1 2 2
    return 0;
}