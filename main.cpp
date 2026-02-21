#include<iostream>
#include<vector>
#include<raylib.h>
using namespace std;
class Particle{
public:
float x,y,r,vx,vy;
void updateparticle(){
    if(x>750 ||x<50) vx*=-1;
    if(y>550 || y<50) vy*=-1;
    x+=vx;
    y+=vy;
}
void setparticle(){
    DrawCircle(x, y, r, RAYWHITE);
}
};
int main()
{
    system("cls");
Particle p;
    InitWindow(800, 600, "Particle Collison Simulation");
    SetTargetFPS(59.99);
    p.x=300; p.y=300; p.r=50; p.vx=1.3; p.vy=1.5;
    while(!WindowShouldClose()){
        BeginDrawing();
        DrawFPS(5,5);
        ClearBackground(BLACK);
        p.setparticle();
        p.updateparticle();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}