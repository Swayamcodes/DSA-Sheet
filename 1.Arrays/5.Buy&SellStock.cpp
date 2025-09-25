/**
 * LeetCode 121 - Best Time to Buy and Sell Stock
 * --------------------------------
 *
 * 📌 Problem:
 * You are given an array prices where prices[i] is the price of a stock on day i.
 * Find the maximum profit you can achieve by buying on one day and selling on another day after the buy day.
 * If no profit is possible, return 0.
 *
 * Example:
 * Input:  [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1), sell on day 5 (price = 6), profit = 5.
 *
 * --------------------------------
 *
 * 📌 Approaches:
 *
 * 1. Brute Force
 *    - For each pair (i, j) with i < j, compute profit = prices[j] - prices[i].
 *    - Track the maximum.
 *    - Time: O(n^2), Space: O(1).
 *    - ❌ Too slow.
 *
 * 2. ✅ Optimal One Pass (Greedy)
 *    - Track the lowest price so far (bestBuy).
 *    - At each day, compute profit = currentPrice - bestBuy.
 *    - Update maximum profit if this profit is greater.
 *    - Time: O(n), Space: O(1).
 *    - ✅ Best solution.
 *
 * --------------------------------
 *
 * 📌 Dry Run:
 * Input: [7,1,5,3,6,4]
 *
 * Day 1: price=7 → bestBuy=7, maxP=0
 * Day 2: price=1 → bestBuy=1, maxP=0
 * Day 3: price=5 → profit=4, maxP=4
 * Day 4: price=3 → profit=2, maxP=4
 * Day 5: price=6 → profit=5, maxP=5
 * Day 6: price=4 → profit=3, maxP=5
 * ✅ Answer = 5
 *
 * --------------------------------
 *
 * 📌 Revision Notes:
 * - Track the lowest price seen so far.
 * - Profit at each day = currentPrice - lowestPriceSoFar.
 * - Return the maximum profit across all days.
 * - If array is strictly decreasing, return 0.
 * - Complexity: O(n) time, O(1) space.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& A) {
        int maxP = 0;           // maximum profit so far
        int bestBuy = INT_MAX;  // lowest price so far

        for (int i = 0; i < A.size(); i++) {
            bestBuy = min(A[i], bestBuy);             // update best buy price
            maxP = max(maxP, A[i] - bestBuy);         // update max profit
        }
        return maxP;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    cout << "Max Profit: " << sol.maxProfit(prices) << endl;
    return 0;
}