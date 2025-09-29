#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Longest Substring Without Repeating Characters (LeetCode 3)

    -------------------------------------------------------------
    🔹 Problem Statement:
    Given a string s, find the length of the longest substring 
    without repeating characters.

    Example:
        Input:  s = "abcabcbb"
        Output: 3   ("abc")

        Input:  s = "bbbbb"
        Output: 1   ("b")

    -------------------------------------------------------------
    🔹 Approach: Sliding Window + Hashing

    Idea:
    - We want substrings with no duplicates.
    - Use two pointers: `left` and `right` to form a window.
    - Use a hash set to track unique characters inside the window.

    Steps:
    1. Start with both pointers at 0.
    2. Expand `right` pointer to include characters one by one.
    3. If a duplicate is found:
          - shrink the window by moving `left` forward
          - remove characters from the set until the duplicate is gone.
    4. After ensuring uniqueness, update the maximum window length.
    5. Continue until `right` reaches the end of the string.

    Time Complexity:  O(n)  (each char is added/removed once)
    Space Complexity: O(k)  (k = unique characters in the window, <= 26 or 128)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Hash set to keep track of unique characters in current window
        unordered_set<char> window;

        int left = 0;          // left boundary of window
        int maxLen = 0;        // result

        // Expand window by moving right pointer
        for (int right = 0; right < s.size(); right++) {
            // If s[right] already exists -> shrink from left
            while (window.find(s[right]) != window.end()) {
                window.erase(s[left]); // remove char at left
                left++;                // move left forward
            }

            // Insert current character (now unique)
            window.insert(s[right]);

            // Update max length (window size = right - left + 1)
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

// -------------------------------------------------------------
// 🔹 Driver Code (for testing)
// -------------------------------------------------------------
int main() {
    Solution sol;

    string s1 = "abcabcbb";
    cout << "Input: " << s1 << " -> Longest substring length = "
         << sol.lengthOfLongestSubstring(s1) << endl;

    string s2 = "bbbbb";
    cout << "Input: " << s2 << " -> Longest substring length = "
         << sol.lengthOfLongestSubstring(s2) << endl;

    string s3 = "pwwkew";
    cout << "Input: " << s3 << " -> Longest substring length = "
         << sol.lengthOfLongestSubstring(s3) << endl;

    string s4 = "";
    cout << "Input: '" << s4 << "' -> Longest substring length = "
         << sol.lengthOfLongestSubstring(s4) << endl;

    return 0;
}

/*
-------------------------------------------------------------
🔹 Dry Run Example: s = "pwwkew"
-------------------------------------------------------------
left=0, right=0 -> window = {p}, maxLen = 1
left=0, right=1 -> duplicate 'w' found → remove 'p' then 'w'
                  window = {w}, maxLen = 1
left=1, right=2 -> duplicate 'w' again → shrink left
                  window = {w}, maxLen = 1
left=2, right=3 -> add 'k' → window = {w,k}, maxLen = 2
left=2, right=4 -> add 'e' → window = {w,k,e}, maxLen = 3
left=2, right=5 -> duplicate 'w' → shrink until unique
                  window = {k,e,w}, maxLen = 3
Final Answer = 3 (substring "wke")
-------------------------------------------------------------
*/
