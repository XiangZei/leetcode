#include <bits/stdc++.h>
using namespace std;
int K, N, step, cal, re, back;
int main()
{
    cin >> K >> N;
    if(K==0){
        cal = 0;
        for(int i = 0; i <N;i++){
            cin>>step;
            if(step>cal){
                back++;
                cal = step - cal;
            } else {
                cal = cal - step;
            }
            if(step==cal){
                cout << "paradox" << endl;
                return 0;
            }
        }
        cout<<cal<<" "<<back<<endl;
        return 0;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> step;
        cal = cal + step;
        if (cal > K)
        {
            re = cal%K;
            back++;
            cal = K-re;
        }
        if(cal==K){
            cout<<"paradox"<<endl;
            return 0;
        }
    }
    cout<<K-cal<<" "<<back<<endl;
    return 0;
}