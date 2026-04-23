class Solution {
public:

    int findLength(string s) {
        int len = s.size();
        int num=0;
        for(int i=0; i<len; i++) {
            num = (10*num) + (s[i]-'0');
        }
        return num;
    }

    string encode(vector<string>& strs) {
        string s;
        for(auto &it : strs) {
            int len = it.size();
            //cout << "string: " << it <<endl;
            string temp;
            while(len > 0) {
                int r = (len % 10);
                len = (len / 10);                
                temp += (r)+'0';
                
            }
            reverse(temp.begin(), temp.end());
            s+=temp;
            s+='#';
            s+=it;
        }
        //cout<< s << endl;
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int lenOfStr = s.size();
        int i = 0;   
        while(s[i] != '\0') {
            //find length and # then string of len length
            string temp;
            while(s[i] != '#') {
                temp+=s[i++];
            }
            i++;
            int len = findLength(temp);
            int j = 0;
            string res;
            for(j=0; j<len; j++) {
                res+=s[i+j];
                //cout<<res<<endl;
            }
            ans.push_back(res);
            i= i+j;

        }
        return ans;
    }
};
