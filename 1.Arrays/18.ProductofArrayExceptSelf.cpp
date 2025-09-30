#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Product of Array Except Self (LeetCode 238)

    -------------------------------------------------------------
    🔹 Problem Statement:
    Given an integer array nums, return an array answer such that
    answer[i] is equal to the product of all elements of nums
    except nums[i].

    ⚠️ Note:
    - You must solve it without using division.
    - O(n) time complexity required.

    Example:
        Input:  nums = [1,2,3,4]
        Output: [24,12,8,6]

        Input:  nums = [-1,1,0,-3,3]
        Output: [0,0,9,0,0]

    -------------------------------------------------------------
    🔹 How to Think About It:
    - Brute force: For each index, multiply everything except itself → O(n^2).
    - But we want O(n).
    - Trick: Pre-compute the product of everything to the left and right of each index.
      answer[i] = prefix[i] * suffix[i]

    -------------------------------------------------------------
    🔹 Multiple Approaches:
    1. Brute Force (O(n^2)) → Too slow.
    2. Division Trick (Not allowed).
    3. Prefix & Suffix Arrays (O(n) time, O(n) space).
    4. Optimized Prefix & Suffix in One Pass (O(n) time, O(1) extra space) ✅ BEST.

    -------------------------------------------------------------
    🔹 Complexity:
    Approach 3: Time O(n), Space O(n).
    Approach 4: Time O(n), Space O(1) (ignoring output).
*/


// -------------------------------------------------------------
// 🔹 Approach 3: Prefix & Suffix Arrays (O(n) space)
// -------------------------------------------------------------
class Solution_PrefixSuffix {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1), suffix(n, 1), ans(n);

        // Build prefix product
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        // Build suffix product
        for (int i = n-2; i >= 0; i--) {
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        // Final answer
        for (int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};


// -------------------------------------------------------------
// 🔹 Approach 4: Optimized (O(1) space) ✅ BEST
// -------------------------------------------------------------
class Solution_Optimized {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Step 1: Store prefix products directly in ans
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        // Step 2: Multiply suffix products into ans
        int suffix = 1;
        for (int i = n-1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};


// -------------------------------------------------------------
// 🔹 Driver Code (for testing)
// -------------------------------------------------------------
int main() {
    Solution_PrefixSuffix sol3;
    Solution_Optimized sol4;

    vector<int> nums1 = {1,2,3,4};
    vector<int> nums2 = {-1,1,0,-3,3};

    // Test Approach 3
    cout << "Approach 3 (Prefix & Suffix Arrays):" << endl;
    auto res1 = sol3.productExceptSelf(nums1);
    for (int x : res1) cout << x << " ";
    cout << endl;

    auto res2 = sol3.productExceptSelf(nums2);
    for (int x : res2) cout << x << " ";
    cout << endl;

    // Test Approach 4
    cout << "Approach 4 (Optimized O(1) space):" << endl;
    auto res3 = sol4.productExceptSelf(nums1);
    for (int x : res3) cout << x << " ";
    cout << endl;

    auto res4 = sol4.productExceptSelf(nums2);
    for (int x : res4) cout << x << " ";
    cout << endl;

    return 0;
}


/*
-------------------------------------------------------------
🔹 Dry Run Example: nums = [1,2,3,4]
-------------------------------------------------------------

Approach 4 (Optimized):

Step 1: Prefix pass
prefix = 1
ans = [1, _, _, _]   (i=0, ans[0]=1, prefix=1*1=1)
ans = [1, 1, _, _]   (i=1, ans[1]=1, prefix=1*2=2)
ans = [1, 1, 2, _]   (i=2, ans[2]=2, prefix=2*3=6)
ans = [1, 1, 2, 6]   (i=3, ans[3]=6, prefix=6*4=24)

Step 2: Suffix pass
suffix = 1
ans[3] = 6*1 = 6   (suffix=1*4=4)
ans[2] = 2*4 = 8   (suffix=4*3=12)
ans[1] = 1*12 = 12 (suffix=12*2=24)
ans[0] = 1*24 = 24 (suffix=24*1=24)

Final ans = [24, 12, 8, 6]

-------------------------------------------------------------
*/
