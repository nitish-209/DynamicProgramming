#include<iostream>
using namespace std;

/*
Optimisation Problem - Paid staircase
    You are climbing a paid staircas. It takes n-steps to reach to the top and you have to pay 
    p[i] to step on i-th stair. Each time you can climb 1 or 2 steps. 
    What's the amount you have to pay to get to the top of staircase??

    Test Case :
    Input : 1
            3
            0 3 2 4
*/

// Time Complexity : O(n)
// Space complexity : O(n) can be optimised to O(1).

int paidStaircase(int n, int p[]){
    int* dp = new int[n+1];
    dp[0] = 0;
    dp[1] = p[1];
    for(int i = 2; i <= n; i++){
        dp[i] = p[i] + min(dp[i-1],dp[i-2]);
    }
    return dp[n];
}

int paidStaircaseOptim(int n, int p[]){
    int a = 0;
    int b = p[1];
    int c;
    for(int i = 2; i <= n; i++){
        c = p[i] + min(a, b);
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int* p = new int[n+1];
        for(int i = 0; i <=n; i++)
            cin >> p[i];

        // cout << paidStaircase(n, p) << " ";
        cout << paidStaircaseOptim(n, p) << " ";
        delete [] p;
    }
}