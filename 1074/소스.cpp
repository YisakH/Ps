#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int cnt;
int r, c;
vector<int> v;
void div(int cnt, int x, int y) {
    if (x == r && y == c) {
        v.push_back(1);
        return;
    }

    if (x <= r && r < x + cnt / 2 && y <= c && c < y + cnt / 2) {
        v.push_back(1);
        div(cnt / 2, x, y);
    }
    else if (x <= r && r < x + cnt / 2 && y <= c + cnt / 2 && c < y + cnt) {
        v.push_back(2);
        div(cnt / 2, x, y + cnt / 2);
    }
    else if (x <= r + cnt / 2 && r < x + cnt && y <= c && c < y + cnt / 2) {
        v.push_back(3);
        div(cnt / 2, x + cnt / 2, y);
    }
    else {
        v.push_back(4);
        div(cnt / 2, x + cnt / 2, y + cnt / 2);
    }
}

int main() {

    int n;
    int sum = 0;
    cin >> n >> r >> c;
    int temp = pow(2, n);
    int q = temp;
    div(temp, 0, 0);
    for (int i = 0; i < n; i++) {
        int t = v[i];
        sum += temp * temp * (t - 1) / 4;
        temp /= 2;
    }
    cout << sum;
    return 0;
}
