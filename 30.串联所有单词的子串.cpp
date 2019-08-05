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
        int result[] = {};
        unordered_map<string, int> vectorHash(10);
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            if (vectorHash.contians(word))
            {
                vectorHash.set(word, vectorhash.get(word) + 1);
            }
            else
            {
                vectorHash.set(word, 1);
            }
        }
        for (int i = 0; i < (s.length - wordSizeSum); i++)
        {
            unordered_map<string, int> wordHash;
            bool isMatch = true;
            for (int j = i; j < i + wordSizeSum; j = j + wordSize)
            {
                string word = s.sub(j, wordSize);
                if (wordHash.has(word))
                {
                    wordHash.set(word, wordHash.get(word) + 1);
                }
                else
                {
                    wordHash.set(word, 1);
                }

                if (wordHash.get(word) > vectorHash.get(word))
                {
                    isMatch = false;
                    break;
                }
            }

            if (isMatch)
            {
                result.push(i);
            }
        }
        return result;
    }
};
