#include<iostream>
using namespace std;
#define ll long long int

/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1...k steps. 
In how many distinct ways can you climb to the top?

Frame Work to Solve a DP Problem
    1. Define Objective Function
        f(i) is number of ways to reach the i-th stair.
    2. Identify base Cases
        f(0) = 1, 
        f(1) = 1,
        f(2) = 2
    3. Recurrance Relation/ Transition function
        f(n) = f(n-1) + f(n-2)+ ... + f(n-k).
    4. Order of Execution?
        bottom-up
    5. Location of the answer?
        f(n)

    Time Complexity = O(nk)
    Space Complexity = O(n) or O(k)
*/

int climbStairs(int n, int k){
    ll* dp = new ll[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = i-1; j >= i-k; j--){
            if(j < 0) break;
            dp[i] += dp[j];
        }
    }
    return dp[n];
}

int main(){

    int t,n,k;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> k;
        cout << climbStairs(n, k) << " ";
    }

}