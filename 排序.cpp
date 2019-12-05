#include <iostream>
#include "vector"
#include "ctime"

using namespace std;

//冒泡排序O(n2)
template <typename T>
void maopaoSort(vector<T>& a)
{
    cout<<endl<<"冒泡排序:"<<endl;
    int n = a.size();
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[j]<a[i])
               swap(a[i],a[j]);

}

//选择排序O(n2)
template <typename T>
void selectionSort(vector<T>& a)
{
    cout<<endl<<"选择排序:"<<endl;
    int n = a.size();
    for(int i=0;i<n;i++)
    {
        int minIndex = i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[minIndex])
                minIndex = j;
        swap(a[i],a[minIndex]);
    }

}



//插入排序O(n2)
template <typename T>
void insertSort(vector<T>& a)
{
    cout<<endl<<"插入排序:"<<endl;
    int n = a.size();
    for(int i=1;i<n;i++)
    {
        T ele = a[i];
        int j;
        for(j=i;j>0&&(a[j-1]>ele);j--)
            a[j]=a[j-1];
        a[j]=ele;
    }
}

//--------------------------------------------------------------

//归并排序O(nlogn)
//將arr[l...mid],arr[mid+1...r]两部分进行归并
template<typename T>
void merge(vector<T>& a,vector<T> aux,int l,int mid, int r)
{
    for(int i=l;i<=r;i++)
        aux[i-l]=a[i];

    int i=l,j=mid+1;
    for(int k=l;k<=r;k++)
    {   //i,j有效性判斷
        if(i>mid)
        {
            a[k]=aux[j-l];
            j++;
        }
        else if(j>r)
        {
            a[k]=aux[i-l];
            i++;
        }
            //i,j均有效
        else if(aux[i-l]<aux[j-l])
        {
            a[k]=aux[i-l];
            i++;
        }
        else
        {
            a[k]=aux[j-l];
            j++;
        }
    }
}

template<typename T>
void _mergeSort(vector<T>& a,vector<T> aux,int l,int r)
{
    if(l>=r)//-----------易错点
        return;
    int mid=(l+r)/2;
    _mergeSort(a,aux,l,mid);
    _mergeSort(a,aux,mid+1,r);
    merge(a,aux,l,mid,r);
}
template<typename T>
void mergeSort(vector<T>& a)
{
    cout<<endl<<"归并排序:"<<endl;
    int n = a.size();
    vector<T> aux(a.size());
    _mergeSort(a,aux,0,n-1);
}
//--------------------------------------------------------------


//快速排序O(nlogn)
//將a[l...r]进行分割操作，返回p，使得a[l...p-1]<a[p],a[p]<a[p+1,...,r]
template<typename T>
int partition(vector<T>& a,int l,int r)
{
    T ele = a[l];//a[l...p-1]<ele, ele<a[p+1,...,r]
    int j=l;
    for(int i=l+1;i<=r;i++)
    {
        if(a[i]<ele)
        {
            swap(a[j+1],a[i]);
            j++;
        }
    }
    swap(a[l],a[j]);
    return j;
}

template <typename T>
void _quickSort(vector<T>& a,int l,int r)
{
    if(l>=r)
        return;
    int p = partition(a,l,r);
    _quickSort(a,l,p-1);
    _quickSort(a,p+1,r);
}
template <typename T>
void quickSort(vector<T>& a)
{
    cout<<endl<<"快速排序:"<<endl;
    _quickSort(a,0,a.size()-1);
}



enum algorithm{
    maopao = 0,
    select1 = 1,
    insert ,
    merge1 ,
    quick ,
};


int main()
{
    //vector<int> a{10,4,57,2,3,6,53,32};
    vector<int> a;
    int count = 100;
    //srand(122);
    for(int i=0;i<count;i++)
        a.push_back(rand()%100);

    cout<<"原始数据："<<endl;
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<"->";
    clock_t t0;

    cout<<endl<<"---------"<<endl;

    algorithm sort_way(algorithm(4));


    switch (sort_way)
    {
        case maopao:
        {
            t0 = clock();
            maopaoSort(a);
            cout<<"time is "<<double(clock()-t0)/CLOCKS_PER_SEC<<" s"<<endl;
            break;
        }
        case select1:
        {
            t0 = clock();
            selectionSort(a);
            cout<<"time is "<<double(clock()-t0)/CLOCKS_PER_SEC<<" s"<<endl;
            break;
        }
        case insert:
        {
            t0 = clock();
            insertSort(a);
            cout<<"time is "<<double(clock()-t0)/CLOCKS_PER_SEC<<" s"<<endl;
            break;
        }
        case merge1:
        {
            t0 = clock();
            mergeSort(a);
            cout<<"time is "<<double(clock()-t0)/CLOCKS_PER_SEC<<" s"<<endl;
            break;
        }
        case quick:
        {
            t0 = clock();
            quickSort(a);
            cout<<"time is "<<double(clock()-t0)/CLOCKS_PER_SEC<<" s"<<endl;

        }


    }

    cout<<endl<<"---------"<<endl<<endl;
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<"->";
    cout<<endl;

    return 0;


/*
    t0 = clock();
    maopaoSort(a);
    cout<<"time is "<<double(clock()-t0)/CLOCKS_PER_SEC<<" s"<<endl;

    t0 = clock();
    selectionSort(a);
    cout<<"time is "<<double(clock()-t0)/CLOCKS_PER_SEC<<" s"<<endl;

    t0 = clock();
    insertSort(a);
    cout<<"time is "<<double(clock()-t0)/CLOCKS_PER_SEC<<" s"<<endl;

    t0 = clock();
    mergeSort(a);
    cout<<"time is "<<double(clock()-t0)/CLOCKS_PER_SEC<<" s"<<endl;


    t0 = clock();
    quickSort(a);
    cout<<"time is "<<double(clock()-t0)/CLOCKS_PER_SEC<<" s"<<endl;

    cout<<endl<<"---------"<<endl<<endl;


    for(int i=0;i<a.size();i++)
        cout<<a[i]<<"->";
    cout<<endl;

    return 0;
    */
}


