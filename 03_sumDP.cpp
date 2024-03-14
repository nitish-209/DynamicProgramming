#include<iostream>
using namespace std;
/*
Problem :
    Find the sum of first n numbers.

Objective function :
    F(i) is the sum of first i elements.

Recurrance relation:
    F(n) = F(n-1) + n

Recurrance relation fails at n = 0 because we cannot access f(-1) hence we must start fron n=1
hence we need to calculate f(0) manually.

*/

int nSum(int n){
    int* dp = new int[n+1];
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1] + i;
    }
    return dp[n];
}

int main(){

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << "For n = " << n << " Sum = " << nSum(n) << endl;
    }
}