class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0, r=0;
        int maxi = 0;
        unordered_set<char> Set;
        while(l<=r && r < s.size()) {
            if(Set.empty()) {
                maxi = max(maxi, 1);
                Set.insert(s[r]);
                r++;
                continue;
            }
            
            if (Set.find(s[r]) == Set.end()) { //new char
                Set.insert(s[r]);
                maxi = max(maxi, r-l+1);
                r++;
            }
            else { //duplicate
                l++;
                r = l;
                Set.clear();
            }
            
        }

        return maxi;        
    }
};
