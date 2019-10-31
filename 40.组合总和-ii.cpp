/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution
{
private:
    vector<int> ownCandidates;
    vector<vector<int>> res;
    vector<int> queue;

public:
    void combinationHandler(int index, int target)
    {
        if (target == 0)
        {
            res.push_back(queue);
            return;
        }
        for (int i = index; i < ownCandidates.size() && target - ownCandidates[i] >= 0; i++)
        {
            if (i > index && ownCandidates[i] == ownCandidates[i - 1])
                continue;
            queue.push_back(ownCandidates[i]);
            // 元素不可重复利用，使用下一个即i+1
            combinationHandler(i + 1, target - ownCandidates[i]);
            queue.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        this->ownCandidates = candidates;
        combinationHandler(0, target);
        return res;
    }
};
// @lc code=end
