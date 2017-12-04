#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int k2, k3, k5, k6;

	cin >> k2 >> k3 >> k5 >> k6;

	int n256 = min(k2, min(k5,k6));
	int n32 = min(k3, k2-n256);

	cout << 256*n256 + 32*n32;

	return 0;
}