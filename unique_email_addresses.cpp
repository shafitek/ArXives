// https://leetcode.com/problems/unique-email-addresses/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> soln_str;
        
        bool ignore_plus;
        
        for(auto const &em : emails) {
            ignore_plus = false;
            string curr_email = "";
            for(int i = 0; i < em.length(); i++) {
                if (em[i] == '@') {
                    curr_email += em.substr(i);
                    soln_str.insert(curr_email);
                    break;
                } else if(em[i] == '+') {
                    ignore_plus = true;
                } else if(em[i] == '.' || ignore_plus) {
                    continue;    
                } else {
                    curr_email += em[i];
                }
            }
        }
            
        return soln_str.size();
    }
};