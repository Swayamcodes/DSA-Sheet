/**
 * LeetCode 74 - Search a 2D Matrix
 * --------------------------------
 *
 * 📌 Problem:
 * Write an efficient algorithm that searches for a value `target` in an m x n integer matrix.
 * The matrix has the following properties:
 *  - Integers in each row are sorted in ascending order from left to right.
 *  - The first integer of each row is greater than the last integer of the previous row.
 *
 * Return true if `target` is in `matrix`, otherwise false.
 *
 * Example:
 * matrix = [
 *  [1,  3,  5,  7],
 *  [10, 11, 16, 20],
 *  [23, 30, 34, 50]
 * ], target = 3
 * Output: true
 *
 * --------------------------------
 *
 * 📌 Approaches:
 *
 * 1) Treat matrix as flattened 1D sorted array and run a single binary search.
 *    - Map index `idx` in [0..m*n-1] to (row, col): row = idx / n, col = idx % n.
 *    - Time: O(log(m*n)) == O(log m + log n). Space: O(1).
 *    - Simple and elegant.
 *
 * 2) Two-step binary search (this file focuses on this approach):
 *    - First binary search across rows to find the row where `target` may exist.
 *      Use the property: row i contains values in [matrix[i][0], matrix[i][n-1]].
 *    - Second binary search inside that row to find `target`.
 *    - Time: O(log m + log n). Space: O(1).
 *
 * Both are logarithmic and acceptable. The two-step approach is often clearer to read
 * and maps directly to the matrix properties; the flattened approach is slightly
 * more concise.
 *
 * --------------------------------
 *
 * 🔍 Detailed reasoning (Two-step method):
 *
 * 1. Edge checks:
 *    - If matrix is empty or matrix[0] is empty, immediately return false.
 *
 * 2. Binary search on rows (indices 0..m-1):
 *    - For a candidate middle row `mid`, compute rowFirst = matrix[mid][0] and
 *      rowLast = matrix[mid][n-1]. There are three possible relations between
 *      `target` and this interval:
 *        a) target in [rowFirst, rowLast] -> target must (if present) be in this row.
 *        b) target > rowLast -> search lower rows: st = mid + 1.
 *        c) target < rowFirst -> search upper rows: end = mid - 1.
 *    - Use `mid = st + (end - st) / 2` to avoid overflow (though ints are fine here).
 *    - Stop when st > end (no candidate row found) and return false.
 *
 * 3. Binary search inside the selected row:
 *    - Standard binary search between columns 0..n-1.
 *    - Use `mid = l + (r - l) / 2`.
 *
 * --------------------------------
 *
 * 💡 Important implementation notes & pitfalls:
 *  - Use correct bounds: rows are 0..m-1, columns 0..n-1 — mixing them up causes
 *    out-of-bound accesses.
 *  - Always return the result of the inner row search when found. Calling the function
 *    without returning discards the result.
 *  - Use `<=` in binary-search loop conditions (`while (l <= r)`) to ensure single-element
 *    windows are checked.
 *  - When comparing to the row's last element, use strict comparisons properly; e.g.,
 *    if target > rowLast, move to lower rows.
 *
 * --------------------------------
 *
 * 📌 Dry Run (two-step) on the example:
 * m = 3, n = 4
 * matrix rows intervals:
 *  row0: [1, 7]
 *  row1: [10, 20]
 *  row2: [23, 50]
 * target = 3
 *
 * Step 1: binary search rows:
 *  st=0, end=2 -> mid = 1 -> interval [10,20]. target(3) < 10 -> end = mid-1 = 0
 *  st=0, end=0 -> mid = 0 -> interval [1,7].  target in [1,7] so search inside row 0.
 *
 * Step 2: binary search inside row0: [1,3,5,7]
 *  l=0, r=3 -> mid=1 -> matrix[0][1]=3 -> found -> return true.
 *
 * --------------------------------
 *
 * 📌 Final Code: Two-step binary search + detailed comments
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Binary search inside a single row. Returns true if `target` found.
    bool searchInRow(const vector<vector<int>>& matrix, int target, int row) {
        int n = matrix[0].size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2; // safe mid
            int val = matrix[row][mid];
            if (val == target) return true;
            if (val < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }

    // Two-step binary search: first find candidate row, then search within that row.
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        // Edge cases: empty matrix
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();

        int st = 0, end = m - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2; // mid row
            int rowFirst = matrix[mid][0];
            int rowLast = matrix[mid][n - 1];

            // If target falls within this row's range, search the row
            if (target >= rowFirst && target <= rowLast) {
                return searchInRow(matrix, target, mid);
            }
            // If target is greater than the last element, go to lower rows
            else if (target > rowLast) {
                st = mid + 1;
            }
            // If target is smaller than the first element, go to upper rows
            else {
                end = mid - 1;
            }
        }

        // No candidate row contains the target
        return false;
    }
};

// -------------------------------
// Helper and main for quick testing and demonstration
// -------------------------------

void testAndPrint(const vector<vector<int>>& matrix, int target) {
    Solution sol;
    bool found = sol.searchMatrix(matrix, target);

    cout << "Matrix:\n";
    for (const auto &r : matrix) {
        cout << "[ ";
        for (int x : r) cout << x << " ";
        cout << "]\n";
    }
    cout << "Target: " << target << " => ";
    cout << (found ? "FOUND\n" : "NOT FOUND\n");
    cout << string(40, '-') << "\n";
}

int main() {
    vector<vector<int>> mat1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };

    // Example tests
    testAndPrint(mat1, 3);   // true
    testAndPrint(mat1, 13);  // false

    // Edge cases
    vector<vector<int>> emptyMat;
    testAndPrint(emptyMat, 1); // false

    vector<vector<int>> oneRow = {{1, 2, 3, 4}};
    testAndPrint(oneRow, 4); // true
    testAndPrint(oneRow, 5); // false

    // Larger test: diagonal checks
    vector<vector<int>> mat2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    testAndPrint(mat2, 9);  // true
    testAndPrint(mat2, 0);  // false

    return 0;
}

/*
 Alternative: Flattened single binary search approach (commented out):

 bool searchMatrix_flat(const vector<vector<int>>& matrix, int target) {
     if (matrix.empty() || matrix[0].empty()) return false;
     int m = matrix.size();
     int n = matrix[0].size();
     int l = 0, r = m * n - 1;
     while (l <= r) {
         int mid = l + (r - l) / 2;
         int row = mid / n;
         int col = mid % n;
         int val = matrix[row][col];
         if (val == target) return true;
         if (val < target) l = mid + 1;
         else r = mid - 1;
     }
     return false;
 }

 This method is equivalent in complexity and is a compact alternative. Use whichever reads better to you.
 */
