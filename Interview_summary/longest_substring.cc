#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

/*
 * Algorithm complexity: O(n)
 * Space complexity: O(n)
 */
int lengthOfLongestSubstr(std::string str) {
    std::unordered_map<char, int> mp;
    int maxLen = 0;
    int left = 0, right;
    for (right = 0; right < str.length(); right++) {
        if (mp.find(str[right]) != mp.end() && mp[str[right]] >= left) {
            left = mp[str[right]] + 1;
        }
        mp[str[right]] = right;
        maxLen = std::max(maxLen, right - left + 1);
    }
    return maxLen;
}

/*
 * Algorithm complexity: O(n)
 * Space complexity: O(1)
 */
int lengthOfLongestSubstring(std::string s) {
    std::vector<int> char_index(256, -1); // 存储字符最后出现的位置
    int max_len = 0;
    int left = 0; // 滑动窗口左边界
    
    for (int right = 0; right < s.size(); ++right) {
        // 如果字符已存在且在窗口内，移动左边界
        if (char_index[s[right]] >= left) {
            left = char_index[s[right]] + 1;
        }
        char_index[s[right]] = right; // 更新字符的最新位置
        max_len = std::max(max_len, right - left + 1); // 计算当前窗口长度
    }
    
    return max_len;
}

int main() {
    std::string str;
    while (std::getline(std::cin, str)) {
        int res1 = lengthOfLongestSubstr(str);
        int res2 = lengthOfLongestSubstring(str);
        std::cout << res1 << std::endl;
        std::cout << res2 << std::endl;
    }
    return 0;
}