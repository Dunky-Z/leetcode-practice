---
title: 剑指 Offer 58 - I. 翻转单词顺序
tags: LeetCode
notebook: a - 001 | ITabc
---

输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串`"I am a student. "`，则输出`"student. a am I"`。
示例 1：
```
输入: "the sky is blue"
输出: "blue is sky the"
```
示例 2：
```
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
```
示例 3：
```
输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
```

说明：
```
无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
```
---

Solution 1:
先反转全部， 再逐一单词反转
```cpp

class Solution {
public:
    string reverseWords(string s) 
    {
        size_t n = s.size();
        //先反转全部，再逐一单词反转
        reverse(s.begin(), s.end());
        size_t curIndex = 0;
        for(size_t i = 0; i < n; ++i)
        {
            //不是空格才开始寻找反转，结果中单词间的空格通过插入形式
            //而不是用原有的空格，可以排除多个空格的情况
            if(s[i] != ' ')
            {
                //如果当前不是第一个单词，就在前插入一个空格
                if(curIndex != 0)
                    s[curIndex++] = ' ';
                size_t j = i;
                while(j < n && s[j] != ' ')
                {
                    s[curIndex++] = s[j++];
                }
                //反转单词
                reverse(s.begin()+curIndex - (j-i), s.begin()+curIndex);
                i = j;
            }
        }
        s.resize(curIndex);
        return s;
    }
};
```


Solution 2:双指针

```cpp
class Solution {
public:
    string reverseWords(string s) 
    {
        int n = s.size();
        string res;
        if(n == 0)
            return res;
        int right = n - 1;
        while(right >= 0)
        {
            //寻找第一个单词的位置，排除末尾的空格
            while(right >= 0 && s[right] == ' ')
                right--;
            if(right < 0)
                break;
            
            //left表示单词左侧的位置
            int left = right;
            
            //寻找当前单词前的第一个空格位置
            while(left >= 0 && s[left] != ' ')
                left--;
            res += s.substr(left + 1, right - left);
            res += ' ';
            
            right = left;
        }
        if(!res.empty())
            res.pop_back();
        return res;
    }
};
```

Solution 3:

```cpp
class Solution {
public:
    string reverseWords(string s) 
    {
        string tmp;
        istringstream ins(s);
        ins >> s;
        while(ins >> tmp)
            s = tmp + ' ' + s;
        if(!s.empty() && s[0] == ' ')
            return "";
        return s;
    }
};
```