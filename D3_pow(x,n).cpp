#include <bits/stdc++.h>
class Solution {
public:
    double myPow(double x,  int n) {
      double res = 1;
        if(n<0){
            x = 1/x;
        }
        long y = labs(n); // to account for negative int max range
        while(y){
            if(y&1){
                res = res * x;
            }
            x = x * x;
            y = y >> 1;
        }
        return res;
    }
};

//https://leetcode.com/problems/powx-n/submissions/