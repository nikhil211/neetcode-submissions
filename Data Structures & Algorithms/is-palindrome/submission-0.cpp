class Solution {
public:
    bool isPalindrome(string s) {
          int len = s.size();
        if(len == 0) return false;

        string str;
        for(int i=0; i<len; i++) {
            char c = s[i];
            if(c >='A' && c<='Z') {
                c = c - 'A' + 'a';
                str+=c;
            }
            else if(c >= 'a' && c<= 'z')
                str+=c;
            else if( c >='0' && c<='9')
                str+=c;            
        }

        int l=0;
        int r = str.size()-1;
        cout << "s:" << str <<endl;
        while(l<r) {
            if(str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;    
    }
};
