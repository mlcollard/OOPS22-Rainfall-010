/*
    Aggregate.cpp

    Implementation file for aggregate functions
*/

#include "Aggregate.hpp"
#include <numeric>
#include <algorithm>

// average of the container
double avg(const std::vector<double>& data) {

    return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
}

// maximum value in the container
double maximum(const std::vector<double>& data) {

    return *std::max_element(data.begin(), data.end());
}
