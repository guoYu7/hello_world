//
// Created by Zhangjun on 2020/3/17.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class priority_queue
{
private:
    vector<int> data;
public:
    void push( int t ){
        data.push_back(t);
        push_heap( data.begin(), data.end());
        //在vector中加好了（push_back），再使用这个函数重新调整一下堆
    }
    void pop(){
        pop_heap( data.begin(), data.end() );
        //使用后，root 结点就被放到了vector的最后，再使用vector的pop_back()删除
        data.pop_back();
    }
    int top() { return data.front(); }
    int size() { return data.size(); }
    bool empty() { return data.empty(); }
};
int main()
{
    priority_queue test;
    test.push( 3 );
    test.push( 5 );
    test.push( 2 );
    test.push( 4 );
    while( !test.empty() ){
        cout << test.top() << endl;
        test.pop();
    }
    return 0;
}
