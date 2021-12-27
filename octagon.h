#ifndef _OCTAGON_H
#define _OCTAGON_H


#include "figure.h"

struct octagon : figure {
private:
    point a1, a2, a3, a4, a5, a6, a7, a8;
public:
    point center() const override;
    void print(std::ostream&) const  override;
    void print_file(std::ofstream&) const  override;
    double square() const override;
    octagon() = default;
    octagon(std::istream& is);
    octagon(std::ifstream& is);
};




#endif //OOP7_OCTAGON_H