//
// Created by Zhangjun on 2020/2/21.
//

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <time.h>

using namespace std;
template <typename T>
void file_read(string input_file_name,vector<vector<T> >& v) {
    ifstream input_file(input_file_name.c_str(), ifstream::in);
    if (!input_file.is_open()) {
        cout << "Failed to open file named : " << input_file_name << endl;
        return;
    }
    string line;
    while (getline(input_file, line)) {
        istringstream iss(line);
        T temp;
        vector<T> v_temp;
        while(iss>>temp){
            v_temp.push_back(temp);
        }
        v.push_back(v_temp);
    }
    cout << "success to open file named : " << input_file_name << endl;
}

template <typename T>
void file_write(string output_file_name,vector<vector<T> >& v){
    ofstream output_file(output_file_name.c_str());
    for(int i=0;i<v.size();i++)
    {
        copy(v[i].begin(),v[i].end(),ostream_iterator<T>(output_file, "\t"));//"\t"
        output_file<<"\n";
    }
    cout << "success to write file named : " << output_file_name << endl;
}

int main(){
    string outname = "../out.txt";
    // 随机向量的生成
    int col,row = 100;
    vector<vector<int> > v;
    srand((unsigned)time(NULL));
    while(row--){
        vector<int> v_temp;
        col = 10;
        while(col--){
            v_temp.push_back(rand()%100);
        }
        v.push_back(v_temp);
    }
    //vector<vector<int> > v{{1,2,3},{1,2,30},{3,4,5}};
    file_write(outname,v);

    vector<vector<int> > v0;
    file_read("../out0.txt",v0);

    for(int i=0;i<v0.size();i++){
        copy(v0[i].begin(),v0[i].end(),ostream_iterator<int>(cout,"\t"));
        cout<<endl;
    }
    return 0;
}


