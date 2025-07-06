#include <iostream>
#include <vector>
#include <iomanip>
#define FIRFilter
#define fir
int main() {
    // Example: Low-pass filter (moving average with 4 taps)
    std::vector<float> fir_coeffs = {0.25f, 0.25f, 0.25f, 0.25f};
    FIRFilter fir(fir_coeffs);

    // Input signal (step input)
    std::vector<float> input = {1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<float> output;

    std::cout << "Input\tOutput\n";
    for (float sample : input) {
        float y = fir.process(sample);
        output.push_back(y);
        std::cout << std::fixed << std::setprecision(3) << sample << "\t" << y << "\n";
    }

    return 0;
}
