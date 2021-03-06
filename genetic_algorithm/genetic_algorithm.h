
#ifndef GENETIC_ALGORITHM
#define GENETIC_ALGORITHM

#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <utility>

typedef std::vector<int> generation;
typedef std::vector<std::string> encoded_generation;
typedef std::unordered_multimap<int,std::string> mated_generation;
typedef std::multimap<float,int> fitness_map;
// typedef std::multimap<float,std::string> selection_map; 

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
    genetic_algorithm(const int max_iterations,const float probability,const int size,const int bits)
    {
        max_iteration = max_iterations;
        probability_mutation = probability;
        population_size = size;
        number_of_bits = bits;
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
     * @return float 
     */
    float fitness_function(int x);
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
     * @return mated_generation 
     */
    encoded_generation mating(encoded_generation& z);
    /**
     * @brief exchange genes at some random location
     * 
     * @param encoded_generation 
     * @return encoded_generation 
     */
    encoded_generation exchange_genes(encoded_generation& mated);
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
     * @param g encoded generation
     * @return encoded generation 
     */
    encoded_generation generation_mutated(encoded_generation& g);
    /**
     * @brief main function in class, run max_iteration to get generation 
     * 
     * @return generation 
     */
    generation evolution();
   
private:
    int max_iteration;
    float probability_mutation;
    int population_size;
    int number_of_bits;
};
    
}

#endif /* GENETIC_ALGORITHM */
