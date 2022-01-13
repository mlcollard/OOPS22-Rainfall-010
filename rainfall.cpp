/*
    rainfall.cpp

    Rainfall report. Inputs are rain amounts per hour. Output is the average
    and heaviest hourly rainfall.
*/

#include <iostream>
#include <iomanip>
#include <vector>

int main() {
    std::vector<float> rainfall;
    float t;
    float m;
    float n;
    while (std::cin >> n) {
        rainfall.push_back(n);
    }
    if (!rainfall.size()) {
        std::cerr << "Error: no rainfall data";
        return 1;
    }
    t = rainfall[0];
    m = rainfall[0];
    for (std::vector<float>::size_type i = 1; i < rainfall.size(); ++i) {
        t += rainfall[i];
        if (rainfall[i] > m)
            m = rainfall[i];
    }
    std::cout << "Average Hourly Rainfall: " << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " hundreds of inches" << '\n';
    std::cout << "Heaviest Hourly Rainfall: " << m << " hundreds of inches" << '\n';

    return 0;
}
