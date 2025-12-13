class Solution {
public:
    double myPow(double x, int n) {
        int is_neg = n < 0;
        return is_neg ? 1 / pow(x, n) : pow(x, n);
    }

    double pow(double x, int n) {
        if (n == 0) return 1.0;
        double val = pow(x, n / 2);
        if (n % 2) {
            return x * val * val;
        } else {
            return val * val;
        }
    }
};
