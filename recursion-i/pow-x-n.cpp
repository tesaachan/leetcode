class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1)
            return 1;
        if (n == 1)
            return x;
        if (n == -1)
            return 1 / x;

        if (n % 2)
            return x * myPow(x, n - 1);
        double k = myPow(x, n / 2);
        return k * k;
    }
};