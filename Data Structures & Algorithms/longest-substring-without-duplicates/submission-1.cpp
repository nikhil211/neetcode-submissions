class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int l = 0;
        int r = 0;
        int res = 0;
        set<char> Set;
        for(r=0; r<s.size(); r++) {
            while(Set.find(s[r]) != Set.end()) { //duplicate
                Set.erase(s[l]);
                l++;
            }

            Set.insert(s[r]);
            res = max(res, r-l+1);            
        }
        return res;
    }
};
