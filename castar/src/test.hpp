#ifndef TEST_H
#define TEST_H

#include "castar.hpp"
#include "field.hpp"
#include <iostream>
#include "math.h"
#include <chrono> 
#include <bits/stdc++.h> 

#define square(_a) ((_a)*(_a))

bool is_in_circle(Coordinates pos, Circle c);
void board_visualize(Field board, std::vector<Coordinates> path);
void test(void);

#endif