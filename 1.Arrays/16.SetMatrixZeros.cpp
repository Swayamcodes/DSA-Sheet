/**
 * LeetCode 73 - Set Matrix Zeroes
 * --------------------------------
 *
 * 📌 Problem:
 * Given an m x n matrix, if an element is 0, set its entire row and column to 0.
 * Do it in-place (without using extra space if possible).
 *
 * Example:
 * Input:
 *   [ [1,1,1],
 *     [1,0,1],
 *     [1,1,1] ]
 *
 * Output:
 *   [ [1,0,1],
 *     [0,0,0],
 *     [1,0,1] ]
 *
 * --------------------------------
 *
 * 📌 Approaches:
 *
 * 1. Extra Space with Row/Col Arrays (Easy but O(m+n) space)
 *    - Maintain two arrays: rowZero[m], colZero[n].
 *    - First pass: mark rows/cols where a 0 appears.
 *    - Second pass: zero out based on those arrays.
 *    - Time: O(m*n), Space: O(m+n).
 *
 * 2. ✅ In-Place Optimal (O(1) extra space)
 *    - Use the first row and first column as markers.
 *    - Steps:
 *      • Check if the first row/col themselves contain zeros.
 *      • For each (i,j), if matrix[i][j]==0, mark matrix[i][0]=0 and matrix[0][j]=0.
 *      • In second pass, zero out based on markers.
 *      • Finally, zero out first row/col if needed.
 *    - Time: O(m*n), Space: O(1).
 *
 * --------------------------------
 *
 * 📌 Dry Run (Optimal Approach):
 * Input:
 *   [ [1,1,1],
 *     [1,0,1],
 *     [1,1,1] ]
 *
 * Step 1: firstRowZero=false, firstColZero=false
 *
 * Step 2: mark row/col for (1,1)=0 → matrix[1][0]=0, matrix[0][1]=0
 *
 * Matrix after marking:
 *   [ [1,0,1],
 *     [0,0,1],
 *     [1,1,1] ]
 *
 * Step 3: second pass:
 *   For cell (1,2): row marker=0 → set to 0
 *   For cell (2,1): col marker=0 → set to 0
 *
 * Result:
 *   [ [1,0,1],
 *     [0,0,0],
 *     [1,0,1] ]
 *
 * ✅ Correct.
 *
 * --------------------------------
 *
 * 📌 Final Code: In-Place Optimal Solution
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        // Step 1: check first row
        for (int j=0; j<n; j++) {
            if (matrix[0][j] == 0) { firstRowZero = true; break; }
        }
        // Step 2: check first col
        for (int i=0; i<m; i++) {
            if (matrix[i][0] == 0) { firstColZero = true; break; }
        }

        // Step 3: mark rows and cols
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // mark row
                    matrix[0][j] = 0; // mark col
                }
            }
        }

        // Step 4: use markers to set zeroes
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 5: handle first row & col
        if (firstRowZero) {
            for (int j=0; j<n; j++) matrix[0][j] = 0;
        }
        if (firstColZero) {
            for (int i=0; i<m; i++) matrix[i][0] = 0;
        }
    }
};

/*
// Alternate Simpler Approach (O(m+n) space):

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> rowZero(m, false);
        vector<bool> colZero(n, false);

        // First pass: mark
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] == 0) {
                    rowZero[i] = true;
                    colZero[j] = true;
                }
            }
        }

        // Second pass: zero out
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (rowZero[i] || colZero[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
*/

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    sol.setZeroes(mat);

    cout << "Result: \n";
    for (auto &row : mat) {
        for (auto &x : row) cout << x << " ";
        cout << endl;
    }
    return 0;
}
