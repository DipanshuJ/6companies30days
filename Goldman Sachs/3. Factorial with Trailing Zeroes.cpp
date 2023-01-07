class Solution {
public:
    int trailingZeroes(int n) {
        int res=0;
        int multiple=5;
        while(multiple<=n){
            res+=n/multiple;
            multiple*=5;
        }
        return res;
    }
};