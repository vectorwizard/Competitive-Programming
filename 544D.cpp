#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    map<pair<int,pair<int,int>>,int> mpp;
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            int x,y,z;
            if(b[i]<0 && a[i]<0) x= 0;
            else if(b[i]>0 && a[i]>0) x = 0;
            else x = 1;
            int gcdd = __gcd(abs(b[i]),abs(a[i]));
            y = abs(b[i])/gcdd;
            z = abs(a[i])/gcdd;
            mpp[{x,{y,z}}]++;
        }
        else if(b[i]==0) cnt++;
    }
    int maxi = 0;
    for(auto it:mpp){
        maxi = max(maxi,it.second);
    }
    cout<<maxi+cnt<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
