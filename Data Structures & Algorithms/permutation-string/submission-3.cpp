class Solution {
public:
    bool compareArr(int (&arr1)[26], int (&arr2)[26]) {
        for(int i=0; i<26; i++) {
            if(arr1[i] != arr2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        int k = l1;
        if(l1 > l2) return false;

        int arr1[26] = {0};
        int arr2[26] = {0};

        int as1 =0, as2 = 0;

        for(int i=0; i<k; i++) {as1 += s1[i] - 'a';   arr1[s1[i]-'a']++;}
        for(int i=0; i<k; i++) {as2 += s2[i] - 'a';   arr2[s2[i]-'a']++;}

        if(as1 == as2) {
            bool res = compareArr(arr1, arr2);
            if (res) return true;
        }

        for(int i=k; i<l2; i++) {
            as2 += s2[i] - 'a';
            as2 -= s2[i-k] - 'a';

            arr2[s2[i] - 'a']++;
            arr2[s2[i-k] - 'a']--;

            bool res = compareArr(arr1, arr2);
            if(res) return true;
        }
        return false;       
    }
};
