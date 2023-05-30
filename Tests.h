#pragma once

#include "Planet.h"
#include "Repository.h"
#include "Service.h"
#include <cassert>

class Tests {
private:
    void testDomain();
    void testRepository();
    void testService();
public:
    void testAll();
};
