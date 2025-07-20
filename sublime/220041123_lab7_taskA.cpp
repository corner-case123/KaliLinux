class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1e8) ; 
        dp[0] = 0 ; 
        for(auto coin:coins){
            for(int i=coin;i<=amount;i++){
                if (dp[i-coin]!=1e8){
                    dp[i]= min(dp[i-coin]+1,dp[i]) ;
                }
            }
        }
        return (dp[amount]==1e8?-1:dp[amount]) ;
    }
};