class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,pair<int,int>> res;
        int min_=INT_MAX;
        for(int i=0;i<cards.size();i++){
            if(res.find(cards[i])==res.end()){
                res[cards[i]]={-1,i};
            }
            else{
                res[cards[i]]={res[cards[i]].second, i};
                min_ = min(min_, i-res[cards[i]].first+1);
            }
        }
        if(min_==INT_MAX) min_=-1;
        return min_;
    }
};