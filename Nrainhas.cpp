#include <iostream>
#include <vector>
#include <set>
using namespace std;

long unsigned int N=4;
set<set<pair<int,int>>> resp;

bool valido(set<pair<int,int>> &rainhas, int i, int j){
    for (auto r : rainhas){
        if (r.first==i or r.second==j or abs(r.first-i)==abs(r.second-j))
            return false;
    }
    return true;
}

void solve(set<pair<int,int>> rainhas, long unsigned int i){
    if (rainhas.size()==N)
        resp.insert(rainhas); 

    if (i==N) return;
    for (long unsigned int j=0; j<N; j++){
        solve(rainhas, i+1);
        if (valido(rainhas, i, j)){
            set<pair<int,int>> novo = rainhas;
            novo.insert({i,j});
            solve(novo, i+1);
        }
    }
    return;
}

int main(){
    set<pair<int,int>> a;
    solve(a, 0);
    for (auto r : resp){
        for (long unsigned int i=0; i<N; i++){
            for (long unsigned int j=0; j<N; j++){
                if (r.count({i,j}))
                    cout << 'x';
                else 
                    cout << 'o';
            }
            cout << endl;
        }
    cout << endl;
    }

    return 0;
}