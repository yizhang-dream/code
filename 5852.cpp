#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<string, char> mp;
    string s;
    char g;

    // 读已知等级
    for (int i = 0; i < N; i++) {
        cin >> s >> g;
        mp[s] = g;
    }

    // 处理查询
    while (M--) {
        cin >> s;

        // 1. 已知直接输出
        if (mp.count(s)) {
            cout << mp[s] << "\n";
            continue;
        }

        // 2. 尝试拆分
        string ans;
        for (int i = 1; i < (int)s.size(); i++) {
            string a = s.substr(0, i);
            string b = s.substr(i);
            if (mp.count(a) && mp.count(b)) {
                ans.push_back(mp[a]);
                ans.push_back(mp[b]);
                break;  // 找到一种拆法就可以停
            }
            
        }

        // 3. 输出
        if (ans.size() == 2)
            cout << ans << "\n";
        else
            cout << 'D' << "\n";
    }

    return 0;
}