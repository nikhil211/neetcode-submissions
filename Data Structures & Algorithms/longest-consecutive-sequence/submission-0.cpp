class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
                set<int> s;
        int maxSeq = 0;
        for(auto x: nums)
            s.insert(x);

        for (auto x: s) {
            int tempS = 1;
            if(!s.count(x-1)) { //start of seq
                while(1) {
                    if(s.count(x+1)) {
                        tempS++;
                        x = x+1;
                    }
                    else {
                        break;
                    }
                }
                if(tempS> maxSeq)
                    maxSeq = tempS;
            }
        }
        return maxSeq;
    }
};
