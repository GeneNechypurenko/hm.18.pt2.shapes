#include "Circle.h"

Circle::Circle(double x, double y, double radius)
    :
    x(x),
    y(y),
    radius(radius)
{}

Circle::Circle()
    :
    x(0),
    y(0),
    radius(0)
{}

void Circle::show() const
{
    cout
        << "______________" << endl
        << "Circle: " << endl
        << "x = " << x << ";" << endl
        << "y = " << y << ";" << endl
        << "radius = " << radius << ";" << endl
        << "______________" << endl;
}

void Circle::save(FILE* file, const char* filename) const
{
    fopen_s(&file, filename, "wb");

    if (file == nullptr)
    {
        cout << "Error file reading!" << endl;
        return;
    }

    fwrite(&x, sizeof(double), 1, file);
    fwrite(&y, sizeof(double), 1, file);
    fwrite(&radius, sizeof(double), 1, file);

    fclose(file);
}

void Circle::load(FILE* file, const char* filename)
{
    fopen_s(&file, filename, "rb");

    if (file == nullptr)
    {
        cout << "Error file reading!" << endl;
        return;
    }

    fread(&x, sizeof(double), 1, file);
    fread(&y, sizeof(double), 1, file);
    fread(&radius, sizeof(double), 1, file);

    fclose(file);

    this->x = x;
    this->y = y;
    this->radius = radius;
}