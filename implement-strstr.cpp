class Solution {//KMP algorithm
public:
    char *strStr(char *haystack, char *needle) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(haystack == NULL || needle == NULL)
            return NULL;
        int nsz = strlen(needle);
        vector<int> next(nsz, -1);
        for(int i = 1; i < nsz; ++i) {
            int index = i - 1;
            while(index != -1 && needle[next[index]+1] != needle[i])
                index = next[index];
            next[i] = index==-1?-1:next[index] + 1;
        }
        int i = 0;
        while(*haystack && i < nsz) {
            while(i != -1 && *haystack != needle[i])
                i = i==0?-1:next[i-1]+1;
            ++haystack;
            ++i;
        }
        return i<nsz?NULL:haystack-nsz;
    }
};