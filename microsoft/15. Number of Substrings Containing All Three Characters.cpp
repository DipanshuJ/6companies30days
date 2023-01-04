class Solution {
public:
    int numberOfSubstrings(string s) {
        int lower=0,cnt[3]={0},res=0;
        for(int i=0;i<s.length();i++){
            cnt[s[i]-'a']++;
            while(cnt[s[lower]-'a']>1){ cnt[s[lower]-'a']--; lower++; }
            if(cnt[0]>0 && cnt[1]>0 && cnt[2]>0) res += lower+1;
        }
        return res;
    }
};