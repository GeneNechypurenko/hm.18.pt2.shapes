#include <iostream>

#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ellips.h"

#define SIZE 4

using namespace std;

int main()
{
    //почему-то при работе с fseek корректно не читался файл,
    //                   все указывал верно,
    //пришлось сделать отдельные сейв файлы для каждой фигуры

    char square_save[_MAX_PATH] = "square_save.bin";
    char rectangle_save[_MAX_PATH] = "rectangle_save.bin";
    char circle_sacve[_MAX_PATH] = "circle_sacve.bin";
    char ellips_save[_MAX_PATH] = "ellips_save.bin";

    FILE* file = nullptr;

    Shape* shapes[SIZE];
    shapes[0] = new Square(0, 0, 5);
    shapes[1] = new Rectangle(1, 1, 4, 3);
    shapes[2] = new Circle(2, 2, 2);
    shapes[3] = new Ellips(3, 3, 6, 4);

    shapes[0]->save(file, "square_save.bin");
    shapes[1]->save(file, "rectangle_save.bin");
    shapes[2]->save(file, "circle_sacve.bin");
    shapes[3]->save(file, "ellips_save.bin");

    //for (int i = 0; i < SIZE; i++)
    //    shapes[i]->save(file, "save.bin"); //могло бы работать через цикл если бы fseek не подвел

    for (int i = 0; i < SIZE; i++)
        delete shapes[i];

    Shape* saveData[SIZE];
    saveData[0] = new Square();
    saveData[1] = new Rectangle();
    saveData[2] = new Circle();
    saveData[3] = new Ellips();

    saveData[0]->load(file, "square_save.bin");
    saveData[1]->load(file, "rectangle_save.bin");
    saveData[2]->load(file, "circle_sacve.bin");
    saveData[3]->load(file, "ellips_save.bin");

    //for (int i = 0; i < SIZE; i++)
    //    saveData[i]->load(file, "save.bin");

    for (int i = 0; i < SIZE; i++)
        saveData[i]->show();

    for (int i = 0; i < SIZE; i++)
        delete saveData[i];

    return 0;
}
