#ifndef AMINATION_H
#define AMINATION_H
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Animation
{
public:
    float f;
    float ani;
    float fcount;
    string a;
    int size;
    int height;
    int row;
    Texture ex;
    Sprite explosion;

    void setani(float f_,float ani_,float fcount_, string a_,int size_,int height_,int row_);
    
    void begin(int x,int y);
    void begin2(int x,int y);

};
 
void Animation::begin(int x,int y){
                 f+=ani;
                 explosion.setTexture(ex);
                 explosion.setTextureRect(IntRect(int(f)*size,row*height,size,height));
                 explosion.setPosition(x,y);  
                
}
void Animation::begin2(int x,int y){
            f+=ani;
            explosion.setTexture(ex);
            explosion.setTextureRect(IntRect(0,int(f)*size,size,height));
            explosion.setPosition(x,y);  
}
void Animation::setani(float f_,float ani_,float fcount_, string a_,int size_,int height_,int row_){
     f=f_;
     ani=ani_;
     fcount=fcount_;
     ex.loadFromFile(a_);
     size=size_;
     height=height_;
     row=row_;
}
#endif
             