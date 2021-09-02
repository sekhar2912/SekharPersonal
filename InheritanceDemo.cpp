#include <iostream>
#include <memory>
#include <numeric>
#include <vector>
#include <cmath>
using namespace std;

class Shape
{
public:
    virtual int GetArea() = 0;
};

class Rectangle : public Shape
{
private:
    int height{0};
    int width{0};

public:
    Rectangle(int h = 0, int w =0): height(h),width(w) {}
    Rectangle(Rectangle& r): height(r.height),width(r.width) {}
    Rectangle& operator=(Rectangle& r)
    {
        height = r.height;
        width = r.width;
        return *this;
    }
    ~Rectangle() {}
    int GetArea()
    {
       
        return height * width;
    }
};
class Triangle : public Shape
{
private:
    int height{0};
    int width{0};

public:
    Triangle(int h = 0, int w =0): height(h),width(w) {}
    Triangle(Triangle& r): height(r.height),width(r.width) {}
    Triangle& operator=(Triangle& r)
    {
        height = r.height;
        width = r.width;
        return *this;
    }
    ~Triangle() {}

    int GetArea()
    {
        
        return (height * width)/2;
    }

};

class Circle : public Shape
{
private:
int radius{0};
public:
    Circle(int r = 0): radius(r){}
    Circle(Circle& r): radius(r.radius){}
    Circle& operator=(Circle& r)
    {
        radius = r.radius;
        return *this;
    }
    ~Circle() {}

    int GetArea()
    {
        
        return (ceil(3.14 * radius * radius));
    }
};

int main() {
    int rectangleHeight = 0, rectangleWidth = 0;
    int triangleHeight = 0, triangleWidth = 0;
    int circleRadius = 0;

    std::cin >> rectangleHeight >> rectangleWidth >> triangleHeight >> triangleWidth >> circleRadius;

    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.emplace_back(std::make_unique<Rectangle>(rectangleHeight, rectangleWidth));
    shapes.emplace_back(std::make_unique<Triangle>(triangleHeight, triangleWidth));
    shapes.emplace_back(std::make_unique<Circle>(circleRadius));

    const int totalArea = std::accumulate(shapes.begin(), shapes.end(), 0, [](int total, const auto& shape)
            { return total + shape->GetArea(); });
    std::cout << totalArea << "\n";

    return 0;
}