// main.cpp
#include "ui.h"
#include "graph.h"
#include <iostream>
#include <vector>

int main() {
    CreateGraph();          // ����ͼ
    initgraph(800, 600);    // ��ʼ������

    bool showDesc[n + 1] = {false}; // ���ƽڵ�������ʾ
    DrawGraph(showDesc);           // ���Ƴ�ʼ����

    int start = -1, end = -1; // �����յ�
    while (true) {
        MOUSEMSG msg = GetMouseMsg();

        if (msg.uMsg == WM_LBUTTONDOWN) { // ��������������
            int clickedNode = GetClickedNode(msg.x, msg.y);
            if (clickedNode != -1) {

                showDesc[clickedNode] = !showDesc[clickedNode];
                DrawGraph(showDesc);
            } else if (IsButtonClicked(msg.x, msg.y)) {

                ShowInputDialog(start, end); // �� start �� end ��Ϊ���ô���

                if (start != -1 && end != -1) {

                    std::vector<int> dist = Dijkstra(start);
                    std::vector<int> path = GetShortestPath(start, end); // ��ȡ·��

                    if (path.empty()) {
                        MessageBox(NULL, "·�����ɴ", "���·����ѯ", MB_OK | MB_ICONERROR);
                    } else {
                        std::string pathStr = "���·��Ϊ��";
                        for (int node : path) {
                            pathStr += nodes[node].name + " -> ";
                        }
                        pathStr = pathStr.substr(0, pathStr.size() - 4);

                        MessageBox(NULL, pathStr.c_str(), "���·����ѯ", MB_OK | MB_ICONINFORMATION);
                    }
                }
            }
        }

        // �����м�����˳�
        if (msg.uMsg == WM_MBUTTONDOWN) {
            break;
        }
    }

    closegraph();
    return 0;
}
