// https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> soln;
        
        set<int> t_set;
        set<string> f_set;
        map<string, int> f_map_idx;
        
        for(int i = 0; i < orders.size(); i++) {
            t_set.insert(stoi(orders[i][1]));
            f_set.insert(orders[i][2]);
        }
        
        vector<int> tables(t_set.begin(), t_set.end());
        
        vector<string> food;
        food.push_back("Table");
        
        std::set<string>::iterator it;
        int idx = 0;
        for(it = f_set.begin(); it != f_set.end(); ++it) {
            string elem = *it;
            f_map_idx[elem] = idx;
            food.push_back(elem);
            idx++;
        }
        
        soln.push_back(food);
        
        map<int, vector<string>> f_map;
        
        for(int i = 0; i < orders.size(); i++) {
            int t_num = stoi(orders[i][1]);
            if(f_map.find(t_num) == f_map.end()) {
                vector<string> v(food.size(), "0");
                v[0] = orders[i][1];
                f_map[t_num] = v;
            }
            int idx = f_map_idx[orders[i][2]]+1;
            f_map[t_num][idx] = to_string((stoi(f_map[t_num][idx]))+1);
        }
        
        for(auto const &[key, val]:f_map) {
            soln.push_back(val);
        }
        
        return soln;
    }
};