#pragma once
#include <iostream>

using namespace std;

class Shape
{
public:
    virtual void show() const = 0;
    virtual void save(FILE* file, const char* filename) const = 0;
    virtual void load(FILE* file, const char* filename) = 0;
    virtual ~Shape() {}
};