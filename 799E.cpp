#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,s;
    cin>>n>>s;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int l = 0;
    int sum = 0;
    int maxi =0;
    for(int r=0;r<n;r++){
        sum+=a[r];
        if(sum>s){
            sum-=a[l];
            l++;
        }
        if(sum==s){
            maxi=max(maxi,r-l+1);
        }
    }
    if(maxi==0) cout<<-1<<endl;
    else cout<<n-maxi<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
