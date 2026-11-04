#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,m;
    cin>>n>>m;
    string p,q;
    cin>>p>>q;
    map<int,int> mpp1;
    map<int,int> mpp2;
    for(int i=0;i<n;i++) mpp1[p[i]]++;
    for(int i=0;i<m;i++) mpp2[q[i]]++;
    for(auto it:mpp1){
        if(mpp2.count(it.first)==0) continue;
        mpp1[it.first]-=mpp2[it.first];
        mpp2[it.first] = 0;
        mpp2.erase(it.first);
    }
    if(mpp2.size()>0){
        cout<<"NO"<<endl;
        return;
    }
    string ans = "";
    string temp = "isx";
    for(auto it:mpp1){
        if(it.second==0) continue;
        else if(it.second==1) ans+=it.first;
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    if(ans==temp){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}