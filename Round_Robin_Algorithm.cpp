#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long int INF=1000000000000000000;

struct robin
{
   ll p, a, c;
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

    ll mn = INT_MAX;
    ll wt[n],wtt[n],tar[n],cpu[n],arival[n];

    double awt = 0.0,atd = 0.0;

    map<ll,ll>m;

    cout << "Enter the Time Quantum :" << endl;
    cin >> Q;

    cout << "Enter the CPU Time :" << endl;

    for(int i=0;i<n;i++){
        cin >> cpu[i];ss+=cpu[i];}

    cout << "Enter the Arrival Time :" << endl;

    for(int i=0;i<n;i++)
        cin >> arival[i];

    vector<robin>v,v1;


    for(int i=0;i<n;i++)
    {
        int h = cpu[i];
        v.push_back({i,arival[i],h});
        //m[arival[i]] = i;
    }
    v1 = v;

    //ll min_index = m[0];

    sort(v.begin(),v.end(),comp);


    deque<ll>q;

    q.push_back(v[0].p);
    //q.push_back(v[min_index].p);

    ll visited[n];

    vector<ll>process,gantt;

     while(g<ss)
     {

         gantt.push_back(g);
         process.push_back(q.front());

         cout << g << "--P" << q.front()+1 << "--";

         ll k = q.front(); // kon process
         visited[k] = 1;


        if(v1[k].c>=Q)
        {
            v1[k].c-=Q;
            g+=Q;
        }
        else
        {
            g+=v1[k].c;
            v1[k].c=0;
        }

        for(int i=0;i<n;i++)
        {
            if(visited[v[i].p] !=1 && v[i].a <= g)
            {
                visited[v[i].p] = 1;
                q.push_back(v[i].p);
                //cout << "Entering into queue :" << v1[i].p << endl;
            }
        }

        q.pop_front();
        if(v1[k].c!=0)
            q.push_back(k);
     }



     cout << endl;
     for(int i=0;i<n;i++)
     {
         int sum =0,first = 0,last=0,f=0;
         for(int j=0;j<gantt.size();j++)
         {
             if(process[j]==i)
             {
                 if(f==0)
                 {
                     first = gantt[j];
                     last = gantt[j+1];
                     f = 1;
                 }
                 else
                 {
                     sum+=(gantt[j]-last);
                     last = gantt[j+1];
                 }
             }
         }
         sum+=(first-v1[i].a);
         awt+=sum;
         atd+= (sum+cpu[i]);
         cout << "Process "  << i+1 << ": " << "Waiting Time :" << sum << " Turnaround Time :" << sum+cpu[i]<< endl;
     }



    cout << "Average Waiting time :" << awt/n << endl;
    cout << "Average Waiting time :" << atd/n << endl;
}
