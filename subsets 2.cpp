class Solution {
public:
    vector<vector<int>>ans;
    void subsets(vector<int>& nums,vector<int>& s,int i){
        if(i==nums.size()){
            ans.push_back(s);
            return;        
        }

        int j=i+1;
        while(j<nums.size() and nums[j]==nums[j-1])j++;
                
        subsets(nums,s,j);        
        for(int k=i;k<j;k++){
                s.push_back(nums[i]);
                subsets(nums,s,j);
        }
        while(j>i)
            s.pop_back(),j--;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();        
        vector<int>s;
        ans.clear();
        subsets(nums,s,0);
        return ans;
    }
};
