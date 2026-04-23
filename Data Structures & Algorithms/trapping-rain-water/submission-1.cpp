class Solution {
public:
    int trap(vector<int>& height) {
       int total = 0;
        int leftM = 0, rightM = 0;
        int l =0;
        int r = height.size()-1;

        while(l < r) {

            if(height[l] <= height[r]) {
                if(leftM > height[l]) {
                    total += leftM - height[l];
                }
                else {
                    leftM = height[l];
                }
                l++;
            }
            else {
                if(rightM > height[r]) {
                    total += rightM-height[r];
                }
                else {
                    rightM = height[r];
                }
                r--;
            }
        }
        return total;
            
    }
};
