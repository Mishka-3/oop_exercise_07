#include "octagon.h"

#include <cmath>
#include "point.h"

point octagon::center() const {
    point p;
    p.x = (a1.x + a2.x + a3.x + a4.x + a5.x + a6.x + a7.x + a8.x) / 8;
    p.y = (a1.y + a2.y + a3.y + a4.y + a5.y + a6.y + a7.y + a8.y) / 8;
    return p;
}

void octagon::print(std::ostream& os) const {
    os << "o\n" << a1 << '\n' << a2 << '\n' << a3 << '\n' << a4 << '\n' << a5 << a6 << a7 << a8 << '\n';
}

void octagon::print_file(std::ofstream& of) const {
    of << "o\n" << a1 << '\n' << a2 << '\n' << a3 << '\n' << a4 << '\n' << a5 << a6 << a7 << a8 << '\n';
}

double octagon::square() const {
    return (-0.5) * ((a1.x * a2.y + a2.x * a3.y + a3.x * a4.y + a4.x * a5.y + a5.x * a6.y + a6.x * a7.y + a7.x * a8.y + a8.x * a1.y) - (a1.y * a2.x + a2.y * a3.x + a3.y * a4.x + a4.y * a5.x + a5.y * a6.x + a6.y * a7.x + a7.y * a8.x + a8.y * a1.x));
}

octagon::octagon(std::istream& is) {
    is >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8;
}

octagon::octagon(std::ifstream& is) {
    is >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8;
}