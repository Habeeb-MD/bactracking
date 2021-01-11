class Solution {
public:
    vector<vector<int>>ans;
    void permute(vector<int>& nums,vector<int>& s,int i) {
        int n=nums.size();
        if(i==n)ans.push_back(s);                
        for(int j=i;j<n;j++){
            swap(nums[i],nums[j]);
            s.push_back(nums[i]);
            permute(nums,s,i+1);
            s.pop_back();
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>s;
        ans.clear();
        permute(nums,s,0);
        return ans;
    }
};
