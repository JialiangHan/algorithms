#ifndef GA_TSP
#define GA_TSP

#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <utility>

// typedef std::unordered_multimap<int,std::string> mated_generation;

struct City
{
    int index;
    std::pair<float,float> coordinates;
    bool operator==(const City& other) const
    {
    return this->index == other.index && this->coordinates.first == other.coordinates.first && this->coordinates.second == other.coordinates.second;
    }
}; 

typedef std::vector<City> TSP;
typedef std::vector<City> chromosome;
typedef std::vector<chromosome> generation;
typedef std::multimap<float,chromosome> fitness_map;
class ga_tsp
{
public:
    /**
     * @brief Construct a new ga tsp object
     * 
     * @param max_iterations 
     * @param probability 
     * @param size 
     * @param cities 
     */
    ga_tsp(const int max_iterations,const float probability,const int size,const int cities)
    {
        max_iteration = max_iterations;
        probability_mutation = probability;
        population_size = size;
        number_of_city = cities;
    };
    /**
     * @brief Destroy the ga tsp object
     * 
     */
    ~ga_tsp(){};
    /**
     * @brief initialize traving sales man problem by number of city;
     * 
     * @return TSP 
     */
    TSP initial_TSP();
    /**
     * @brief generate a chromosome from TSP problem
     * 
     * @param problem 
     * @return chromosome 
     */
    chromosome form_chromosome(TSP problem);
    /**
     * @brief generate initial generation;
     * 
     * @param problem 
     * @return generation 
     */
    generation initial_generation(TSP& problem);
    /**
     * @brief calculate euler distance between city a and city b;
     * 
     * @param a city a
     * @param b city b
     * @return float 
     */
    float distance(City& a, City& b);

    float get_fitness_for_chromosome(chromosome& chromo);
       
    fitness_map get_fitness_for_generation(generation& gen);
    
    generation select_chromosome(fitness_map& fm);

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
