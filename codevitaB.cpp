#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll m,n;
    cin>>m>>n;
    vector<vector<char>> a(m,vector<char>(n));
    ll r=-1;
    ll c=-1;
    ll o = 0;
    ll len = 0;
    for(ll i=0;i<m;i++){
        for(ll j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j]=='l' && r==-1){
                r=i;
                c=j;
            }
            if(a[i][j]=='l') len++;
        }
    }
    for(ll i=0;i<m;i++){
        for(ll j=0;j<n;j++){
            if(a[i][j]=='l' && r!=i) o = 1;  
        }
    }
    ll dist[16][16][2];
    memset(dist,0x3f,sizeof(dist));
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
    pq.push({0,r,c,o});
    dist[r][c][o] = 0;
    vector<ll> dr = {-1,0,1,0};
    vector<ll> dc = {0,1,0,-1};
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        ll cost = it[0];
        ll row = it[1];
        ll col = it[2];
        ll ori = it[3];
        bool fl = true;
        if(ori==0){
            for(ll j=0;j<len;j++){
                if(col+j>=n || a[row][col+j]!='L'){
                    fl = false;
                    break;
                }
            }
        }
        else{
            for(ll i=0;i<len;i++){
                if(row+i>=m || a[row+i][col]!='L'){
                    fl = false;
                    break;
                }
            }
        }
        if(fl){
            cout<<cost<<endl;
            return;
        }
        for(ll k=0;k<4;k++){
            bool fl = true;
            if(ori==0){
                for(ll i=0;i<len;i++){
                    ll nrow = row+dr[k];
                    ll ncol = col + i + dc[k];
                    if(nrow<0 || nrow>=m || ncol<0 || ncol>=n || a[nrow][ncol]=='B'){
                        fl = false;
                        break;
                    }
                }
                if(fl){
                    ll nrow = row + dr[k];
                    ll ncol = col + dc[k];
                    if(dist[nrow][ncol][ori]>cost+1){
                        dist[nrow][ncol][ori]=cost+1;
                        pq.push({cost+1,nrow,ncol,ori});
                    }
                }
            }
            else{
                for(ll j=0;j<len;j++){
                    ll nrow = row+ j +dr[k];
                    ll ncol = col + dc[k];
                    if(nrow<0 || nrow>=m || ncol<0 || ncol>=n || a[nrow][ncol]=='B'){
                        fl = false;
                        break;
                    }
                }
                if(fl){
                    ll nrow = row + dr[k];
                    ll ncol = col + dc[k];
                    if(dist[nrow][ncol][ori]>cost+1){
                        dist[nrow][ncol][ori]=cost+1;
                        pq.push({cost+1,nrow,ncol,ori});
                    }
                }
            }
        }
        if(ori==0){
            bool fl = true;
            for(ll i = 0;i<len;i++){
                for(ll j=0;j<len;j++){
                    ll nrow = row + i;
                    ll ncol = col + j;
                    if(nrow<0 || nrow>=m || ncol<0 || ncol>=n || a[nrow][ncol]=='B'){
                        fl =  false;
                        break;
                    }
                }
            }
            if(fl){
                if(dist[row][col][1] > cost + 1){
                    dist[row][col][1] = cost + 1;
                    pq.push({cost + 1, row, col, 1});
                }
                if(dist[row][col + len - 1][1] > cost + 1){
                    dist[row][col + len - 1][1] = cost + 1;
                    pq.push({cost + 1, row, col + len - 1, 1});
                }
            }
            fl = true;
            for(ll i = 0;i<len;i++){
                for(ll j=0;j<len;j++){
                    ll nrow = row - i;
                    ll ncol = col + j;
                    if(nrow<0 || nrow>=m || ncol<0 || ncol>=n || a[nrow][ncol]=='B'){
                        fl =  false;
                        break;
                    }
                }
            }
            if(fl){
                if(dist[row - len + 1][col][1] > cost + 1){
                    dist[row - len + 1][col][1] = cost + 1;
                    pq.push({cost + 1, row - len + 1, col, 1});
                }
                if(dist[row - len + 1][col + len - 1][1] > cost + 1){
                    dist[row - len + 1][col + len - 1][1] = cost + 1;
                    pq.push({cost + 1, row - len + 1, col + len - 1, 1});
                }
            }
        }
        else{
            bool fl = true;
            for(ll i = 0;i<len;i++){
                for(ll j=0;j<len;j++){
                    ll nrow = row + i;
                    ll ncol = col + j;
                    if(nrow<0 || nrow>=m || ncol<0 || ncol>=n || a[nrow][ncol]=='B'){
                        fl =  false;
                        break;
                    }
                }
            }
            if(fl){
                if(dist[row][col][0] > cost + 1){
                    dist[row][col][0] = cost + 1;
                    pq.push({cost + 1, row, col, 0});
                }
                if(dist[row + len - 1][col][0] > cost + 1){
                    dist[row + len - 1][col][0] = cost + 1;
                    pq.push({cost + 1, row + len - 1, col, 0});
                }
            }
            fl = true;
            for(ll i = 0;i<len;i++){
                for(ll j=0;j<len;j++){
                    ll nrow = row + i;
                    ll ncol = col - j;
                    if(nrow<0 || nrow>=m || ncol<0 || ncol>=n || a[nrow][ncol]=='B'){
                        fl =  false;
                        break;
                    }
                }
            }
            if(fl){
                if(dist[row][col - len + 1][0] > cost + 1){
                    dist[row][col - len + 1][0] = cost + 1;
                    pq.push({cost + 1, row, col - len + 1, 0});
                }
                if(dist[row + len - 1][col - len + 1][0] > cost + 1){
                    dist[row + len - 1][col - len + 1][0] = cost + 1;
                    pq.push({cost + 1, row + len - 1, col - len + 1, 0});
                }
            }
        }
    }
    cout<<"Impossible"<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}