#include <iostream>
#include <vector>
#include <iomanip>

class FIRFilter {
private:
    std::vector<float> coeffs;      // Filter coefficients
    std::vector<float> buffer;      // Circular buffer for input history
    size_t order;                   // Number of taps

public:
    // Constructor
    FIRFilter(const std::vector<float>& coefficients) : coeffs(coefficients), order(coefficients.size()) {
        buffer.resize(order, 0.0f); // Initialize buffer with zeros
    }

    // Process a single sample
    float process(float input) {
        // Shift old values
        for (size_t i = order - 1; i > 0; --i) {
            buffer[i] = buffer[i - 1];
        }
        buffer[0] = input;

        // Compute output
        float output = 0.0f;
        for (size_t i = 0; i < order; ++i) {
            output += coeffs[i] * buffer[i];
        }

        return output;
    }
};
