//
// Created by sgris on 14.02.2024.
//

#pragma once
#include <iostream>
#include <fstream>
#include <cstring>


#ifndef CAPACITY
#define CAPACITY 12
#endif
class planet {
public:
    planet() { name = new char[100]; diam = 0, life = 0, sate = 0; }

    void setname(char* x) {
        delete[] name;
        name = new char[strlen(x) + 1];
        strcpy_s(name, strlen(x) + 1, x);
    }
    void setdiam(int x) {
        diam = x;
    }
    void setlife(bool x) {
        life = x;
    }
    void setsate(int x) {
        sate = x;
    }
    char* getname() {
        return name;
    }
    int getdiam() {
        return diam;
    }
    bool getlife() {
        return life;
    }
    int getsate() {
        return sate;
    }
    planet(const planet& obj) {
        setname(obj.name);
        diam = obj.diam;
        life = obj.life;
        sate = obj.sate;
    }
    ~planet() { delete[] name; }

    friend std::ostream& operator<<(std::ostream& out, planet& x);
    friend std::ofstream& operator<<(std::ofstream& out, planet& x);
    friend std::ifstream& operator>>(std::ifstream& in, planet& x);
    friend std::istream& operator>>(std::istream& in, planet& x);

    planet& operator=(planet& other) {
        if (this != &other) {
            setname(other.name);
            diam = other.diam;
            life = other.life;
            sate = other.sate;
        }
        return *this;
    }

    static void read_db(planet* p, int& c);
    static void write_db(planet* p, int c);
    static void getsort(planet* p, int c);
    static void add(planet* p, int& c);
    static void remove(planet* p, int& c);
    static void getall(planet* p, int c);
    static void change(planet* p);

private:
    char* name;
    int diam;
    bool life;
    int sate;
};


