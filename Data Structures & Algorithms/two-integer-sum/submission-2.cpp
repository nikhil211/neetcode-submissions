class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> ans;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            int res = target - nums[i];
            if(mp.find(res) != mp.end()) {
                    ans.push_back(mp[res]);
                    ans.push_back(i);
                    break;
            }
            mp.insert({nums[i], i});
        }

        return ans;  
    }
};
