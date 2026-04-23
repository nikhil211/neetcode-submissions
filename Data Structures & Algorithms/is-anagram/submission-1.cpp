#define MAX_LEN 26
class Solution {
public:
    bool isAnagram(string s, string t) {
        int lenS = s.size();
        int lenT = t.size();
        if(lenS!=lenT) return false;

        int arr[MAX_LEN] = {0};

        for(int i=0; i<lenS; i++)
            arr[s[i] - 'a']++;

        for(int i=0; i<lenT; i++)
            arr[t[i]-'a']--;

        for(int i=0; i<MAX_LEN; i++) {
            if(arr[i] != 0) return false;
        }
        return true;       
    } 
};
