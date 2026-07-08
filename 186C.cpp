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
    vector<int> a(n),b(n),c(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    ll ans1=0,ans2=0;
    for(int s=0;s<n;s++){
        bool fl = true;
        for(int i=0;i<n;i++){
            if(c[i]<=b[(i+s)%n]){
                fl=false;
                break;
            }
        }
        if(fl==true) ans1++;
    }
    for(int s=0;s<n;s++){
        bool fl = true;
        for(int i=0;i<n;i++){
            if(b[i]<=a[(i+s)%n]){
                fl=false;
                break;
            }
        }
        if(fl==true) ans2++;
    }
    ll ans = n*ans1*ans2;
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
