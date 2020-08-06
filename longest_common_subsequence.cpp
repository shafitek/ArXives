// https://leetcode.com/problems/longest-common-subsequence/

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));

        CalcLength(dp, text1, text2);

        return dp[text1.length()][text2.length()];
    }

    void CalcLength(vector<vector<int>> &dp, string &text1, string &text2)
    {
        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 1; j < dp[0].size(); j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else if (dp[i - 1][j] >= dp[i][j - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }

// MEMOIZED VERSION - TLE!
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {        
        vector<vector<int>> dp(text1.length()+1, vector<int> (text2.length() + 1, 0));
                
        CalcLength(dp, text1, text2, text1.length(), text2.length());
        
        return dp[text1.length()][text2.length()];
    }
    
    int CalcLength(vector<vector<int>>& dp, string& text1, string& text2, int i, int j){
        if (i < 1 || j < 1) return 0;
                
        if(text1[i-1] == text2[j-1]) {
            dp[i][j] = 1 + CalcLength(dp, text1, text2, i-1, j-1);
        } else {
            dp[i][j] = max(CalcLength(dp, text1, text2, i-1, j), CalcLength(dp, text1, text2, i, j-1));
        }
        
        return dp[i][j];
    }
    
    template <class T>
    void PrintMatrix(vector<vector<T>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            cout << "| ";
            for (int j = 0; j < matrix[0].size(); j++)
            {
                cout << matrix[i][j] << " | ";
            }
            cout << endl;
        }
        cout << "-----" << endl;
    }
};