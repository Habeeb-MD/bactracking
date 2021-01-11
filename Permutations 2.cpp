class Solution {
public:
    vector<vector<int>>ans;
    void permute(vector<int>& nums,vector<int>& s,int i){
        if(i==nums.size()){
            ans.push_back(s);
            return;        
        }
        unordered_set<int>t;
        for(int j=i;j<nums.size();j++){
            if(t.find(nums[j])!=t.end())continue;
            t.insert(nums[j]);
            swap(nums[i],nums[j]);
            s.push_back(nums[i]);

            permute(nums,s,i+1);
            
            s.pop_back();            
            swap(nums[i],nums[j]);               
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {        
        ans.clear();vector<int>v;
        permute(nums,v,0);
        return ans;
    }
};
