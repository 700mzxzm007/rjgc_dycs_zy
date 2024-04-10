#pragma once
#include<iostream>
#include<vector>
#include<random>

std::vector<int> generate_random_array4() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1000, 9999);
    std::uniform_int_distribution<> value(-99, 99);
    int n = dis(gen);
    std::vector<int>arr(n);
    int i = 0;
    for (int i = 0; i < n; i++) {
        arr[i] = value(gen);
    }
    return arr;

}
std::vector<int> generate_random_array5() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(10000, 99999);
    std::uniform_int_distribution<> value(-99, 99);
    int n = dis(gen);
    std::vector<int>arr(n);
    int i = 0;
    for (int i = 0; i < n; i++) {
        arr[i] = value(gen);
    }
    return arr;

}


