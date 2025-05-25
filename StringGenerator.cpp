#include "StringGenerator.hpp"
#include <fstream>
#include <random>
#include <algorithm>
#include <iostream>

StringGenerator::StringGenerator(size_t min_length, size_t max_length, const std::string& alphabet)
    : min_length_(min_length)
    , max_length_(max_length)
    , alphabet_(alphabet)
    , rng_(std::random_device{}())
{}

std::vector<std::string> StringGenerator::generate(size_t count) {
    std::vector<std::string> result;
    result.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        result.push_back(generateString());
    }
    
    return result;
}

std::string StringGenerator::generateString() {
    std::uniform_int_distribution<size_t> length_dist(min_length_, max_length_);
    std::uniform_int_distribution<size_t> char_dist(0, alphabet_.length() - 1);
    size_t length = length_dist(rng_);
    std::string result;
    result.reserve(length);
    for (size_t i = 0; i < length; ++i) {
        result += alphabet_[char_dist(rng_)];
    }
    
    return result;
} 