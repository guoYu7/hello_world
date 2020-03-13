//
// Created by Zhangjun on 2020/3/13.
//
//
// Created by Zhangjun on 2020/3/13.
//

#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>
#include <stack>

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
class UnionFind{

private:
    int* parent;
    int* rank;
    int count;

public:
    UnionFind(int count){
        parent = new int[count];
        rank = new int[count];
        this->count = count;
        for( int i = 0 ; i < count ; i ++ ){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    ~UnionFind(){
        delete[] parent;
        delete[] rank;
    }

    int size(){
        return count;
    }

    bool isConnected( int p , int q ){
        return find(p) == find(q);
    }

    int find(int p){

        assert( p >= 0 && p < count );

        // path compression 1
        while( p != parent[p] ){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;

    }

    void unionElements(int p, int q){

        int pRoot = find(p);
        int qRoot = find(q);

        if( pRoot == qRoot )
            return;

        if( rank[pRoot] < rank[qRoot] )
            parent[pRoot] = qRoot;
        else if( rank[qRoot] < rank[pRoot])
            parent[qRoot] = pRoot;
        else{ // rank[pRoot] == rank[qRoot]
            parent[pRoot] = qRoot;
            rank[qRoot] ++;
        }

    }

    void show(){
        for( int i = 0 ; i < count ; i ++ )
            cout<<i<<" : "<<parent[i]<<endl;
    }
};

template<typename Item>
class IndexMinHeap{

private:
    Item *data;
    int *indexes;
    int *reverse;

    int count;
    int capacity;

    void shiftUp( int k ){

        while( k > 1 && data[indexes[k/2]] > data[indexes[k]] ){
            swap( indexes[k/2] , indexes[k] );
            reverse[indexes[k/2]] = k/2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }

    void shiftDown( int k ){

        while( 2*k <= count ){
            int j = 2*k;
            if( j + 1 <= count && data[indexes[j]] > data[indexes[j+1]] )
                j += 1;

            if( data[indexes[k]] <= data[indexes[j]] )
                break;

            swap( indexes[k] , indexes[j] );
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }

public:
    IndexMinHeap(int capacity){

        data = new Item[capacity+1];
        indexes = new int[capacity+1];
        reverse = new int[capacity+1];

        for( int i = 0 ; i <= capacity ; i ++ )
            reverse[i] = 0;

        count = 0;
        this->capacity = capacity;
    }

    ~IndexMinHeap(){
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    void insert(int index, Item item){
        assert( count + 1 <= capacity );
        assert( index + 1 >= 1 && index + 1 <= capacity );

        index += 1;
        data[index] = item;
        indexes[count+1] = index;
        reverse[index] = count+1;
        count++;
        shiftUp(count);
    }

    Item extractMin(){
        assert( count > 0 );

        Item ret = data[indexes[1]];
        swap( indexes[1] , indexes[count] );
        reverse[indexes[count]] = 0;
        reverse[indexes[1]] = 1;
        count--;
        shiftDown(1);
        return ret;
    }

    int extractMinIndex(){
        assert( count > 0 );

        int ret = indexes[1] - 1;
        swap( indexes[1] , indexes[count] );
        reverse[indexes[count]] = 0;
        reverse[indexes[1]] = 1;
        count--;
        shiftDown(1);
        return ret;
    }

    Item getMin(){
        assert( count > 0 );
        return data[indexes[1]];
    }

    int getMinIndex(){
        assert( count > 0 );
        return indexes[1]-1;
    }

    bool contain( int index ){

        return reverse[index+1] != 0;
    }

    Item getItem( int index ){
        assert( contain(index) );
        return data[index+1];
    }

    void change( int index , Item newItem ){

        assert( contain(index) );
        index += 1;
        data[index] = newItem;

        shiftUp( reverse[index] );
        shiftDown( reverse[index] );
    }

};

template<typename Graph, typename Weight>
class Dijkstra{

private:
    Graph &G;
    int s;
    Weight *distTo;
    bool *marked;
    vector<Edge<Weight>*> from;

public:
    Dijkstra(Graph &graph, int s):G(graph){

        this->s = s;
        distTo = new Weight[G.V()];
        marked = new bool[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ ){
            distTo[i] = Weight();//默认是0，由于不知道数据类型，采用模板类初始化
            marked[i] = false;
            from.push_back(NULL);
        }

        IndexMinHeap<Weight> ipq(G.V());

        // start dijkstra
        distTo[s] = Weight();//默认是0，由于不知道数据类型，采用模板类初始化
        ipq.insert(s, distTo[s] );
        marked[s] = true;
        while( !ipq.isEmpty() ){
            int v = ipq.extractMinIndex();

            // distTo[v]就是s到v的最短距离
            marked[v] = true;
            //cout<<v<<endl;
            typename Graph::adjIterator adj(G, v);
            for( Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() ){
                int w = e->other(v);
                if( !marked[w] ){
                    if( from[w] == NULL || distTo[v] + e->wt() < distTo[w] ){
                        distTo[w] = distTo[v] + e->wt();
                        from[w] = e;
                        if( ipq.contain(w) )
                            ipq.change(w, distTo[w] );
                        else
                            ipq.insert(w, distTo[w] );
                    }
                }
            }
        }
    }

    ~Dijkstra(){
        delete[] distTo;
        delete[] marked;
    }

    Weight shortest_value_PathTo( int w ){
        assert( w >= 0 && w < G.V() );
        return distTo[w];
    }

    bool hasPathTo( int w ){
        assert( w >= 0 && w < G.V() );
        return marked[w];
    }

    void shortestPath( int w, vector<Edge<Weight>> &vec ){

        assert( w >= 0 && w < G.V() );

        stack<Edge<Weight>*> s;
        Edge<Weight> *e = from[w];
        while( e->v() != this->s ){
            s.push(e);
            e = from[e->v()];
        }
        s.push(e);

        while( !s.empty() ){
            e = s.top();
            vec.push_back( *e );
            s.pop();
        }
    }

    void showPath(int w){

        assert( w >= 0 && w < G.V() );

        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        for( int i = 0 ; i < vec.size() ; i ++ ){
            cout<<vec[i].v()<<" -> ";
            if( i == vec.size()-1 )
                cout<<vec[i].w()<<endl;
        }
    }
};


int main() {
    int V, E;
    string line, line1;
    getline(cin, line);
    stringstream ss(line);
    ss >> V >> E;//输入顶点数 边数

    //SparseGraph<int> g = SparseGraph<int>(V, true);
    SparseGraph<int> g = SparseGraph<int>(V, false);
    for (int i = 0; i < E; i++) {
        getline(cin, line1);
        stringstream ss0(line1);

        int a, b;
        double w;//注意输入权重的数据类型
        ss0 >> a >> b >> w;
        assert(a >= 0 && a < V);//注意：编号从0开始！！！！！！！！！！！！！！
        assert(b >= 0 && b < V);//！！！！！！！！
        g.addEdge(a, b, w);//g.addEdge(a-1, b-1, w-1);
    }

    int a = 3;//出发点（源点）
    Dijkstra<SparseGraph<int>, int> dij(g, a);

    for (int i = 0; i < V; i++) {
        if (i == a)
            continue;
        if (dij.hasPathTo(i)) {
            cout << a << " to " << i << " shortest value is: " << dij.shortest_value_PathTo(i) << endl;
            dij.showPath(i);
            cout << "----------" << endl;
        } else {
            cout << a << " has no path to " << i << endl;
        }

    }
    return 0;
}
//有向/无向权边测试（测试ok，20200313）
//5 8
//0 1 5
//0 2 2
//0 3 6
//1 4 1
//2 1 1
//2 4 5
//2 3 3
//3 4 2

