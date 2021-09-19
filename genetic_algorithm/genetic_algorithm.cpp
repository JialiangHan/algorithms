//this is a simple example for genetic algorithm
//exmaple is to find max value of -(x^2)/10 +3x, x in [0,31]

#include "genetic_algorithm.h"
#include <bitset>
#include <math.h>
#include <iostream>
#include <random>
#include <cstring>

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

    encoded_generation genetic_algorithm::encoding(generation& x)
    {
        encoded_generation encoded_generation;
        for(auto i:x)
        {
            // std::string encoded = std::bitset<number_of_bits >( i ).to_string();
            std::string encoded = std::bitset< 5 >( i ).to_string();
            encoded_generation.emplace(i,encoded);
        }
        return encoded_generation;
    }

    generation genetic_algorithm::decoding(encoded_generation& y)
    {
        generation generation;
        for(auto i:y)
        {
            generation.push_back(i.first);
        }
        return generation;
    }

    double genetic_algorithm::fitness_function(int x)
    {
        double result;
        result = -(x * x)/10 + 3*x;
        return result;
    }

    fitness_map genetic_algorithm::fitness(encoded_generation& y)
    {
        fitness_map map;
        for(auto i:y)
        {
            map.emplace(i.second,fitness_function(i.first));
        }
        return map;
    }
        
    int genetic_algorithm::string_to_int(std::string s)
    {
        int size = s.size();
        int result=0;
        for(int i=0;i<size;++i)
        {
            result += (s[i]-48) * pow(2,size-i-1);
        }
        return result;
    }

    encoded_generation genetic_algorithm::selection(fitness_map& z)
    {
        float total_fitness=0;
        selection_map probability_map;
        encoded_generation selected;
        for(auto i:z)
        {
            total_fitness += i.second;
        }
        for(auto i:z)
        {
            probability_map.emplace(i.second/total_fitness, i.first);
        }
        auto j=probability_map.lower_bound(0.10);
        for(j;j!=probability_map.end();++j)
        {
            selected.emplace(string_to_int(j->second),j->second);
        }
        return selected;
    }

    encoded_generation genetic_algorithm::mating(encoded_generation& z)
    {   
        encoded_generation next;
        int size = z.size();
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(0,size);
        for(int i=0;i<population_size;++i)
        {
            int dice_roll = distribution(generator);
            auto random_it = std::next(std::begin(z), dice_roll);
            next.emplace(random_it->first,random_it->second);
        }
        return next;
    }

    encoded_generation genetic_algorithm::exchange_genes(encoded_generation& before)
    {
        encoded_generation exchanged;
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(0,number_of_bits);
        auto iter = before.begin();
        std::string temp11,temp12,temp21,temp22;
        while(iter!=before.end())
        {
            int dice_roll = distribution(generator);
            temp11 = iter->second.substr(0,dice_roll);
            temp12 = iter->second.substr(dice_roll);
            temp21 = (++iter)->second.substr(0,dice_roll);
            temp22 = (++iter)->second.substr(dice_roll);
            exchanged.emplace(string_to_int(temp11+temp22),temp11+temp22);
            exchanged.emplace(string_to_int(temp21+temp12),temp21+temp12);
            ++iter;
            ++iter;
            if(exchanged.size() >= population_size)
            {
                break;
            }
        }
        return exchanged;
    }

    std::string genetic_algorithm::mutation(std::string chrono)
    {
        std::default_random_engine generator;
        std::uniform_real_distribution<double> distribution(0.0,1.0);
        std::string mutated="";
        for(int i =0; i< chrono.size(); ++i)
        {
            float dice_roll = distribution(generator);
            if(dice_roll<=probability_mutation)
            {
                if(std::strcmp(&chrono[i],"0"))
                {
                    mutated+="1";
                }
                else
                {
                    mutated+="0";
                }
            }
            else
            {
                mutated += chrono[i];
            }
        }
        return mutated;
    }
    

    generation genetic_algorithm::generate_next(encoded_generation& generation)
    {
        //mating
        //select location to swap genes
        //mutation
    }

    

}

int main(int argc, char** argv) {
    int max_iterations =1000;
    double probability_mutation = 0.8;
    int population_size = 10;
    int number_of_bits = 5;
    genetic_algorithm::genetic_algorithm test(max_iterations,probability_mutation,population_size,number_of_bits);
    std::string a="11111";
    std::string out;
    out = test.mutation(a);   
    // generation initial_generation;
    // initial_generation=test.initial_generation();
    // for(auto j=initial_generation.begin();j!=initial_generation.end();++j)
    // {
    //         std::cout << "value: " << (*j) <<std::endl;
    // }
    std::cout << "before: " << a <<std::endl;
    std::cout << "after: " << out <<std::endl;
    return 0;
}