class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int i = 0;
        int j = 0;
        int len = nums.size();
        vector<int> ans;
        bool found = false;
        for(; i<len-1; i++) {
            int res = target - nums[i];
            for (j=i+1; j<len; j++) {
                if(nums[j] == res) {
                    ans.push_back(i);
                    ans.push_back(j);
                    found = true;
                    break;
                }

            }
            if (found) break;
        }
        return ans;        
    }
};
