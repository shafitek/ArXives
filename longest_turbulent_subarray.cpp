// https://leetcode.com/problems/longest-turbulent-subarray/
// INCOMPLETE!

class Solution
{
public:
    int maxTurbulenceSize(vector<int> &A)
    {
        if (A.size() == 1)
            return 1;
        if (A.size() == 2)
            return (A[0] > A[1] || A[0] < A[1]) ? 2 : 1;

        int max_score = 0;

        short greaterThan = (A[0] > A[1]) ? 1 : 0;
        int curr_score = (A[0] == A[1]) ? 1 : 2;

        for (int i = 1; i < A.size() - 1; i++)
        {
            if (A[i] == A[i + 1])
            {
                // cout << "Equal at " << i << endl;
                max_score = curr_score == 1 ? max(max_score, curr_score) : max(max_score, ++curr_score);
                curr_score = 1;
                if (i + 2 < A.size())
                {
                    if (A[i] > A[i + 2])
                    {
                        greaterThan = 0;
                        i += 2;
                        curr_score = 2;
                    }
                    if (A[i] < A[i + 2])
                    {
                        greaterThan = 1;
                        i += 2;
                        curr_score = 2;
                    }
                }
                continue;
            }
            if ((greaterThan == 0 && A[i] < A[i + 1]) || (greaterThan == 1 && A[i] > A[i + 1]))
            {
                max_score = max(max_score, curr_score);
                // cout << "Pattern breaks at index " << i << " which is " << A[i] << endl;
                curr_score = 2;
                continue;
            }
            if (greaterThan == 1 && A[i] < A[i + 1])
            {
                curr_score++;
                greaterThan = 0;
                // cout << A[i+1] << " greaterThan " << A[i] << endl;
                continue;
            }
            if (greaterThan == 0 && A[i] > A[i + 1])
            {
                curr_score++;
                greaterThan = 1;
                // cout << A[i+1] << " LessThan " << A[i] << endl;
                continue;
            }
        }

        return max(max_score, curr_score);
    }
};
