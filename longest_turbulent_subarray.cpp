// https://leetcode.com/problems/longest-turbulent-subarray/

class Solution
{
public:
    int maxTurbulenceSize(vector<int> &A)
    {
        if (A.size() == 1)
            return 1;
        if (A.size() == 2)
            return (A[0] > A[1] || A[0] < A[1]) ? 2 : 1;

        int max_val = 0;
        short sgn = A[0] > A[1] ? 1 : A[0] == A[1] ? 2 : 0;
        int ptr = A[0] == A[1] ? 1 : 0;

        for (int i = 1; i < A.size() - 1; i++)
        {
            if ((sgn == 0 && A[i] < A[i + 1]) || (sgn == 1 && A[i] > A[i + 1]))
            {
                max_val = max(max_val, i - ptr + 1);
                ptr = i;
            }

            if (A[i] == A[i + 1])
            {
                sgn = 2;
                max_val = max(max_val, i - ptr + 1);
                ptr = i + 1;
            }

            if (A[i] > A[i + 1])
                sgn = 1;
            if (A[i] < A[i + 1])
                sgn = 0;
        }

        return max_val > A.size() - ptr ? max_val : A.size() - ptr;
    }
};