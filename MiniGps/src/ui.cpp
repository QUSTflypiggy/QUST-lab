//written by flypiggy

#include "ui.h"
#include <cmath> // ���ڼ������

void DrawGraph(bool showDesc[]) {
    setbkcolor(WHITE);
    cleardevice();

    // ���ƽڵ�
    for (int i = 1; i <= n; ++i) {
        setcolor(BLACK);
        circle(nodes[i].x, nodes[i].y, 10); // ���ƽڵ�
        setfillstyle(SOLID_FILL, WHITE);
        floodfill(nodes[i].x, nodes[i].y, BLACK);

        outtextxy(nodes[i].x - 20, nodes[i].y - 10, nodes[i].name.c_str());
        if (showDesc[i]) {
            setcolor(BLUE);
            outtextxy(nodes[i].x - 40, nodes[i].y + 20, nodes[i].desc.c_str());
        }
    }
    setcolor(BLACK);

    // ���Ʊ�
    for (int i = 1; i <= n; ++i) {
        for (const Edge& edge : adj[i]) {
            int x1 = nodes[i].x, y1 = nodes[i].y;
            int x2 = nodes[edge.to].x, y2 = nodes[edge.to].y;
            line(x1, y1, x2, y2);

            char weightStr[10];
            sprintf(weightStr, "%d", edge.weight);
            outtextxy((x1 + x2) / 2 - 10, (y1 + y2) / 2 - 10, weightStr);
        }
    }

    DrawButton();

    DrawReadme();
}

void DrawButton() {
    setcolor(BLACK);
    rectangle(BUTTON_X1, BUTTON_Y1, BUTTON_X2, BUTTON_Y2);
    outtextxy(BUTTON_X1 + 10, BUTTON_Y1 + 5, "��ѯ���·");
}

int GetClickedNode(int mouseX, int mouseY) {
    for (int i = 1; i <= n; ++i) {
        int dx = mouseX - nodes[i].x, dy = mouseY - nodes[i].y;
        if (sqrt(dx * dx + dy * dy) <= 30) {
            return i;
        }
    }
    return -1;
}

bool IsButtonClicked(int mouseX, int mouseY) {
    return mouseX >= BUTTON_X1 && mouseX <= BUTTON_X2 && mouseY >= BUTTON_Y1 && mouseY <= BUTTON_Y2;
}

void ShowInputDialog(int& start, int& end) {
    while (true) {
        char input[100];
        InputBox(input, 100, "�����������յ�Ĵ����Կ��ٲ�ѯ���ÿո�ָ�����", "���·����ѯ", NULL, 0, false);
        if (sscanf(input, "%d %d", &start, &end) != 2 || start < 1 || start > n || end < 1 || end > n) {
            MessageBox(NULL, "���Ϸ����룬�����䣡", "����", MB_OK | MB_ICONERROR);
        } else {
            break;
        }
    }
}

void DrawReadme() {
    settextcolor(RED);
    settextstyle(30, 0, "����"); // ����������ʽ
    outtextxy(400, 100, "��ӭ��������ƴ���ͼ");
    settextstyle(20, 0, "����");
    outtextxy(400, 150, "����������㣺չʾ����������");
}