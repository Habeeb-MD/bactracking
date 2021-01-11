class Solution {
public:
    vector<vector<string>>ans;
    vector<vector<bool>> dp;
    vector<string>t;
    void partition(string &s,int i,int j) {
        if(i>j){
            ans.push_back(t);
            return;            
        }
        for(int k=i;k<=j;k++){
            if(dp[i][k]){
                t.push_back(s.substr(i,k-i+1));
                partition(s,k+1,j);
                t.pop_back();
            }
        }            
    }    
    vector<vector<string>> partition(string s) {
        ans.clear();
        dp.resize(s.size(),vector<bool>(s.size(),true));   
		for(int len=1;len<s.size();len++){
            for(int i=0;i+len<s.size();i++)
                if(s[i]!=s[i+len] or !dp[i+1][i+len-1])  
                    dp[i][i+len]=false;           
        }
        partition(s,0,s.size()-1);
        return ans;           
    }
};
