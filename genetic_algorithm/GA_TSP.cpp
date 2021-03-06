//this is a simple example for genetic algorithm
//exmaple is to solve traving salesman problem

#include "GA_TSP.h"
// #include <bitset>
#include <math.h>
#include <iostream>
// #include <random>
#include <algorithm> 
// #include <matplotlibcpp.h>

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

chromosome ga_tsp::form_chromosome(TSP problem)
{
    chromosome chromo;
    chromo.push_back(problem[0]);
    problem.erase(problem.begin());
    for(int i=1;i<number_of_city;++i)
    {
        int index=rand() % problem.size();
        chromo.push_back(problem[index]);
        problem.erase(problem.begin() + index);
    }    
    return chromo;
}

generation ga_tsp::initial_generation(TSP& problem)
{
    generation gen;
    chromosome chromo;
    while(gen.size()<population_size)
    {
        chromo=form_chromosome(problem);
        if (std::find(gen.begin(), gen.end(), chromo) != gen.end())
        {
            continue;
        }
        else
        {
            gen.push_back(chromo);
        }
    }
    return gen;
}

float ga_tsp::distance(City& a, City& b)
{
    float temp1,temp2;
    temp1 = a.coordinates.first - b.coordinates.first;
    temp2 = a.coordinates.second - b.coordinates.second;
    return sqrt(temp1 * temp1 + temp2 * temp2);
}

float ga_tsp::get_fitness_for_chromosome(chromosome& chromo)
{
    float travel_distance=0.0;
    for(int i=0;i<chromo.size()-1;++i)
    {
        travel_distance += distance(chromo[i],chromo[i+1]);
    }
    travel_distance += distance(chromo.front(), chromo.back());
    return travel_distance;
}

fitness_map ga_tsp::get_fitness_for_generation(generation& gen)
{
    fitness_map fm;
    float temp=0.0;
    for(auto i:gen)
    {
        fm.emplace(get_fitness_for_chromosome(i),i);
    }
    return fm;
}
    
generation ga_tsp::select_chromosome(fitness_map& fm)
{
    generation gen;
    //keep chromosomo with highest fitness
    gen.push_back((fm.rbegin()->second));
    float total_fitness=0.0;
    float cumulated_fitness = 0.0;
    fitness_map probability_map;
    for(auto i:fm)
    {
        total_fitness += i.first;
    }
    for(auto i:fm)
    {
        cumulated_fitness += i.first;
        probability_map.emplace(cumulated_fitness/total_fitness, i.second);
    }
    // i: number of chromosome selected
    int i=population_size/2 -1;
    float roll=0.0;
    while(i>0)
    {
        roll = rand() % RAND_MAX / (float) RAND_MAX;
        gen.push_back(probability_map.lower_bound(roll)->second);
        --i;
    }
    return gen;
}

void ga_tsp::exchange_genes(chromosome& a, chromosome& b)
{
    //select a random location to swap genes;
    int i;
    i= rand() % a.size();
    City temp;
    // swap a[i],b[i];
    std::swap(a[i],b[i]);
    // if duplicates find in a
    if(std::count(a.begin(),a.end(),a[i])!=1)
    {
        
    }
}

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
    const int population_size = 20;
    const int number_of_cities = 20;
    ga_tsp test(max_iterations,probability_mutation,population_size,number_of_cities);
    TSP problem;
    problem = test.initial_TSP();
    // chromosome chromo;
    // chromo = test.form_chromosome(problem);
    generation gen;
    gen = test.initial_generation(problem);
    fitness_map fm;
    fm = test.get_fitness_for_generation(gen);
    gen = test.select_chromosome(fm);
    // gen = test.evolution();
    // float result=0.0;
    // float temp=0.0;
    int j=0;
    for(auto i=fm.begin();i!=fm.end();++i)
    {
        std::cout <<"index "<< j << " fitness " << i->first <<"\n";
        j++;
    }
    j=0;
    for(auto i=gen.begin();i!=gen.end();++i)
    {
        std::cout <<"index "<< j <<"\n";
        for(auto k=i->begin();k!=i->end();++k)
        {
            std::cout << k->index<<" " ;
        }
        j++;
    }
    return 0;
}