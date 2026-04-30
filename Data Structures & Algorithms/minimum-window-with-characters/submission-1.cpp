class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() == 0) return "";
        if(t.size() > s.size()) return "";

        unordered_map<char,int> mpT;
        int lenS = s.size();
        int lenT = t.size();
        for(char c: t) mpT[c]++;
        int miniLen = INT_MAX;
        pair<int,int> idx;

        for(int i=0; i<lenS; i++) {
            unordered_map<char,int> mpS;
            for(int j=i; j<lenS; j++) {                
                mpS[s[j]]++;
                if(j-i+1 >= lenT) {
                    //check if hashmap is equal
                    bool flag = true;
                    for(auto it= mpT.begin(); it!=mpT.end(); it++) {
                            char c = it->first;
                            int count = it->second;
                           
                            if(count > mpS[c]) {
                                flag = false;
                                break;
                            }
                    }
                    

                    if(true == flag) { //hashmap is equal
                        
                        if(miniLen > (j-i+1)) {
                            miniLen = (j-i+1);
                            idx = {i, j};
                          
                        }
                    }
                  
                }
                

            }
        }
        

        if(INT_MAX == miniLen) return "";
        else return s.substr(idx.first, miniLen);

    }
};
