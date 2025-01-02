//written by flypiggy

//ʵ��ͼͷ�ļ�

#include "graph.h"
#include <climits>  // ���� INT_MAX
#include <queue>
#include <iostream>

int n,m;
std::vector<std::vector<Edge> > adj;
std::vector<Node> nodes;



std::vector<int> Dijkstra(int start) {
    std::vector<int> dist(n + 1, INT_MAX);
    std::vector<int> parent(n + 1, -1);
    dist[start] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        // ���������ڽӽڵ�
        for (const Edge& e : adj[u]) {
            int v = e.to;
            int weight = e.weight;

            // ���ɲ��������¾���
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    return parent;
}


std::vector<int> GetShortestPath(int start, int end) {

    std::vector<int> parent = Dijkstra(start);

    if (parent[end] == -1) {
        std::cout << "�޷������յ�!" << std::endl;
        return {};
    }

    std::vector<int> path;
    for (int current = end; current != -1; current = parent[current]) {
        path.push_back(current);
    }

    std::reverse(path.begin(), path.end());
    return path;
}


void CreateGraph() {
    n=10;
    m=13;
    adj.resize(n+1);
    nodes.resize(n+1);

    //��ƽڵ�����
    nodes[1]={"(1)��Է����","��Էѧ����Ϣ�ĵط�",50,100};
    nodes[2]={"(2)����","ѧУ����",150,50};
    nodes[3]={"(3)��Էʳ��","�ڱ�Է��ʳ��",200,150};
    nodes[4]={"(4)ѧԺ¥","ѧԺ��ʦ�쵼�칫�ĵط�",300,200};
    nodes[5]={"(5)������","ѧУ����",400,300};
    nodes[6]={"(6)����¥","�Ͽεĵط�",250,350};
    nodes[7]={"(7)����¥","�Ͽεĵط�",150,300};
    nodes[8]={"(8)�ٳ�","�˶��ĵط�",300,500};
    nodes[9]={"(9)��Էʳ��","����Է��ʳ��",50,400};
    nodes[10]={"(10)��Է����","��Էѧ����Ϣ�ĵط�",100,550};

    //����
    adj[1].push_back({2,1});
    adj[2].push_back({1,1});

    adj[1].push_back({3,2});
    adj[3].push_back({1,2});

    adj[2].push_back({3,2});
    adj[3].push_back({2,2});

    adj[3].push_back({4,3});
    adj[4].push_back({3,3});

    adj[3].push_back({6,4});
    adj[6].push_back({3,4});

    adj[4].push_back({6,2});
    adj[6].push_back({4,2});

    adj[4].push_back({5,3});
    adj[5].push_back({4,3});

    adj[5].push_back({6,1});
    adj[6].push_back({5,1});

    adj[6].push_back({7,3});
    adj[7].push_back({6,3});

    adj[6].push_back({8,6});
    adj[8].push_back({6,6});

    adj[7].push_back({8,1});
    adj[8].push_back({7,1});

    adj[7].push_back({9,1});
    adj[9].push_back({7,1});

    adj[8].push_back({9,2});
    adj[9].push_back({8,2});

    adj[9].push_back({10,2});
    adj[10].push_back({9,2});

    adj[10].push_back({8,1});
    adj[8].push_back({10,1});
}
