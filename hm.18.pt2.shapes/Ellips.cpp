#include "Ellips.h"

Ellips::Ellips(double x, double y, double width, double height)
    :
    x(x),
    y(y),
    width(width),
    height(height)
{}

Ellips::Ellips()
    :
    x(0),
    y(0),
    width(0),
    height(0)
{}

void Ellips::show() const
{
    cout
        << "______________" << endl
        << "Ellips: " << endl
        << "x = " << x << ";" << endl
        << "y = " << y << ";" << endl
        << "width = " << width << ";" << endl
        << "height = " << height << ";" << endl
        << "______________" << endl;
}

void Ellips::save(FILE* file, const char* filename) const
{
    fopen_s(&file, filename, "wb");

    if (file == nullptr)
    {
        cout << "Error file reading!" << endl;
        return;
    }

    fwrite(&x, sizeof(double), 1, file);
    fwrite(&y, sizeof(double), 1, file);
    fwrite(&width, sizeof(double), 1, file);
    fwrite(&height, sizeof(double), 1, file);

    fclose(file);
}

void Ellips::load(FILE* file, const char* filename)
{
    fopen_s(&file, filename, "rb");

    if (file == nullptr)
    {
        cout << "Error file reading!" << endl;
        return;
    }

    fread(&x, sizeof(double), 1, file);
    fread(&y, sizeof(double), 1, file);
    fread(&width, sizeof(double), 1, file);
    fread(&height, sizeof(double), 1, file);

    fclose(file);

    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}