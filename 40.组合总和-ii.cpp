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

    void combinationHandler(int index, int target)
    {
        if (target == 0)
        {
            res.push_back(queue);
            return;
        }
        for (int i = index + 1; i < ownCandidates.size() && target - ownCandidates[i] >= 0; i++)
        {
            if (i != ownCandidates.size() + 1 && ownCandidates[i] == ownCandidates[i + 1])
            {
                continue;
            }
            queue.push_back(ownCandidates[i]);
            combinationHandler(i, target - ownCandidates[i]);
            queue.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        this->ownCandidates = candidates;
        combinationHandler(0, target);
    }
};
// @lc code=end
