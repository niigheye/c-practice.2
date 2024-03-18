
#include "planet/planet.h"
#include "train/train.h"

using namespace std;

const int count_of_increasing = 2;

int main()
{
    int choose, count = 0, size = 15;
    std::cout << "Planets(print 1)" << std::endl << "Train(print 2)" << std::endl;
    std::cin >> choose;
    if (choose == 1)
    {
        planet* planets = new planet[size];

        while (choose != 0) {
            std::cout << "1. Sort data" << std::endl << "2. Add data" << std::endl << "3. Delete data" <<
                      std::endl << "4. Print all information" << std::endl << "5. Get data TO file" <<
                      std::endl << "6. Get data FROM file" << std::endl << "7. Change data" << std::endl << "0. Exit" << std::endl;

            std::cin >> choose;
            std::cout << std::endl;

            switch (choose) {
                case 1:
                    planet::getsort(planets, count);
                    break;
                case 2:
                    planet::add(planets, count);
                    if (count + 1 >= size) {
                        int size1 = size;
                        size *= count_of_increasing;
                        planet* temp = new planet[size];
                        for (int i = 0; i < size1; ++i) { temp[i] = planets[i]; }
                        delete[] planets;
                        planets = temp;
                    }
                    break;
                case 3:
                    planet::remove(planets, count);
                    if (count < size / 2) {
                        size /= 2;
                        planet* temp = new planet[size];
                        for (int i = 0; i < size; ++i) { temp[i] = planets[i]; }
                        delete[] planets;
                        planets = temp;
                    }
                    break;
                case 4:
                    planet::getall(planets, count);
                    break;
                case 5:
                    planet::write_db(planets, count);
                    break;
                case 6:
                    planet::read_db(planets, count);
                    break;
                case 7:
                    planet::change(planets);
                    break;
                case 0:
                    delete[] planets;
                    return 0;
                default:
                    std::cout << "Wrong number, try again." << std::endl;
                    break;
            }
        }
    }
    else
    {
        Train* train = new Train[size];

        while (choose != 0) {
            std::cout << "1. Sort data" << std::endl << "2. Add data" << std::endl << "3. Remove data" <<
                      std::endl << "4. Print all information" << std::endl << "5. Get data TO file" <<
                      std::endl << "6. Get data FROM file" << std::endl << "7. Change data" << std::endl << "0. Exit" << std::endl;

            std::cin >> choose;
            std::cout << std::endl;

            switch (choose) {
                case 1:
                    Train::getsort(train, count);
                    break;
                case 2:
                    Train::add(train, count);
                    if (count + 1 >= size) {
                        int size1 = size;
                        size *= count_of_increasing;
                        Train* temp = new Train[size];
                        for (int i = 0; i < size1; ++i) { temp[i] = train[i]; }
                        delete[] train;
                        train = temp;
                    }
                    break;
                case 3:
                    Train::remove(train, count);
                    if (count < size / 2) {
                        size /= 2;
                        Train* temp = new Train[size];
                        for (int i = 0; i < size; ++i) { temp[i] = train[i]; }
                        delete[] train;
                        train = temp;
                    }
                    break;
                case 4:
                    Train::getall(train, count);
                    break;
                case 5:
                    Train::write_db(train, count);
                    break;
                case 6:
                    Train::read_db(train, count);
                    break;
                case 7:
                    Train::change(train);
                    break;
                case 0:
                    delete[] train;
                    return 0;
                default:
                    std::cout << "Wrong number, try again." << std::endl;
                    break;
            }
        }
    }
    return 0;
}

