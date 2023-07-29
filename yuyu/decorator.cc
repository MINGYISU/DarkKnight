#include "decorator.h"

Decorator::Decorator(Map* p): nextLayer{p} {}

Decorator::~Decorator(){
    delete nextLayer;
}


