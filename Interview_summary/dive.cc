
#include <cmath>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
string dive(int a, int b) {
    if (a == 0) {
        return "0";
    }
    string res = "";
    if ((a < 0) ^ (b < 0)) {
        res += "-";
    }
    int c = abs(a);
    int d = abs(b);
    res += to_string(c / d);
    int remain = c % d;
    if (remain == 0) {
        return res;
    }
    res += ".";
    unordered_map<int, int> mp;
    while (remain != 0) {
        if (mp.find(remain) != mp.end()) {
            int idx = mp[remain];
            res.insert(idx, "(");
            res += ")";
            break;
        }
        mp[remain] = res.size();
        remain *= 10;
        res += to_string(remain / d);
        remain %= d;
    }
    return res;
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        string ans;
        ans = dive(a, b);
        cout << ans << endl;
    }
    return 0;
}

// case: a = 1, b = 4, return "0.25"
// case: a = 1, b = 7, return "0.(142857)"
// case: a = 1, b = 6, return "0.1(6)"

// 如何让括号内的循环节更长？a,b互质，1 3571