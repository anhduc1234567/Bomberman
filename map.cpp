
#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include"animation.h" 
using namespace sf;
using namespace std;
bool isBomx2 = true;
bool isSpeedUp = false;
bool isPowerX2 = true;
bool isGameOver = false;
int timex2Power = 5;
int timex2 = 5;
int timeSpeedUp = 5;
const int col=35;
const int row=13;
int random(int max,int min){
         int res = rand() % (max- min + 1) + min;//rand() % (max – min + 1) + min [max,min]
         return res; 
}
class BackGround{//các nền ảnh 64x64
    private:
        Texture a;
        Sprite Back;
    public:
    void setBackGround(string s){
        a.loadFromFile(s);
        Back.setTexture(a);
    }
    Sprite getSprite(){
        return Back;
    }
    void setPosition(int x,int y){
        Back.setPosition(x,y);
    }
};
class Character{
    private:
    Animation characterIdleLeft;
    Animation characterIdleRight;
    Animation characterIdleFront;
    Animation characterIdleBack;

    Animation characterAttackLeft;
    Animation characterAttackRight;
    Animation characterAttackFront;
    Animation characterAttackBack;

    Animation characterWalkLeft;
    Animation characterWalkRight;
    Animation characterWalkFront;
    Animation characterWalkBack;
    double x=64;
    double y=64;
    double v;

    void idleLeft(RenderWindow &window) {
            characterIdleLeft.begin2(x,y);
            if(characterIdleLeft.f>characterIdleLeft.fcount) characterIdleLeft.f=0;
            window.draw(characterIdleLeft.explosion);
    }
    void idleRight(RenderWindow &window) {
            characterIdleRight.begin2(x,y);
            if(characterIdleRight.f>characterIdleRight.fcount) characterIdleRight.f=0;
            window.draw(characterIdleRight.explosion);
    }
    void idleFront(RenderWindow &window) {
            characterIdleFront.begin2(x,y);
            if(characterIdleFront.f>characterIdleFront.fcount) characterIdleFront.f=0;
            window.draw(characterIdleFront.explosion);
    }
    void idleBack(RenderWindow &window){
            characterIdleBack.begin2(x,y);
            if(characterIdleBack.f>characterIdleBack.fcount) characterIdleBack.f=0;
            window.draw(characterIdleBack.explosion);
    }
    void walkLeft(RenderWindow &Window) {
        characterWalkLeft.begin2(x,y);
        if(characterWalkLeft.f>characterWalkLeft.fcount) {
            characterWalkLeft.f=0;
            }
        Window.draw(characterWalkLeft.explosion);
    }
    void walkRight(RenderWindow &Window) {
           characterWalkRight.begin2(x,y);
         if(characterWalkRight.f>characterWalkRight.fcount) {
             characterWalkRight.f=0;
            }
        Window.draw(characterWalkRight.explosion);
     }
     void walkFront(RenderWindow &Window) {
        characterWalkFront.begin2(x,y);
        if(characterWalkFront.f>characterWalkFront.fcount) {
            characterWalkFront.f=0;
            }
        Window.draw(characterWalkFront.explosion);
    }
    void walkBack(RenderWindow &Window) {
        characterWalkBack.begin2(x,y);
        if(characterWalkBack.f>characterWalkBack.fcount) {
            characterWalkBack.f=0;
            }
        Window.draw(characterWalkBack.explosion);
    }
public:
    void setAnimation(string idleL,string idleR,string idleF,string idleB,string attL,string attR,string attF,string attB,
    string walkL,string walkR,string walkF,string walkB) {
        this->characterIdleLeft.setani(0,0.01,2,idleL,64,64,0);
        this->characterIdleRight.setani(0,0.01,2,idleR,64,64,0);
        this->characterIdleFront.setani(0,0.01,2,idleF,64,64,0);
        this->characterIdleBack.setani(0,0.01,2,idleB,64,64,0);

        this->characterAttackLeft.setani(0,0.04,4,attL,128,128,0);
        this->characterAttackRight.setani(0,0.04,4,attR,128,128,0);
        this->characterAttackFront.setani(0,0.04,4,attF,128,128,0);
        this->characterAttackBack.setani(0,0.04,4,attB,128,128,0);

        this->characterWalkLeft.setani(0,0.01,4,walkL,64,64,0);
        this->characterWalkRight.setani(0,0.01,4,walkR,64,64,0);
        this->characterWalkFront.setani(0,0.01,4,walkF,64,64,0);
        this->characterWalkBack.setani(0,0.01,4,walkB,64,64,0);
    }   
    bool isWalk=false;
    bool isLeft=false;
    bool isRight=false;
    bool isFront=true;
    bool isBack=false;
    bool isValidRight=false;
    bool isValidDown=false;
    bool isValidLeft=false;
    bool isValidUp=false;
    bool isAttack = false;
    void setX_char(double x) {
        this->x=this->x+x;
    }
    void setY_char(double x) {
        this->y=x;
    }
    void setV(double v){
        this->v=v;
    }
    double getX_char(){
        return x;
    }
    double getY_char(){
        return y;
    }
    double getV(){
        return v;
    }

    void attackLeft(RenderWindow &window) {
           characterAttackLeft.begin2(x-32,y-32);
           if(characterAttackLeft.f>characterAttackLeft.fcount) {
            characterAttackLeft.f =0;
            isAttack =false;
           }
           window.draw(characterAttackLeft.explosion);
    }

    void attackRight(RenderWindow &window) {
           characterAttackRight.begin2(x-32,y-32);
           if(characterAttackRight.f>characterAttackRight.fcount) {
            characterAttackRight.f =0;
             isAttack =false;
           }
           window.draw(characterAttackRight.explosion);
    }

    void attackBack(RenderWindow &window) {
           characterAttackBack.begin2(x-32,y-32);
           if(characterAttackBack.f>characterAttackBack.fcount) {
            characterAttackBack.f =0;
             isAttack =false;
           }
           window.draw(characterAttackBack.explosion);
    }
    void attackFront(RenderWindow &window) {
           characterAttackFront.begin2(x-32,y-32);
           if(characterAttackFront.f>characterAttackFront.fcount) {
            characterAttackFront.f =0;
             isAttack =false;
           }
           window.draw(characterAttackFront.explosion);
    }
   
    void displayCharacter(RenderWindow &window) {
       
        if(isWalk==false&& isAttack ==false) {
            v=0;
            if   (isLeft==true)     idleLeft(window);   
            else if(isFront==true) idleFront(window);
            else if(isBack==true)  idleBack(window);
            else if(isRight==true) idleRight(window);
        }
        else if(isAttack == true) {
             if(isLeft==true)      attackLeft(window);
            else if(isRight==true) attackRight(window);
            else if(isBack==true)  attackBack(window);
            else if(isFront==true) attackFront(window);         
        }
        else if(isWalk==true) {
            if(isLeft==true) {
               if(!isSpeedUp)  v = v + 0.5;
               else v = v + 1;
                if(v==64) {
                    isWalk=false;
                    v=0; }
                if(!isSpeedUp) x = x - 0.5;
                else x = x - 1;
                walkLeft(window); }
            else if(isRight==true) {
               if(!isSpeedUp)  v = v + 0.5;
               else v = v + 1;
                if(v==64) {
                  v=0;
                  isWalk=false;}
               if(!isSpeedUp) x = x + 0.5;
                else x = x + 1;
                walkRight(window);
                }
            else if(isFront==true) {
              if(!isSpeedUp)  v = v + 0.5;
               else v = v + 1;
                if(v==64) {
                    v=0;
                    isWalk=false; }
                if(!isSpeedUp) y = y + 0.5;
                else y = y + 1;
                walkFront(window);
                }
            else if(isBack==true) {
               if(!isSpeedUp)  v = v + 0.5;
               else v = v + 1;
                if(v==64) {
                    v=0;
                    isWalk=false; } 
                if(!isSpeedUp) y = y - 0.5;
                else y = y - 1;
                walkBack(window);
                }
        }
    }
};
class Map{//vẽ map
 private:
     double x_first;
     BackGround grases[row][col];// cỏ
     BackGround stones[row][col];
     BackGround bricks[row][col];
     BackGround x2bomItem;
     BackGround speedUp;
     BackGround victoryItem;
     BackGround x2PowerItem;
    int map[row][col]={                                                           //0 cỏ có thể đi và đặt bom
        { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },//1 đá không thể phá
        { 1,3,0,2,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,1 },//2 tường có thể phá
        { 1,0,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,0,1,0,1,0,1,0,1 },//3 vị trí nhân vật
        { 1,2,2,0,0,0,2,2,2,2,2,2,0,0,0,2,2,2,0,0,0,0,2,0,2,2,0,0,2,0,0,2,0,2,1 },//4
        { 1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,0,1,2,1,2,1,2,1,0,1,2,1,0,1,0,1,2,1,0,1 },//5
        { 1,2,2,2,0,0,0,0,2,2,2,2,2,0,0,0,0,2,0,0,0,0,2,0,2,2,0,0,2,0,2,0,0,2,1 },//6
        { 1,2,1,2,1,2,1,2,1,2,1,2,1,0,1,0,1,2,1,0,1,0,1,0,1,2,1,0,1,0,1,0,1,0,1 },//7
        { 1,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,0,0,0,0,2,0,2,2,0,0,2,0,2,0,2,0,1 },//8
        { 1,2,1,2,1,2,1,2,1,2,1,0,1,2,1,2,1,2,1,2,1,2,1,0,1,2,1,0,1,0,1,0,1,0,1 },//9
        { 1,2,2,2,2,2,2,2,2,2,0,0,0,2,2,2,2,2,0,0,0,0,2,0,2,2,0,0,2,0,2,0,2,0,1 },//10
        { 1,2,1,2,1,2,1,2,1,2,1,0,1,2,1,2,1,2,1,2,1,2,1,0,1,2,1,0,1,2,1,0,1,0,1 },//11
        { 1,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,2,2,2,2,2,2,2,2,2,2,0,2,0,0,2,0,7,1 },//12
        { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }//13
    };
    void characterSolve(Character &player,int &i,int &j) {
                     if(haveRunRight == true&& map[i][j+1] != 1 && map[i][j+1] != 2&&player.isWalk==false) {
                        if(map[i][j+1] == 4 ) {
                            if(isBomx2 == false)  isBomx2 = true;
                            else timex2 = timex2 + 5;
                        }
                        else if (map[i][j+1] == 5) {
                            if(!isSpeedUp) isSpeedUp = true;
                            else timeSpeedUp = timeSpeedUp + 5;
                        }
                        else if (map[i][j+1] == 6) {
                            if(!isPowerX2) isPowerX2 = true;
                            else timex2Power = timex2Power + 5;
                        }
                        map[i][j]=0;
                        map[i][j+1]=3;
                        player.isWalk=true;
                        haveRunRight=false;
                    }
                    if(haveRunDown==true&& map[i+1][j]!=1 && map[i+1][j]!=2&&player.isWalk==false) {
                          if(map[i+1][j] == 4) {
                             if(isBomx2 == false)  isBomx2 = true;
                            else timex2 = timex2 + 5;
                            }
                        else if (map[i+1][j] == 5) {
                            if(!isSpeedUp) isSpeedUp = true;
                            else timeSpeedUp = timeSpeedUp + 5;
                        }
                        else if (map[i+1][j] == 6) {
                            if(!isPowerX2) isPowerX2 = true;
                            else timex2Power = timex2Power + 5;
                        }
                        map[i][j]=0;
                        map[i+1][j]=3;
                        player.isWalk=true;
                        haveRunDown=false;
                    }
                    if(haveRunLeft==true&& map[i][j-1]!=1&&map[i][j-1]!=2&&player.isWalk==false) {
                        if(map[i][j - 1] == 4) {
                             if(isBomx2 == false)  isBomx2 = true;
                            else timex2 = timex2 + 5;
                            }
                        else if (map[i][j - 1] == 5) {
                            if(!isSpeedUp) isSpeedUp = true;
                            else timeSpeedUp = timeSpeedUp + 5;
                        }
                        else if (map[i][j - 1] == 6) {
                            if(!isPowerX2) isPowerX2 = true;
                            else timex2Power = timex2Power + 5;
                        }
                        map[i][j]=0;
                        map[i][j-1]=3;
                        player.isWalk=true;
                        haveRunLeft=false;
                    }
                    if(haveRunUp==true&& map[i-1][j]!=1&&map[i-1][j]!=2&&player.isWalk==false) {
                        if(map[i - 1][j] == 4) {
                            if(isBomx2 == false)  isBomx2 = true;
                            else timex2 = timex2 + 5;
                        }
                        else if (map[i - 1][j] == 5) {
                            if(!isSpeedUp) isSpeedUp = true;
                            else timeSpeedUp = timeSpeedUp + 5;
                        }
                        else if (map[i - 1][j] == 6) {
                            if(!isPowerX2) isPowerX2 = true;
                            else timex2Power = timex2Power + 5;
                        }
                        map[i][j]=0;
                        map[i-1][j]=3;
                        player.isWalk = true;
                        haveRunUp = false;
                    }
                    haveRunRight = false;
                    haveRunDown = false;
                    haveRunLeft = false;
                    haveRunUp = false;
    }
public:
    Map(){
        x_first=0;
        x2bomItem.setBackGround("x2bom.png");
        speedUp.setBackGround("x2move.png");
        x2PowerItem.setBackGround("x2power.png");
        victoryItem.setBackGround("victory.png");
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++){
            grases[i][j].setBackGround("grass.png");}
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
            stones[i][j].setBackGround("stone.png");}
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
            bricks[i][j].setBackGround("gach.png");}
        }
    
    }
    void setX(double x){
        x_first=x_first+x;
    }
    double getX(){
        return x_first;
    }
    void setMap(int i,int j,int k) {
        map[i][j]=k;
    }
   
    int** getMap(){
        int ** getMap = new int*[row];
        for(int i = 0; i < row; i++){
            getMap[i] = new int [col];
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                getMap[i][j]=map[i][j];
            }
        }
        return getMap;
    }

    bool haveRunRight=false;
    bool haveRunDown=false;
    bool haveRunLeft=false;
    bool haveRunUp=false;
    bool isSetVertex = false;
    void drawMap(RenderWindow &window,Character &player){
         for(int i=0;i<row;i++){
             for(int j=0;j<col;j++){
                if(map[i][j]==0){
                    grases[i][j].setPosition((64)*j-x_first,(64)*i);
                    window.draw(grases[i][j].getSprite());
                }
                else if(map[i][j]==1){
                 stones[i][j].setPosition(64*j-x_first,64*i);
                 window.draw(stones[i][j].getSprite());
              }
                else if(map[i][j]==2){
                    bricks[i][j].setPosition(64*j-x_first,64*i);
                    window.draw(bricks[i][j].getSprite());
                }
                else if(map[i][j]==4){
                    grases[i][j].setPosition((64)*j-x_first,(64)*i);
                    window.draw(grases[i][j].getSprite());
                    x2bomItem.setPosition(64*j-x_first,64*i);
                    window.draw(x2bomItem.getSprite());
                }
                else if(map[i][j]==5){
                    grases[i][j].setPosition((64)*j-x_first,(64)*i);
                    window.draw(grases[i][j].getSprite());
                    speedUp.setPosition(64*j-x_first,64*i);
                    window.draw(speedUp.getSprite());
                }
                else if(map[i][j] == 6){
                    grases[i][j].setPosition((64)*j-x_first,(64)*i);
                    window.draw(grases[i][j].getSprite());
                    x2PowerItem.setPosition(64*j-x_first,64*i);
                    window.draw(x2PowerItem.getSprite());
                }
                else if(map[i][j] == 7){
                    grases[i][j].setPosition((64)*j-x_first,(64)*i);
                    window.draw(grases[i][j].getSprite());
                    victoryItem.setPosition(64*j-x_first,64*i);
                    window.draw(victoryItem.getSprite());
                }
                else if(map[i][j]==3){
                    grases[i][j].setPosition((64)*j-x_first,(64)*i);
                    window.draw(grases[i][j].getSprite());
                    characterSolve(player,i,j); 
                }
                
            }
          }
    }
};

class Peak {
public:
    int i;
    int j;
    int lable;
    Peak() {

    }
    Peak(int i, int j, int n) {
        this->i = i;
        this->j = j;
        this->lable = n;
    }
     friend ostream& operator << (ostream&os,const Peak& v){
         os << "( " << v.i << " - " << v.j << " )";
	         return os;
      }
    
};
class Monster {
private:
    Animation MWalkLeft;
    Animation MWalkRight;
    Animation MWalkFront;
    Animation MWalkBack;
    vector<Peak> vertices;
    vector<vector<pair<int,int>>> adj; // {đỉnh kề, trọng số}
    double x = 320;
    double y = 320;
    double v = 0;

    void walkLeft(RenderWindow &Window) {
        MWalkLeft.begin2(x,y);
        if(MWalkLeft.f>MWalkLeft.fcount) {
            MWalkLeft.f=0;
            }
        Window.draw(MWalkLeft.explosion);
    }
    void walkRight(RenderWindow &Window) {
           MWalkRight.begin2(x,y);
         if(MWalkRight.f>MWalkRight.fcount) {
             MWalkRight.f=0;
            }
        Window.draw(MWalkRight.explosion);
     }
    void walkFront(RenderWindow &Window) {
        MWalkFront.begin2(x,y);
        if(MWalkFront.f>MWalkFront.fcount) {
            MWalkFront.f=0;
            }
        Window.draw(MWalkFront.explosion);
    }
    void walkBack(RenderWindow &Window) {
        MWalkBack.begin2(x,y);
        if(MWalkBack.f>MWalkBack.fcount) {
            MWalkBack.f=0;
            }
        Window.draw(MWalkBack.explosion);
    }
    
    int getN(const vector<Peak>&v, const int &i, const int &j) {
        for(auto k : v) {
            if(k.i==i && k.j == j) {
                return k.lable;
            }
        }
    }
    Peak getV(const vector<Peak>&v,const int& n) {
    for(auto k : v) {
        if(k.lable==n) {
            return k;
        }
    }
    } 
  
   
   int dijkstra(vector<vector<pair<int,int>>> &adj, int &source, int &size, int &target, int *path) {
        int *distance = new int[size]();
        bool *unvisited = new bool[size];
            for(int i = 0; i < size; i++) {
                unvisited[i] = true;
                distance[i] = 10000;
            }
        distance[source] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q; // { khoảng cách đến đỉnh đó, đinh} ;
    // < khoang cách, đỉnh nguồn đến đó>
    Q.push({0,source});
    while(!Q.empty()) {
        pair<int,int> top = Q.top();
        Q.pop();
        int u = top.second; // đinh
        int w  = top.first;
        if(u == target) {
            return distance[u];
        } 
        if(unvisited[u] == true) {
            unvisited[u] = false;
            for(auto i : adj[u]) {
                int v = i.first;
                int weight =  i.second;
                if(distance[u] + weight < distance[v] ) {
                    distance[v] = distance[u] + weight;
                    Q.push({distance[v],v});
                    path[v] = u;
                }
            } 
        }
    }
    delete[] distance;
    delete[] unvisited;
    return -1;
} 

public:
    void setPositionMons(double x, double y) {
        this->x = x;
        this->y = y;
    }
    
     void setX_Mons(double x) {
        this->x=this->x+x;
    }
    void setY_Mons(double x) {
        this->y=x;
    }
    void setV(double v){
        this->v=v;
    }
    double getX_Mons(){
        return x;
    }
    double getY_Mons(){
        return y;
    }
    double getV(){
        return v;
    }
    bool notWalk = true;
    bool isLeft = false;
    bool isRight =  false;
    bool isFront = false;
    bool isBack = false;
    
    Monster(string L, string R , string F, string B, double x, double y,Map &m, bool isNotWalk) {
        this->MWalkLeft.setani(0,0.01,4,L,64,64,0);
        this->MWalkRight.setani(0,0.01,4,R,64,64,0);
        this->MWalkFront.setani(0,0.01,4,F,64,64,0);
        this->MWalkBack.setani(0,0.01,4,B,64,64,0);
        this->x= x;
        this->y = y;
        setVertex(m);
        this->notWalk = isNotWalk;
    }
    void setVertex(Map &m) {
        int **map ;
        vertices.clear();
        adj.clear();
        map = m.getMap();
        int n = 0;
        for(int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j++) {
                if(map[i][j]!=1&&map[i][j]!=2) { // khi khác 1 và 2
                    vertices.push_back(Peak(i,j,n++));
                }
            }
         }
         adj.resize(vertices.size());
        
         for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j++) {
                if (map[i][j]!=1 && map[i][j]!=2) {
                    if(map[i][j+1]!=1 &&map[i][j+1]!=2) {
                        adj[getN(vertices,i,j)].push_back({getN(vertices,i,j+1),1});
                        adj[getN(vertices,i,j+1)].push_back({getN(vertices,i,j),1});
                    }
                    if(map[i+1][j]!=1 &&map[i+1][j]!=2)  {
                        adj[getN(vertices,i +1 ,j)].push_back({getN(vertices,i,j),1});
                        adj[getN(vertices,i,j)].push_back({getN(vertices,i + 1,j),1});
                    }
                }
            }
        }
    }
    void monsterMove(Map &mapp){ // di chuyển ngẫu nhiên
        int **map;
        map = mapp.getMap();
        notWalk = false;
                if(map[(int)(getY_Mons()/64)+1][(int)((getX_Mons()+mapp.getX())/64)]!=0&&isBack ==true&&(int)(getY_Mons())%64==0
                &&map[(int)(getY_Mons()/64)+1][(int)((getX_Mons()+mapp.getX())/64)]!=3) {
                        isBack = false;
                        int k = random(3,1);
                        if(k==1&&map[(int)(getY_Mons()/64)][(int)((getX_Mons()+mapp.getX())/64)+1]==0)  isLeft =  true; 
                        else if(k==2&&map[(int)(getY_Mons()/64)][(int)((getX_Mons()+mapp.getX())/64)-1]==0) isRight=true;
                        else  isFront =  true; 
                   
                    }              
                if(map[(int)(getY_Mons()/64)-1][(int)((getX_Mons()+mapp.getX())/64)] != 0&& isFront == true&&(int)(getY_Mons())%64==0
                &&map[(int)(getY_Mons()/64)-1][(int)((getX_Mons()+mapp.getX())/64)] !=3 ) {
                        isFront = false;

                        int k = random(3,1);
                        if(k==1&&map[(int)(getY_Mons()/64)][(int)((getX_Mons()+mapp.getX())/64)+1]==0)  isLeft =  true; 
                        else if(k==2&&map[(int)(getY_Mons()/64)][(int)((getX_Mons()+mapp.getX())/64)-1]==0) isRight=true;
                        else  isBack =true;
                      
                    }  
                if(map[(int)(getY_Mons()/64)][(int)((getX_Mons()+mapp.getX())/64)-1]!=0&&(int)(getX_Mons()+mapp.getX())%64==0&&isRight==true
                &&map[(int)(getY_Mons()/64)][(int)((getX_Mons()+mapp.getX())/64)-1] != 3) {
                        isRight = false;
                        int k = random(3,1);
                        if(k==1&&map[(int)(getY_Mons()/64)-1][(int)((getX_Mons()+mapp.getX())/64)]==0)  isFront =  true; 
                        else if(k==2&&map[(int)(getY_Mons()/64)+1][(int)((getX_Mons()+mapp.getX())/64)]==0) isBack=true;
                        else  isLeft =true;
                        
                    }
                if(map[(int)(getY_Mons()/64)][(int)((getX_Mons()+mapp.getX())/64)+1]!=0&&(int)(getX_Mons()+mapp.getX())%64==0&&isLeft==true
                &&map[(int)(getY_Mons()/64)][(int)((getX_Mons()+mapp.getX())/64)+1] != 3) {
                        isLeft =  false; 
                        int k = random(3,1);
                        if(k==1&&map[(int)(getY_Mons()/64)-1][(int)((getX_Mons()+mapp.getX())/64)]==0)  isFront =  true; 
                        else if(k==2&&map[(int)(getY_Mons()/64)+1][(int)((getX_Mons()+mapp.getX())/64)]==0) isBack =true;
                        else  isRight =true;
                    }
    }
    void getMinPath(Map &m, Character &p,RenderWindow &window) {// di chuyển đuổi theo người
        int **map ;
        map = m.getMap();
      //  int n=0;
       // setVertex(m);
        int * path = new int[vertices.size()];
        int source; // bắt đầu vị trí người chơi
        for ( int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j++) {
                if(map[i][j]==3) {
                    source = getN(vertices,i,j);
                    break;
                }
            }
        }
        int target; // đích đến
        int i_mons = 0;
        int j_mons = 0;
        int size = vertices.size();
        int weight ;
             i_mons = (int)(getY_Mons()/64);
             j_mons = (int)((getX_Mons()+m.getX())/64);
            target = getN(vertices,i_mons,j_mons);

            if(target ==  source) {
                weight = 0;
                isGameOver = true;
                }
            else weight =  dijkstra(adj,source,size,target,path);
           // cout << weight <<endl;
        if(weight != -1) {
                 int pre ;// bước đi kế tiếp
                pre  = path[target];
                Peak vertex;
               vertex = getV( vertices, pre);
             if(j_mons > vertex.j) {
                     notWalk =  false;
                     isRight = true;
                     isFront = false;
                    isLeft = false;
                    isBack = false;
             }
             if(i_mons > vertex.i) {
                 notWalk =  false;
                 isRight = false;
                 isLeft = false;
                     isBack = false;
                 isFront  = true;
             }
             if(j_mons < vertex.j) {
                     notWalk =  false;
                     isRight = false;
                     isFront = false;
                     isLeft = true;
                     isBack = false;
             }
             if(i_mons < vertex.i) {
                 notWalk =  false;
                 isRight = false;
                 isLeft = false;
                 isBack = true;
                 isFront  = false;
          }
        }
        else {
                 notWalk =  true;
                 isRight = false;
                 isLeft = false;
                 isBack = false;
                 isFront  = false;
        }
       
         for(int i = 0; i<row; i++) {
            delete []map[i]; }
            delete []map;
            delete []path;
    }
    void displayMonster(RenderWindow &window) {
            if(isLeft ==true) {
                walkLeft(window);
                x= x + 0.25;
                v = v + 0.25;
                 if(v==64) {
                  notWalk=true;
                    v=0; }
            }
            else if(isRight == true ) {
                walkRight(window);
                x= x - 0.25;
                v = v + 0.25;
                if(v==64) {
                    notWalk=true;
                    v=0; }
            }
            else if(isFront == true ) {
                walkBack(window);
                y= y - 0.25;
                v = v + 0.25;
                if(v==64) {
                    notWalk=true;
                    v=0; }
                }
            else if(isBack == true ) {
                walkFront(window);
                y= y + 0.25;
                v = v + 0.25;
                if(v==64) {
                  notWalk=true;
                    v=0; }
            }
            else if(notWalk == true) {
                walkFront(window);
            }
    }
    void monsterKill(Map &m) { // quái giết người
        int **map;
        map = m.getMap();
        if(map[(int)(getY_Mons()/64)][(int)((getX_Mons()+m.getX())/64)] == 3) {
            isGameOver = true; 
        }
    }
};
 class Boom{
private:
    Animation  boom;
    Animation  explosion;
    BackGround flameRight;
    BackGround flameLeft;
    BackGround flameTop;
    BackGround flameBottom;

    BackGround flameRightx2;
    BackGround flameLeftx2;
    BackGround flameTopx2;
    BackGround flameBottomx2;

    BackGround flameMid;
    Clock clockBoom;//đo thời gian từ lúc đặt bom đén khi nổ;
    double x_Boom;
    double y_Boom;
public:
    Boom(){
        boom.setani(0,0.01,3,"boom.png",64,64,0);
        explosion.setani(0,0.03,12,"explosion.png",128,128,0);
        flameRight.setBackGround("flameRight.png");
        flameLeft.setBackGround("flameLeft.png");
        flameTop.setBackGround("flame.png");
        flameBottom.setBackGround("flameBack.png");

        flameRightx2.setBackGround("flameRightx2.png");
        flameLeftx2.setBackGround("flameLeftx2.png");
        flameTopx2.setBackGround("flamex2.png");
        flameBottomx2.setBackGround("flameBackx2.png");

        flameMid.setBackGround("midFlame.png");

    }
    bool isSetBoom = false;
    bool isExplose = false;
    bool isFlameLeft = true;
    bool isFlameRight = true;
    bool isFlameTop = true;
    bool isFlameBottom = true;

    void setBoom(RenderWindow &window, Map &m){
        int ** map ;
        map =  m.getMap();
        int x_first = m.getX();
        boomSolve(m);
        Time timesBoom=clockBoom.getElapsedTime();
        int timeToExPlo=timesBoom.asSeconds();
        if(timeToExPlo<2) {
            boom.begin(x_Boom,y_Boom);
            if(boom.f>=boom.fcount) boom.f=0;
            window.draw(boom.explosion);
        }
        else {
            isExplose = true;
            if(!isPowerX2) {
                    if(map[(int)getBoomY()/64][(int)((getBoomX()+x_first)/64)-1]==2) {
                        int item = random(10,1);
                        if(item == 4 || item ==5 || item ==6) {
                         m.setMap((int)getBoomY()/64,(int)((getBoomX()+x_first)/64)-1,item); }
                        else {
                            m.setMap((int)getBoomY()/64,(int)((getBoomX()+x_first)/64)-1,0);
                        }
                     }
                    if(map[(int)getBoomY()/64][(int)((getBoomX()+x_first)/64)+1]==2) {
                     int item = random(10,1);
                        if(item == 4 || item ==5 || item ==6) {
                         m.setMap((int)getBoomY()/64,(int)((getBoomX()+x_first)/64)+1,item); }
                        else {
                            m.setMap((int)getBoomY()/64,(int)((getBoomX()+x_first)/64)+1,0);
                        }
                    }
                    if(map[(int)(getBoomY()/64)-1][(int)((getBoomX()+x_first)/64)]==2) {
                         int item = random(10,1);
                        if(item == 4 || item ==5 || item ==6) {
                         m.setMap((int)(getBoomY()/64)-1,(int)((getBoomX()+x_first)/64),item); }
                        else {
                            m.setMap((int)(getBoomY()/64)-1,(int)((getBoomX()+x_first)/64),0);
                        }
                    }
                    if(map[(int)(getBoomY()/64)+1][(int)((getBoomX()+x_first)/64)]==2) {
                         int item = random(10,1);
                        if(item == 4 || item ==5 || item ==6) {
                         m.setMap((int)(getBoomY()/64)+1,(int)((getBoomX()+x_first)/64),item); }
                        else {
                            m.setMap((int)(getBoomY()/64)+1,(int)((getBoomX()+x_first)/64),0);
                        }
                    }
            }
            else {
                    if(map[(int)getBoomY()/64][(int)((getBoomX()+x_first)/64)-1]==2) {
                         int item = random(10,1);
                        if(item == 4 || item ==5 || item ==6)  m.setMap((int)getBoomY()/64,(int)((getBoomX()+x_first)/64)-1,item); 
                        else   m.setMap((int)getBoomY()/64,(int)((getBoomX()+x_first)/64)-1,0);
                    }
                    if(map[(int)getBoomY()/64][(int)((getBoomX()+x_first)/64)+1]==2) {
                         int item = random(10,1);
                        if(item == 4 || item ==5 || item ==6)  m.setMap((int)getBoomY()/64,(int)((getBoomX()+x_first)/64) + 1,item); 
                        else   m.setMap((int)getBoomY()/64,(int)((getBoomX()+x_first)/64) + 1,0);
                    } 
                    if(map[(int)(getBoomY()/64)-1][(int)((getBoomX()+x_first)/64)]==2) {
                        int item = random(10,1);
                        if(item == 4 || item ==5 || item ==6) m.setMap((int)(getBoomY()/64)-1,(int)((getBoomX()+x_first)/64),item); 
                        else  m.setMap((int)(getBoomY()/64)-1,(int)((getBoomX()+x_first)/64),0);   
                    } 
                    if(map[(int)(getBoomY()/64)+1][(int)((getBoomX()+x_first)/64)]==2) {
                        int item = random(10,1);
                        if(item == 4 || item ==5 || item ==6) m.setMap((int)(getBoomY()/64)+1,(int)((getBoomX()+x_first)/64),item); 
                        else  m.setMap((int)(getBoomY()/64)+1,(int)((getBoomX()+x_first)/64),0);   
                        }
               
                int yFront = (int)((getBoomX()+x_first)/64) + 2;
                int yBack = (int)((getBoomX()+ x_first)/64) - 2;
                int xFront = (int)(getBoomY()/64) - 2;
                int xBack = (int)(getBoomY()/64) + 2;
               
                if(yFront > col) yFront = yFront - 1;
                if(yBack < 0) yBack =  yBack + 1;
                if(xBack >= row) xBack = xBack - 1;
                if(xFront < 0 ) xFront = xFront + 1;
                    if(map[(int)getBoomY()/64][yBack]==2 && isFlameLeft ) {
                            int item = random(10,1);
                          if(item == 4 || item ==5 || item ==6)  m.setMap((int)getBoomY()/64,yBack,item);
                          else m.setMap((int)getBoomY()/64,yBack,0);
                    } 
                    if(map[(int)getBoomY()/64][yFront]==2 && isFlameRight) {
                           int item = random(10,1);
                          if(item == 4 || item ==5 || item ==6)  m.setMap((int)getBoomY()/64,yFront,item);
                          else  m.setMap((int)getBoomY()/64,yFront,0);
                    }
                    if(map[xFront][(int)((getBoomX()+x_first)/64)]==2 && isFlameTop) {
                         int item = random(10,1);
                          if(item == 4 || item ==5 || item ==6) m.setMap(xFront,(int)((getBoomX()+x_first)/64),item);
                          else  m.setMap(xFront,(int)((getBoomX()+x_first)/64),0);
                    } 
                    if(map[xBack][(int)((getBoomX()+x_first)/64)]==2 && isFlameBottom) {
                         int item = random(10,1);
                          if(item == 4 || item ==5 || item ==6) m.setMap(xBack,(int)((getBoomX()+x_first)/64),item);
                          else  m.setMap(xBack,(int)((getBoomX()+x_first)/64),0);
                    } 
            }
            explosion.begin(x_Boom-32,y_Boom-64);

            flameRight.setPosition(x_Boom+64,y_Boom);
            flameLeft.setPosition(x_Boom-64,y_Boom);
            flameTop.setPosition(x_Boom,y_Boom-64);
            flameBottom.setPosition(x_Boom,y_Boom+64);

            flameRightx2.setPosition(x_Boom+64,y_Boom);
            flameLeftx2.setPosition(x_Boom-128,y_Boom);
            flameTopx2.setPosition(x_Boom,y_Boom-128);
            flameBottomx2.setPosition(x_Boom,y_Boom+64);

            flameMid.setPosition(x_Boom,y_Boom);

            if(explosion.f>=explosion.fcount){
                explosion.f=0;
                isSetBoom=false;
                isFlameLeft=true;
                isFlameRight=true;
                isFlameTop=true;
                isFlameBottom=true;
                isExplose=false;
            }
             window.draw(flameMid.getSprite());
                     if(map[(int)getBoomY()/64][(int)((getBoomX()+ x_first)/64)-1] == 3) isGameOver = true;
                     if(map[(int)getBoomY()/64][(int)((getBoomX()+x_first)/64)+1] == 3) isGameOver = true;
                     if(map[(int)(getBoomY()/64)-1][(int)((getBoomX()+x_first)/64)] == 3) isGameOver = true;
                     if(map[(int)(getBoomY()/64)+1][(int)((getBoomX()+x_first)/64)] == 3) isGameOver = true; 
                     if(map[(int)(getBoomY()/64)][(int)((getBoomX()+x_first)/64)] == 3) isGameOver = true; 
            if(isPowerX2 == false) {
                if (isFlameRight==true) window.draw(flameRight.getSprite());
                if (isFlameLeft==true)  window.draw(flameLeft.getSprite());
                if (isFlameTop==true) window.draw(flameTop.getSprite());
                if (isFlameBottom==true) window.draw(flameBottom.getSprite());                    
            }
            else {
                int yFront = (int)((getBoomX()+x_first)/64) + 2;
                int yBack = (int)((getBoomX()+ x_first)/64) - 2;
                int xFront = (int)(getBoomY()/64) - 2;
                int xBack = (int)(getBoomY()/64) + 2;
                    //cout << xBack << " " << xFront << endl;
                if(yFront > col) yFront = yFront - 1;
                if(yBack < 0) yBack =  yBack + 1;
                if(xBack >= row) xBack = xBack - 1;
                if(xFront < 0 ) xFront = xFront + 1;
                
                    if (isFlameRight==true && map[(int)getBoomY()/64][yFront] == 1) window.draw(flameRight.getSprite());
                    if (isFlameLeft==true && map[(int)getBoomY()/64][yBack ]== 1)  window.draw(flameLeft.getSprite());
                    if (isFlameTop==true && map[xFront][(int)((getBoomX()+x_first)/64)] == 1) window.draw(flameTop.getSprite());
                    if (isFlameBottom==true && map[xBack][(int)((getBoomX()+x_first)/64)] == 1) window.draw(flameBottom.getSprite());
                
                    if (isFlameRight==true && map[(int)getBoomY()/64][yFront] != 1) window.draw(flameRightx2.getSprite());
                    if (isFlameLeft==true && map[(int)getBoomY()/64][yBack] != 1)  window.draw(flameLeftx2.getSprite());
                    if (isFlameTop==true && map[xFront][(int)((getBoomX()+x_first)/64)] != 1) window.draw(flameTopx2.getSprite());
                    if (isFlameBottom==true && map[xBack][(int)((getBoomX()+x_first)/64)] != 1) window.draw(flameBottomx2.getSprite());

                    if (isFlameRight==true && map[(int)getBoomY()/64][yFront] == 3) isGameOver = true;
                    if (isFlameLeft==true && map[(int)getBoomY()/64][yBack ]== 3)   isGameOver = true;
                    if (isFlameTop==true && map[xFront][(int)((getBoomX()+x_first)/64)] == 3)  isGameOver = true;
                    if (isFlameBottom==true && map[xBack][(int)((getBoomX()+x_first)/64)] == 3)  isGameOver = true;
            }
             window.draw(explosion.explosion);       
        }
        
    }
void boomSolve(Map &m) {
        int ** map ;
        int x_first = m.getX();
        map =m.getMap();           
                     if(map[(int)getBoomY()/64][(int)((getBoomX()+ x_first)/64)-1]==1) isFlameLeft=false;
                     if(map[(int)getBoomY()/64][(int)((getBoomX()+x_first)/64)+1]==1) isFlameRight=false;
                     if(map[(int)(getBoomY()/64)-1][(int)((getBoomX()+x_first)/64)]==1) isFlameTop=false;
                     if(map[(int)(getBoomY()/64)+1][(int)((getBoomX()+x_first)/64)]==1) isFlameBottom=false;  
    }
    void reStartClock(){
        clockBoom.restart();
    }
    void setBoomX(double x) {
        x_Boom=x;
    }
    void setBoomY(double y) {
        y_Boom=y;
    }
    void moveBoomX(double x) {
        this->x_Boom=this->x_Boom+x;
    }
    double getBoomX() {
        return x_Boom;
    }
    double getBoomY() {
        return y_Boom;
    }
    void killMonster(vector<Monster> &mon) {
        for(int i = 0; i < mon.size(); i++) {
            double xMons = mon[i].getX_Mons();
            double yMons = mon[i].getY_Mons();
            if(isExplose == true) {
                if(xMons == x_Boom && y_Boom == yMons) {
                    mon.erase(mon.begin() + i);
                }
                if(xMons == x_Boom + 64 && y_Boom == yMons) {
                    mon.erase(mon.begin() + i);
                }
                if(xMons == x_Boom -64 && y_Boom == yMons) {
                    mon.erase(mon.begin() + i);
                }
                if(xMons == x_Boom && y_Boom + 64 == yMons ) {
                    mon.erase(mon.begin() + i);
                }
                if(xMons == x_Boom && y_Boom - 64 == yMons) {
                    mon.erase(mon.begin() + i);
                }
                if(isPowerX2 == true) {
                    if(xMons == x_Boom + 128 && y_Boom == yMons) {
                    mon.erase(mon.begin() + i);
                    }
                    if(xMons == x_Boom - 128 && y_Boom == yMons) {
                        mon.erase(mon.begin() + i);
                    }
                    if(xMons == x_Boom && y_Boom + 128 == yMons ) {
                        mon.erase(mon.begin() + i);
                    }
                    if(xMons == x_Boom && y_Boom - 128 == yMons ) {
                        mon.erase(mon.begin() + i);
                    }
                }
            }
        }
    }
};
void catchEvent(Event &event, RenderWindow &window, Character &player, Map &map, Boom &boom, Boom &boom2, vector<Monster> &m,vector<Monster> &m2) {
            if (event.type== Event:: KeyPressed&&event.key.code==Keyboard::Right&&player.isWalk==false){
                player.isRight=true;
                player.isLeft=false;
                player.isFront=false;
                player.isBack=false;
                map.haveRunRight=true;      
            }           
            if (event.type== Event:: KeyPressed&&event.key.code==Keyboard::Left&&player.isWalk==false){
                player.isLeft=true;
                player.isRight=false;
                player.isFront=false;
                player.isBack=false;
                map.haveRunLeft=true;
            }
            if (event.type== Event:: KeyPressed&&event.key.code==Keyboard::Up&&player.isWalk==false){
                player.isFront=false;
                player.isLeft=false;
                player.isRight=false;
                player.isBack=true;
                map.haveRunUp=true;       
            }   
            if (event.type == Event:: KeyPressed && event.key.code==Keyboard::Down && player.isWalk==false){
                player.isBack=false;
                player.isLeft=false;
                player.isFront=true;
                player.isRight=false;
                map.haveRunDown=true;              
            }
            if (event.type == Event:: KeyPressed && event.key.code==Keyboard::Right){
               if(map.getX()!=896) {
                  map.setX(4);
                  player.setX_char(-4); 
                  boom.moveBoomX(-4);
                  boom2.moveBoomX(-4);
                  for(int i = 0; i < m.size(); i++) {
                  m[i].setX_Mons(-4);
                  }
                  for(int i = 0; i < m2.size(); i++) {
                  m2[i].setX_Mons(-4);
                  }
                  }
            }
            if (event.type== Event:: KeyPressed&&event.key.code==Keyboard::Left){
                if(map.getX()!=0) {
                    map.setX(-4);
                    player.setX_char(4);
                    boom.moveBoomX(4);
                    boom2.moveBoomX(4);
                    for(int i = 0; i < m.size(); i++) {
                    m[i].setX_Mons(4);
                     }
                     for(int i = 0; i < m2.size(); i++) {
                    m2[i].setX_Mons(4);
                     }
                }
            }
            if (event.type== Event:: KeyPressed&&event.key.code==Keyboard::Space && player.isWalk == false) {
                if(boom.isSetBoom == false) {
                boom.reStartClock();
                boom.setBoomX((int)player.getX_char() );
                boom.setBoomY((int)player.getY_char() );
                boom.isSetBoom=true;
                player.isAttack =true;
                }
                else if(boom.isSetBoom == true && boom2.isSetBoom == false && isBomx2 == true) {
                boom2.reStartClock();
                boom2.setBoomX((int)player.getX_char() );
                boom2.setBoomY((int)player.getY_char() );
                boom2.isSetBoom=true;
                player.isAttack =true;
                }
            }
            if(event.type== Event ::MouseButtonPressed&&event.key.code==Mouse::Left){
             Vector2i localPosition = Mouse::getPosition(window);
             cout<<localPosition.x<<' '<<localPosition.y<<endl;
           }
}
Text setText(Font &font,string s,int size,int Color1,int Color2,int Color3,int x,int y){
    Text game;
    game.setFont(font);
    game.setString(s);
    game.setCharacterSize(size);
    game.setFillColor(Color(Color1,Color2,Color3));
    game.setOutlineThickness(1.f);
    game.setOutlineColor(Color::Black);
    game.setPosition(x,y);
return game;
}
void manageItem(bool &isActive, Clock &clock, int &timesEffect, Text &info, Font &font, int col1, int col2, int col3, int xPosition) { // thời gian giới hạn 
        if(isActive == false) {
            clock.restart();
            info = setText(font,"0",20,col1,col2,col3,xPosition,850);
        }
        else  {
            Time t = clock.getElapsedTime();
            int times = t.asSeconds();
            info = setText(font,to_string(timesEffect - times),20,col1,col2,col3,xPosition,850);
            if(times > timesEffect) {
                isActive = false;
                timesEffect = 5;
             }
        }
}
void setPositionMonster(vector<Monster> &m, vector<Monster> &m2) {
    m[0].setPositionMons(1152,64);  m2[0].setPositionMons(192,704);
    m[1].setPositionMons(896,704);  m2[1].setPositionMons(832,192);
    m[2].setPositionMons(704,576);  m2[2].setPositionMons(320,320);
    m[3].setPositionMons(768,64);   m2[3].setPositionMons(1792,64);
    m[4].setPositionMons(960,320);  m2[4].setPositionMons(1856,704);
    m[5].setPositionMons(256,704);  m2[5].setPositionMons(1984,448);
    m[6].setPositionMons(832,384);  m2[6].setPositionMons(1728,320);
    m[7].setPositionMons(1280,576); m2[7].setPositionMons(1280,448);
    m[8].setPositionMons(256,192);  m2[8].setPositionMons(1216,192);
    m[9].setPositionMons(2112,64);  m2[9].setPositionMons(1792,192);
                                    m2[10].setPositionMons(448,64);
                                    m2[11].setPositionMons(1600,384);
                                    m2[12].setPositionMons(2112,640);
}
int main(){
       RenderWindow window(VideoMode(1280+64, 640+64+64+64+64), "jjj!");
       Map map;
       Font font;
       font.loadFromFile("Mermaid Babies.ttf");
       Boom boom;
       Boom boom2;
       Clock ClockItemX2Boom;//đo thời gian item boom x2;
       Clock ClockSpeedX2 ;// đo thời gian item speed up;
       Clock ClockPowerX2;
       Text infoItemBoom  = setText(font,"X2Boom: ",20,242,75,75,50,850);
       Text infoItemSpeed  = setText(font,"X2Speed: ",20,56,130, 240,350,850);
       Text infoItemPower  = setText(font,"X2Power: ",20,250,176,0,650,850);
       Text infoGameOver = setText(font,"Game Over", 90, 0, 51, 0, 450, 300);
       Text infoTimeBoom ;
       Text infoTimePower ;
       Text infoTimeSpeed ;
       Character player;
       player.setAnimation("idleLeft.png","idleRight.png","idleFront.png","idleBack.png","attackLeft.png","attackRight.png","attackFront.png",
       "attackBack.png","walkLeft.png","walkRight.png","walkFront.png","walkBack.png");
      Monster monster("MwalkLeft.png","MwalkRight.png","MwalkFront.png","MwalkBack.png",704,576,map,true);
      Monster monster2("walkRight2.png","walkLeft2.png","walkFront2.png","walkBack2.png",320,320,map,true);
      monster2.isRight = true;
      vector<Monster> monsters;
      vector<Monster> monsters2;
      for(int i = 0; i < 13; i++) {
         monsters2.push_back(monster2);
      }
        for(int i = 0; i < 10; i++) {
        monsters.push_back(monster);
         }
         setPositionMonster(monsters,monsters2);

       while (window.isOpen())
    {
        manageItem(isBomx2,ClockItemX2Boom,timex2,infoTimeBoom,font,242,75,75,150);
        manageItem(isSpeedUp,ClockSpeedX2,timeSpeedUp,infoTimeSpeed,font,56,130,240,450);
        manageItem(isPowerX2,ClockPowerX2,timex2Power,infoTimePower,font,250,176,0,750);

         Event event;       
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) window.close();           
            if(isGameOver == false) {
                catchEvent(event,window,player,map,boom,boom2,monsters,monsters2);
            }
        }

        window.clear(Color::Black);

        map.drawMap(window,player);
        if(boom.isSetBoom==true) { // đặt bom
            boom.setBoom(window,map); 
            boom.killMonster(monsters);
            boom.killMonster(monsters2);
            }
        if(boom2.isSetBoom==true) { // đặt bom
            boom2.setBoom(window,map); 
            boom2.killMonster(monsters);
            boom2.killMonster(monsters2);
        }
        if((boom.isExplose == true || boom2.isExplose == true) && map.isSetVertex == false) { // reset đồ thị
            map.isSetVertex = true;
            for(int i = 0; i < monsters.size(); i++) {
                    monsters[i].setVertex(map);
                }
        }
        else if ((boom.isExplose == false && boom2.isExplose == false)) {
            map.isSetVertex = false;// cout<<"b";
        }
        player.displayCharacter(window);

       for(int i = 0; i < monsters.size(); i++) { // quái di chuyển theo người 
           if(monsters[i].notWalk == true ) {
             monsters[i].getMinPath(map,player,window); 
            }
            monsters[i].displayMonster(window);
       }
       for(int i = 0; i < monsters2.size(); i++) {// quái loại 2 đi chuyển ngẫu nhiên
            if(monsters2[i].notWalk == true) monsters2[i].monsterMove(map);
            monsters2[i].monsterKill(map);
            monsters2[i].displayMonster(window);
       }
        window.draw(infoItemBoom);
        window.draw(infoItemPower);
        window.draw(infoItemSpeed);
        window.draw(infoTimeBoom);
        window.draw(infoTimeSpeed);
        window.draw(infoTimePower);
    if(isGameOver == true) {
        window.draw(infoGameOver);
    }

        window.display();   
    }
}