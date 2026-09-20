#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

double func(double mid,vector<int> &a,vector<int> &t){
    int n = a.size();
    double r = 1e9;
    double l = -1e9;
    for(int i=0;i<n;i++){
        double rem = mid - t[i];
        l = max(l,a[i]-rem);
        r = min(r,a[i]+rem);
    }
    if(l>r) return -1;
    return (l+r)/2;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> t(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>t[i];
    double low = 0;
    double high = 1e9;
    double timeans = 1e9;
    double pointans = 0;
    int cnt= 100;
    while(cnt--){
        double mid = low+(high-low)/2.0;
        double x = func(mid,a,t);
        if(x!=-1){
            timeans = mid;
            high = mid;
            pointans = x;
        }
        else{
            low = mid;
        }
    }
    cout<<fixed<<setprecision(6)<<pointans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}