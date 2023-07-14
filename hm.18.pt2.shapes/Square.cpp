#include "Square.h"

Square::Square(double x, double y, double side) 
    :
    x(x),
    y(y),
    side(side)
{}

Square::Square()
	:
	x(0),
	y(0),
	side(0)
{}

void Square::show() const
{
    cout
        << "______________" << endl
        << "Square: " << endl
        << "x = " << x << ";" << endl
        << "y = " << y << ";" << endl
        << "side = " << side << ";" << endl
        << "______________" << endl;
}

void Square::save(FILE* file, const char* filename) const
{
	fopen_s(&file, filename, "wb");

	if (file == nullptr)
	{
		cout << "Error file reading!" << endl;
		return;
	}

	fwrite(&x, sizeof(double), 1, file);
	fwrite(&y, sizeof(double), 1, file);
	fwrite(&side, sizeof(double), 1, file);

	fclose(file);
}

void Square::load(FILE* file, const char* filename)
{
	fopen_s(&file, filename, "rb");

	if (file == nullptr)
	{
		cout << "Error file reading!" << endl;
		return;
	}

	fread(&x, sizeof(double), 1, file);
	fread(&y, sizeof(double), 1, file);
	fread(&side, sizeof(double), 1, file);

	fclose(file);

	this->x = x;
	this->y = y;
	this->side = side;
}