
#include "Planet.h"

Planet::Planet(int code, const string &name, const string &solarSystem, int mass, int diameter) {
    this->code = code;
    this->name = name;
    this->solarSystem = solarSystem;
    this->mass = mass;
    this->diameter = diameter;
}

int Planet::getCode() const {
    return this->code;
}

int Planet::getMass() const {
    return this->mass;
}

int Planet::getDiameter() const {
    return this->diameter;
}

string Planet::getName() const {
    return this->name;
}

string Planet::getSolarSystem() const {
    return this->solarSystem;
}
