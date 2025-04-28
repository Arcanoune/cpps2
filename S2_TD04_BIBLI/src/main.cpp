#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    // Vecteur
    std::vector<int> array{10, 26, 53, 8, 54, 66, 4, 91, 17};

    // Affichage vecteur
    for (std::vector<int>::iterator it{array.begin()}; it != array.end(); ++it)
    {
        std::cout << *it << ", ";
    }

    // Demandez le guessz
    std::cout << std::endl
              << "Ton guess : ";
    int guess{0};
    std::cin >> guess;

    // Vérifiez le guess dans le vecteur
    auto it{std::find(array.begin(), array.end(), guess)};
    if (it != array.end())
    {
        std::cout << *it << std::endl;
    }
    else
    {
        std::cout << "Element not found" << std::endl;
    }

    // Compter les occurrences
    int count = std::count(array.begin(), array.end(), guess);
    std::cout << "Occurrences de " << guess << " : " << count << std::endl;

    // Trier le vecteur
    std::sort(array.begin(), array.end());
    std::cout << "Vecteur dans l'ordre : ";
    for (int num : array)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}







/////////////////////////////////////

auto const is_space = [](char letter)
{ return letter == ' '; };

// Longueur premier mot
int first_word_length(std::string const &str)
{
    auto first = std::find_if_not(str.begin(), str.end(), is_space);
    auto last = std::find_if(first, str.end(), is_space);
    return std::distance(first, last);
}

// Découper phrase
std::vector<std::string> split_string(std::string const &str)
{
    std::vector<std::string> words;
    auto it = str.begin();

    while (it != str.end())
    {
        // Début du mot
        it = std::find_if_not(it, str.end(), is_space);
        if (it == str.end())
            break;

        // Fin du mot
        auto last = std::find_if(it, str.end(), is_space);

        // Ajouter le mot au vecteur
        words.emplace_back(it, last);

        // Continuer après le mot trouvé
        it = last;
    }

    return words;
}

int main()
{
    // Phrase
    std::string phrase;
    std::cout << "Entre une phrase : ";
    std::getline(std::cin, phrase);

    // Longueur du premier mot
    std::cout << "Longueur du premier mot : " << first_word_length(phrase) << std::endl;

    // Découper la phrase
    std::vector<std::string> mots = split_string(phrase);

    // Affichage des mots
    std::cout << "Mots : ";
    for (std::string const &mot : mots)
    {
        std::cout << mot << ", ";
    }
    std::cout << std::endl;

    return 0;
}



//////////////////////////////////

bool estPalindrome(const std::string& str)
{
    return std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin());
}

int main()
{
    std::cout << "Entre un mot : ";
    std::string mot;
    std::cin >> mot;

    if (estPalindrome(mot))
    {
        std::cout << "palindrome" << std::endl;
    }
    else
    {
        std::cout << "pas palindrome" << std::endl;
    }

    return 0;
}
