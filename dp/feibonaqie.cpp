#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int fib(int N)
    {
        if (N <= 1)
            return N;
        vector<int> dp(N + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= N; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[N];
    }
};
 int main()
{
    Solution solution;
    int N;
    cout << "Enter the value of N:";
    cin >> N;
    cout<<solution.fib(N)<<endl;
    return 0;
}