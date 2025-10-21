#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * KMP 算法：在主串 text 中查找模式串 pattern
 * 返回第一个匹配的起始位置，未找到返回 -1
 */
int kmpSearch(const string& text, const string& pattern) {
    int n = pattern.size();
    int m = text.size();

    // 如果模式串为空，认为在位置 0 匹配
    if (n == 0) return 0;
    if (m == 0) return -1;

    // Step 1: 构建 next 数组（即 LPS 数组）
    vector<int> next(n, 0);
    int len = 0;  // 当前最长公共前后缀的长度
    int i = 1;    // 从第二个字符开始构建

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            next[i] = len;
            i++;
        } else {
            if (len != 0) {
                // 回退到更短的公共前后缀位置
                len = next[len - 1];
            } else {
                next[i] = 0;
                i++;
            }
        }
    }

    // Step 2: 在 text 中搜索 pattern
    int j = 0;  // pattern 的指针
    i = 0;      // text 的指针

    while (i < m) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            // 完全匹配
            if (j == n) {
                int start_index = i - j;
                cout << "找到匹配，起始位置: " << start_index << endl;
                // 如果只想找第一个匹配，可以直接返回
                return start_index;

                // 如果想继续找下一个匹配，取消下面这行注释，并注释 return
                // j = next[j - 1];  // 重置 j 继续查找
            }
        } else {
            if (j != 0) {
                j = next[j - 1];  // 利用 next 数组跳转
            } else {
                i++;  // j 已经是 0，只能移动主串
            }
        }
    }

    cout << "未找到匹配" << endl;
    return -1;
}

// 测试函数
int main() {
    string text = "ABABCABABA";
    string pattern = "ABABA";

    int pos = kmpSearch(text, pattern);
    if (pos != -1) {
        cout << "首次匹配位置: " << pos << endl;
    } else {
        cout << "未找到匹配" << endl;
    }

    return 0;
}