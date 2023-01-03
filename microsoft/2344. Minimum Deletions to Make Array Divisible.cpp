#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int req_hcf=numsDivide[0], ans=0;
        for(int i=1; i<numsDivide.size(); i++){
            int small = (req_hcf<numsDivide[i]) ? req_hcf : numsDivide[i];
            int large = (req_hcf>=numsDivide[i]) ? req_hcf : numsDivide[i];
            int rem;
            while(rem = large%small){
                large = small;
                small = rem;
            }
            req_hcf = small;
        }
        cout<<req_hcf;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size() && req_hcf%nums[i];i++) ans++;
        return (ans==nums.size()) ? -1 : ans;
    }
};