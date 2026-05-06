class Solution {
public:
    string minWindow(string s, string t) {
        int lenT = t.size();
        int lenS = s.size();
        if(lenT == 0 || (lenS < lenT)) return "";

        unordered_map<char,int> mpT,mpS;
        int miniLen = INT_MAX;
        pair<int,int> idx;

        for(auto c: t) mpT[c]++;
        int need = mpT.size();
        int have = 0;

        int l=0;
        int r;

       for(r=0; r<lenS; r++) {
            char c = s[r];
            mpS[c]++;

            if(mpT.count(c) && mpS[c] == mpT[c]) // condition meet
                have++;

            while(have == need) {

               if(miniLen > (r-l+1)) {
                    miniLen = r-l+1;
                    idx = {l, r};
               }
               mpS[s[l]]--;
               
               if(mpT.count(s[l]) && (mpT[s[l]] > mpS[s[l]])) have--;
               l++;
            }


        
        }
        return (miniLen == INT_MAX) ? "" : s.substr(idx.first, miniLen);
    }
};
