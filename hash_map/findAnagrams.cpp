#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        //利用vector进行记录，分别是s和p，同样是滑动窗口
        vector<int> s_count(26, 0), p_count(26, 0), ans;
        int left = 0, right = 0;
        //先把要找的异位词s记录下来
        for (int i = 0; i < p.size(); i++)
        {
            p_count[p[i] - 'a']++;
        }
        //开始将原字符串s与要找的字符串p比对
        for (int right = 0; right < s.size(); right++)
        {
            s_count[s[right] - 'a']++;
            //当s遍历的大小和p一样时开始比对是不是异位词
            if (right - left + 1 == p.size())
            {
                //由于是s[i]/p[i]- 'a'进行统计每个字符的数量，因此顺序是一样的，异位不异位无所谓
                if (s_count == p_count)
                //找到异位词就把第一个字符加进结果数组中
                    ans.push_back(left);
                //窗口滑动，删去第一个字符并且窗口向右移动
                s_count[s[left] - 'a']--;
                left++;
            }
        }
        return ans;
    }
};

int main(){
    string s = "abcabcabcabcddddde";
    string p = "abc";
    Solution solu;
    
    vector<int> result = solu.findAnagrams(s,p);
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    
    return 0;
}