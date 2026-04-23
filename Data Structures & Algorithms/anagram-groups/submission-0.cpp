class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> ans;
        unordered_map<string,vector<int>> mp;
        int idx = 0;

        for(int i=0; i<strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());

            if (mp.find(temp) != mp.end()) { //already present
                mp[temp].push_back(i);
            }
            else { //not present
                vector<int> v;
                v.push_back(i);
                mp.insert({temp, v});
            }
        }

        for (auto it: mp) {
            vector<string> v;
            for(int i=0; i < it.second.size(); i++) {
                v.push_back(strs[it.second[i]]);
            }
            ans.push_back(v);
        }

        return ans;         
    }
};
