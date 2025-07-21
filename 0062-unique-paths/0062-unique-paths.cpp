class Solution {
public:
    int countPath(int m, int n){
        int N = (m + n - 2);   
        int R = min(m - 1, n - 1); 

        long double result = 1.0;
        for (int i = 1; i <= R; i++) {
            result *= static_cast<long double>(N - R + i) / i;
        }

        return static_cast<int>(round(result));
    }

    int uniquePaths(int m, int n) {
        return countPath(m, n);
    }
};
