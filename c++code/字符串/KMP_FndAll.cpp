#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * KMP 算法：查找模式串在主串中所有出现的位置
 * 返回所有起始索引的 vector
 */
vector<int> kmpSearchAll(const string& text, const string& pattern) {
    vector<int> matches;  // 存储所有匹配的起始位置
    int n = pattern.size();
    int m = text.size();

    if (n == 0) {
        // 空模式串：按惯例，每个位置都算匹配（或只返回0）
        matches.push_back(0);
        return matches;
    }
    if (m == 0 || n > m) return matches;

    // Step 1: 构建 next 数组（LPS 数组）
    vector<int> next(n, 0);
    int j = 0;
    int i = 1; //因为LPS[0]固定为0，所以下标从1开始

    while (i < n) {
        if (pattern[i] == pattern[j]) {
            j++;
            next[i] = j;
            i++;
        } else {
            if (j != 0) {
                j = next[j - 1];
            } else {
                next[i] = 0;
                i++;
            }
        }
    }

    // Step 2: 匹配过程，查找所有匹配
    int j = 0;  // 模式串指针
    i = 0;      // 主串指针

    while (i < m) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            // 完全匹配！
            if (j == n) {
                int start_index = i - j;
                matches.push_back(start_index);
                cout << "找到匹配，起始位置: " << start_index << endl;

                // 关键：重置 j，继续查找下一个匹配
                j = next[j - 1];
            }
        } else {
            if (j != 0) {
                j = next[j - 1];
            } else {
                i++;
            }
        }
    }

    return matches;
}

// 测试函数
int main() {
    string text = "ABABABABA";  // 注意：ABABA 出现多次
    string pattern = "ABABA";

    vector<int> allMatches = kmpSearchAll(text, pattern);

    if (allMatches.empty()) {
        cout << "未找到任何匹配" << endl;
    } else {
        cout << "所有匹配位置: ";
        for (int pos : allMatches) {
            cout << pos << " ";
        }
        cout << endl;
    }

    return 0;
}