#include "map_usage.h"

using namespace std;
using namespace map_usage;

int main() {
    TradeBook tb;
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string operation;
        getline(cin, operation);

        stringstream ss(operation);
        string cmd;
        ss >> cmd;

        if (cmd == "update") {
            int timestamp, price;
            ss >> timestamp >> price;
            tb.update(timestamp, price);
        } else if (cmd == "current") {
            cout << tb.current() << endl;
        } else if (cmd == "maximum") {
            cout << tb.highest() << endl;
        } else if (cmd == "minimum") {
            cout << tb.lowest() << endl;
        }
    }
    return 0;
}