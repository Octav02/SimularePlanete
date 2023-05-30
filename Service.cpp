//
// Created by octav on 25.05.2023.
//

#include <algorithm>
#include "Service.h"

Planet Service::getPlanet(int code) {
    return repository.getPlanet(code);
}

vector<Planet> Service::getAllPlanets() {
    return repository.getAllPlanets();
}

vector<Planet> Service::sortByMass() {
    vector<Planet> planets = repository.getAllPlanets();
    sort(planets.begin(),planets.end(),[](Planet p1, Planet p2){
        return p1.getMass() <= p2.getMass();
    });
    return planets;
}

vector<Planet> Service::sortByDiameter() {
    vector<Planet> planets = repository.getAllPlanets();
    sort(planets.begin(),planets.end(),[](Planet p1, Planet p2){
        return p1.getDiameter() <= p2.getDiameter();
    });
    return planets;
}

vector<Planet> Service::sortByName() {
    vector<Planet> planets = repository.getAllPlanets();
    sort(planets.begin(),planets.end(),[](Planet p1, Planet p2){
        return p1.getName() <= p2.getName();
    });
    return planets;
}

map<string, vector<Planet>> Service::getPlanetBySolarSystem() {
    map<string, vector<Planet>> result;
    vector<Planet> planets = repository.getAllPlanets();
    for (auto & planet : planets) {
        result[planet.getSolarSystem()].push_back(planet);
    }
    return result;
}

vector<Planet> Service::filterByMass(int mass) {
    vector<Planet> result;
    vector<Planet> planets = repository.getAllPlanets();
    copy_if(planets.begin(),planets.end(),back_inserter(result),[mass](const Planet& planet){
        return planet.getMass() < mass;
    });
    return result;
}
