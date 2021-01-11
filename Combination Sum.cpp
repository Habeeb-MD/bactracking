class Solution {
public:
    vector<vector<int>> ans;
    void solve(int target,vector<int>&v,int i,vector<int>& candidates)
    {
        if(target==0){ans.emplace_back(v);return;} 
        int n=candidates.size();
        if(target<0 or i>=n)return;

        //dont want to use it;            
        solve(target,v,i+1,candidates);            

        //use it 
        v.emplace_back(candidates[i]);
        solve(target-candidates[i],v,i,candidates);       
        v.pop_back();                    
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        vector<int>v;
        solve(target,v,0,candidates);
        return ans;
    }
};
