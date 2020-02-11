#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef int FLOW;                // フローを表す型、今回は int 型
int MAX_V;                      // グラフの最大ノード数
const FLOW INF = 1000;      // 十分大きい値

// グラフの辺の構造体
struct Edge {
    int rev, from, to;
    FLOW cap, icap;
    Edge(int r, int f, int t, FLOW c) : rev(r), from(f), to(t), cap(c), icap(c) {}
    friend ostream& operator << (ostream& s, const Edge& E) {
        if (E.cap > 0) return s << E.from << "->" << E.to << '(' << E.cap << ')';
        else return s;
    }
};

// グラフ構造体
struct Graph {
    int V;
    vector<Edge> list[MAX_V];

    Graph(int n = 0) : V(n) { for (int i = 0; i < MAX_V; ++i) list[i].clear(); }
    void init(int n = 0) { V = n; for (int i = 0; i < MAX_V; ++i) list[i].clear(); }
    void resize(int n = 0) { V = n; }
    void reset() { for (int i = 0; i < V; ++i) for (int j = 0; j < list[i].size(); ++j) list[i][j].cap = list[i][j].icap; }
    inline vector<Edge>& operator [] (int i) { return list[i]; }

    Edge &redge(Edge e) {
        if (e.from != e.to) return list[e.to][e.rev];
        else return list[e.to][e.rev + 1];
    }

    void addedge(int from, int to, FLOW cap) {
        list[from].push_back(Edge((int)list[to].size(), from, to, cap));
        list[to].push_back(Edge((int)list[from].size() - 1, to, from, 0));
    }
};

// 最大流を求めるサブルーチンたち
int level[MAX_V];
int iter[MAX_V];

void dibfs(Graph &G, int s) {
    for (int i = 0; i < MAX_V; ++i) level[i] = -1;
    level[s] = 0;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < G[v].size(); ++i) {
            Edge &e = G[v][i];
            if (level[e.to] < 0 && e.cap > 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

FLOW didfs(Graph &G, int v, int t, FLOW f) {
    if (v == t) return f;
    for (int &i = iter[v]; i < G[v].size(); ++i) {
        Edge &e = G[v][i], &re = G.redge(e);
        if (level[v] < level[e.to] && e.cap > 0) {
            FLOW d = didfs(G, e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                re.cap += d;
                return d;
            }
        }
    }
    return 0;
}

// 最大流を求めるメイン関数
FLOW Dinic(Graph &G, int s, int t) {
    FLOW res = 0;
    while (true) {
        dibfs(G, s);
        if (level[t] < 0) return res;
        memset(iter, 0, sizeof(iter));
        FLOW flow;
        while ((flow = didfs(G, s, t, INF)) > 0) {
            res += flow;
        }
    }
}

typedef pair<int, int> PII;

int main() {

    int N;
    cin >> N; 
    int NUM_MEN = N, NUM_WOMEN = N;
    MAX_V = 2 * N + 2;

    // グラフの定義 (ノード数を引数に)
    Graph G(NUM_MEN + NUM_WOMEN + 2);             // +2 は S, T の分

    // スーパーノード S, T の index
    int S_node = NUM_MEN + NUM_WOMEN;
    int T_node = NUM_MEN + NUM_WOMEN + 1;

    vector<PII> x,y;

    for(int i = 0; i < N; i++){
      int a,b;
      cin >> a >> b;
      x.push_back(make_pair(a,b));
    }
    for(int i = 0; i < N; i++){
      int c,d;
      cin >> c >> d;
      y.push_back(make_pair(c,d));
    }


    // グラフに枝を張っていく
    for (int i = 0; i < NUM_MEN; ++i) {
        PII man = x.at(i);
        for (int j = 0; j < NUM_WOMEN; ++j) {
            PII woman = y.at(j);
            if (man.first < woman.first && man.second < woman.second) {
                // 男 i から、女 j (index は j + NUM_MEN) へと、容量 1 の枝を張る
                G.addedge(i, j + NUM_MEN, 1);
            }
        }
    }

    for (int i = 0; i < NUM_MEN; ++i) {
        // S から男 i へと、容量 1 の枝を張る
        G.addedge(S_node, i, 1);
    }

    for (int j = 0; j < NUM_WOMEN; ++j) {
        // 女 j から T へと、容量 1 の枝を張る
        G.addedge(j + NUM_MEN, T_node, 1);
    }

    // 最大流を求める
    FLOW res = Dinic(G, S_node, T_node);


    // 出力
    cout << res << endl;

    // 誰が誰に
    for (int i = 0; i < NUM_MEN; ++i) {
        for (auto e : G[i]) {
            // 元々の容量 (e.icap) が 1 で、フローが流れて容量 (e.cap) が 0 になった部分が割り当てられたところ
            if (e.icap == 1 && e.cap == 0) {
              //
            }
        }
    }

}
