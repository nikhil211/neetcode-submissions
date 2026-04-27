class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int l = 0;
        int r = height.size()-1;

        while(l < r) {
            int area = 0;
            if (height[l] < height[r]) {
                area = (r-l) * height[l];
                l++;
            }
            else {
                area = (r-l) * height[r];
                r--;
            }
            maxWater = max (maxWater, area);
        }
        return maxWater;        
    }
};
