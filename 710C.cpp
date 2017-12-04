#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j){
            cout << n*((i + j - 1 + (n/2))%n) + ((i + 2*j - 2) % n) + 1 << " ";
        }
        cout << endl;
    }
}