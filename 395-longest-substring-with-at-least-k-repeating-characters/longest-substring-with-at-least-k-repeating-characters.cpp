class Solution {
public:

    int longestSubstring(string s, int k) {

        // If substring is smaller than k,
        // no character can occur k times
        if (s.length() < k)
            return 0;

        // Count frequency of characters
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        // Find a character whose frequency is less than k
        for (int i = 0; i < s.length(); i++) {

            if (freq[s[i]] < k) {

                // Split at this invalid character
                string left = s.substr(0, i);
                string right = s.substr(i + 1);

                // Solve both parts recursively
                return max(
                    longestSubstring(left, k),
                    longestSubstring(right, k)
                );
            }
        }

        // Every character occurs at least k times
        return s.length();
    }
};