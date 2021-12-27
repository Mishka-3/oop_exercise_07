#include <iostream>
#include "factory.h"
#include "editor.h"

using namespace std;

void crt(editor& edit) {
    std::string tmp;
    std::cin >> tmp;
    edit.crt_doc(tmp);
}

void load(editor& edit) {
    std::string tmp;
    std::cin >> tmp;
    try {
        edit.load_doc(tmp);
    } catch (std::runtime_error& e) {
        std::cout << e.what();
    }
}

void save(editor& edit) {
    std::string tmp;
    try {
        edit.save_doc();
    } catch (std::runtime_error& e) {
        std::cout << e.what();
    }
}

void add(editor& edit) {
    factory fac;
    try {
        std::shared_ptr<figure> newElem = fac.new_figure(std::cin);
        edit.add_doc(newElem);
    } catch (std::logic_error& e) {
        std::cout << e.what() << '\n';
    }
}

void rmv(editor& edit) {
    int index;
    std::cin >> index;
    try {
        edit.delete_doc(index);
    } catch (std::logic_error& err) {
        std::cout << err.what() << "\n";
    }
}

int main() {
    editor edit;
    std::string command;
    while (true) {
        cout << "1-Create " << "2-Add " << "3-Print " << "4-Save " << "5-Load " << "6-Remove " << "7-Undo " << "8-Exit" << '\n';
        std::cin >> command;
        if (command == "1") {
            cout << "filename\n";
            crt(edit);
        } else if (command == "5") {
            load(edit);
        } else if (command == "4") {
            save(edit);
        } else if (command == "8") {
            break;
        } else if (command == "2") {
            add(edit);
        } else if (command == "6") {
            rmv(edit);
        } else if (command == "3") {
            edit.prt_doc();
        } else if (command == "7") {
            try {
                edit.undo();
            } catch (std::logic_error& e) {
                std::cout << e.what();
            }
        } else {
            std::cout << "no such a command\n";
        }
    }
    return 0;
}