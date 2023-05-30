
#include "RepositoryException.h"
RepositoryException::RepositoryException(const string &message) {
    this->message = message;
}

string RepositoryException::what() {
    return this->message;
}
