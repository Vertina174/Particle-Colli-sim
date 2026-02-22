#include<iostream>
#include<vector>
#include<raylib.h>
#include<random>
using namespace std;
#define width 800
#define  height 600
static const int size1=10;
class particle{
    public:
    float x,y,radius,vx,vy;
};
void setparticle(particle *particles){
random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> random_radius(5,15);
for(int i=0; i<size1; i++){
    
    
    particles[i].radius=random_radius(gen);
    uniform_int_distribution<> random_width(particles[i].radius,width-particles[i].radius);
    uniform_int_distribution<> random_height(particles[i].radius,height-particles[i].radius);
    particles[i].x=random_width(gen);
    particles[i].y=random_height(gen);
    uniform_int_distribution<> random_speed(-2.00,2.00);
    particles[i].vx=random_speed(gen);
    particles[i].vy=random_speed(gen);

}
}
void drawparticle(particle *particles){
    for(int i=0; i<size1; i++){
        particles[i].x;
        particles[i].y;
        particles[i].radius;
    DrawCircle( particles[i].x,  particles[i].y,  particles[i].radius,RAYWHITE);

}
}
void updateparticle(particle *particles){
    for(int i=0; i<size1; i++){
        int x=particles[i].x;
        int y=particles[i].y;
        int r=particles[i].radius;
        float vx=particles[i].vx, vy=particles[i].vy;
 if(x>width-r ||x<r) particles[i].vx*=-1;
    if(y>height-r || y<r) particles[i].vy*=-1;
    particles[i].x+=particles[i].vx;
    particles[i].y+=particles[i].vy;
}
}

int main(){
particle particles[size1];
InitWindow(width,height,"Particle Collision Simulator");
SetTargetFPS(30);
setparticle(particles);
while(!WindowShouldClose()){
    
BeginDrawing();
ClearBackground(BLACK);
drawparticle(particles);
updateparticle(particles);
DrawFPS(5,5);
EndDrawing();
}
CloseWindow();
}