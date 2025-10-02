/**
 * LeetCode 852 - Peak Index in a Mountain Array
 * --------------------------------------------
 *
 * 📌 Problem:
 * Given a mountain array (strictly increasing then strictly decreasing), return the index of the peak element.
 *
 * Example:
 * Input: [0,2,5,3,1]
 * Output: 2 (since 5 is the peak)
 *
 * --------------------------------------------
 *
 * 📌 Approaches:
 *
 * 1. Brute Force (Linear Scan)
 *    - Traverse array and check where A[i] > A[i-1] and A[i] > A[i+1].
 *    - Time: O(n), Space: O(1).
 *
 * 2. ✅ Binary Search (Slope Method - Preferred)
 *    - Compare mid with mid+1.
 *    - If A[mid] < A[mid+1], we are on the increasing slope → move right (st = mid+1).
 *    - Else, we are on the decreasing slope → move left (end = mid).
 *    - Eventually st == end, which is the peak.
 *    - Time: O(log n), Space: O(1).
 *
 * 3. Alternative: Neighbor Check Method
 *    - Start st=1, end=n-2 to avoid out-of-bounds.
 *    - If A[mid-1] <= A[mid] && A[mid] >= A[mid+1], mid is peak.
 *    - Else if A[mid] < A[mid+1], move right (st=mid+1).
 *    - Else, move left (end=mid-1).
 *    - More explicit, but requires extra boundary handling.
 *
 * --------------------------------------------
 *
 * 📌 Dry Run (Slope Method):
 * Input: [0,2,5,3,1]
 * st=0, end=4 → mid=2 → A[mid]=5, A[mid]>A[mid+1]=3 → move left (end=mid=2)
 * st=0, end=2 → mid=1 → A[mid]=2, A[mid]<A[mid+1]=5 → move right (st=2)
 * st=2, end=2 → return 2.
 *
 * --------------------------------------------
 *
 * 📌 Code 1 (Slope Method - Cleaner)
 */

#include <bits/stdc++.h>
using namespace std;

class SolutionSlope {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int st = 0, end = A.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;
            if (A[mid] < A[mid+1]) {
                st = mid + 1; // move right
            } else {
                end = mid; // move left (mid could be peak)
            }
        }
        return st; // or end, both are same
    }
};

/*
 * 📌 Code 2 (Neighbor Check Method - More Explicit)
 */

class SolutionNeighbor {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size();
        int st = 1, end = n - 2; // peak cannot be at edges

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (A[mid-1] <= A[mid] && A[mid] >= A[mid+1]) {
                return mid; // found peak
            } else if (A[mid] < A[mid+1]) {
                st = mid + 1; // move right
            } else {
                end = mid - 1; // move left
            }
        }
        return -1; // should never happen in valid mountain array
    }
};

int main() {
    vector<int> nums = {0,2,5,3,1};

    SolutionSlope sol1;
    cout << "Peak Index (Slope Method): " << sol1.peakIndexInMountainArray(nums) << endl;

    SolutionNeighbor sol2;
    cout << "Peak Index (Neighbor Check Method): " << sol2.peakIndexInMountainArray(nums) << endl;

    return 0;
}

/*
 * --------------------------------------------
 * 📌 Revision Notes:
 * - Two valid binary search approaches exist.
 * - Slope method is shorter and safer (just compare A[mid] with A[mid+1]).
 * - Neighbor method directly checks A[mid-1], A[mid], A[mid+1], but needs boundary care.
 * - Both achieve O(log n) time and O(1) space.
 */
