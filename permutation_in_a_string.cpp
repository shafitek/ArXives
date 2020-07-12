// https://leetcode.com/problems/permutation-in-string/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        size_t len1 = s1.length();
        size_t len2 = s2.length();
        
        if (len1 > len2) return false;
        
        int window_size = len1;
        int total_stride = len2 - len1 + 1;
        
        vector<int> h_map(26,0);
        
        for(int i = 0; i < len1; i++) h_map[s1[i]-'a']++;
        
        int k = 0;
        unsigned int permNum;
        vector<int> tmp_arr(26,0);
        
        while(k < total_stride){
            fill(tmp_arr.begin(), tmp_arr.end(), 0);
            permNum = 0;
            for(int i = 0; i < len1; i++) tmp_arr[s2[k+i]-'a']++;
            k++;

            for (int i = 0; i < 26; i++) {
                if(h_map[i] != tmp_arr[i]) break;
                permNum++;
            }
                        
            if (permNum == tmp_arr.size()) return true;
        }
        return false;
    }
};