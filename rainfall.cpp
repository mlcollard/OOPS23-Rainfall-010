/*
    rainfall.cpp

    Rainfall report. Inputs are rain amounts per hour. Output is the average
    and heaviest hourly rainfall.
*/

#include <iostream>
#include <iomanip>
#include <vector>

int main() {

    // input hourly rainfall data
    std::vector<double> rainfall;
    double n;
    while (std::cin >> n) {
        rainfall.push_back(n);
    }
    if (!rainfall.size()) {
        std::cerr << "Error: no rainfall data\n";
        return 1;
    }

    // calculate heaviest rainfall
    auto heaviest = rainfall[0];
    for (const auto rain: rainfall) {
        if (rain > heaviest)
            heaviest = rain;
    }

    // calculate average rainfall
    auto total = 0.0;
    for (const auto rain: rainfall) {
        total += rain;
    }
    const auto average = (total / rainfall.size());

    // output the rainfall report
    std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
    std::cout << "|:----------------|----------------|" << '\n';
    std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << average << " |" << '\n';
    std::cout << "| Heaviest        |     " << std::left << std::setw(10) << heaviest << " |" << '\n';

    return 0;
}
