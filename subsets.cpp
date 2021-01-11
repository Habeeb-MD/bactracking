class Solution {
public:
    vector<vector<int>>ans;
    void subsets(vector<int>& nums,vector<int>& s,int i){
        if(i==nums.size()){
            ans.push_back(s);
            return;        
        }
        subsets(nums,s,i+1);
        s.push_back(nums[i]);
        subsets(nums,s,i+1);
        s.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>s;
        ans.clear();
        subsets(nums,s,0);
        return ans;
    }
};
