#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 哈希表的key：字符A,B,C   value：出现的次数 如{'A':1,'B':1,'C':1}
    //shortStr表示要查询找的字符串，longtStr是整个长的字符串
    unordered_map<char, int> shortStr, longtStr;
    //判断长字符串的现在窗口下的子串是否包含短字符串
    bool check()
    {
        for (auto p : shortStr)
        {
            //如果
            if (longtStr[p.first] < p.second)
            {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t)
    {
        //先把短字符串放到map里，用于后面比对
        for (auto c : t)
        {
            shortStr[c]++;
        }
        //定义双指针
        int l = 0;
        int r = -1;
        //定义记录结果的最短窗口长度和起始最短字符串位置
        int len = INT_MAX, ansL = -1;
        //不太理解为什么要int（）
        //当要对比的长字符串的子串长度不够，先把后面的数放进来一些
        while (r < int(s.size()))
        {
            r++;
            //当窗口中找到短字符串的部分，在长字符串的map中记一下
            if (shortStr.find(s[r]) != shortStr.end())
            {
                longtStr[s[r]]++;
            }
            //当窗口已经满足找到所有短字符串的内容后，开始动窗口左端
            while (check() && l <= r)
            {
                //记录下最短窗口长度和起始位置
                if (r - l + 1 < len)
                {
                    len = r - l + 1;
                    ansL = l;
                }
                //改变左端窗口边界，判断是否有短字符串中的字符，有的话要把刚刚记录的长字符串-1，说明窗口变短并且删去了一个要的字符
                if (shortStr.find(s[l]) != shortStr.end())
                {
                    longtStr[s[l]]--;
                }
                l++;
            }
        }
        if (ansL == -1)
        {
            return string();
        }
        else
        {
            return s.substr(ansL, len);
        }
    }
};
int main(){
    string s = "ABCDSEFGADANBC";
    string t = "ABS";
    Solution solu;
    string ans = solu.minWindow(s,t);
    cout<<ans<<endl;
}
