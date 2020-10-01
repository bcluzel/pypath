#include <cmath>
#include "distance.hpp"


float distance(Coordinates a, Coordinates b)
{
    return sqrtf(square(a.x - b.x) + square(a.y - b.y));
}
