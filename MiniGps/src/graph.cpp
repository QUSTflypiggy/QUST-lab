//written by flypiggy

//ʵ��ͼͷ�ļ�

#include "graph.h"

int n,m;
std::vector<std::vector<Edge> > adj;
std::vector<Node> nodes;

void CreateGraph() {
    n=10;
    m=13;
    adj.resize(n+1);
    nodes.resize(n+1);

    //��ƽڵ�����
    nodes[1]={"��Է����","��Էѧ����Ϣ�ĵط�",50,100};
    nodes[2]={"����","ѧУ����",150,50};
    nodes[3]={"��Էʳ��","�ڱ�Է��ʳ��",200,150};
    nodes[4]={"ѧԺ¥","ѧԺ��ʦ�쵼�칫�ĵط�",300,200};
    nodes[5]={"������","ѧУ����",400,300};
    nodes[6]={"����¥","�Ͽεĵط�",250,350};
    nodes[7]={"����¥","�Ͽεĵط�",150,350};
    nodes[8]={"�ٳ�","�˶��ĵط�",200,500};
    nodes[9]={"��Էʳ��","����Է��ʳ��",50,400};
    nodes[10]={"��Է����","��Էѧ����Ϣ�ĵط�",100,500};

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
