// menu driven program for 2D transformations

#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

void translation(int x1, int y1, int x2, int y2, int tx, int ty)
{
    int gd = DETECT, gm = VGAMAX;
    initgraph(&gd, &gm, NULL);

    line(x1, y1, x2, y2);
    outtextxy(x2 + 2, y2 + 2, "Original line");

    int x3 = x1 + tx;
    int y3 = y1 + ty;
    int x4 = x2 + tx;
    int y4 = y2 + ty;

    line(x3, y3, x4, y4);
    outtextxy(x4 + 2, y4 + 2, "Line after translation");

    getchar();
    closegraph();
}

void rotation(int x1, int y1, int x2, int y2, float angle_degree)
{
    int gd = DETECT, gm = VGAMAX;
    initgraph(&gd, &gm, NULL);

    line(x1, y1, x2, y2);
    outtextxy(x2 + 2, y2 + 2, "Original line");

    float angle_radian = angle_degree * (3.14 / 180);

    int x3 = (x1 * cos(angle_radian)) - (y1 * sin(angle_radian));
    int y3 = (x1 * sin(angle_radian)) + (y1 * cos(angle_radian));
    int x4 = (x2 * cos(angle_radian)) - (y2 * sin(angle_radian));
    int y4 = (x2 * sin(angle_radian)) + (y2 * cos(angle_radian));

    line(x3, y3, x4, y4);
    outtextxy(x4 + 2, y4 + 2, "Line after rotation");

    getchar();
    closegraph();
}

void scaling(int x1, int y1, int x2, int y2, float scale_x, float scale_y)
{
    int gd = DETECT, gm = VGAMAX;
    initgraph(&gd, &gm, NULL);

    line(x1, y1, x2, y2);
    outtextxy(x2 + 2, y2 + 2, "Original line");

    int x3 = x1 * scale_x;
    int y3 = y1 * scale_y;
    int x4 = x2 * scale_x;
    int y4 = y2 * scale_y;

    line(x3, y3, x4, y4);
    outtextxy(x4 + 2, y4 + 2, "Line after scaling");

    getchar();
    closegraph();
}

int main()
{
    int x1, y1, x2, y2, tx, ty, choice;
    float angle_degree, scale_x, scale_y;

    cout << "Enter the coordinates of the line: ";
    cin >> x1 >> y1 >> x2 >> y2;

    cout << "Enter the choice: " << endl;
    cout << "1. Translation" << endl;
    cout << "2. Rotation" << endl;
    cout << "3. Scaling" << endl;
    cin >> choice;

    switch(choice)
    {
        case 1:
            cout << "Enter the translation factor: ";
            cin >> tx >> ty;
            translation(x1, y1, x2, y2, tx, ty);
            break;
        case 2:
            cout << "Enter the angle of rotation: ";
            cin >> angle_degree;
            rotation(x1, y1, x2, y2, angle_degree);
            break;
        case 3:
            cout << "Enter the scaling factor: ";
            cin >> scale_x >> scale_y;
            scaling(x1, y1, x2, y2, scale_x, scale_y);
            break;
        default:
            cout << "Invalid choice" << endl;
    }

    return 0;
}
