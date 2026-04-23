class Solution {
public:
    bool isAnagram(string s, string t) {
        int lenS = s.size();
        int lenT = t.size();
        if(lenS!=lenT) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for(int i=0; i<lenS; i++) {
            if(s[i] != t[i]) return false;
        }
        
        return true;        
    } 
};
