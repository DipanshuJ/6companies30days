#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int d(vector<int> &p1, vector<int> &p2){
        return (p2[1]-p1[1])*(p2[1]-p1[1]) + (p2[0]-p1[0])*(p2[0]-p1[0]);
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res=0;
        for(int i=0;i<points.size();i++){
            unordered_map<int,int> cnt;
            for(int j=0;j<points.size();j++){
                if(i==j) continue;
                cnt[d(points[i],points[j])]++;
            }
            for(auto val:cnt){
                if(val.second>=2){
                    res+=(val.second)*(val.second-1);
                }
            }
        }
        return res;
    }
};