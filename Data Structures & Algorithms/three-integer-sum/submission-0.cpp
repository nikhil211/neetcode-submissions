class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<len; i++) {
            if(i>0 && nums[i] == nums[i-1])
                continue;

            int j= i+1;
            int k = len-1;

            while(j<k) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(j< k && nums[j] == nums[j-1])
                        j++;
                    
                }
                else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                }
                else {
                    j++;
                }
            }
        }
        return result;        
    }
};
