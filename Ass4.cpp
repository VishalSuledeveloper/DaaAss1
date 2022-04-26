//Suppose we have a set of coins of denominations Cn-1, Cn-2,......C0 for some C>1. 
//Coins of each denominations are available unlimited quantity. 
//The problem is to make up an exact amount A using a minimum total number of coins. 
//Device a solution for this problem and analyze the time complexity of the algorithm.
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int dp[1000] = {0};
int findminCoins(int coins[], int N, int M)
{
    for (int i = 0; i <= N; i++)
        dp[i] = INT_MAX;

    dp[0] = 0;

    for (int i = 1; i <= N; i++)
    {

        for (int j = 0; j < M; j++)
        {

            if (coins[j] <= i)
            {

                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
           
        }

    }
    
    return dp[N];
}


int main()
{

    int demn, coins[100], n;
    cout << "Enter the number of denomination you have:";
    cin >> demn;
    cout << "\nEnter the coin denominations: ";
    for (int i = 0; i < demn; i++)
    {
        cin >> coins[i];
    }

    cout << "\nThe amount for which you need to find minimum no of coins:";
    cin >> n;

    steady_clock::time_point c1 = steady_clock::now();
    cout << "\nMinimum no of coins we need: " << findminCoins(coins, n, demn);
    steady_clock::time_point c2 = steady_clock::now();
    duration<double> ctimespan = duration_cast<duration<double>>(c2 - c1);
    cout<<"\n\nTime Taken to find the min of coins through DP : "<<ctimespan.count() << "seconds";

    return 0;
}