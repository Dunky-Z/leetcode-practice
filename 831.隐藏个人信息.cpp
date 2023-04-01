/*
 * @lc app=leetcode.cn id=831 lang=cpp
 *
 * [831] 隐藏个人信息
 */

// @lc code=start
class Solution {
public:
  string maskPII(string s) {
    int at = s.find('@');
    cout << at << endl;
    // 如果有@符号表示是邮箱
    // 返回小写的第一个字符+*****+@+小写的后面的字符
    if (at != string::npos) {
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z')
          tolower(s[i]) s[i] += 32;
        // cout << s[i] << endl;
      }
      cout << s[0] << endl;
      cout << s[at - 1] << endl;
      cout << s.substr(at) << endl;
      return string(1, s[0]) + "*****" + s.substr(at - 1);
    } else {
      // 否则是电话号码
      // 返回***-***-后四位
      string res;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= '0' && s[i] <= '9')
          res += s[i];
      }
      if (res.size() == 10)
        return "***-***-" + res.substr(6);
      else {
        string tmp = res.substr(res.size() - 10);
        return "+" + string(res.size() - 10, '*') + "-***-***-" + tmp.substr(6);
      }
    }
  }
};

// 使用 C 语言的方法

char *maskPII(char *s) {

  char *at = strchr(s, '@');
  // 如果有@符号表示是邮箱
  // 返回小写的第一个字符+*****+@+小写的后面的字符
  if (at != NULL) {
    for (int i = 0; i < strlen(s); ++i) {
      if (s[i] >= 'A' && s[i] <= 'Z')
        s[i] = tolower(s[i]);
    }
    char *res = (char *)malloc(sizeof(char) * 100);
    res[0] = s[0];
    res[1] = '\0';
    strcat(res, "*****");
    strcat(res, at - 1);
    return res;
  } else {
    // 否则是电话号码
    // 返回***-***-后四位
    char *res = (char *)malloc(sizeof(char) * strlen(s));
    int j = 0;
    for (int i = 0; i < strlen(s); ++i) {
      if (s[i] >= '0' && s[i] <= '9')
        res[j++] = s[i];
    }
    res[j] = '\0';
    if (strlen(res) == 10) {
      char *tmp = (char *)malloc(sizeof(char) * 100);
      tmp[0] = '\0';
      strcat(tmp, "***-***-");
      strcat(tmp, res + 6);
      return tmp;
    } else {
      char *tmp = (char *)malloc(sizeof(char) * 100);
      tmp[0] = '\0';
      strcat(tmp, "+");
      for (int i = 0; i < strlen(res) - 10; ++i)
        strcat(tmp, "*");
      strcat(tmp, "-***-***-");
      strcat(tmp, res + strlen(res) - 4);
      return tmp;
    }
  }
}
// @lc code=end
