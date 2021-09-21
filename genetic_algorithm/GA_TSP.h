
#ifndef GA_TSP
#define GA_TSP

#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <utility>

// typedef std::vector<std::string> encoded_generation;
// typedef std::unordered_multimap<int,std::string> mated_generation;
// typedef std::multimap<float,int> fitness_map;

struct City
{
    int index;
    std::pair<float,float> coordinates;
}; 

typedef std::vector<City> TSP;
typedef std::vector<City> chromosome;
typedef std::vector<chromosome> generation;

class ga_tsp
{
public:
    ga_tsp(const int max_iterations,const float probability,const int size,const int cities)
    {
        max_iteration = max_iterations;
        probability_mutation = probability;
        population_size = size;
        number_of_city = cities;
    };
    ~ga_tsp(){};

    TSP initial_TSP();

    chromosome form_chromosome(TSP problem);
   
    generation initial_generation();
    
    // encoded_generation encoding(generation& x);
   
    // generation decoding(encoded_generation& y);
   
    // float fitness_function(int x);
    
    // int string_to_int(std::string s);
    
    // fitness_map fitness(encoded_generation& y);
    
    // encoded_generation selection(fitness_map& z);

    // encoded_generation mating(encoded_generation& z);
   
    // encoded_generation exchange_genes(encoded_generation& mated);
   
    // std::string mutation(std::string chrono);
    
    // encoded_generation generation_mutated(encoded_generation& g);
    
    // generation evolution();
   
private:
    int max_iteration;
    float probability_mutation;
    int population_size;
    int number_of_city;
};
    

#endif /* GA_TSP */
