class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto it: mp) {
            v.push_back({it.second, it.first});
        }

        sort(v.begin(), v.end());
        int idx = v.size()-1;
        while(k>0) {
            ans.push_back(v[idx].second);
            k--;
            idx--;
        }
        return ans;       
    }
};
