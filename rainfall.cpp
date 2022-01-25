 /*
    rainfall.cpp

    Rainfall report. Inputs are rain amounts per hour. Output is the average
    and heaviest hourly rainfall.
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

// maximum value in the container
double maximum(const std::vector<double>& data) {

    return *std::max_element(data.begin(), data.end());
}

int main() {

    // input hourly rainfall data
    const std::vector<double> rainfall{ std::istream_iterator<double>(std::cin),
                                        std::istream_iterator<double>() };
    if (!rainfall.size()) {
        std::cerr << "Error: no rainfall data\n";
        return 1;
    }

    // calculate average rainfall
    const auto average = std::accumulate(rainfall.begin(), rainfall.end(), 0.0) / rainfall.size();

    // output the rainfall report
    std::cout << "Average Hourly Rainfall: " << std::fixed << std::setprecision(2) << average << " hundreds of inches" << '\n';
    std::cout << "Heaviest Hourly Rainfall: " << maximum(rainfall) << " hundreds of inches" << '\n';

    return 0;
}
