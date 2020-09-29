// https://leetcode.com/problems/backspace-string-compare/

class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        string A, B;

        int idx_A = 0, idx_B = 0;

        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] != '#')
            {
                idx_A++;
                A += S[i];
            }
            else
            {
                idx_A = max(0, idx_A - 1);
                A.erase(A.begin() + idx_A, A.end());
            }
        }

        for (int i = 0; i < T.length(); i++)
        {
            if (T[i] != '#')
            {
                idx_B++;
                B += T[i];
            }
            else
            {
                idx_B = max(0, idx_B - 1);
                B.erase(B.begin() + idx_B, B.end());
            }
        }

        return A == B;
    }
};