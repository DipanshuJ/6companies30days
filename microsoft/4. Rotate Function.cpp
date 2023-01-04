#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){ sum+=nums[i]; }
        long long prev=0;
        for(int i=1;i<nums.size();i++) prev+=i*nums[i];
        long long max_=prev;
        for(int i=1;i<nums.size();i++){
            prev += sum - nums.size()*nums[nums.size()-i];
            max_ = max(max_, prev);
        }
        return max_;
    }
};
