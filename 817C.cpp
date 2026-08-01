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
    vector<string> v1(n);
    vector<string> v2(n);
    vector<string> v3(n);
    map<string,int> mpp;
    for(int i=0;i<n;i++){
        cin>>v1[i];
        mpp[v1[i]]++;
    }
    for(int i=0;i<n;i++){
        cin>>v2[i];
        mpp[v2[i]]++;
    }
    for(int i=0;i<n;i++){
        cin>>v3[i];
        mpp[v3[i]]++;
    }
    int x=0,y=0,z=0;
    for(int i=0;i<n;i++){
        if(mpp[v1[i]]==1) x+=3;
        else if(mpp[v1[i]]==2) x++;
    }
    for(int i=0;i<n;i++){
        if(mpp[v2[i]]==1) y+=3;
        else if(mpp[v2[i]]==2) y++;
    }
    for(int i=0;i<n;i++){
        if(mpp[v3[i]]==1) z+=3;
        else if(mpp[v3[i]]==2) z++;
    }
    cout<<x<<" "<<y<<" "<<z<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
