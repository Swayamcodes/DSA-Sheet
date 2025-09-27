/**
 * LeetCode 18 - 4Sum
 * --------------------------------
 *
 * 📌 Problem:
 * Find all unique quadruplets (a, b, c, d) in an array such that:
 *   a + b + c + d == target
 *
 * Example:
 * Input:  [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2], [-2,0,0,2], [-1,0,0,1]]
 *
 * --------------------------------
 *
 * 📌 Approaches:
 *
 * 1. Brute Force (❌ Too Slow)
 *    - Four nested loops.
 *    - Time: O(n^4), Space: O(1).
 *
 * 2. Sorting + Binary Search
 *    - Sort array.
 *    - Fix 3 numbers, binary search for 4th.
 *    - Time: O(n^3 log n), Space: O(1).
 *
 * 3. ✅ Sorting + Two-Pointer Approach (Optimal)
 *    - Sort array.
 *    - Fix first two numbers i and j.
 *    - Use two pointers k=j+1 and l=n-1 to find remaining two numbers.
 *    - Skip duplicates at every step.
 *    - Time: O(n^3), Space: O(1) (ignoring output).
 *
 * --------------------------------
 *
 * 📌 Dry Run (Sorting + Two-Pointer):
 * Input: [1,0,-1,0,-2,2], target = 0
 * Sorted: [-2,-1,0,0,1,2]
 * - i=0 (-2), j=1 (-1):
 *   k=2 (0), l=5 (2) → sum=-1 → k++
 *   k=3 (0), l=5 (2) → sum=0 → [-2,-1,0,2]
 *   k=4 (1), l=4 → done
 * - i=0, j=2 (0):
 *   k=3, l=5 → sum=0 → [-2,0,0,2]
 * - i=1 (-1), j=2 (0):
 *   k=3, l=5 → sum=1 → l--
 *   k=3, l=4 → sum=0 → [-1,0,0,1]
 * ✅ Result: [[-2,-1,0,2], [-2,0,0,2], [-1,0,0,1]]
 *
 * --------------------------------
 *
 * 📌 Final Code: Sorting + Two-Pointer (Optimal)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& A, int target) {
        int n = A.size();
        vector<vector<int>> ans;
        sort(A.begin(), A.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && A[i] == A[i-1]) continue; // skip duplicate i

            for (int j = i+1; j < n; j++) {
                if (j > i+1 && A[j] == A[j-1]) continue; // skip duplicate j

                int k = j+1;
                int l = n-1;

                while (k < l) {
                    long long sum = (long long)A[i] + A[j] + A[k] + A[l];
                    if (sum < target) k++;
                    else if (sum > target) l--;
                    else {
                        ans.push_back({A[i], A[j], A[k], A[l]});
                        k++;
                        l--;
                        while (k < l && A[k] == A[k-1]) k++; // skip duplicate k
                        while (k < l && A[l] == A[l+1]) l--; // skip duplicate l
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    auto res = sol.fourSum(nums, target);

    cout << "Quadruplets: ";
    for (auto &q : res) {
        cout << "[";
        for (int i = 0; i < 4; i++) {
            cout << q[i];
            if (i < 3) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}
