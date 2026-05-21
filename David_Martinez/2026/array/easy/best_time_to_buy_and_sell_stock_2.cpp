#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        info
        
            input
                - integer array prices, prices[i] is the price of a given stock on the ith day
            
            output
                - max profit
            
            constraints
                - what ranges of values can the prices[i] numbers have. between 0 and 10k, included
                - how big or small can the prices array be. between 1 and 30k
            
        example
                                j
                                i
            prices = [7,1,5,3,6,4]
            profit = 4 + 3 = 7
            
            price at j, bigger than price at i
                - sell price[j] - price[i] 
                - move i to j
                
            price at j lower than price at i
                - move i to j
                
            prices = [3,2,1]
                          i
                           j
                           
                    [1,2,3]
                         i
                         j
                         
            best conceivable runtime
            - runtime o(n), we have to traverse al lnumbers at least once
            - memory o(1)
        
        test
            - all decreasing
            - all increasing
            - mixed numbers
        
        */
            
            if(prices.size() == 1) return 0;
            
            int max_profit = 0;
            int i = 0;
        
            for(int j = 1; j < prices.size(); j++){
                if(prices[i] < prices[j]){
                    max_profit += (prices[j] - prices[i]);
                    i = j;
                }
                else if(prices[i] > prices[j]){
                    i = j;
                }
            }
            return max_profit;
    }
};
//15 min
