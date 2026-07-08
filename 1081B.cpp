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
    int ones = 0,zeros = 0;
    vector<int> onesvec;
    vector<int> zerosvec;
    for(int i=0;i<n;i++){
        if(s[i]=='1') {
            ones++;
            onesvec.push_back(i+1);
        }
        else {
            zeros++;
            zerosvec.push_back(i+1);
        }
    }
    if(zeros==n){
        cout<<0<<endl;
        return;
    }
    if(n%2!=0 && ones%2!=0){
        cout<<-1<<endl;
        return;
    }
    if(ones%2==0){
        cout<<ones<<endl;
        for(auto it:onesvec){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    if(ones%2==1){
        cout<<zeros<<endl;
        for(auto it:zerosvec){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}