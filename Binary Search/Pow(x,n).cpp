class Solution {
public:
    double myPow(double x, int n) {
        vector<double> valList;
        double res = 1.0;
        if(n == 0)
            return res;
        else if(n>0)
            res = binary(x, n);
        else{
            int absN = abs(n);
            res = binary(x, absN);
            res = 1./res;
        }
         return res;
    }
    double binary(double x, int n){
        double res = 1.0;
        if(n == 0) return res;
        double half = binary(x, n/2);
        if(n%2 == 0)
            res = half*half;
        else 
            res = half*half*x;
        return res;
    }
};