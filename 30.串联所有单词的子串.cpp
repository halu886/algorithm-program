/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */
#include <unordered_map>
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        if (s.size() == 0 || words.size() == 0)
        {
            return {};
        }

        int wordSize = words[0].size();
        int wordSizeSum = wordSize * words.size();

        if (wordSizeSum > s.size())
        {
            return {};
        }
        vector<int> result;
        unordered_map<string, int> vectorHash;
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            if (vectorHash[word])
            {
                ++vectorHash[word];
            }
            else
            {
                vectorHash[word] = 1;
            }
        }
        // for (const auto &n : vectorHash)
        // {
        //     cout << n.first << "\t" << n.second << endl;
        // }
        for (int i = 0; i <= (s.size() - wordSizeSum); i++)
        {
            unordered_map<string, int> wordHash;
            bool isMatch = true;
            // cout << "begin" << endl;
            for (int j = i; j < i + wordSizeSum; j = j + wordSize)
            {
                string word = s.substr(j, wordSize);

                if (wordHash[word])
                {
                    ++wordHash[word];
                }
                else
                {
                    wordHash[word] = 1;
                }
                // cout << word << int(wordHash[word]) << endl;
                // cout << i << "\t" << j << endl;

                if (wordHash[word] > vectorHash[word])
                {
                    isMatch = false;
                    break;
                }
            }

            // cout << "end"
            //      << "\t" << isMatch << "\t" << s << endl;
            // cout << i << "\t" << s.size() << "\t" << wordSizeSum << endl;
            if (isMatch)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};
