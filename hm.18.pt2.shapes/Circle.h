#include "Shape.h"

class Circle : public Shape
{
private:
    double x, y; 
    double radius;

public:
    Circle(double x, double y, double radius);
    Circle();

    void show() const override;
    void save(FILE* file, const char* filename) const override;
    void load(FILE* file, const char* filename) override;
};