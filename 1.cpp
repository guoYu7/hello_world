//
// Created by Zhangjun on 2020/3/15.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    map<string,vector<string>> mm;
    int N;
    string line;
    getline(cin,line);
    stringstream ss(line);
    ss>>N;
    for(int i=0;i<N;i++){
        getline(cin,line);
        stringstream ss1(line);
        string user,model;
        ss1>>user>>model;
        mm[model].push_back(user);

    }

    for(map<string,vector<string>>::iterator it = mm.begin();it!=mm.end();it++){
        cout<<it->first<<" ";
        sort(it->second.begin(),it->second.end());
        for(int i=0;i<it->second.size();i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }



    return 0;
}
