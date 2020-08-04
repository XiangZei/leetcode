#include<bits/stdc++.h>
using namespace std;
int N,A,B,C,D,E,F;
int visit[1001],dist;
vector<int> cnt;

bool equall(vector<int> t1, vector<int> t2)
{
    if (t1[0] == t2[0] && t1[1] == t2[1] && t1[2] == t2[2] && t1[3] == t2[3] && t1[4] == t2[4] && t1[5] == t2[5])
    {
        return true;
    }
    if (t1[0] == t2[0] && t1[1] == t2[1] && t1[4] == t2[2] && t1[5] == t2[3] && t1[3] == t2[4] && t1[2] == t2[5])
    {
        return true;
    }
    if (t1[0] == t2[0] && t1[1] == t2[1] && t1[5] == t2[2] && t1[4] == t2[3] && t1[2] == t2[4] && t1[3] == t2[5])
    {
        return true;
    }
    if (t1[0] == t2[0] && t1[1] == t2[1] && t1[3] == t2[2] && t1[2] == t2[3] && t1[5] == t2[4] && t1[4] == t2[5])
    {
        return true;
    }

    return false;
}

bool eee(vector<int> t1, vector<int> t2) {
    if(equall(t1,t2)){
        return true;
    }
    //左
    vector<int> tmp(6, 0);
    tmp[0] = t1[3];
    tmp[1] = t1[2];
    tmp[2] = t1[0];
    tmp[3] = t1[1];
    tmp[4] = t1[4];
    tmp[5] = t1[5];
    if(equall(tmp, t2)){
        return true;
    }
    // 右
    tmp[0] = t1[2];
    tmp[1] = t1[3];
    tmp[2] = t1[1];
    tmp[3] = t1[0];
    tmp[4] = t1[4];
    tmp[5] = t1[5];
    if (equall(tmp, t2))
    {
        return true;
    }
    // 前
    tmp[0] = t1[5];
    tmp[1] = t1[4];
    tmp[2] = t1[2];
    tmp[3] = t1[3];
    tmp[4] = t1[0];
    tmp[5] = t1[1];
    if (equall(tmp, t2))
    {
        return true;
    }
    // 后
    tmp[0] = t1[4];
    tmp[1] = t1[5];
    tmp[2] = t1[2];
    tmp[3] = t1[3];
    tmp[4] = t1[1];
    tmp[5] = t1[0];
    if (equall(tmp, t2))
    {
        return true;
    }
    // 下
    tmp[0] = t1[1];
    tmp[1] = t1[0];
    tmp[2] = t1[2];
    tmp[3] = t1[3];
    tmp[4] = t1[5];
    tmp[5] = t1[4];
    if (equall(tmp, t2))
    {
        return true;
    }
    return false;
}

bool cmp(int a,int b) {
    return a>b;
}
int main(){
    cin>>N;
    vector<vector<int>> con;
   
    for(int i = 0; i < N; i++) {
        cin>>A>>B>>C>>D>>E>>F;
        vector<int> tmp;
        tmp.push_back(A);
        tmp.push_back(B);
        tmp.push_back(C);
        tmp.push_back(D);
        tmp.push_back(E);
        tmp.push_back(F);
        con.push_back(tmp);
    }
    for(int i = 0; i < con.size(); i++) {
        if(visit[i]) continue;
        int count = 1;
        for(int j = i+1; j < con.size(); j++) {
            
            if (eee(con[i], con[j]))
            {
                visit[i] = 1;
                visit[j] = 1;
                count++;
            }
        }
        cnt.push_back(count);
        dist++;
    }
    cout<<dist<<endl;
    sort(cnt.begin(), cnt.end(), cmp);
    for(int i = 0; i < cnt.size(); i++) {
        cout<<cnt[i];
        if(i!=cnt.size()-1){
            cout<<" ";
        }
    }
    return 0;
}