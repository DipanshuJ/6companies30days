#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegrees(numCourses,0);
        for(auto val: prerequisites){
            indegrees[val[0]]++; adj[val[1]].emplace_back(val[0]);
        }
        queue<int> q; int processed=0;
        for(int i=0;i<numCourses; i++){
            if(indegrees[i]==0) q.push(i);
        }
        while(!q.empty()){
            int curr= q.front(); q.pop(); processed++;
            for(int i=0; i<adj[curr].size(); i++){
                if( --indegrees[adj[curr][i]]==0 ) q.push(adj[curr][i]);
            }
        }
        return processed==numCourses;
    }
};