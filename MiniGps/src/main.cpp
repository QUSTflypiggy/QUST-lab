#include "ui.h"
#include "graph.h"

int main() {
    CreateGraph();          // ����ͼ
    initgraph(800, 600);    // ��ʼ������

    bool showDesc[n + 1] = {false}; // ���ƽڵ�������ʾ
    DrawGraph(showDesc);           // ���Ƴ�ʼ����

    while (true) {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN) {//WM_LBUTTONDOWN��windows����Ϣ��������������������
            int clickedNode = GetClickedNode(msg.x, msg.y);
            if (clickedNode != -1) {
                showDesc[clickedNode] = !showDesc[clickedNode];
                DrawGraph(showDesc);
            } else if (IsButtonClicked(msg.x, msg.y)) {
                ShowInputDialog();
            }
        }
        if (msg.uMsg == WM_MBUTTONDOWN) {
            break;
        }
    }

    closegraph();
    return 0;
}
