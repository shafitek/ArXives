class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int len = strs.size();
        int min_str_size = INT_MAX;
        int min_idx = 0;
        std::string soln = "";

        for (int i = 0; i < len; i++)
        {
            if (min_str_size > strs[i].size())
            {
                min_str_size = strs[i].size();
                min_idx = i;
            }
        }

        if (len == 0 || min_str_size == 0)
            return "";
        if (len == 1)
            return strs[0];

        char ch_of_int = strs[0][0];

        for (int j = 0; j < min_str_size; j++)
        {
            ch_of_int = strs[min_idx][j];
            for (int i = 0; i < len; i++)
            {
                if (strs[i][j] != ch_of_int)
                    return soln;
            }
            soln += ch_of_int;
        }

        return soln;
    }
};