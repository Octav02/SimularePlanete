#pragma once
#include <vector>
#include "Planet.h"
#include "RepositoryException.h"
#include <sstream>
#include <fstream>


class Repository {
private:
    vector<Planet> planets;
    string fileName;

    //Function to load data from file
    void loadFromFile();
public:
    //Default constructor
    Repository() = default;
    //Constructor with parameters
    Repository(string fileName);

    //Function that returns a Planet based on its uniq code
    Planet getPlanet(int code);
    //Function that returns all the Planets in the repository list
    vector<Planet> getAllPlanets();
};
