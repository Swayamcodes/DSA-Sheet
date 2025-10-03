/**
 * LeetCode 540 - Single Element in a Sorted Array
 * ----------------------------------------------
 *
 * 📌 Problem:
 * Given a sorted array where every element appears exactly twice except for one element
 * which appears only once, return that single element.
 *
 * Example:
 * Input: [1,1,2,3,3,4,4,8,8]
 * Output: 2
 *
 * ----------------------------------------------
 *
 * 📌 Approaches:
 *
 * 1. Brute Force
 *    - Traverse linearly, check neighbors.
 *    - Time: O(n), Space: O(1).
 *    - ❌ Not efficient.
 *
 * 2. ✅ Binary Search with Index Parity (Clean Method)
 *    - Use binary search and exploit the property:
 *      • Before the single element, pairs start at even indices.
 *      • After the single element, pairs start at odd indices.
 *    - Always make mid even, compare with next element.
 *    - Time: O(log n), Space: O(1).
 *
 * 3. Alternative: Neighbor Check with Parity (User’s Style, Fixed)
 *    - Explicitly check if mid is unique by comparing A[mid-1], A[mid], A[mid+1].
 *    - Otherwise use parity logic:
 *      • If mid is even → compare with right neighbor.
 *      • If mid is odd → compare with left neighbor.
 *    - Works but needs careful handling of boundaries.
 *
 * ----------------------------------------------
 *
 * 📌 Clean Code (Parity Trick)
 */

#include <bits/stdc++.h>
using namespace std;

class SolutionClean {
public:
    int singleNonDuplicate(vector<int>& A) {
        int st = 0, end = A.size() - 1;
        while (st < end) {
            int mid = st + (end - st) / 2;
            if (mid % 2 == 1) mid--; // ensure mid is even

            if (A[mid] == A[mid+1]) {
                st = mid + 2; // pair is fine → go right
            } else {
                end = mid; // pair broken → go left
            }
        }
        return A[st];
    }
};

/*
 * 📌 Alternative Code (Neighbor Check with Parity)
 * - Matches the user’s original approach, but fixed.
 */

class SolutionNeighborCheck {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n = A.size();
        if (n == 1) return A[0];

        int st = 0, end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;

            // Edge cases
            if (mid == 0 && A[0] != A[1]) return A[mid];
            if (mid == n-1 && A[n-1] != A[n-2]) return A[mid];

            // Check if mid itself is unique
            if (A[mid-1] != A[mid] && A[mid] != A[mid+1]) return A[mid];

            // Parity-based logic
            if (mid % 2 == 0) {
                // Even mid → should pair with right neighbor
                if (A[mid] == A[mid+1]) {
                    st = mid + 2;
                } else {
                    end = mid - 1;
                }
            } else {
                // Odd mid → should pair with left neighbor
                if (A[mid] == A[mid-1]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1; // should not happen for valid input
    }
};

int main() {
    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    SolutionClean sol1;
    cout << "Single element (Clean Method): " << sol1.singleNonDuplicate(nums) << endl;

    SolutionNeighborCheck sol2;
    cout << "Single element (Neighbor Check Method): " << sol2.singleNonDuplicate(nums) << endl;

    return 0;
}

/*
 * ----------------------------------------------
 * 📌 Revision Notes:
 * - Unique element breaks the pairing pattern.
 * - Clean method: always adjust mid to even, compare with next.
 * - Neighbor method: check mid explicitly, then use parity rules.
 * - Both achieve O(log n) time and O(1) space.
 */
