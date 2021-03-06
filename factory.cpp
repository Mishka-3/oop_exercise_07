#include "factory.h"
#include "pentagon.h"
#include "hexagon.h"
#include "octagon.h"

std::shared_ptr<figure> factory::new_figure(std::istream &is) {
    std::string name;
    is >> name;
    if ( name == "p" ) {
        return std::shared_ptr<figure> ( new pentagon(is));
    } else if ( name == "h") {
        return std::shared_ptr<figure> ( new hexagon(is));
    } else if ( name == "o") {
        return std::shared_ptr<figure> ( new octagon(is));
    } else {
        throw std::logic_error("no such a figure\n");
    }
}
std::shared_ptr<figure> factory::new_figure_file(std::istream &is) {
    std::string name;
    is >> name;
    if ( name == "p" ) {
        return std::shared_ptr<figure> ( new pentagon(is));
    } else if ( name == "h") {
        return std::shared_ptr<figure> ( new hexagon(is));
    } else if ( name == "o") {
        return std::shared_ptr<figure> ( new octagon(is));
    } else {
        throw std::logic_error("no such a figure\n");
    }
}
