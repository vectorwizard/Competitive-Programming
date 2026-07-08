#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    double n,k;
    cin>>n>>k;
    vector<double> a(n);
    for(double i=0;i<n;i++) cin>>a[i];
    double ans = 0;
    double final =0;
    for(double i=0;i<k;i++){
        ans+=a[i];
    }
    final = ans;
    double l = 0;
    for(double r=k;r<n;r++){
        ans+=a[r];
        ans-=a[l];
        final+=ans;
        l++;
    }
    cout<<fixed<<setprecision(10)<<(final/(n-k+1))<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
