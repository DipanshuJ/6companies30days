#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long distance(vector<int> &p1, vector<int> &p2){
        return (p2[1]-p1[1])*(p2[1]-p1[1]) + (p2[0]-p1[0])*(p2[0]-p1[0]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<long long> res{ distance(p1,p2), distance(p1,p3), distance(p1,p4), distance(p2,p3), distance(p2,p4), distance(p3,p4)};
        return res.size()==2 && res.count(0)==0;
        
    }
};