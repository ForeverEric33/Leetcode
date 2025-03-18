#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // key:s[i],value:s[i]出现的次数0，1
        unordered_set<char> sets;
        int i = 0;
        int res = 0;
        for (int j = 0; j < s.size(); j++)
        {
            // 当有窗口大小，并且每次判定一下s[j]中的k出现过
            while (i < j && sets.count(s[j]) != 0)
            {
                sets.erase(s[i]);
                i++;
            }
            sets.insert(s[j]);
            res = max(res, j - i + 1);
        }
        return res;
    }
};

int main(){
    Solution solution;
    string s = "abcdefgacdf";
    cout<< solution.lengthOfLongestSubstring(s)<<endl;
    return 0;
}