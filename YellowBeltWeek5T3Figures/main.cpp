#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <iomanip>

#include "Figure.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include "Rect.hpp"
#include "Test.hpp"

using namespace std;

shared_ptr<Figure> CreateFigure(istringstream& is)
{
    string type = "";
    uint32_t a = 0, b = 0, c = 0;

    is >> type;
    is >> a;

    if (type == "RECT")
    {
        is >> b;
        return make_shared<Rect>(a, b);
    }
    if (type == "TRIANGLE")
    {
        is >> b >> c;
        return make_shared<Triangle>(a, b, c);
    }

    return make_shared<Circle>(a);
}

int main() {
    runTests();

    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) 
    {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            figures.push_back(CreateFigure(is));
        }
        else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                    << current_figure->Name() << " "
                    << current_figure->Perimeter() << " "
                    << current_figure->Area() << endl;
            }
        }
    }

    return 0;
}