#include <iostream>
#include <vector>
#include <chrono>
#include "solution.hpp"

// Solución ingenua (O(n)) para comparar
int naive_search(const std::vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    Solution sol;

    // Arreglo muy grande para estresar el algoritmo
    const int SIZE = 10000000; 
    std::vector<int> nums;
    nums.reserve(SIZE); // Buena práctica STL [cite: 195]

    // Llenar el arreglo: [5000000, 5000001 ... 9999999, 0, 1 ... 4999999]
    for (int i = SIZE / 2; i < SIZE; ++i) nums.push_back(i);
    for (int i = 0; i < SIZE / 2; ++i) nums.push_back(i);

    int target = (SIZE / 2) - 1; // El peor caso: buscar el último elemento del arreglo

    std::cout << "--- Iniciando Benchmark (Arreglo de " << SIZE << " elementos) ---" << std::endl;

    // Solución Ingenua O(n)
    auto start_naive = std::chrono::high_resolution_clock::now();
    int result_naive = naive_search(nums, target);
    auto end_naive = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time_naive = end_naive - start_naive;

    std::cout << "Busqueda Lineal O(n) encontro el indice: " << result_naive 
              << " en " << time_naive.count() << " ms" << std::endl;

    // Solución  O(log n)
    auto start_elite = std::chrono::high_resolution_clock::now();
    int result_elite = sol.search(nums, target);
    auto end_elite = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time_elite = end_elite - start_elite;

    std::cout << "Busqueda Binaria O(log n) encontro el indice: " << result_elite 
              << " en " << time_elite.count() << " ms" << std::endl;

    // Conclusión
    std::cout << "\nConclusion: La busqueda binaria es " 
              << (time_naive.count() / time_elite.count()) 
              << " veces mas rapida en este escenario." << std::endl;

    return 0;
}