// https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string S) {        
        vector<int> soln;
                
        unordered_map<char, vector<int>> mmap;
        
        for(int i = 0; i < S.length(); i++) {
            mmap[S[i]].push_back(i);
        }
        
        int new_chk_bound = mmap[S[0]].back();
        for(int i = 0; i < S.length(); i++) {
            for(int j = i+1; j < new_chk_bound; j++) {
                if (mmap[S[j]].back() > new_chk_bound) {
                    new_chk_bound = mmap[S[j]].back();
                }
            }
            // cout << S.substr(i, (new_chk_bound - i + 1)) << ", " << i << endl;
            soln.push_back(new_chk_bound - i + 1);
            i = new_chk_bound + 1;
            new_chk_bound = (i < S.length()) ? mmap[S[i]].back() : 0;
            i--;
        }
        
        
        return soln;
    }
};