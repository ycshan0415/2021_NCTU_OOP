#include <cstdlib>
#include <iostream>
#define PI 3.14
using namespace std;

class Shape
{
protected:
    float volume;

public:
    Shape(){
        volume = 0;
    }
    virtual void computeVolume() = 0;
    void printVolume(){
        cout << volume << endl;
    }
};

class Cuboid : public Shape
{
    public:
        Cuboid(float a, float b, float c){
            len = a;
            wid = b;
            hei = c;
        }
        
    private:
        float len, wid, hei;
    
    virtual void computeVolume() override{
        volume = len * wid * hei;
    }
};

class Pyramid : public Shape
{
    public:
        Pyramid(float a, float h){
            area = a;
            height = h;
        }
        
    private:
        float area, height;
        
    virtual void computeVolume() override{
        volume = area * height * 1/3;          
    }
};
class Sphere : public Shape
{
    public:
        Sphere(float r){
            radius = r;
        }
        
    private:
        float radius;
        
    virtual void computeVolume() override{
        volume = 4.0/3.0 * radius * radius * radius * PI;            
    }
};

int main()
{
    float a, b, c;
    Shape *shape;

    cin >> a >> b >> c; // Enter the height and width of Rectangle
    Cuboid cub(a, b, c);

    cin >> a >> b; // Enter the bottom and height of Triangle
    Pyramid pyr(a, b);

    cin >> a; // Enter the radius of Circle
    Sphere sph(a);

    shape = &cub;
    shape->computeVolume();
    shape->printVolume();

    shape = &pyr;
    shape->computeVolume();
    shape->printVolume();

    shape = &sph;
    shape->computeVolume();
    shape->printVolume();

    return 0;
}