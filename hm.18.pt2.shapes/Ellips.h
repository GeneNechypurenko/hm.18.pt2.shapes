#include "Shape.h"

class Ellips : public Shape
{
private:
    double x, y;
    double width, height;

public:
    Ellips(double x, double y, double width, double height);
    Ellips();

    void show() const override;
    void save(FILE* file, const char* filename) const override;
    void load(FILE* file, const char* filename) override;
};