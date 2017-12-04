#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k;
    cin >> n >> k;
    
    long long int a[100005];
    int b[105] = {0};
    
    for(int i=0; i<n; i++){
        cin >> a[i];
        b[a[i]%k] += 1;
    }
    
    int ans=0;
    
    for(int i=1; i<k/2; i++){
        ans+= max(b[i],b[k-i]); 
    }
    
    if(k%2==1 && k!=1){
        ans+= max(b[k/2], b[(k/2)+1]);
    }
    if(k==1){
        ans=1;
    }
    
    cout << ans <<endl;
    return 0;
}
