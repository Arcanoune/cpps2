// exo1 //

// #include <iostream>
// #include <vector>
// #include <algorithm>

// bool is_sorted(std::vector<int> const &vec)
// {
//     return std::is_sorted(vec.begin(), vec.end());
// }

// void bubble_sort(std::vector<int> &vec)
// {
//     int n = vec.size();
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (vec[j] > vec[j + 1])
//             {
//                 std::swap(vec[j], vec[j + 1]);
//             }
//         }
//     };
// }

// int main()
// {
//     std::vector<int> array{1, 2, 3, 8, 5, 6, 4, 9, 7};
//     if (is_sorted(array))
//     {
//         std::cout << "Le tableau est trié" << std::endl;
//     }
//     else
//     {
//         std::cout << "Le tableau n'est pas trié" << std::endl;
//         bubble_sort(array);
//         std::cout << "tableau trié maintenant : ";
//         for (int num : array)
//         {
//             std::cout << num << " ";
//         }
//         std::cout << std::endl;
//     }
//     return 0;
// }

/////////////////////////////////////////////////////////////////////::

// ex2 //
// #include <iostream>
// #include <vector>
// #include <algorithm>

// bool is_sorted(std::vector<int> const &vec)
// {
//     return std::is_sorted(vec.begin(), vec.end());
// }

// void merge(std::vector<int> &vec, size_t left, size_t middle, size_t right)
// {
//     std::vector<int> gauche(vec.begin() + left, vec.begin() + middle + 1);
//     std::vector<int> droite(vec.begin() + middle + 1, vec.begin() + right + 1);

//     size_t i = 0, j = 0, k = left;
//     while (i < gauche.size() && j < droite.size())
//     {
//         if (gauche[i] <= droite[j])
//             vec[k++] = gauche[i++];
//         else
//             vec[k++] = droite[j++];
//     }

//     while (i < gauche.size()) vec[k++] = gauche[i++];
//     while (j < droite.size()) vec[k++] = droite[j++];
// }

// void merge_sort(std::vector<int> &vec, size_t left, size_t right)
// {
//     if (left < right)
//     {
//         size_t middle = left + (right - left) / 2;
//         merge_sort(vec, left, middle);
//         merge_sort(vec, middle + 1, right);
//         merge(vec, left, middle, right);
//     }
// }

// void merge_sort(std::vector<int> &vec)
// {
//     merge_sort(vec, 0, vec.size() - 1);
// }

// int main()
// {
//     std::vector<int> array{1, 2, 3, 8, 5, 6, 4, 9, 7};
//     if (is_sorted(array))
//     {
//         std::cout << "Le tableau est trié" << std::endl;
//     }
//     else
//     {
//         std::cout << "Le tableau n'est pas trié" << std::endl;
//         merge_sort(array);
//         std::cout << "Tableau trié maintenant : ";
//         for (int num : array)
//         {
//             std::cout << num << " ";
//         }
//         std::cout << std::endl;
//     }
//     return 0;
// }

/////////////////////////////////////////////////////////////////////::

// ex3 //
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cstdlib>
// #include <ctime>
// #include "ScopedTimer.hpp"

// bool is_sorted(std::vector<int> const &vec)
// {
//     return std::is_sorted(vec.begin(), vec.end());
// }

// std::vector<int> generate_random_vector(size_t const size, int const max = 100)
// {
//     std::vector<int> vec(size);
//     std::generate(vec.begin(), vec.end(), [&max]()
//                   { return std::rand() % max; });
//     return vec;
// }

// void bubble_sort(std::vector<int> &vec)
// {
//     ScopedTimer timer("chrono bubble");

//     int n = vec.size();
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (vec[j] > vec[j + 1])
//             {
//                 std::swap(vec[j], vec[j + 1]);
//             }
//         }
//     };
// }

// void merge(std::vector<int> &vec, size_t left, size_t middle, size_t right)
// {
//     ScopedTimer timer("chrono merge");

//     std::vector<int> gauche(vec.begin() + left, vec.begin() + middle + 1);
//     std::vector<int> droite(vec.begin() + middle + 1, vec.begin() + right + 1);

//     size_t i = 0, j = 0, k = left;
//     while (i < gauche.size() && j < droite.size())
//     {
//         if (gauche[i] <= droite[j])
//             vec[k++] = gauche[i++];
//         else
//             vec[k++] = droite[j++];
//     }

//     while (i < gauche.size())
//         vec[k++] = gauche[i++];
//     while (j < droite.size())
//         vec[k++] = droite[j++];
// }

// void merge_sort(std::vector<int> &vec, size_t left, size_t right)
// {
//     ScopedTimer timer("chrono merge sort");

//     if (left < right)
//     {
//         size_t middle = left + (right - left) / 2;
//         merge_sort(vec, left, middle);
//         merge_sort(vec, middle + 1, right);
//         merge(vec, left, middle, right);
//     }
// }

// void merge_sort(std::vector<int> &vec)
// {
//     ScopedTimer timer("chrono merge sort2");

//     merge_sort(vec, 0, vec.size() - 1);
// }

// void sort_bibli(std::vector<int> &vec)
// {
//     ScopedTimer timer("chrono bibli");
//     std::sort(vec.begin(), vec.end());
// }

// int main()
// {
//     std::srand(std::time(nullptr));
//     std::vector<int> array = generate_random_vector(10000, 100000);

//     if (is_sorted(array))
//     {
//         std::cout << "Le tableau est déjà trié." << std::endl;
//     }
//     else
//     {
//         std::cout << "Le tableau n'est pas trié, tri en cours..." << std::endl;

//         {
//             std::vector<int> array1 = array;
//             ScopedTimer timer("Temps Bubble Sort");
//             bubble_sort(array1);
//         }

//         {
//             std::vector<int> array2 = array;
//             ScopedTimer timer("Temps Merge Sort");
//             merge_sort(array2);
//         }

//         {
//             std::vector<int> array3 = array;
//             ScopedTimer timer("Temps std::sort");
//             std::sort(array3.begin(), array3.end());
//         }

//         std::cout << "Tri terminé !" << std::endl;
//     }

//     return 0;
// }

/////////////////////////////////////////////////////////////////////::

// ex4 //

#include <iostream>
#include <vector>

int search(std::vector<int> &vec, int value)
{
    int left = 0, right = vec.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (vec[mid] == value)
            return mid;
        if (vec[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    std::vector<std::vector<int>> test_cases = {
        {1, 2, 2, 3, 4, 8, 12},
        {1, 2, 3, 3, 6, 12, 14, 15},
        {2, 2, 3, 4, 5, 8, 12, 15, 16},
        {5, 6, 7, 8, 9, 10, 11, 12, 13},
        {1, 2, 3, 4, 5, 6, 7, 8, 9}};
    std::vector<int> values = {8, 15, 16, 6, 10};

    for (size_t i = 0; i < test_cases.size(); ++i)
    {
        int result = search(test_cases[i], values[i]);
        std::cout << "Valeur " << values[i] << (result != -1 ? " trouvee a l'indice " + std::to_string(result) : " pas trouvee") << std::endl;
    }

    return 0;
}