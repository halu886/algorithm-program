/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现strStr()
 */
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
        {
            return 0;
        }
        int p_haystack = 0;
        int is_match = false;

        while (p_haystack <= (int(haystack.size()) - int(needle.size())) && !is_match)
        {
            is_match = true;
            for (int i = 0; i < needle.size(); i++)
            {
                if (haystack[p_haystack + i] != needle[i])
                {
                    is_match = false;
                    break;
                }
            }
            p_haystack++;
        }
        return is_match ? p_haystack - 1 : -1;
    }
};
