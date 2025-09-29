#include <bits/stdc++.h>
using namespace std;

/*
LeetCode 56 - Merge Intervals
-------------------------------------
We are given a list of intervals. We must merge all overlapping intervals
and return the result.

Approach 1 (Brute Force) - O(n^2):
----------------------------------
- Compare each interval with every other interval to check overlap.
- Merge them manually and mark visited.
- Very inefficient for large input.

Approach 2 (Optimal, Greedy + Sorting) - O(n log n):
----------------------------------------------------
1. Sort all intervals by their starting time.
2. Traverse intervals in sorted order.
   - If answer list is empty, push the current interval.
   - Else check if current interval overlaps with the last one in answer.
     * If overlap → merge by updating the end.
     * If no overlap → push new interval to answer.
3. Return the answer list.

Why does sorting help?
- Because once sorted, any overlap can only happen with the *last* interval added.
- This avoids O(n^2) checks.
*/

// Optimal function
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> arr) {
    int n = arr.size();

    // Step 1: Sort intervals by start time
    sort(arr.begin(), arr.end());

    // Step 2: Create answer container
    vector<vector<int>> ans;

    // Step 3: Traverse intervals
    for (int i = 0; i < n; i++) {
        // Case 1: If answer is empty OR no overlap
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // Case 2: Overlap found → merge with last interval
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    return ans;
}

// Utility function to print intervals
void printIntervals(vector<vector<int>> &intervals) {
    cout << "[ ";
    for (auto &iv : intervals) {
        cout << "[" << iv[0] << "," << iv[1] << "] ";
    }
    cout << "]\n";
}

int main() {
    // Example 1
    vector<vector<int>> arr1 = {{1,3},{2,6},{8,10},{15,18}};
    cout << "Input: [[1,3],[2,6],[8,10],[15,18]]\n";
    auto res1 = mergeOverlappingIntervals(arr1);
    cout << "Merged: ";
    printIntervals(res1);

    /* Dry Run for arr1:
       Sorted → [[1,3],[2,6],[8,10],[15,18]]
       - Take [1,3], ans = [[1,3]]
       - [2,6] overlaps with [1,3] → merge → [1,6]
       - [8,10] does not overlap → add → [[1,6],[8,10]]
       - [15,18] does not overlap → add → [[1,6],[8,10],[15,18]]
       Final Answer = [[1,6],[8,10],[15,18]]
    */

    // Example 2
    vector<vector<int>> arr2 = {{1,4},{4,5}};
    cout << "\nInput: [[1,4],[4,5]]\n";
    auto res2 = mergeOverlappingIntervals(arr2);
    cout << "Merged: ";
    printIntervals(res2);
    // Output: [[1,5]] (since touching intervals are considered overlapping)

    return 0;
}