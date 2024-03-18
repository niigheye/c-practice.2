
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
}



/*
int interactive() {
    int sizefirst = 30;
    size_t size = 0;
    Train db[sizefirst];
    std::fstream file("traindata.txt");
    while (true) {
        switch (menuTrain()) {
            case 1:
                while (file) {
                    file >> db[size++];
                }
                size--;
                break;
            case 2:
                Train::DBtoFile(db, size, "traindata.txt");
                break;
            case 3:
                Train::EditTrainValues(db, size);
                break;
            case 4:
                Train::PrintDB(db, size);
                break;
            case 5:
                Train::Sort(db, size);
                break;
            case 6:
                Train::AddTrain(db, size);
                break;
            case 7:
                Train::DeleteTrain(db, size);
                break;
            case 8:
                return 0;
                break;
            default:
                std::cout << "\nWrong input, try again)\n";
                break;
        }
    }
}
int demo()
{
    int sizefirst = 30;
    Planet db[sizefirst];
    size_t size = 0;

    std::fstream file("planetdata.txt");
    while (file)
    {
        file >> db[size++];
    }
    size--;

    std::cout << "\nprinting database\n";
    Planet::PrintDB(db, size);
    std::cout << "\nsorting database\n";
    Planet::Sort(db, size);
    std::cout << "\nprinting database\n";
    Planet::PrintDB(db, size);
    std::cout << "\nDeleting mercury\n";
    char planetName[30];
    strcpy(planetName, "Mercury");
    Planet::DeletePlanet(db, size, planetName);
    std::cout << "\nprinting database\n";
    Planet::PrintDB(db, size);
    std::cout << "\nadding moon with 780 as diameter, false value of having life and 10 satellites\n";
    Planet moon;
    strcpy(planetName, "Moon");
    moon.SetPlanetName(planetName);
    moon.SetDiameter(780);
    moon.SetHaveLife(0);
    moon.SetSatellites(10);
    Planet::AddPlanet(db, size, moon);
    std::cout << "\nprinting database\n";
    Planet::PrintDB(db, size);
    std::cout << "\nmerging to file\n";
    Planet::DBtoFile(db, size, "data.txt");
    return 0;
}

   /* while (true) {
        switch (menuPlanet()) {
            case 1:
                while (file) {
                    file >> db[size++];
                }
                size--;
                break;
            case 2:
                Planet::DBtoFile(db1, size, "planetdata.txt");
                break;
            case 3:
                Planet::EditPlanetValues(db1, size);
                break;
            case 4:
                Planet::PrintDB(db1, size);
                break;
            case 5:
                Planet::Sort(db1, size);
                break;
            case 6:
                Planet::AddPlanet(db1, size);
                break;
            case 7:
                Planet::DeletePlanet(db1, size);
                break;
            case 8:
                return 0;
                break;
            default:
                std::cout << "\nWrong input, try again)\n";
                break;
        }
    }
    return 0;
}


int main(int argc, char *argv[])
{
    system("chcp 1251");
    bool isInteractive = false;
    if ((argc == 2) && strcmp(argv[1], "i") == 0)
    {
        isInteractive = true;
    }

    if (isInteractive)
    {
        return interactive();
    }
    else
    {
        return demo();
    }
    return 0;
}




        int sizefirst = 30;
        size_t size = 0;
        Train db[sizefirst];
        std::fstream file("traindata.txt");
        while (true) {
            switch (menuTrain()) {
                case 1:
                    while (file) {
                        file >> db[size++];
                    }
                    size--;
                    break;
                case 2:
                    Train::DBtoFile(db, size, "traindata.txt");
                    break;
                case 3:
                    Train::EditTrainValues(db, size);
                    break;
                case 4:
                    Train::PrintDB(db, size);
                    break;
                case 5:
                    Train::Sort(db, size);
                    break;
                case 6:
                    Train::AddTrain(db, size);
                    break;
                case 7:
                    Planet::DeleteTrain(db, size);
                    break;
                case 8:
                    return 0;
                    break;
                default:
                    std::cout << "\nWrong input, try again)\n";
                    break;
            }
        }
    }
}
*/













