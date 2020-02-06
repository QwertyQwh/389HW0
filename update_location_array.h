#pragma once
#include <cstdint>
using data_t = float;

//Create a list of 'size' floating point numbers in the range[-bound, bound]
data_t* generate_random_list(int size, float bound);

void update_coords(data_t* xs, data_t* ys, data_t* zs, data_t* vx, data_t* vy, data_t* vz,int size);



