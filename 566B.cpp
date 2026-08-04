#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int up(int i,int j,vector<vector<int>> &a){
    int cnt = 0;
    for(int k = i;k>=0;k--){
        if(a[k][j]==1) cnt++;
        else break;
    }
    return cnt;
}

int down(int i,int j,vector<vector<int>> &a){
    int h = a.size();
    int w = a[0].size();
    int cnt = 0;
    for(int k = i;k<h;k++){
        if(a[k][j]==1) cnt++;
        else break;
    }
    return cnt;
}

int left(int i,int j,vector<vector<int>> &a){
    int h = a.size();
    int w = a[0].size();
    int cnt = 0;
    for(int k = j;k>=0;k--){
        if(a[i][k]==1) cnt++;
        else break;
    }
    return cnt;
}

int right(int i,int j,vector<vector<int>> &a){
    int h = a.size();
    int w = a[0].size();
    int cnt = 0;
    for(int k = j;k<w;k++){
        if(a[i][k]==1) cnt++;
        else break;
    }
    return cnt;
}


void solve() {
    int h,w;
    cin>>h>>w;
    vector<vector<int>> a(h,vector<int>(w,0));
    int good = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char ch;
            cin>>ch;
            if(ch=='*') {
                a[i][j] = 1;
                good++;
            }
        }
    }
    int cnt = 0;
    for(int i=1;i<h-1;i++){
        for(int j=1;j<w-1;j++){
            if(a[i][j]==0) continue;
            else if(a[i+1][j]==0 || a[i-1][j]==0 || a[i][j+1]==0 || a[i][j-1]==0) continue;
            else if(a[i-1][j+1]==1 || a[i-1][j-1]==1) continue;
            else if(a[i+1][j+1]==1 || a[i+1][j-1]==1) continue;
            else if(a[i+1][j+1]==1 || a[i-1][j+1]==1) continue;
            else if(a[i+1][j-1]==1 || a[i-1][j-1]==1) continue;
            int sum = 0;
            sum+=up(i-1,j,a);
            sum+=down(i+1,j,a);
            sum+=left(i,j-1,a);
            sum+=right(i,j+1,a);
            sum++;
            if(sum==good) cnt++;
        }
    }
    if(cnt==1){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
