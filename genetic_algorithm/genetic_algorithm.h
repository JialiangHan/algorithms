
#ifndef GENETIC_ALGORITHM
#define GENETIC_ALGORITHM

#include <string>
#include <vector>
#include <unordered_map>
#include <map>

typedef std::vector<int> generation;
typedef std::unordered_map<int,std::string> encoded_generation;
typedef std::unordered_map<std::string,double> fitness_map;
typedef std::map<float,std::string> selection_map; 

namespace genetic_algorithm
{

class genetic_algorithm
{
public:
    // genetic_algorithm();
    /**
     * @brief Construct a new genetic algorithm object
     * 
     * @param max_iterations 
     * @param probability_mutation 
     * @param population_size 
     */
    genetic_algorithm(int max_iterations,double probability_mutation,int population_size)
    {
        max_iteration = max_iterations;
        probability_mutation = probability_mutation;
        population_size = population_size;
    };
    // ~genetic_algorithm();
    /**
     * @brief generate initial generation randomly
     * 
     * @return generation 
     */
    generation initial_generation();
    /**
     * @brief encoding generation into encoded generation by defined encoding method
     * 
     * @param x : a generation
     * @return encoded_generation 
     */
    encoded_generation encoding(generation& x);
    /**
     * @brief decoding encoding generation into generation
     * 
     * @param y a encoded generation
     * @return generation 
     */
    generation decoding(encoded_generation& y);
    /**
     * @brief fitness function
     * 
     * @param x 
     * @return double 
     */
    double fitness_function(int x);
    /**
     * @brief convert a string type binary code into a decimal int
     * 
     * @param s a binary int in string type
     * @return int 
     */
    int string_to_int(std::string s);
    /**
     * @brief generate a fitness map using fitness function
     * 
     * @param y encoded generation
     * @return fitness_map 
     */
    fitness_map fitness(encoded_generation& y);
    /**
     * @brief select some chrono accoriding some crieteria
     * 
     * @param z fitness map
     * @return encoded_generation 
     */
    encoded_generation selection(fitness_map& z);
    /**
     * @brief randomly mate two chrono to get a full size generation 
     * 
     * @param z encoded generation after selection 
     * @return encoded_generation 
     */
    encoded_generation mating(encoded_generation& z);
    /**
     * @brief exchange genes at some random location
     * 
     * @param encoded_generation 
     * @return encoded_generation 
     */
    encoded_generation exchange_genes(encoded_generation& encoded_generation);
    /**
     * @brief mutate a chrono by some probability
     * 
     * @param chrono 
     * @return std::string 
     */
    std::string mutation(std::string chrono);
    /**
     * @brief use mutation function for  generation to mutate full generation
     * 
     * @param g a generation
     * @return generation 
     */
    generation generation_mutated(generation& g);
    /**
     * @brief generate next generation by selection, mating and mutation
     * 
     * @param generation 
     * @return generation 
     */
    generation generate_next(encoded_generation& generation);
   
private:
    int max_iteration;
    double probability_mutation;
    int population_size;
};
    
}

#endif /* GENETIC_ALGORITHM */
