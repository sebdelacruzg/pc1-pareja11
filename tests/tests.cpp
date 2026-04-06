#include <iostream>
#include <vector>
#include <cassert>
#include "solution.hpp"

void test_search_in_rotated_array() {
    Solution sol;

    // Ejemplo 1 de LeetCode
    {
        std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 0;
        int result = sol.search(nums, target);
        assert(result == 4 && "Fallo en Caso Normal: target 0");
    }

    // Ejemplo 2 de LeetCode
    {
        std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 3;
        int result = sol.search(nums, target);
        assert(result == -1 && "Fallo en Caso Normal: target inexistente");
    }

    // Ejemplo 3 de LeetCode
    {
        std::vector<int> nums = {1};
        assert(sol.search(nums, 0) == -1 && "Fallo en array de 1 elemento, no encontrado");
        assert(sol.search(nums, 1) == 0 && "Fallo en array de 1 elemento, encontrado");
    }

    // Caso Borde diseñado por la pareja (Rotación de 0, array normal)
    {
        std::vector<int> nums = {1, 2, 3, 4, 5};
        assert(sol.search(nums, 5) == 4 && "Fallo en array sin rotar");
    }

    // Caso Borde (Target en los extremos del array)
    {
         std::vector<int> nums = {5, 1, 2, 3, 4};
         assert(sol.search(nums, 5) == 0 && "Fallo al buscar el pivote máximo");
         assert(sol.search(nums, 4) == 4 && "Fallo al buscar el último elemento");
    }

    std::cout << "¡Todos los tests pasaron exitosamente!" << std::endl;
}

int main() {
    test_search_in_rotated_array();
    return 0;
}