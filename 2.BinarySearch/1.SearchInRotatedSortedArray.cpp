/**
 * LeetCode 33 - Search in Rotated Sorted Array
 * --------------------------------------------
 *
 * 📌 Problem:
 * Given an integer array nums sorted in ascending order and then rotated at some pivot,
 * search for a target value. If the target exists, return its index, otherwise return -1.
 *
 * Example:
 * Input:  nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 * --------------------------------------------
 *
 * 📌 Approaches:
 *
 * 1. Brute Force (Linear Search)
 *    - Scan every element until found.
 *    - Time: O(n), Space: O(1).
 *    - ❌ Too slow for large inputs.
 *
 * 2. ✅ Modified Binary Search
 *    - Even in a rotated array, one half (left or right) is always sorted.
 *    - Use mid to decide which half is sorted.
 *    - Then check if target lies in that half or the other half.
 *    - Time: O(log n), Space: O(1).
 *
 * --------------------------------------------
 *
 * 📌 Steps (Binary Search Version):
 * 1. Initialize st=0, end=n-1.
 * 2. While st <= end:
 *    • mid = (st+end)/2
 *    • If nums[mid] == target → return mid.
 *    • If left half is sorted (nums[st] <= nums[mid]):
 *         - If target in [nums[st], nums[mid]) → move end = mid-1.
 *         - Else → move st = mid+1.
 *    • Else (right half is sorted):
 *         - If target in (nums[mid], nums[end]] → move st = mid+1.
 *         - Else → move end = mid-1.
 * 3. If loop ends, return -1.
 *
 * --------------------------------------------
 *
 * 📌 Dry Run:
 * nums = [4,5,6,7,0,1,2], target=0
 * st=0, end=6 → mid=3 → nums[mid]=7
 * - Left half [4..7] sorted, but target not in [4..7].
 * - Move st=4.
 *
 * st=4, end=6 → mid=5 → nums[mid]=1
 * - Left half [0..1] sorted, target=0 in [0..1].
 * - Move end=4.
 *
 * st=4, end=4 → mid=4 → nums[mid]=0 → Found at index 4.
 *
 * --------------------------------------------
 *
 * 📌 Correct Code (C++)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& A, int target) {
        int n = A.size();
        int st = 0, end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (A[mid] == target) return mid;

            // Left half is sorted
            if (A[st] <= A[mid]) {
                if (A[st] <= target && target < A[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (A[mid] < target && target <= A[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << "Index of target: " << sol.search(nums, target) << endl; // Output: 4
    return 0;
}

/*
 * --------------------------------------------
 * 📌 Revision Notes:
 * - At every step, one half of the array is sorted.
 * - Check if target lies in sorted half.
 * - Use conditions with && (not chained comparisons).
 * - Return -1 if not found.
 * - Complexity: O(log n) time, O(1) space.
 */
