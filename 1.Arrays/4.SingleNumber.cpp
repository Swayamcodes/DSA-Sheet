/**
 * LeetCode 136 - Single Number
 * --------------------------------
 *
 * 📌 Problem:
 * Given a non-empty array of integers `nums`, every element appears twice except for one.
 * Find that single element.
 *
 * Example:
 * Input:  [4,1,2,1,2]
 * Output: 4
 *
 * Constraints:
 * - Must run in linear time O(n).
 * - Use only constant extra space O(1).
 *
 * --------------------------------
 *
 * 📌 Approaches:
 *
 * 1. Brute Force (Hash Map / Frequency Count)
 *    - Count occurrences of each number.
 *    - Return the number with frequency 1.
 *    - Time: O(n), Space: O(n).
 *    - ❌ Uses extra space.
 *
 * 2. Sorting
 *    - Sort the array, then scan to find the non-duplicate.
 *    - Time: O(n log n), Space: O(1).
 *    - ❌ Not optimal.
 *
 * 3. ✅ Optimal: XOR Trick
 *    - Use property: x ^ x = 0, x ^ 0 = x.
 *    - If we XOR all numbers, duplicates cancel out and only the single number remains.
 *    - Time: O(n), Space: O(1).
 *
 * --------------------------------
 *
 * 📌 Dry Run (XOR approach):
 * nums = [4,1,2,1,2]
 * result = 0 ^ 4 = 4
 * result = 4 ^ 1 = 5
 * result = 5 ^ 2 = 7
 * result = 7 ^ 1 = 6
 * result = 6 ^ 2 = 4
 * ✅ Answer = 4
 *
 * --------------------------------
 *
 * 📌 Bitwise Basics for DSA:
 * 1. AND (&): 1 if both bits are 1.
 *    Example: 6 & 3 → 110 & 011 = 010 (2)
 *
 * 2. OR (|): 1 if at least one bit is 1.
 *    Example: 6 | 3 → 110 | 011 = 111 (7)
 *
 * 3. XOR (^): 1 if bits are different.
 *    Example: 6 ^ 3 → 110 ^ 011 = 101 (5)
 *    ✅ Common use: find unique elements.
 *
 * 4. NOT (~): Flips all bits.
 *    Example: ~5 (for 8-bit) → 11111010 (-6)
 *
 * 5. Left Shift (<<): Multiply by 2.
 *    Example: 5 << 1 = 10.
 *
 * 6. Right Shift (>>): Divide by 2 (floor).
 *    Example: 10 >> 1 = 5.
 *
 * --------------------------------
 *
 * 📌 Where Useful in DSA:
 * - Find unique numbers (LC 136, LC 137).
 * - Subset generation using bitmasking.
 * - Fast multiplication/division by powers of 2.
 * - Checking if a number is odd/even (x & 1).
 * - Swapping numbers without temp variable (a^=b, b^=a, a^=b).
 * - Counting set bits (Brian Kernighan’s algorithm).
 *
 * --------------------------------
 *
 * 📌 Revision Notes:
 * - XOR is the key trick here.
 * - Bit manipulation is widely used in optimization, subsets, DP, and interview tricks.
 * - Time O(n), Space O(1).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;  // XOR cancels out duplicates
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Single Number: " << sol.singleNumber(nums) << endl;

    return 0;
}
