#pragma once
#include <stdexcept>
#include "Repository.h"

class RepositoryException : std::exception {
private:
    string message;
public:
    RepositoryException(const std::string& message);
    string what();
};

