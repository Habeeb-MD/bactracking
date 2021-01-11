#define pb push_back
#define	all(v)			    v.begin(),v.end()

class Solution {
public:
    vector<vector<int>>s;
    vector<int>v;

    void solve(vector<int>& candidates, int target,int sum,int i){
        if(sum>target) return;
        int n=candidates.size();
        if(i>=n){
            if(sum==target)
                s.pb(v);
            return;
        }
        v.pb(candidates[i]);
        solve(candidates,target,sum+candidates[i],i+1);
        v.pop_back();
        int j=i+1;
        while(j<n and candidates[i]==candidates[j])j++;
        solve(candidates,target,sum,j);                          
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        s.clear();
        sort(all(candidates));
        solve(candidates,target,0,0);                          
        return s;
    }
};
