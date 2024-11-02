//Approach 1 : poor approcah but accepted

class Solution {
public:
    bool isgood(string s) {
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] == 0) {
                mp[s[i]]++;
            } else {
                return false;
            }
        }
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        string t;
        int mx_ln = 0;  // Initialize to 0 instead of INT_MIN
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            t.push_back(s[r]);
            if (isgood(t)) {
                mx_ln = max(mx_ln, (int)t.size());
            } else {
                l++;
                t.erase(t.begin());
            }
        }
        return mx_ln;
    }
};
//Approach 2 : much more optimized and accepted
class Solution {
public:
    bool isgood(const string& s, int left, int right) {
        map<char, int> mp;
        for (int i = left; i <= right; i++) {
            if (mp[s[i]] > 0) {
                return false;
            }
            mp[s[i]]++;
        }
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            // Check if the substring s[left:right] has all unique characters
            if (isgood(s, left, right)) {
                maxLength = max(maxLength, right - left + 1);
            } else {
                // Move the left pointer to reduce the window size
                left++;
            }
        }

        return maxLength;
    }
};
//Approach 3 : Also much more efficient
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;  // Store the index of each character
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            char currentChar = s[right];

            // If the character is already in the map and is within the current window
            if (charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= left) {
                // Move the left pointer to one position after the previous occurrence
                left = charIndex[currentChar] + 1;
            }

            // Update the index of the current character
            charIndex[currentChar] = right;

            // Calculate the max length of the substring
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
//Approach 4 : from leetcode Editorial
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_set<char> charSet;
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (charSet.count(s[right]) == 0) {
                charSet.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
            } else {
                while (charSet.count(s[right])) {
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);
            }
        }

        return maxLength;
    }
};




