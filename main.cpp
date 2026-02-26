#include<iostream>
#include<vector>
#include<raylib.h>
#include<random>
using namespace std;
#define width 800
#define  height 600
static const int size1=5;
class particle{
    public:
    float x,y,radius,vx,vy;
};
void setparticle(particle *particles){
random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> random_radius(5,15);
for(int i=0; i<size1; i++){
    
    
    particles[i].radius=50;
    uniform_int_distribution<> random_width(particles[i].radius,width-particles[i].radius);
    uniform_int_distribution<> random_height(particles[i].radius,height-particles[i].radius);
    particles[i].x=random_width(gen);
    particles[i].y=random_height(gen);
    uniform_int_distribution<> random_speed(-5.00,5.00);
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
void particleoverlapping(particle *particles, int i, int j){
        float x=particles[j].x-particles[i].x;
         float y=particles[j].y-particles[i].y;
         float distance = sqrt((x*x)+(y*y));
         float overlap = (particles[i].radius+particles[j].radius)-distance;
         if(overlap>0){
x/=distance;
y/=distance;
particles[i].x-=x*overlap/2;
particles[i].y-=y*overlap/2;
particles[j].x+=x*overlap/2;
particles[j].y+=y*overlap/2;
         }
         if(overlap==0) return;
}
void particlecollision(particle *particles){
    for(int i=0; i<size1; i++){
        for(int j=0; j<size1; j++){
            if(i==j) continue;
               Vector2 c1={particles[i].x, particles[i].y};
            Vector2 c2={particles[j].x, particles[j].y};
             bool collide = CheckCollisionCircles(c1,particles[i].radius,c2,particles[j].radius);
            if(collide){
                cout<<"Collision Occured"<<endl;
                
                swap(particles[i].vx, particles[j].vx);
    swap(particles[i].vy, particles[j].vy);
    particleoverlapping(particles,i,j);
            }
        }
    }
}

int main(){
particle particles[size1];
InitWindow(width,height,"Particle Collision Simulator");
SetTargetFPS(60);
setparticle(particles);
while(!WindowShouldClose()){
    
BeginDrawing();
ClearBackground(BLACK);
drawparticle(particles);
updateparticle(particles);
particlecollision(particles);

DrawFPS(5,5);
EndDrawing();
}
CloseWindow();
}