class Solution:
    def numDecodings(self, s: str) -> int:
        soln = 0
        
        if len(s) == 0:
            return 0
        
        if s[0] == '0':
            return 0
        
        memo = [-1]*len(s)
        
        def inRange(n):
            return 0 < int(n) < 27
        
        if len(s) == 1:
            return 1 if inRange(s) else 0
        
        if len(s) == 2:
            sum = 0
            if inRange(s[0]) and int(s[1]) > 0:
                sum += 1
            if inRange(s) and int(s[0]) > 0:
                sum += 1

            return sum
        
        def decode(s, idx):
            if memo[idx] != -1:
                return memo[idx]
            if len(s) == 1:
                return 1 if inRange(s) else 0
            if len(s) == 2:
                sum = 0
                if inRange(s[0]) and int(s[1]) > 0:
                    sum += 1
                if inRange(s) and int(s[0]) > 0:
                    sum += 1
                
                return sum
            
            if s[0] == '0':
                return 0
            
            if inRange(s[:2]):
                memo[idx] = decode(s[1:], idx + 1) + decode(s[2:], idx + 2)
            else:
                memo[idx] = decode(s[1:], idx + 1)
            
            return memo[idx]
    
        decode(s, 0)
        soln = max(memo)
        return soln