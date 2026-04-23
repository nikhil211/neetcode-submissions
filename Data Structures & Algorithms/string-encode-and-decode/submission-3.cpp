class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(const string &it : strs) {
            s += to_string(it.size()) + "#" + it;
        }
        cout<< "Encode s:" << s <<endl;
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i=0;
        cout<< "Decode s:" << s <<endl;
        while(i < s.size()) {
            int j = i;
            string res;
            while(j<s.size() && s[j] != '#' )
                j++;

            int lenOfNumString = j-i;         
            string temp = s.substr(i, lenOfNumString);
            int len = stoi(temp);
            cout<< "temp " << temp << "Len: " << len << "j:" << j <<endl;
            i = j+1;
            j = i + len;
            res = s.substr(i, len);
            cout<< res <<endl;
            ans.push_back(res);
            i=j;
        }


        return ans;
    }
};
