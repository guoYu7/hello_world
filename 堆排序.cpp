#include <iostream>
#include <fstream>
#include <vector>
#include <assert.h>

using namespace std;
//最大堆：根结点的键值是所有堆结点键值中最大者，且每个结点的值都比其孩子的值大。
//最小堆：根结点的键值是所有堆结点键值中最小者，且每个结点的值都比其孩子的值小。
template<typename T>
class MaxHeap{//定義最大堆
private:
    T* data;
    int count;
    int capacity;
    void shiftUp(int k){
        while(k>1&&data[k/2]<data[k]){
            swap(data[k/2],data[k]);
            k/=2;
        }
    }

    void shiftDown(int k){
        while(2*k<=count){
            int j=2*k;
            if(j+1<=count && data[j]<data[j+1])
                j++;
            if(data[k]>data[j])
                break;
            swap(data[k],data[j]);
            k=j;
        }
    }

public:
    MaxHeap(int capacity){
        data = new T[capacity+1];
        count=0;
        this->capacity=capacity;
    }

    ~MaxHeap(){
        delete[] data;
    }

    void insert(T item){
        assert(count+1<=capacity);
        data[count+1] = item;
        count++;
        shiftUp(count);
    }

    T extractMax(){
        assert(count>0);
        T ret=data[1];
        swap(data[1],data[count]);
        count--;
        shiftDown(1);
        return ret;
    }
};

template<typename T>
void heapsort(vector<T> &v){
    int n = v.size();
    MaxHeap<T> maxheap=MaxHeap<T>(n);
    for(int i=0;i<n;i++){
        maxheap.insert(v[i]);
    }
    for(int i=n-1;i>=0;i--){
        v[i]=maxheap.extractMax();
    }
}

int main(){
    vector<int> v{1,4,3,2,32,3,2,10,2,12,9,0};
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" -> ";
    cout<<endl;
    heapsort(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" -> ";
    cout<<endl;
}

