// https://leetcode.com/problems/shopping-offers/

class Solution {
public:
    map<vector<int>,int> memo;
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int rem_sum = findBestOffers(price, special, needs);
        
        int best_sum = memo.size() > 0 ? memo.rbegin()->second : INT_MAX;
        return min(rem_sum, best_sum);
    }
    
    int findBestOffers(vector<int>& price, vector<vector<int>>& special, vector<int> needs) {
        int best_price = INT_MAX-1000;
        int rem_sum = 0;
        
        for (int i = 0; i < special.size(); i++) {
            
            vector<int> curr_offer(price.size(), 0);
            for(int k = 0; k < price.size(); k++) curr_offer[k] = special[i][k];
            
            if (isValidOffer(curr_offer, needs)) {
                
                if(memo.find(needs) != memo.end()) return memo[needs];
                
                vector<int> new_needs(needs.size(), 0);
                for(int j = 0; j < needs.size(); j++) new_needs[j] = needs[j] - curr_offer[j];
                
                best_price = min(best_price, special[i][price.size()] + findBestOffers(price, special, new_needs));
                memo[new_needs] = best_price;
            }
        }
        
        for (int i = 0; i < needs.size(); i++) rem_sum += needs[i]*price[i];
        return min(best_price, rem_sum);
    }
    
    bool isValidOffer(vector<int>& offer, vector<int>& needs) {
        for(int i = 0; i < offer.size(); i++) if(needs[i] < offer[i]) return false;
        return true;
    }
};