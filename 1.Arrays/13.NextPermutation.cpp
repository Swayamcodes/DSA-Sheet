/**
 * LeetCode 31 - Next Permutation
 * --------------------------------
 *
 * 📌 Problem:
 * Rearrange numbers into the lexicographically next greater permutation
 * of numbers. If such arrangement is not possible, rearrange it as the
 * lowest possible order (i.e., sorted in ascending order).
 *
 * Example:
 * Input:  [1,2,3]
 * Output: [1,3,2]
 *
 * Input:  [3,2,1]
 * Output: [1,2,3]
 *
 * Input:  [1,1,5]
 * Output: [1,5,1]
 *
 * --------------------------------
 *
 * 📌 Approaches:
 *
 * 1. Brute Force (❌ Not feasible)
 *    - Generate all permutations, sort them, and pick the next one.
 *    - Time: O(n!), Space: O(n).
 *
 * 2. ✅ Optimal Greedy + Two-Pointer (Standard Solution)
 *    Steps:
 *    - Traverse from the right, find the "pivot" index `i` such that A[i] < A[i+1].
 *      (If no pivot exists, the array is in descending order → reverse it).
 *    - From the right again, find the smallest element > A[pivot] and swap.
 *    - Reverse the suffix after pivot (to make it the smallest possible suffix).
 *
 *    Time: O(n), Space: O(1).
 *
 * --------------------------------
 *
 * 📌 Dry Run (Example: [2,3,6,5,4,1])
 * - Step 1: Find pivot:
 *   Traverse from back → pivot = index 1 (value=3), because 3 < 6.
 * - Step 2: Find rightmost number greater than 3 → it's 4 (index 4).
 * - Swap → [2,4,6,5,3,1].
 * - Step 3: Reverse suffix after pivot → reverse [6,5,3,1] → [1,3,5,6].
 * - Final → [2,4,1,3,5,6].
 *
 * ✅ Next permutation.
 *
 * --------------------------------
 *
 * 📌 Final Code: O(n) Time, O(1) Space
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int n = A.size();
        int pivot = -1;

        // Step 1: Find rightmost pivot
        for (int i = n-2; i >= 0; i--) {
            if (A[i] < A[i+1]) {
                pivot = i;
                break; // ✅ must break to ensure rightmost pivot
            }
        }

        if (pivot == -1) {
            // Entire array is in descending order → reverse to smallest
            reverse(A.begin(), A.end());
            return;
        }

        // Step 2: Find rightmost successor to pivot
        for (int i = n-1; i > pivot; i--) {
            if (A[i] > A[pivot]) {
                swap(A[i], A[pivot]);
                break;
            }
        }

        // Step 3: Reverse suffix after pivot
        reverse(A.begin() + pivot + 1, A.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,3,6,5,4,1};
    sol.nextPermutation(nums);

    cout << "Next permutation: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    return 0;
}
