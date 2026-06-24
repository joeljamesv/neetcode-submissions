class Solution {
   public:
    std::array<int, 45> stairs{0};
    int climbStairs(int n) { return fibonnocci(n); }

    int fibonnocci(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int fib1, fib2;
        if (stairs[n - 1] == 0) {
            stairs[n - 1] = fibonnocci(n - 1);
        }
        fib1 = stairs[n - 1];

        if (stairs[n - 2] == 0) {
            stairs[n - 2] = fibonnocci(n - 2);
        }
        fib2 = stairs[n - 2];
        return fib1 + fib2;
    }
};