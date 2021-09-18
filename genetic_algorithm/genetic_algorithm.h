#ifndef GENETIC_ALGORITHM
#define GENETIC_ALGORITHM

#include <string>
#include <vector>
#include <unordered_map>

typedef std::vector<int> generation;
typedef std::unordered_map<int,std::string> encoded_generation;
typedef std::unordered_map<std::string,double> fitness_map;
typedef std::unordered_map<std::string,float> selection_map; 

namespace genetic_algorithm
{

class genetic_algorithm
{
public:
    genetic_algorithm();
    genetic_algorithm(int max_iterations,double probability_mutation,int population_size)
    {
        max_iteration = max_iterations;
        probability_mutation = probability_mutation;
        population_size = population_size;
    };
    ~genetic_algorithm();
    generation initial_generation();
    encoded_generation encoding(generation x);
    generation decoding(encoded_generation y);
    fitness_map fitness(encoded_generation y);
    encoded_generation selection(fitness_map z);
    generation generate_next(encoded_generation generation);
    std::string mutation(std::string chrono);
   
private:
    int max_iteration;
    double probability_mutation;
    int population_size;
};
    
}

#endif /* GENETIC_ALGORITHM */
