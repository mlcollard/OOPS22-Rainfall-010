/*
    Aggregate.cpp

    Implementation file for aggregate functions
*/

#include "Aggregate.hpp"
#include <numeric>

// average of the container
double avg(const std::vector<double>& data) {

    return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
}
