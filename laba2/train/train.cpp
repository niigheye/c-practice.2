//
// Created by sgris on 17.03.2024.
//
#include "train.h"
#include <iostream>
#include <fstream>
#include <cstring>

class Train;

void Train::read_db(Train* a, int& c) {
    std::ifstream file("traindata.txt");
    if (!file) { std::cout << "Failed to open the file." << std::endl; return; }
    while (!file.eof()) {
        file >> a[c];
        ++c;
    }
    file.close();
}

void Train::write_db(Train* a, int c) {
    std::ofstream file("traindata.txt");
    if (!file) { std::cout << "Failed to open the file." << std::endl; return; }
    for (int i = 0; i < c; ++i) {
        file << a[i];
    }
    file.close();
}

void Train::getsort(Train* a, int c) {
    Train temp;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < c - i - 1; ++j) {
            if (strcmp(a[j].getto(), a[j + 1].getto()) > 0) {
                temp = a[j]; a[j] = a[j + 1]; a[j + 1] = temp;
            }
        }
    }
}

void Train::add(Train* a, int& c) {
    std::cin >> a[c];
    ++c;
}

void Train::remove(Train* a, int& c) {
    int number;
    Train temp;
    std::cout << "Input number of train: ";
    std::cin >> number;
    for (int i = number - 1; i < c - 1; ++i) {
        temp = a[i]; a[i] = a[i + 1]; a[i + 1] = temp;
    }
    --c;
}

void Train::getall(Train* a, int c) {
    for (int i = 0; i < c; ++i) {
        std::cout << "Train #" << i + 1 << ": " << a[i];
    }
}

void Train::change(Train* a) {
    int number;
    std::cout << "Input number of train: ";
    std::cin >> number;
    std::cin >> a[number - 1];
}

void Train::setto(char* x) {
    delete[] from;
    from = new char[strlen(x) + 1];
    strcpy_s(from, strlen(x) + 1, x);
}

void Train::setfrom(char* x) {
    delete[] to;
    to = new char[strlen(x) + 1];
    strcpy_s(to, strlen(x) + 1, x);
}

void Train::setcost(int x) {
    cost = x;
}

void Train::sethours(int x) {
    hours = x;
}

char* Train::getto() {
    return from;
}
char* Train::getfrom() {
    return to;
}
int Train::getcost() {
    return cost;
}
int Train::gethours() {
    return hours;
}

std::ostream& operator<<(std::ostream& out, Train& x) {
    out << x.from << ' ' << x.to << ' ' << x.cost << ' ' << x.hours << std::endl;
    return out;
}
std::ofstream& operator<<(std::ofstream& out, Train& x) {
    out << x.from << ' ' << x.to << ' ' << x.cost << ' ' << x.hours << std::endl;
    return out;
}

std::ifstream& operator>>(std::ifstream& in, Train& x) {
    char to[100], from[15];
    int Cost, hours;
    in >> to >> from >> Cost >> hours;
    if (in) {
        x.setto(to); x.setfrom(from); x.setcost(Cost); x.sethours(hours);
    }
    return in;
}
std::istream& operator>>(std::istream& in, Train& x) {
    std::cout << "To: "; in >> x.from;
    std::cout << "From: "; in >> x.to;
    std::cout << "Cost: "; in >> x.cost;
    std::cout << "Hours: "; in >> x.hours;
    return in;
}
