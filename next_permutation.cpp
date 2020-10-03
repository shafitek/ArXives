// https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int start = n-1, end = 0;
        
        lexPermute(nums, start, end);
    }
    
    void lexPermute(vector<int> &nums, int &start, int end) {
        int i;
        for(i = start-1; i >= end; i--) {
            if(nums[i+1] > nums[i]) {
                int sm_idx = getNextBigNum(nums, nums[i], start, i+1);
                swap(nums[i], nums[sm_idx]);
                lexPermute(nums, start, i+1);
                return;
            }
        }
        
        reverse(nums, end);
    }
    
    int getNextBigNum(vector<int> &nums, int &num, int &start, int end) {
        for(int i = start; i >= end; i--) {
            if(nums[i] > num) {
                return i;
            }
        }
        
        return -1;
    }
    
    void reverse(vector<int> &nums, int start) {
        int n = (nums.size()-start)/2;
        int end = nums.size() - 1;
        for(int i = 0; i < n; i++) {
            swap(nums[start+i], nums[end-i]);
        }
    }
};