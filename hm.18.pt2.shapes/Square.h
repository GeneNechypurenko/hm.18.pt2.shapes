#include "Shape.h"

class Square : public Shape
{
private:
    double x, y; 
    double side;

public:
    Square(double x, double y, double side);
    Square();

    void show() const override;
    void save(FILE* file, const char* filename) const override;
    void load(FILE* file, const char* filename) override;
};