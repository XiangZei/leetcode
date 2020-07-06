// KMP 利用模式串内部的重复性
#include <bits/stdc++.h>
using namespace std;
namespace KMP
{
    vector<int> next;
    void build(const string &pattern)
    {
        int n = pattern.length();
        next.resize(n + 1);
        for (int i = 0, j = next[0] = -1; i < n; next[++i] = ++j)
        {
            while (j != -1 && pattern[i] != pattern[j])
                j = next[j];
        }
        cout << "next: ";
        for (int i = 0; i <= n; i++)
        {
            cout << next[i] << " ";
        }
        cout << endl;
    }
    vector<int> match(const string &pattern, const string &text)
    {
        vector<int> res;
        int n = pattern.length(), m = text.length();
        build(pattern);
        for (int i = 0, j = 0; i < m; ++i)
        {
            while (j > 0 && text[i] != pattern[j])
                j = next[j];
            if (text[i] == pattern[j])
                ++j;
            if (j == n)
                res.push_back(i - n + 1), j = next[j];
        }
        return res;
    }
} // namespace KMP

int main()
{
    string pattern = "abcabc";
    string text = "AIDCEabcabcqweqEDWabcabcqweqJIEN";
    vector<int> res = KMP::match(pattern, text);
    for(int i = 0; i < res.size(); i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}