//
// Created by octav on 25.05.2023.
//

#include "Repository.h"

Repository::Repository(string fileName) {
    this->fileName = "../" + fileName;
    this->loadFromFile();
}

Planet Repository::getPlanet(int code) {
    for (auto &planet: planets) {
        if (planet.getCode() == code)
            return planet;
    }
    throw RepositoryException("Planet does not exist");
}

vector<Planet> Repository::getAllPlanets() {
    vector<Planet> result;
    for (auto &planet: planets)
        result.push_back(planet);
    return result;
}

void Repository::loadFromFile() {
    ifstream fin(fileName);
    if (!fin.is_open())
        throw RepositoryException("File  could not be opened");
    string line;
    planets.clear();
    while (getline(fin,line)) {
        stringstream  ss(line);
        string token;
        vector<string> tokens;
        while(getline(ss,token,','))
            tokens.push_back(token);
        int code = stoi(tokens[0]);
        string name = tokens[1];
        string solarSystem = tokens[2];
        int mass = stoi(tokens[3]);
        int diameter = stoi(tokens[4]);
        Planet planet(code,name,solarSystem,mass,diameter);
        planets.push_back(planet);
    }
}
