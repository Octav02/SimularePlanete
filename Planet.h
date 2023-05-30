#pragma once

#include <string>

using namespace std;


class Planet {
private:
    int code, mass, diameter;
    string name, solarSystem;
public:
    //Default constructor
    Planet() = default;
    //Constructor with parameters
    Planet(int code, const string &name, const string &solarSystem, int mass, int diameter);

    //Getter for code, returns the integer code of the Planet
    int getCode() const;
    //Getter for mass, returns the integer mass of the Planet
    int getMass() const;
    //Getter for diameter, returns the integer diameter of the Planet
    int getDiameter() const;
    //Getter for name, returns the string name of the Planet
    string getName() const;
    //Getter for solar system, returns the string solar system of the Planet
    string getSolarSystem() const;
};

