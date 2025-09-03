class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int lastsum = 0;
        int prevsum = 1;
        for (int i = 2; i <= n; ++i) {
            int currsum = prevsum + lastsum;
            lastsum = prevsum;
            prevsum = currsum;
        }
        return prevsum;
    }
};
