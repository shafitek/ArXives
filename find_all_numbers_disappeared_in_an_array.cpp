// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

// SOLN 1
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> soln;

        int nums_length = nums.size();
        int idx = 0;

        for (auto num : nums)
        {
            idx = num > 0 ? (num - 1) : (-num - 1);
            if (nums[idx] > 0)
            {
                nums[idx] = -nums[idx];
            }
        }

        for (int i = 0; i < nums_length; i++)
        {
            if (nums[i] > 0)
            {
                soln.push_back(i + 1);
            }
        }

        return soln;
    }
};

// SOLN 2
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> soln;
        
        vector<int> &A = nums;
        int n = nums.size();
        
        for (auto &i : nums) i--;
        
        for(int i = 0; i < n; i++) {
            if (A[i] == -1) continue;
            int k = A[i];
            while(k != -1) {
                int tmp = A[k];
                A[k] = -1;
                k = tmp;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(A[i] != -1) soln.push_back(i+1);
        }
        
        return soln;
    }
};