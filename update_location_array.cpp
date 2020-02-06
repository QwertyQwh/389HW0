#include "update_location_array.h"
#include <random>
#include <iostream>
#include <numeric>
#include "windows.h"
#include <chrono>
#include <thread>

data_t* generate_random_list(int size, float bound)
{
	// !!!!:The burden to free the memory the array used is on the caller.
	const int array_size = size;

	auto* random_list =  new data_t[array_size];//create a vector to store the return value
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	const std::uniform_real_distribution<> dist(-bound, bound);
	for (auto n = 0; n < size; n++)
	{
		random_list[n] = dist(gen);//append the generated random number
	}
	return random_list;

}

void update_coords(data_t* xs, data_t* ys, data_t* zs, data_t* vx, data_t* vy, data_t* vz,int size)
{
	for (auto i = 0; i < size; i++)
	{
		xs[i] = xs[i] + vx[i];
		ys[i] = ys[i] + vy[i];
		zs[i] = zs[i] + vz[i];
	}
}


int main()
{
	std::cout << "Enter any non-num symbol to end input\n";
	//Get system input
	std::vector<int> input_vector;
	int input;
	while (std::cin >> input)
	{
		input_vector.push_back(input);
	}
	if (input_vector.size() != 2)
	{
		std::cout << "Required arguments: vector_length(N) and iterations_num(M)";
		return -1;
	}
	const int size = input_vector[0];
	const int iters = input_vector[1];


	//initiate vectors
	auto xs = generate_random_list(size, 1000.);
	auto ys = generate_random_list(size, 1000.);
	auto zs = generate_random_list(size, 1000.);
	const auto vx = generate_random_list(size, 1000.);
	const auto vy = generate_random_list(size, 1000.);
	const auto vz = generate_random_list(size, 1000.);
	//run the actual updating function and measure time
	auto const t1 = std::chrono::high_resolution_clock::now();
	for (auto i = 0; i < iters; i++)
	{
		update_coords(xs, ys, zs, vx, vy, vz,size);
	}
	auto const t2 = std::chrono::high_resolution_clock::now();
	//compute and output
	float const duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	float chksum = 0;
	chksum = std::accumulate(xs, xs + size, chksum);
	chksum = std::accumulate(ys, ys + size, chksum);
	chksum = std::accumulate(zs, zs + size, chksum);


	// Free the Memory!
	delete[] xs;
	delete[] ys;
	delete[] zs;
	delete[] vx;
	delete[] vy;
	delete[] vz;
	double const coordinate_duration = duration / (double)(size * iters);
	std::cout << "Mean time per coordinate: " << coordinate_duration << "us.\n";
	std::cout << "Final checksum is: " << chksum;
	return 0;
}
