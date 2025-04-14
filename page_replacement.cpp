#include <bits/stdc++.h>
using namespace std;
#define int long long
void FIFO(vector<int>processes,int cap){
    queue<int>q;
    map<int,bool>inqueue;
    for(int i=0;i<processes.size();i++){
        if(inqueue[processes[i]]){
            cout<<"for "<<processes[i]<<" is a cache hit :"<<endl;
        }
        else{
            if(q.size()==cap){
                cout<<"for "<<processes[i]<<" replacement is :"<<q.front()<<endl;
                inqueue[q.front()]=false;
                q.pop();
                q.push(processes[i]);
                inqueue[processes[i]]=true;
            }else{
                cout<<"for "<<processes[i]<<" cache miss witthout replacement  :"<<endl;
                q.push(processes[i]);
                inqueue[processes[i]]=true;
            }
        }
    }
}
void LRU(vector<int>&pages,int cap){
    set<pair<int,int>>lru_set;
    map<int,int>lru_indices;
    int n = pages.size();
    for(int i=0;i<n;i++){
        if(lru_indices.find(pages[i])==lru_indices.end()){
            lru_indices[pages[i]] = i;
            if(lru_set.size()==cap){
                cout<<"for page "<<pages[i]<<"replaced with "<<lru_set.begin()->second<<endl;
                lru_set.erase(lru_set.begin());
                lru_set.insert({i,pages[i]});
            }else{
                cout<<"cache miss for (without replacement)"<<pages[i]<<endl;
                lru_set.insert({i,pages[i]});
            }
        }else{
            int current_index = lru_indices[pages[i]];
            lru_indices[pages[i]] = i;
            if(lru_set.find({current_index,pages[i]})==lru_set.end()){
                if(lru_set.size()==cap){
                cout<<"cache miss for page "<<pages[i]<<" replaced with "<<lru_set.begin()->second<<endl;
                lru_set.erase(lru_set.begin());
                lru_set.insert({i,pages[i]});
                }
                else{
                    cout<<"cache miss for (without replacement)"<<pages[i]<<endl;
                    lru_set.insert({i,pages[i]});
                }
            }else{
                cout<<"chache hit for page "<<pages[i]<<endl;
                lru_set.erase({current_index,pages[i]});
                lru_set.insert({i,pages[i]});
            }
        }
       
    }
}
int find_next(vector<int>&pages,int idx,int target){
    for(int i=idx;i<pages.size();i++){
        if(pages[i]==target)return i;
    }
    return -1;
}
void optimal(vector<int>&pages,int cap){
    set<int>a;
    unordered_map<int,bool>pr;
    int n = pages.size();
    for(int i =0;i<n;i++){
        if(pr[pages[i]]){
            cout<<"cache hit for page no : "<<pages[i]<<endl;
        }else{
            if(a.size()==cap){
                int next_idx = -1;
                int removal_el = -1;

                for(auto el : a){
                    int local_next =find_next(pages,i+1,el);
                    if(local_next==-1){
                        removal_el = el;
                        break;
                    }
                    else if(local_next>next_idx){
                        next_idx = local_next;
                        removal_el = el;
                    }
                }

                cout<<"cache miss with replacement for page : "<<pages[i]<< " with "<<removal_el<<endl;
                a.erase(removal_el);
                a.insert(pages[i]);
                pr[pages[i]]=true;

            }else{
                cout<<"cache miss without replacement for page : "<<pages[i]<<endl;
                a.insert(pages[i]);
                pr[pages[i]] = true;
            }
        }
    }
}
int32_t main() {
    vector<int>pages = {1,2,2,3,4,5,4,2,1,6,7,8,9};
    int cap = 4;
    optimal(pages,cap);
    return 0;
}