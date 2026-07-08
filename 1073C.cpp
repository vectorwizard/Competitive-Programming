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
    string s;
    cin>>s;
    vector<int> a(n);
    vector<int> ans;
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        a[i]=(s[i]-'0');
        mpp[a[i]]++;
    }
    vector<int> b;
    b=a;
    sort(b.begin(),b.end());
    if(b==a){
        cout<<"Bob"<<endl;
        return;
    }
    else cout<<"Alice"<<endl;
    int limit = mpp[0];
    for(int i=0;i<limit;i++){
        if(a[i]==1){
            ans.push_back(i+1);
        }
    }
    for(int i=limit;i<n;i++){
        if(a[i]==0){
            ans.push_back(i+1);
        }
    }
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}