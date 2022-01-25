 /*
    rainfall.cpp

    Rainfall report. Inputs are rain amounts per hour. Output is the average
    and heaviest hourly rainfall.
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>

// average of the container
double avg(const std::vector<double>& data) {

    double total = 0.0;
    for (const auto item : data) {
        total += item;
    }

    return total / data.size();
}

int main() {

    // input hourly rainfall data
    const std::vector<double> rainfall{ std::istream_iterator<double>(std::cin),
                                        std::istream_iterator<double>() };
    if (!rainfall.size()) {
        std::cerr << "Error: no rainfall data\n";
        return 1;
    }

    // calculate heaviest rainfall
    auto max = rainfall[0];
    for (const auto rain : rainfall) {
        if (rain > max)
            max = rain;
    }

    // output the rainfall report
    std::cout << "Average Hourly Rainfall: " << std::fixed << std::setprecision(2) << avg(rainfall) << " hundreds of inches" << '\n';
    std::cout << "Heaviest Hourly Rainfall: " << max << " hundreds of inches" << '\n';

    return 0;
}
