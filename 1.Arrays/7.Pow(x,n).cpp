/**
 * LeetCode 50 - Pow(x, n)
 * --------------------------------
 *
 * 📌 Problem:
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 *
 * Examples:
 * Input:  x = 2.00000, n = 10 → Output: 1024.00000
 * Input:  x = 2.00000, n = -2 → Output: 0.25000
 *
 * Constraints:
 * - n can be negative.
 * - Must run in logarithmic time O(log n).
 *
 * --------------------------------
 *
 * 📌 Approach (Binary Exponentiation / Fast Power):
 *
 * We use the idea of squaring the base and halving the exponent step by step.
 *
 * Steps:
 * 1. Handle edge cases:
 *    - n == 0 → return 1 (anything to the power 0 is 1).
 *    - x == 0 → return 0 (0^n = 0).
 *    - x == 1 → return 1 (1^n = 1).
 *    - x == -1 → return 1 if n is even, -1 if n is odd.
 *
 * 2. Handle negative exponents:
 *    - If n < 0, then x^n = (1/x)^(-n).
 *    - Flip the base: x = 1/x.
 *    - Make exponent positive: n = -n.
 *
 * 3. Main loop (binary exponentiation):
 *    - While exponent > 0:
 *      • If exponent is odd → multiply ans by current base.
 *        (This "saves" the extra x because odd exponents can't be fully halved.)
 *      • Square the base: x = x * x.
 *      • Halve the exponent: n = n / 2.
 *
 * Example Dry Run: x = 2, n = 10
 * - ans=1, x=2, n=10
 * - n even → square base → x=4, n=5
 * - n odd  → ans=1*4=4, square base → x=16, n=2
 * - n even → x=256, n=1
 * - n odd  → ans=4*256=1024, x=65536, n=0
 * ✅ Result = 1024
 *
 * Example Dry Run: x = 2, n = -2
 * - Flip: x=1/2=0.5, n=2
 * - ans=1, x=0.5, n=2
 * - n even → x=0.25, n=1
 * - n odd  → ans=1*0.25=0.25, x=0.0625, n=0
 * ✅ Result = 0.25
 *
 * --------------------------------
 *
 * 📌 Revision Notes:
 * - Always handle negative exponents (x = 1/x, n = -n).
 * - In each loop iteration:
 *   S1 → If exponent odd, multiply ans by base.
 *   S2 → Square the base.
 *   S3 → Divide the exponent by 2.
 * - Time complexity: O(log n).
 * - Space complexity: O(1).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (x == 0) return 0.0;
        if (x == 1) return 1.0;
        if (x == -1 && n % 2 == 0) return 1.0;
        if (x == -1 && n % 2 != 0) return -1.0;

        double ans = 1;
        long binForm = n; // use long to handle -2^31 case

        if (binForm < 0) {
            x = 1 / x;         // flip base for negative power
            binForm = -binForm; // make exponent positive
        }

        while (binForm > 0) {
            if (binForm % 2 == 1) {
                ans *= x;       // save current base if exponent is odd
            }
            x = x * x;          // square the base
            binForm /= 2;       // divide exponent by 2
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.myPow(2.00000, 10) << endl;   // 1024
    cout << sol.myPow(2.00000, -2) << endl;   // 0.25
    cout << sol.myPow(-1.0000, 3) << endl;    // -1
    cout << sol.myPow(-1.0000, 4) << endl;    // 1
    return 0;
}