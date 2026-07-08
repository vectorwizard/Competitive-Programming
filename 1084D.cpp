#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> a;
    vector<int> b;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(i<x || i>=y) a.push_back(val);
        else b.push_back(val);
    }
    if(!b.empty()){
        auto min_pos = min_element(b.begin(),b.end());
        rotate(b.begin(),min_pos,b.end());
    }
    auto it = a.begin();
    if(!b.empty()){
        int min_ele = b[0];
        while(it!=a.end() && min_ele>*it) it++;
    }
    a.insert(it,b.begin(),b.end());
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int main() {
    fastio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}
