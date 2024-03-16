#include<iostream>
using namespace std;

/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1, 2 or 3 steps. 
In how many distinct ways can you climb to the top?

Frame Work to Solve a DP Problem
    1. Define Objective Function
        f(i) is number of ways to reach the i-th stair.
    2. Identify base Cases
        f(0) = 1, 
        f(1) = 1,
        f(2) = 2
    3. Recurrance Relation
        f(n) = f(n-1) + f(n-2) + f(n-3)
    4. Order of Execution?
        bottom-up
    5. Location of the answer?
        f(n)
*/

int climbStairs(int n){
    int ans_1 = 2, ans_2 = 1, ans_3 = 1, ans;
    for(int i = 3; i <= n; i++){
        ans = ans_1 + ans_2 + ans_3;
        ans_3 = ans_2;
        ans_2 = ans_1;
        ans_1 = ans;
    }
    return ans;
}

int main(){

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << climbStairs(n) << " ";
    }

}