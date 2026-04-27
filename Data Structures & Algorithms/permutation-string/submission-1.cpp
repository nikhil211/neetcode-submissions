class Solution {
public:
    bool compareString(string a, string b) {
        //sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        //cout<< "A:" << a << endl;
        //cout<< "B:" << b << endl;
        for(int i=0; i< a.size(); i++)
            if(a[i] != b[i]) {
                //cout<< "false" <<endl; 
                return false;
            }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
       int k = s1.size();
        int len = s2.size();
        if (k > len) return false;
        int as1 = 0;
        int as2 = 0;
        sort(s1.begin(), s1.end());
        for(int i=0; i<k; i++)
            as1 += s1[i] -'a';

        for(int i=0; i<k; i++)
            as2 += s2[i] -'a';

        if(as1 == as2) {
            string s = s2.substr(0, k);
            bool res = compareString(s1, s);
            if (res) 
                return true;
        }
        
        for (int i=k; i<s2.size(); i++) {
            as2 += s2[i] - 'a';
            //cout << as2 << endl;
            as2 -= s2[i-k] - 'a';
            //cout << as2 << endl;
            //cout << "as1:" <<as1 << "   as2:" << as2<<endl;
            if(as1 == as2) {
                
                string s = s2.substr(i-k+1, k);
                bool res = compareString(s1, s);
                if (res) 
                    return true;
            }
        }
        return false;        
    }
};
