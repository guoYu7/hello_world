//
// Created by Zhangjun on 2020/3/13.
//
#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>

using namespace std;

template<typename Weight>
class Edge{
private:
    int a, b;
    Weight weight;

public:
    Edge(int a, int b, Weight weight){
        this->a = a;
        this->b = b;
        this->weight = weight;
    }

    Edge(){}

    ~Edge(){}

    int v(){ return a;}

    int w(){ return b;}

    Weight wt(){ return weight;}

    int other(int x){
        assert( x == a || x == b );
        return x == a ? b : a;
    }

    bool operator<(Edge<Weight>& e){
        return weight < e.wt();
    }

    bool operator<=(Edge<Weight>& e){
        return weight <= e.wt();
    }

    bool operator>(Edge<Weight>& e){
        return weight > e.wt();
    }

    bool operator>=(Edge<Weight>& e){
        return weight >= e.wt();
    }

    bool operator==(Edge<Weight>& e){
        return weight == e.wt();
    }

    friend ostream& operator<<(ostream &os, const Edge &e){
        os<<e.a<<"-"<<e.b<<": "<<e.weight;
        return os;
    }
};
// 稀疏图 - 邻接表
template<typename Weight>
class SparseGraph{

private:
    int n, m;
    bool directed;
    vector<vector<Edge<Weight> *>> g;
public:
    SparseGraph( int n , bool directed){
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for( int i = 0 ; i < n ; i ++ )
            g.push_back( vector<Edge<Weight> *>() );
    }

    ~SparseGraph(){
        for( int i = 0 ; i < n ; i ++ )
            for( int j = 0 ; j < g[i].size() ; j ++ )
                delete g[i][j];
    }

    int V(){ return n;}
    int E(){ return m;}

    void addEdge( int v, int w , Weight weight){
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );

        g[v].push_back(new Edge<Weight>(v, w, weight));
        if( v != w && !directed )
            g[w].push_back(new Edge<Weight>(w, v, weight));
        m ++;
    }

    bool hasEdge( int v , int w ){
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );
        for( int i = 0 ; i < g[v].size() ; i ++ )
            if( g[v][i]->other(v) == w )
                return true;
        return false;
    }

    void show(){

        for( int i = 0 ; i < n ; i ++ ){
            cout<<"vertex "<<i<<":\t";
            for( int j = 0 ; j < g[i].size() ; j ++ )
                cout<<"( to:"<<g[i][j]->w()<<",wt:"<<g[i][j]->wt()<<")\t";
            cout<<endl;
        }
    }

    class adjIterator{
    private:
        SparseGraph &G;
        int v;
        int index;
    public:
        adjIterator(SparseGraph &graph, int v): G(graph){
            this->v = v;
            this->index = 0;
        }

        Edge<Weight>* begin(){
            index = 0;
            if( G.g[v].size() )
                return G.g[v][index];
            return NULL;
        }

        Edge<Weight>* next(){
            index += 1;
            if( index < G.g[v].size() )
                return G.g[v][index];
            return NULL;
        }

        bool end(){
            return index >= G.g[v].size();
        }
    };
};

template<typename Item>
class MinHeap{

private:
    Item *data;
    int count;
    int capacity;

    void shiftUp(int k){
        while( k > 1 && data[k/2] > data[k] ){
            swap( data[k/2], data[k] );
            k /= 2;
        }
    }

    void shiftDown(int k){
        while( 2*k <= count ){
            int j = 2*k;
            if( j+1 <= count && data[j+1] < data[j] ) j ++;
            if( data[k] <= data[j] ) break;
            swap( data[k] , data[j] );
            k = j;
        }
    }

public:

    MinHeap(int capacity){
        data = new Item[capacity+1];
        count = 0;
        this->capacity = capacity;
    }

    MinHeap(Item arr[], int n){
        data = new Item[n+1];
        capacity = n;

        for( int i = 0 ; i < n ; i ++ )
            data[i+1] = arr[i];
        count = n;

        for( int i = count/2 ; i >= 1 ; i -- )
            shiftDown(i);
    }

    ~MinHeap(){
        delete[] data;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    void insert(Item item){
        assert( count + 1 <= capacity );
        data[count+1] = item;
        shiftUp(count+1);
        count ++;
    }

    Item extractMin(){
        assert( count > 0 );
        Item ret = data[1];
        swap( data[1] , data[count] );
        count --;
        shiftDown(1);
        return ret;
    }

    Item getMin(){
        assert( count > 0 );
        return data[1];
    }

    void show(){
        cout<<"| ";
        for( int i = 1 ; i <= count ; i ++ )
            cout<<data[i]->wt()/*<<","<<data[i]*/<<" | ";
        cout<<endl;
    }
};

template<typename Graph, typename Weight>
class LazyPrimMST{

private:
    Graph &G;
    vector<Edge<Weight>> mst;

    bool* marked;
    MinHeap<Edge<Weight>> pq;
    Weight mstWeight;


    void visit(int v){
        assert( !marked[v] );
        marked[v] = true;

        typename Graph::adjIterator adj(G,v);
        for( Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() )
            if( !marked[e->other(v)] )
                pq.insert(*e);

    }
public:
    // 保证图是连通无向有权图
    LazyPrimMST(Graph &graph):G(graph), pq(MinHeap<Edge<Weight>>(graph.E())){

        marked = new bool[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ )
            marked[i] = false;
        mst.clear();

        visit(0);
        while( !pq.isEmpty() ){
            Edge<Weight> e = pq.extractMin();
            if( marked[e.v()] && marked[e.w()] )
                continue;

            mst.push_back(e);
            if( !marked[e.v()] )
                visit(e.v());
            if( !marked[e.w()] )
                visit(e.w());
        }

        mstWeight = mst[0].wt();
        for( int i = 1 ; i < mst.size() ; i ++ )
            mstWeight += mst[i].wt();
    }

    ~LazyPrimMST(){
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges(){
        return mst;
    };

    Weight result(){
        return mstWeight;
    };
};


int main() {
    int V,E;
    string line,line1;
    getline(cin,line);
    stringstream ss(line);
    ss>>V>>E;

    SparseGraph<double> g = SparseGraph<double>(V, false);
    for(int i=0;i<E;i++){
        getline(cin,line1);
        stringstream ss0(line1);

        int a, b;
        double w;//注意输入权重的数据类型
        ss0>>a>>b>>w;
        assert( a >= 0 && a < V );//注意：编号从0开始！！！！！！！！！！！！！！
        assert( b >= 0 && b < V );//！！！！！！！！
        g.addEdge(a, b, w);//g.addEdge(a-1, b-1, w-1);
    }

    LazyPrimMST<SparseGraph<double>,double> lazyPrimMST(g);

    vector<Edge<double>> res_edge = lazyPrimMST.mstEdges();
    double res_weight = lazyPrimMST.result();

    cout<<res_weight<<endl;

    for(auto e:res_edge)
        cout<<e<<endl;//边的定义里，运算符重载定义的输出方式

    return 0;
}
//  输入顶点数和边数
//7 9
//0 1 28
//1 2 16
//1 6 14
//2 3 12
//3 4 22
//3 6 18
//4 5 25
//4 6 24
//0 5 10
//    99
//
//
//    4 5
//    1 2 2
//    1 3 2
//    1 4 3
//    2 3 4
//    3 4 3
//    输出样例#1：
//    7
