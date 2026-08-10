class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int num : nums){
            freq[num]++;
        }
        priority_queue<pair<int,int>>pqu;
        for(auto &it : freq){
            pqu.push({it.second,it.first});
        }
        vector<int> result;
        while(k--){
           result.push_back(pqu.top().second);
           pqu.pop();
        }
        return result;
    }
};