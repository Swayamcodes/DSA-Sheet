/*
LeetCode 2965 - Find Missing and Repeated Values

------------------------------------------------
Problem:
We are given an n x n grid containing numbers from 1 to n^2.
- Exactly one number is missing
- Exactly one number is repeated
We need to return [repeated, missing].

------------------------------------------------
Approach (Set + Math):
1. Use an unordered_set to track numbers we’ve seen.
   - First occurrence → insert into set.
   - Second occurrence → repeated element found.
2. Keep track of actual sum of all elements.
3. Compute expected sum of numbers from 1..n^2 = (n^2)(n^2+1)/2.
4. Missing number = expectedSum + repeated - actualSum.
5. Return [repeated, missing].

------------------------------------------------
Why use set?
- The set keeps memory of all numbers we’ve seen so far.
- If we encounter a number already in the set → that’s the duplicate.

------------------------------------------------
Complexity:
- Time: O(n^2) (we scan every element once).
- Space: O(n^2) (the set can hold up to n^2 numbers).

------------------------------------------------
Short Revision Notes:
- Use set to find repeated element.
- Track actual sum while traversing.
- Missing = expectedSum + repeated - actualSum.
- Answer = [repeated, missing].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;   // to detect duplicates
        int n = grid.size();
        int a, b;               // a = repeated, b = missing
        int expSum = 0, actualSum = 0;

        // Traverse grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                actualSum += grid[i][j];

                if (s.find(grid[i][j]) != s.end()) {
                    // found duplicate
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }

        // Expected sum of 1..n^2
        expSum = (n*n) * ((n*n) + 1) / 2;

        // Find missing
        b = expSum + a - actualSum;
        ans.push_back(b);

        return ans;
    }
};

// Example run
int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 3}, {2, 2}};
    vector<int> ans = sol.findMissingAndRepeatedValues(grid);
    cout << "Repeated = " << ans[0] << ", Missing = " << ans[1] << endl;
    return 0;
}
