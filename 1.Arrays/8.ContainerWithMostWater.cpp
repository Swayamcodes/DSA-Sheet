/**
 * LeetCode 11 - Container With Most Water
 * --------------------------------
 *
 * 📌 Problem:
 * You are given an array height[], where each element represents a vertical line.
 * Find two lines that form a container which holds the maximum amount of water.
 *
 * Example:
 * Input:  [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: Between lines at index 1 (height=8) and index 8 (height=7),
 * width = 7 and height = 7 → area = 49.
 *
 * --------------------------------
 *
 * 📌 Approaches:
 *
 * 1. Brute Force
 *    - Try all pairs (i, j).
 *    - Compute area = min(height[i], height[j]) * (j - i).
 *    - Track maximum.
 *    - Time: O(n^2), Space: O(1).
 *    - ❌ Too slow.
 *
 * 2. ✅ Two-Pointer Optimal
 *    - Place one pointer at left end (lp=0) and one at right end (rp=n-1).
 *    - Compute current area.
 *    - Move the pointer pointing to the shorter line inward.
 *    - Reason: taller line cannot increase area if width decreases, but shorter line might.
 *    - Repeat until lp >= rp.
 *    - Time: O(n), Space: O(1).
 *
 * --------------------------------
 *
 * 📌 Dry Run:
 * Input: [1,8,6,2,5,4,8,3,7]
 * - lp=0, rp=8 → area = min(1,7)*8 = 8, max=8 → move lp.
 * - lp=1, rp=8 → area = min(8,7)*7 = 49, max=49 → move rp.
 * - lp=1, rp=7 → area = min(8,3)*6 = 18, max=49 → move rp.
 * - … continue until lp >= rp.
 * ✅ Result = 49.
 *
 * --------------------------------
 *
 * 📌 Revision Notes:
 * - Brute force checks all pairs → O(n^2).
 * - Optimal: Two-pointer greedy.
 * - Always move pointer at smaller height.
 * - Each pointer moves at most once across array.
 * - Final answer = maximum area tracked.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& A) {
        int n = A.size();
        int lp = 0;
        int rp = n - 1;
        int maxWater = 0;

        while (lp < rp) {
            int width = rp - lp;
            int height = min(A[lp], A[rp]);
            maxWater = max(maxWater, height * width);

            // Move pointer at smaller height
            A[lp] < A[rp] ? lp++ : rp--;
        }
        return maxWater;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    cout << "Max Water: " << sol.maxArea(heights) << endl; // 49
    return 0;
}