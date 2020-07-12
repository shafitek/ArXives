class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        size_t len = strs.size();
        unordered_map<string, vector<string>> h_map;

        vector<string> str_cp = strs;

        for (auto s : str_cp)
        {
            string orig = s;
            sort(s.begin(), s.end());
            h_map[s].push_back(orig);
        }

        vector<vector<string>> soln;

        for (auto const &[key, val] : h_map)
        {
            soln.push_back(val);
        }

        return soln;
    }
};