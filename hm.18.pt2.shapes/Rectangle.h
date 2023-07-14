#include "Shape.h"

class Rectangle : public Shape
{
private:
    double x, y;
    double width, height;

public:
    Rectangle(double x, double y, double width, double height);
    Rectangle();

    void show() const override;
    void save(FILE* file, const char* filename) const override;
    void load(FILE* file, const char* filename) override;
};