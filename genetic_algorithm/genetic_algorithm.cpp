//this is a simple example for genetic algorithm
//exmaple is to find max value of -(x^2)/10 +3x, x in [0,31]

#include "genetic_algorithm.h"



namespace genetic_algorithm
{

    generation genetic_algorithm::initial_generation()
    {
        generation initial_generation;
        for(int i=0;i<population_size; ++i)
        {
            initial_generation.push_back(rand()%31);
        }
        return initial_generation;
    }

    encoded_generation encoding(generation x)
    {
        std::string encoded="";
        encoded_generation encoded_generation;
        for(auto i:x)
        {
            std::itoa(i,encoded,2);
            encoded_generation.emplace(i,encoded);
        }
    }
}
