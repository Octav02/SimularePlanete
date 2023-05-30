
#include "Tests.h"

void Tests::testAll() {
    testDomain();
    testRepository();
    testService();
}

void Tests::testDomain() {
    Planet planet1;
    Planet planet2 = Planet(1,"1","1",1,1);
    assert(planet2.getCode() == 1);
    assert(planet2.getName() == "1");
    assert(planet2.getDiameter() == 1);
    assert(planet2.getMass() == 1);
    assert(planet2.getSolarSystem() == "1");
}

void Tests::testRepository() {
    Repository repository = Repository("tests.txt");
    assert(repository.getAllPlanets().size() == 3);
    assert(repository.getPlanet(1111).getSolarSystem() == "Solar1");
    try {
        repository.getPlanet(5251);
        assert(false);
    }
    catch (RepositoryException &e) {
        assert(e.what() == "Planet does not exist");
    }
}

void Tests::testService() {
    Repository repository = Repository("tests.txt");
    Service service = Service(repository);
    assert(service.getAllPlanets().size() == 3);
    assert(service.getPlanet(1111).getSolarSystem() == "Solar1");
    try {
        service.getPlanet(5251);
        assert(false);
    }
    catch (RepositoryException &e) {
        assert(true);
    }

    vector<Planet> res = service.sortByName();
    assert(res[0].getName() == "Marte");
    assert(res[1].getName() == "Pluto");
    assert(res[2].getName() == "Terra");

    res = service.sortByDiameter();
    assert(res[0].getDiameter() == 2000);
    assert(res[1].getDiameter() == 3000);
    assert(res[2].getDiameter() == 4000);

    res = service.sortByMass();
    assert(res[0].getMass() == 1000);
    assert(res[1].getMass() == 1500);
    assert(res[2].getMass() == 1600);

    auto res2 = service.getPlanetBySolarSystem();
    assert(res2["Solar1"].size() == 2);

}