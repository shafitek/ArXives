// INCOMPLETE!!!

class Solution
{
public:
    vector<vector<int>> twoSum(vector<int> &nums, int idx, vector<bool> &doneList)
    {
        vector<vector<int>> result;
        unordered_map<int, int> h_map;
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == idx || doneList[i])
                continue;
            j = -nums[idx] - nums[i];
            if (h_map.count(j) > 0)
            {
                result.push_back({nums[i], nums[h_map[j]]});
            }
            else
            {
                h_map[nums[i]] = i;
            }
        }

        return result;
    }
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> soln;
        if (nums.size() < 3)
            return soln;
        unordered_map<long, bool> item_exists_map;

        vector<bool> doneList(nums.size(), false);
        for (int i = 0; i < nums.size(); i++)
        {
            doneList[i] = true;
            vector<vector<int>> res = twoSum(nums, i, doneList);
            for (int j = 0; j < res.size(); j++)
            {
                res[j].push_back(nums[i]);
                long hash = res[j][0] ^ res[j][1] ^ res[j][2];
                // cout << nums[i] << " -> " << res[j][0] << "," << res[j][1] << "," << res[j][2] << " | " << hash << endl;
                if (item_exists_map.count(hash) > 0)
                    continue;

                item_exists_map[hash] = true;

                soln.push_back(res[j]);
            }
            // cout << "---\n";
        }

        return soln;
    }
};