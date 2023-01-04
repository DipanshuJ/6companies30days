#include<bits/stdc++.h>
using namespace std;

//O(nlogn) time complexity
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());
        int first=0, last=nums.size()-1;
        while(first<=last){
            if(temp[first]==nums[first]) first++;
            else if(temp[last]==nums[last]) last--;
            else break;
        }
        return (first>last) ? 0 : last-first+1;
    }
};

//O(n) time complexity
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int max_=nums[0], start=-1, last=-1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>=max_){
                max_ = nums[i]; continue; 
            }
            if(start==-1){
                int t;
                for(t=0;t<=i;t++){
                    if(nums[t]>nums[i]){ start=t; last=i; break;}
                }
            }
            else{
                last=i;
                int t;
                for(t=start-1;t>=0;t--){
                    if(nums[i]>=nums[t]){ break;}
                }
                start=t+1;
            }
        }
        return (start==-1) ? 0 : last-start+1;
    }
};