#pragma once
#include "Repository.h"
#include <map>

class Service {
private:
    Repository& repository;
public:
    //Default consturctor
    Service() = default;
    //Constructor with parameters
    Service(Repository& repository) : repository(repository) {};

    //Function that returns a Planet based on its uniq code
    Planet getPlanet(int code);
    //Function that returns all the Planets in the repository list
    vector<Planet> getAllPlanets();

    //Function that returns a vector of Planets, sorted ascending by mass
    vector<Planet> sortByMass();
    //Function that returns a vector of Planets, sorted ascending by Diameter
    vector<Planet> sortByDiameter();
    //Function that returns a vector of Planets, sorted ascending by Name
    vector<Planet> sortByName();
    //Function that gets all the Planets, grouped by the solar System
    map<string,vector<Planet>> getPlanetBySolarSystem();

    vector<Planet> filterByMass(int mass);
};
