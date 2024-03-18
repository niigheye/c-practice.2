//
// Created by sgris on 17.03.2024.
//
#pragma once

#ifndef CAPACITY
#define CAPACITY 12
#endif

#include <iostream>
#include <fstream>
#include <cstring>

class Train{
public:
    Train() { from = new char[1]; from[0] = '\0'; to = new char[1]; to[0] = '\0'; cost = 0; hours = 0; }
    Train(const Train& obj) {
        from = new char[strlen(obj.from) + 1];
        strcpy_s(from, strlen(obj.from) + 1, obj.from);
        to = new char[strlen(obj.to) + 1];
        strcpy_s(to, strlen(obj.to) + 1, obj.to);
        cost = obj.cost;
        hours = obj.hours;
    }
    ~Train() { delete[] from; delete[] to; }

    friend std::ostream& operator<< (std::ostream& out, Train& x);
    friend std::ofstream& operator<< (std::ofstream& out, Train& x);
    friend std::istream& operator>> (std::istream& in, Train& x);
    friend std::ifstream& operator>> (std::ifstream& in, Train& x);

    Train& operator=(Train& other) {
        if (this != &other) {
            delete[] from;
            from = new char[strlen(other.from) + 1];
            strcpy_s(from, strlen(other.from) + 1, other.from);
            delete[] to;
            to = new char[strlen(other.to) + 1];
            strcpy_s(to, strlen(other.to) + 1, other.to);
            cost = other.cost;
            hours = other.hours;
        }
        return *this;
    }

    static void read_db(Train* a, int& c);
    static void write_db(Train* a, int c);
    static void getsort(Train* a, int c);
    static void add(Train* a, int& c);
    static void remove(Train* a, int& c);
    static void getall(Train* a, int c);
    static void change(Train* a);

    void setto(char*);
    void setfrom(char*);
    void setcost(int);
    void sethours(int);

    char* getto();
    char* getfrom();
    int getcost();
    int gethours();

private:
    char* from;
    char* to;
    int cost;
    int hours;

};


