class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int l=0, r=0;
        int maxi = 0;
        int arr[26]= {0};

        for(r=0; r<s.size(); r++) {
            arr[s[r]-'A']++;
            maxi = max(maxi, arr[s[r]-'A']);
            while((r-l+1) - maxi > k) {
                arr[s[l] - 'A']--;
                l++;
            }

            
            res = max(res, r-l+1);
            
        }

        return res;       
    }
};
