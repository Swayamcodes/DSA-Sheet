/**
 * LeetCode 88 - Merge Sorted Array
 * --------------------------------
 *
 * 📌 Problem:
 * Given two sorted arrays nums1 and nums2, merge nums2 into nums1 as a single sorted array.
 * nums1 has a size of m+n, where the last n elements are placeholders (0s).
 *
 * Example:
 * Input:  nums1 = [1,2,3,0,0,0], m = 3
 *         nums2 = [2,5,6], n = 3
 * Output: [1,2,2,3,5,6]
 *
 * --------------------------------
 *
 * 📌 Approaches:
 *
 * 1. Brute Force (Sort after merging)
 *    - Copy nums2 into nums1, then sort.
 *    - Time: O((m+n) log(m+n)), Space: O(1).
 *    - Inefficient.
 *
 * 2. Two Pointers with Extra Array
 *    - Merge like merge-sort into a new array, then copy back.
 *    - Time: O(m+n), Space: O(m+n).
 *    - Extra space required.
 *
 * 3. ✅ Optimal: Two Pointers from End (In-place)
 *    - Use three pointers:
 *        i = m-1  (last valid element of nums1)
 *        j = n-1  (last element of nums2)
 *        idx = m+n-1 (last position in nums1)
 *    - Compare nums1[i] and nums2[j], place larger at nums1[idx].
 *    - Decrement pointers accordingly.
 *    - If nums2 still has elements left, copy them into nums1.
 *    - Time: O(m+n), Space: O(1).
 *    - Best solution.
 *
 * --------------------------------
 *
 * 📌 Dry Run:
 * nums1 = [1,2,3,0,0,0], m=3
 * nums2 = [2,5,6], n=3
 *
 * Step 1: Compare 3 & 6 -> place 6 -> [1,2,3,0,0,6]
 * Step 2: Compare 3 & 5 -> place 5 -> [1,2,3,0,5,6]
 * Step 3: Compare 3 & 2 -> place 3 -> [1,2,3,3,5,6]
 * Step 4: Compare 2 & 2 -> place 2 -> [1,2,2,3,5,6]
 * Done ✅
 *
 * --------------------------------
 *
 * 📌 Revision Notes:
 * - Always merge from the end to avoid overwriting elements.
 * - If nums2 has leftovers, copy them. If nums1 has leftovers, they are already in place.
 * - Time O(m+n), Space O(1).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int idx = m + n - 1; 
        int i = m - 1;
        int j = n - 1;

        // Merge from the back
        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j]) {
                A[idx] = A[i];
                idx--, i--;
            } else {
                A[idx] = B[j];
                idx--, j--;
            }
        }

        // Copy remaining elements from B
        while (j >= 0) {
            A[idx] = B[j];
            idx--, j--;
        }
    }
};

int main() {
    Solution sol;

    // Example test
    vector<int> A = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> B = {2, 5, 6};
    int n = 3;

    sol.merge(A, m, B, n);

    cout << "Merged Array: ";
    for (int x : A) cout << x << " ";
    cout << endl;

    return 0;
}