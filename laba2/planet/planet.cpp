#include "planet.h"

class planet;

void planet::read_db(planet* p, int& c) {
    std::ifstream file("planetdata.txt");
    if (!file) { std::cout << "Failed to open the file." << std::endl; return; }
    while (!file.eof()) {
        file >> p[c];
        ++c;
    }
    file.close();
}

void planet::write_db(planet* p, int c) {
    std::ofstream file("planetdata.txt");
    if (!file) { std::cout << "Failed to open the file." << std::endl; return; }
    for (int i = 0; i < c; ++i) {
        file << p[i];
    }
    file.close();
}

void planet::getsort(planet* p, int c) {
    planet temp;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < c - i - 1; ++j) {
            if (strcmp(p[j].getname(), p[j + 1].getname()) > 0) {
                temp = p[j]; p[j] = p[j + 1]; p[j + 1] = temp;
            }
        }
    }
}

void planet::add(planet* p, int& c) {
    std::cin >> p[c];
    ++c;
}

void planet::remove(planet* p, int& c) {
    int number;
    planet temp;
    std::cout << "Input number of planet: ";
    std::cin >> number;
    for (int i = number - 1; i < c - 1; ++i) {
        temp = p[i]; p[i] = p[i + 1]; p[i + 1] = temp;
    }
    --c;
}

void planet::getall(planet* p, int c) {
    for (int i = 0; i < c; ++i) {
        std::cout << "Planet #" << i + 1 << ": " << p[i];
    }
}

void planet::change(planet* p) {
    int number;
    std::cout << "Input number of planet: ";
    std::cin >> number;
    std::cin >> p[number - 1];
}

std::ostream& operator<<(std::ostream& out, planet& x) {
    out << x.name << ' ' << x.diam << ' ' <<  x.life << ' ' << x.sate << std::endl;
    return out;
}
std::ofstream& operator<<(std::ofstream& out, planet& x) {
    out << x.name << ' ' << x.diam << ' ' <<  x.life << ' ' << x.sate << std::endl;
    return out;
}

std::ifstream& operator>>(std::ifstream& in, planet& x) {
    char Name[100];
    int Diam, Sate;
    bool Life;
    in >> Name >> Diam >> Life >> Sate;
    if (in) {
        x.setname(Name); x.setdiam(Diam); x.setlife(Life); x.setsate(Sate);
    }
    return in;
}
std::istream& operator>>(std::istream& in, planet& x) {
    std::cout << "Name: "; in >> x.name;
    std::cout << "Diameter: "; in >> x.diam;
    std::cout << "Life: "; in >> x.life;
    std::cout << "Satellites: "; in >> x.sate;
    return in;
}





