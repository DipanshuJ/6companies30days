#include<bits/stdc++.h>
using namespace std;

//O(n^3) solution
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int max_ = 2;
        if(points.size()==1 || points.size()==2) return points.size();
        for(int i=0;i<points.size()-2;i++){
            for(int j=i+1;j<points.size();j++){
                int temp=2;
                int slope_upper=points[j][1]-points[i][1], slope_lower=points[j][0]-points[i][0];
                bool sign=true;
                if(slope_lower<0 && slope_upper<0);
                else if(slope_lower<0 || slope_upper<0){sign=false;}
                slope_upper = abs(slope_upper); slope_lower=abs(slope_lower);
                if(slope_lower!=0 && slope_upper!=0){
                    int gcd = __gcd(slope_lower,slope_upper);
                    slope_lower/=gcd; slope_upper/=gcd;
                }
                
                for(int k=j+1;k<points.size();k++){
                    int temp_slope_upper=points[k][1]-points[i][1], temp_slope_lower=points[k][0]-points[i][0];
                    bool temp_sign=true;
                    if(temp_slope_lower<0 && temp_slope_upper<0);
                    else if(temp_slope_lower<0 || temp_slope_upper<0){temp_sign=false;}
                    temp_slope_upper = abs(temp_slope_upper); temp_slope_lower=abs(temp_slope_lower);
                    if((slope_upper==0 && temp_slope_upper==0) || (slope_lower==0 && temp_slope_lower==0)){
                        temp++; continue;
                    }
                    int gcd = __gcd(temp_slope_lower,temp_slope_upper);
                    temp_slope_lower/=gcd; temp_slope_upper/=gcd;
                    if(temp_sign==sign && slope_lower==temp_slope_lower && slope_upper==temp_slope_upper){
                        
                        temp++;
                    }
                }
                max_ = max(max_,temp);
            }
        }
        return max_;
    }
};