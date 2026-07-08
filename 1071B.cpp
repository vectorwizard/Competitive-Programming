#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxi  = 0;
    for(int i=1;i<n-1;i++){
        int curr = abs(a[i]-a[i-1]) + abs(a[i]-a[i+1]);
        int fut = abs(a[i+1]-a[i-1]);
        int profit = curr-fut;
        maxi = max(maxi,profit);
    }
    maxi = max(maxi,abs(a[1]-a[0]));
    maxi = max(maxi,abs(a[n-1]-a[n-2]));
    long long total = 0;
    for(int i=1;i<n;i++){
        total+=abs(a[i]-a[i-1]);
    }
    cout<< total-maxi<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
