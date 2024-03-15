#include<iostream>
using namespace std;

/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?

Frame Work to Solve a DP Problem
    1. Define Objective Function
        f(i) is number of ways to reach the i-th stair.
    2. Identify base Cases
        f(0) = 1, 
        f(1) = 1
    3. Recurrance Relation
        f(n) = f(n-1) + f(n+1)
    4. Order of Execution?
        bottom-up
    5. Location of the answer?
        f(n)
*/

int climbStairs(int n){
    int* dp = new int[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << climbStairs(n) << " ";
    }

}