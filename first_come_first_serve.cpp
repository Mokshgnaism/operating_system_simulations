#include <bits/stdc++.h>
using namespace std;
#define int long long
struct process{
    int id;
    int arrival;
    int burst;
    int completion = 0;
    int wait = 0;
    int turnaroud = 0;
};
bool cmp(process &p1,process &p2){
    if(p1.arrival!=p2.arrival){
        return p1.arrival<p2.arrival;
    }
    if(p1.burst!=p2.burst){
        return p1.burst<p2.burst;
    } 
    return p1.id < p2.id;
}
void fcfs(vector<process>&p){
    sort(p.begin(),p.end(),cmp);
    int curr =0;
    for(int i=0;i<p.size();i++){
        if(curr<p[i].arrival){
            curr = p[i].arrival;
        }
        int t = p[i].burst;
        p[i].wait = curr - p[i].arrival;
        curr += t;
        p[i].completion = curr;
        p[i].turnaroud = curr - p[i].arrival;
    }
    sort(p.begin(),p.end(),[](process &p1,process &p2){
        return p1.id < p2.id;
    });
    cout<<"process id"<<"\t"<<"arrival"<<"\t"<<"burst"<<"\t"<<"completion"<<"\t"<<"wait"<<"\t"<<"turnaround"<<endl;
    for(int i=0;i<p.size();i++){
        cout<<p[i].id<<"\t"<<p[i].arrival<<"\t"<<p[i].burst<<"\t"<<p[i].completion<<"\t"<<p[i].wait<<"\t"<<p[i].turnaroud<<endl;
    }
}

int32_t main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<process> p(n);
    cout << "Enter arrival time and burst time for each process:\n";

    for (int i = 0; i < n; ++i) {
        p[i].id = i + 1;  // Assign process ID as 1-based
        cout << "P" << p[i].id << " -> Arrival and Burst: ";
        cin >> p[i].arrival >> p[i].burst;
    }

    fcfs(p);  // Call the scheduling function

    return 0;
}
