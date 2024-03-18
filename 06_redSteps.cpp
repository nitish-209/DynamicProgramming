#include<iostream>
using namespace std;
#include<algorithm>
#define ll long long int

/*
You are climbing a staircase. It takes n steps to reach the top while avoiding the RED stairs.
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

    Test case:
        input:  1
                7 3
                0 1 0 1 1 0 0 0
        output: 2
*/

// bool array element is 1 if red 0 if not.
int climbStairSkipRed(int n, int k, bool arr[]){
    int* dp = new int[k];
    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        if(arr[i] == 1) dp[i%k] = 0;
        else{
            for(int j = 1; j < k; j++){
                if(i-j < 0) break;
                dp[i%k] += dp[(i-j) % k];
            }
        }
    }
    return dp[n%k];
}

int main(){

    int t,n,k;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> k;
        bool* red = new bool[n];
        for(int i = 0 ; i <= n; i++){
            cin >> red[i];
        }
        cout << climbStairSkipRed(n, k, red) << " ";
        delete [] red;
    }

}