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
    vector<string> vec(6);
    vec[0] = "RGB";
    vec[1] = "RBG";
    vec[2] = "GBR";
    vec[3] = "GRB";
    vec[4] = "BRG";
    vec[5] = "BGR";
    int mini = INT_MAX;
    int ans = 0;
    for(int i=0;i<6;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(vec[i][j%3]!=s[j]) cnt++;
        }
        if(cnt<mini){
            mini = cnt;
            ans = i;
        }
    }
    cout<<mini<<endl;
    for(int i=0;i<n;i++){
        cout<<vec[ans][i%3];
    }
    cout<<endl;
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
