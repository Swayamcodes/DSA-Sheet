/**
 * LeetCode 15 - 3Sum
 * --------------------------------
 *
 * 📌 Problem:
 * Find all unique triplets (i, j, k) in an array such that:
 *   A[i] + A[j] + A[k] == 0
 *
 * Example:
 * Input:  [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2], [-1,0,1]]
 *
 * --------------------------------
 *
 * 📌 Approaches:
 *
 * 1. Brute Force (❌ Too Slow)
 *    - Triple nested loops.
 *    - Time: O(n^3), Space: O(1).
 *
 * 2. Hashing Approach (O(n^2) but tricky duplicates)
 *    - Fix one element A[i].
 *    - Use an unordered_set to check if -(A[i] + A[j]) exists.
 *    - Collect valid triplets in a set to avoid duplicates.
 *    - Time: O(n^2), Space: O(n).
 *    - Harder to manage duplicates cleanly.
 *
 * 3. ✅ Sorting + Two-Pointer Approach (Best)
 *    - Sort array.
 *    - Loop i from 0..n-3:
 *      • Skip duplicate i values.
 *      • Use two pointers j=i+1, k=n-1.
 *      • Move pointers inward depending on sum.
 *      • Skip duplicates for j and k.
 *    - Time: O(n^2), Space: O(1) (ignoring output).
 *    - Cleanest and most widely accepted.
 *
 * --------------------------------
 *
 * 📌 Dry Run (Sorting + Two-Pointer):
 * Input: [-1,0,1,2,-1,-4]
 * Sorted: [-4,-1,-1,0,1,2]
 * - i=0 (-4) → no valid pairs.
 * - i=1 (-1):
 *   j=2, k=5 → sum=0 → [-1,-1,2]
 *   j=3, k=4 → sum=0 → [-1,0,1]
 * - i=2 (-1) → skip duplicate.
 * ✅ Result: [[-1,-1,2], [-1,0,1]]
 *
 * --------------------------------
 *
 * 📌 Final Code: Sorting + Two-Pointer (Optimal)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> ans;
        sort(A.begin(), A.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && A[i] == A[i-1]) continue; // skip duplicate i

            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = A[i] + A[j] + A[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    ans.push_back({A[i], A[j], A[k]});
                    j++;
                    k--;
                    while (j < k && A[j] == A[j-1]) j++; // skip dup j
                    while (j < k && A[k] == A[k+1]) k--; // skip dup k
                }
            }
        }
        return ans;
    }
};

/*
// Alternate Hashing-Based O(n^2) Approach:
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        int n = A.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++) {
            unordered_set<int> seen;
            for (int j = i+1; j < n; j++) {
                int target = -(A[i] + A[j]);
                if (seen.count(target)) {
                    vector<int> triplet = {A[i], A[j], target};
                    sort(triplet.begin(), triplet.end());
                    st.insert(triplet);
                }
                seen.insert(A[j]);
            }
        }
        return vector<vector<int>>(st.begin(), st.end());
    }
};
*/

int main() {
    Solution sol;
    vector<int> nums = {-1,0,1,2,-1,-4};
    auto res = sol.threeSum(nums);
    cout << "Triplets: ";
    for (auto &t : res) {
        cout << "[" << t[0] << "," << t[1] << "," << t[2] << "] ";
    }
    cout << endl;
    return 0;
}
