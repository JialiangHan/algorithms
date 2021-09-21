//this is a simple example for genetic algorithm
//exmaple is to find max value of -(x^2)/10 +3x, x in [0,31]

#include "GA_TSP.h"
#include <bitset>
#include <math.h>
#include <iostream>
#include <random>
#include <algorithm> 


TSP ga_tsp::initial_TSP()
{
    int i=0;
    TSP city_list;
    City city;
    for(i;i<number_of_city;++i)
    {
        city.index=i;
        city.coordinates.first = rand() % 1000 / 1000.0;
        city.coordinates.second = rand() % 1000 / 1000.0;
        city_list.push_back(city);
    }
    return city_list;
}

// generation ga_tsp::initial_generation()
// {
//     generation initial_generation;
//     int i;
//     while(initial_generation.size()<population_size)
//     {
//         i=rand()%31;
//         if (std::find(initial_generation.begin(), initial_generation.end(), i) != initial_generation.end())
//         {
//             continue;
//         }
//         else{initial_generation.push_back(i);}
        
//     }
//     return initial_generation;
// }

// encoded_generation ga_tsp::encoding(generation& x)
// {
//     encoded_generation encoded_generation;
//     for(auto i:x)
//     {
//         // std::string encoded = std::bitset<number_of_bits >( i ).to_string();
//         std::string encoded = std::bitset< 5 >( i ).to_string();
//         encoded_generation.push_back(encoded);
//     }
//     return encoded_generation;
// }

// generation ga_tsp::decoding(encoded_generation& y)
// {
//     generation generation;
//     for(auto i:y)
//     {
//         generation.push_back(string_to_int(i));
//     }
//     return generation;
// }

// float ga_tsp::fitness_function(int x)
// {
//     float result;
//     result = -(x * x)/10.0 + 3.0*x;
//     return result;
// }

// fitness_map ga_tsp::fitness(encoded_generation& y)
// {
//     fitness_map map;
//     for(auto i:y)
//     {
//         map.emplace(fitness_function(string_to_int(i)),string_to_int(i));
//     }
//     return map;
// }
    
// int ga_tsp::string_to_int(std::string s)
// {
//     int size = s.size();
//     int result=0;
//     for(int i=0;i<size;++i)
//     {
//         result += (s[i]-48) * pow(2,size-i-1);
//     }
//     return result;
// }

// encoded_generation ga_tsp::selection(fitness_map& z)
// {
//     float total_fitness=0.0;
//     fitness_map probability_map;
//     encoded_generation selected;
//     for(auto i:z)
//     {
//         total_fitness += i.first;
//     }
//     for(auto i:z)
//     {
//         probability_map.emplace(i.first/total_fitness, i.second);
//     }
//     int i=5;
//     auto j=probability_map.end();
//     --j;
//     while(i>0)
//     {
//         selected.push_back(std::bitset< 5 >( j->second ).to_string());
//         --j;
//         --i;
//     }
//     return selected;
// }

// encoded_generation ga_tsp::mating(encoded_generation& z)
// {   
//     encoded_generation next;
//     while(next.size() < population_size)
//     {
//         for(auto i=z.begin();i!=z.end();++i)
//         {
//             next.push_back(*i);
//         }
//     }
//     return next;
// }

// encoded_generation ga_tsp::exchange_genes(encoded_generation& before)
// {
//     encoded_generation exchanged;
//     std::default_random_engine generator;
//     std::uniform_int_distribution<int> distribution(0,number_of_bits);
//     auto iter = before.begin();
//     std::string temp11,temp12,temp21,temp22;
//     while(iter!=before.end())
//     {
//         int dice_roll = distribution(generator);
//         temp11 = (*iter).substr(0,dice_roll);
//         temp12 = (*iter).substr(dice_roll);
//         temp21 = (*(++iter)).substr(0,dice_roll);
//         temp22 = (*iter).substr(dice_roll);
//         exchanged.push_back(temp11+temp22);
//         exchanged.push_back(temp21+temp12);
//         ++iter;
//         if(exchanged.size() >= population_size)
//         {
//             break;
//         }
//     }
//     return exchanged;
// }

// std::string ga_tsp::mutation(std::string chrono)
// {
//     std::string mutated="";
//     std::string zero ="0";
//     for(int i =0; i< chrono.size(); ++i)
//     {
//         float dice_roll = rand() % (999 + 1) / (float)(999 + 1);
//         if(dice_roll<=probability_mutation)
//         {
//             if(chrono[i]==zero[0])
//             {
//                 mutated+="1";
//             }
//             else
//             {
//                 mutated+="0";
//             }
//         }
//         else
//         {
//             mutated += chrono[i];
//         }
//     }
//     return mutated;
// }

// encoded_generation ga_tsp::generation_mutated(encoded_generation& g)
// {
//     encoded_generation next_gen;
//     for(auto i:g)
//     {
//         next_gen.push_back(mutation(i));
//     }
//     return next_gen;
// }

// generation ga_tsp::evolution()
// {
//     int iteration=0;
//     generation gen;
//     encoded_generation encoded_gen_1;
//     encoded_generation encoded_gen_2;
//     // mated_generation mated;
//     fitness_map fitness_map;
//     //initial generation
//     gen = initial_generation();
//     encoded_gen_1 = encoding(gen);
//     while(iteration<max_iteration)
//     {
//         //get fitness map
//         fitness_map = fitness(encoded_gen_1);
//         //selection
//         encoded_gen_2 = selection(fitness_map);
//         //mating
//         encoded_gen_1 = mating(encoded_gen_2);
//         //exchange genes
//         encoded_gen_2 = exchange_genes(encoded_gen_1);
//         //mutation
//         encoded_gen_1 = generation_mutated(encoded_gen_2);
//         ++iteration;
//     }
//     gen = decoding(encoded_gen_1);
//     return gen;
// }


int main(int argc, char** argv) {
    const int max_iterations =100;
    const float probability_mutation = 0.02;
    const int population_size = 10;
    const int number_of_cities = 20;
    ga_tsp test(max_iterations,probability_mutation,population_size,number_of_cities);
    TSP problem;
    problem = test.initial_TSP();
    // gen = test.evolution();
    // float result=0.0;
    // float temp=0.0;
    // int max_index;
    // for(int i=0; i<gen.size();++i)
    // {
    //     temp = test.fitness_function(gen[i]);
    //     if(result<=temp)
    //     {
    //         result = temp;
    //         max_index =i;
    //     }
    // }
    for(int i=0;i<problem.size();++i)
    {
        std::cout << " index: " << problem[i].index<<"\n";   
        std::cout << " x: " << problem[i].coordinates.first<<"\n";
        std::cout << " y: " << problem[i].coordinates.second<<"\n";
    }
    // std::cout << " x: " << gen[max_index]<<"\n";
    // std::cout << " fitness: " << result<<"\n";
    return 0;
}