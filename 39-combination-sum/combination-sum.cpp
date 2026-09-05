class Solution {
public:
    void solve(int id, vector<vector<int>>& res,vector<int>& dxs, vector<int>& cad, int target) {
        if (id==cad.size()) {
            if (target==0) {
                res.push_back(dxs);
            }
            return;
        }
        if (cad[id]<=target) {
            dxs.push_back(cad[id]);
            solve(id,res,dxs,cad,target-cad[id]);
            dxs.pop_back();
        }
        solve(id+1,res,dxs,cad,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> dxs;
        solve(0,res,dxs,candidates,target);
        return res;
    }
};