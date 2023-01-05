#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string getHint(string secret, string guess) {
        int first[10]={0}, second[10]={0};
        int matched=0;
        for(int i=0; i<secret.length(); i++){
            if(secret[i]==guess[i]) matched++;
            else{
                first[secret[i]-'0']++; second[guess[i]-'0']++;
            }
        }
        int unordered=0;
        for(int i=0; i<10; i++){
            unordered += min(first[i],second[i]);
        }
        string res ;
        res.append(to_string(matched));
        res.push_back('A');
        res.append(to_string(unordered));
        res.push_back('B');
        return  res;
    }
};