#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long int INF=1000000000000000000;

struct robin
{
   ll p, a, c,prio;
};
bool comp(robin x, robin y)
{
    return x.a < y.a ;
}

int main()
{
    cout << "Enter the number of process :" << endl;
    ll n,Q,g=0,ss=0;
    cin >> n;

    ll wt[n],wtt[n],tar[n],cpu[n],arival[n],priority[n];

    double awt = 0.0,atd = 0.0;

    map<ll,ll>m;
    vector<robin>v,v1;

    ll q[n],process[n];

   cout << "Arrival  Time : " << endl;
    for(int i=1;i<=n;i++)
        cin >> arival[i] ;

    cout << "CPU Time  : " << endl;
    for(int i=1;i<=n;i++){
        cin >> cpu[i] ;ss+=cpu[i];}

    cout << "Priority  : " << endl;
    for(int i=1;i<=n;i++)
        cin >> priority[i] ;

    for(int i=0;i<n;i++)
        v.push_back({i+1,arival[i+1],cpu[i+1],priority[i+1]});


    v1 = v;
    sort(v.begin(),v.end(),comp);
    q[0]=v[0].p;

    ll visited[n];

    cout << "Gantt Chart :" << endl;
     while(g<ss)
     {
         cout << g << "--P" << q[0]<< "--" ;

         ll k = q[0];
         process[k] = g;
         visited[k] = 1;
         g+=v1[k-1].c;

         ll mn = INT_MAX;
        for(int i=1;i<=n;i++)
        {
            if(visited[v[i-1].p] !=1 && v[i-1].a <= g)
            {
                mn = min(mn,v[i-1].prio);
                if(!m.count(v[i-1].prio)){
                    m[v[i-1].prio] = v[i-1].p;
                }
            }
        }
        q[0]=m[mn];
        m.clear();
     }
     cout << ss << endl;

     for(int i=1;i<=n;i++)
     {
         wtt[i] = process[i]-arival[i];
         awt+=wtt[i];
         tar[i] = wtt[i]+cpu[i];
         atd += tar[i];

         cout << "Waiting Time :" << wtt[i] << "Turnaround :" << tar[i] << endl;
     }

    cout << "Average Waiting time :" << awt/n << endl;
    cout << "Average Waiting time :" << atd/n << endl;
}

