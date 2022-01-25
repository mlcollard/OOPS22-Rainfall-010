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

// average of the container
double avg(const std::vector<double>& data) {

    return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
}

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

    // output the rainfall report
    std::cout << "Average Hourly Rainfall: " << std::fixed << std::setprecision(2) << avg(rainfall) << " hundreds of inches" << '\n';
    std::cout << "Heaviest Hourly Rainfall: " << maximum(rainfall) << " hundreds of inches" << '\n';

    return 0;
}
