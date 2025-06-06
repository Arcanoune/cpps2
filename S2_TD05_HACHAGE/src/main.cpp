// #include <iostream>
// #include <string>

// size_t folding_string_hash(std::string const &s, size_t max)
// {
//     size_t hash = 0;
//     for (char c : s)
//         hash = (hash + static_cast<size_t>(c)) % max;
//     return hash;
// }

// size_t folding_string_ordered_hash(std::string const &s, size_t max)
// {
//     size_t hash = 0;
//     for (size_t i = 0; i < s.size(); ++i)
//         hash = (hash + static_cast<size_t>(s[i]) * (i + 1)) % max;
//     return hash;
// }

// size_t polynomial_rolling_hash(std::string const &s, size_t p, size_t m)
// {
//     size_t hash = 0, power = 1;
//     for (char c : s)
//     {
//         hash = (hash + static_cast<size_t>(c) * power) % m;
//         power = (power * p) % m;
//     }
//     return hash;
// }

// int main()
// {
//     std::string s = "abc";
//     size_t max = 1024;
//     size_t p = 31, m = 1000000009;

//     std::cout << "folding_string_hash: " << folding_string_hash(s, max) << "\n";
//     std::cout << "folding_string_ordered_hash: " << folding_string_ordered_hash(s, max) << "\n";
//     std::cout << "polynomial_rolling_hash: " << polynomial_rolling_hash(s, p, m) << "\n";

//     return 0;
// }

/////////////////////////////

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <random>
// #include <functional>
// #include <iomanip>

// enum class Insect
// {
//     ClassicBee,
//     Ladybug,
//     Butterfly,
//     Dragonfly,
//     Ant,
//     Grasshopper,
//     Beetle,
//     Wasp,
//     Caterpillar,
//     Spider,
//     GuimielBee
// };

// std::vector<Insect> const insect_values{
//     Insect::ClassicBee,
//     Insect::Ladybug,
//     Insect::Butterfly,
//     Insect::Dragonfly,
//     Insect::Ant,
//     Insect::Grasshopper,
//     Insect::Beetle,
//     Insect::Wasp,
//     Insect::Caterpillar,
//     Insect::Spider,
//     Insect::GuimielBee};

// std::unordered_map<Insect, std::string> const insect_to_string = {
//     {Insect::ClassicBee, "ClassicBee"},
//     {Insect::Ladybug, "Ladybug"},
//     {Insect::Butterfly, "Butterfly"},
//     {Insect::Dragonfly, "Dragonfly"},
//     {Insect::Ant, "Ant"},
//     {Insect::Grasshopper, "Grasshopper"},
//     {Insect::Beetle, "Beetle"},
//     {Insect::Wasp, "Wasp"},
//     {Insect::Caterpillar, "Caterpillar"},
//     {Insect::Spider, "Spider"},
//     {Insect::GuimielBee, "GuimielBee"}};

// std::vector<int> const expected_insect_counts{
//     75,  // ClassicBee
//     50,  // Ladybug
//     100, // Butterfly
//     20,  // Dragonfly
//     400, // Ant
//     150, // Grasshopper
//     60,  // Beetle
//     10,  // Wasp
//     40,  // Caterpillar
//     90,  // Spider
//     5,   // GuimielBee
// };

// std::vector<std::pair<Insect, int>> get_insect_observations(
//     size_t n, std::vector<float> const &probs, unsigned int seed = 0)
// {
//     std::default_random_engine re(seed);
//     auto rand_index = std::bind(std::discrete_distribution<size_t>{probs.begin(), probs.end()}, re);
//     std::vector<std::pair<Insect, int>> obs;
//     for (size_t i = 0; i < n; ++i)
//     {
//         Insect insect = insect_values[rand_index()];
//         if (!obs.empty() && obs.back().first == insect)
//         {
//             obs.back().second++;
//             i--;
//         }
//         else
//         {
//             obs.push_back({insect, 1});
//         }
//     }
//     return obs;
// }

// std::vector<float> probabilities_from_count(std::vector<int> const &counts)
// {
//     float sum = 0;
//     for (int c : counts)
//         sum += c;
//     std::vector<float> res;
//     for (int c : counts)
//         res.push_back(c / sum);
//     return res;
// }

// int main()
// {
//     auto probs = probabilities_from_count(expected_insect_counts);
//     auto obs = get_insect_observations(10000, probs, 42);

//     std::unordered_map<Insect, int> counts;
//     for (auto &[i, n] : obs)
//         counts[i] += n;

//     std::vector<int> observed_counts;
//     for (auto &i : insect_values)
//         observed_counts.push_back(counts[i]);

//     auto observed_probs = probabilities_from_count(observed_counts);

//     std::cout << std::fixed << std::setprecision(3);
//     std::cout << "Probabilities of observed insects vs expected probabilities\n";
//     for (size_t i = 0; i < insect_values.size(); ++i)
//     {
//         float diff = std::abs(observed_probs[i] - probs[i]);
//         std::cout << insect_to_string.at(insect_values[i]) << " : "
//                   << observed_probs[i] << " vs " << probs[i] << " "
//                   << (diff < 0.01 ? "OK" : "BAD") << "\n";
//     }
// }

/////////////////////////////

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstdlib>

enum class CardKind
{
    Heart,
    Diamond,
    Club,
    Spade
};

enum class CardValue
{
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

struct Card
{
    CardKind kind;
    CardValue value;

    bool operator==(Card const &other) const
    {
        return kind == other.kind && value == other.value;
    }

    size_t hash() const
    {
        return static_cast<size_t>(static_cast<int>(kind) * 13 + static_cast<int>(value));
    }
};

namespace std
{
    template <>
    struct hash<Card>
    {
        size_t operator()(Card const &card) const
        {
            return card.hash();
        }
    };
}

#include <vector>
std::vector<Card> get_cards(size_t const size)
{
    std::vector<Card> cards{};
    cards.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::string card_name(Card const &card)
{
    std::string name{};

    unsigned int card_value{(static_cast<unsigned int>(card.value) + 2) % 14};

    if (card_value < 10)
    {
        name += '0' + std::to_string(card_value);
    }
    else if (card_value == 10)
    {
        name += "10";
    }
    else if (card_value == 11)
    {
        name += 'J';
    }
    else if (card_value == 12)
    {
        name += 'Q';
    }
    else if (card_value == 13)
    {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart)
    {
        name += "Heart";
    }
    else if (card.kind == CardKind::Diamond)
    {
        name += "Diamond";
    }
    else if (card.kind == CardKind::Club)
    {
        name += "Club";
    }
    else if (card.kind == CardKind::Spade)
    {
        name += "Spade";
    }
    return name;
}

int main()
{
    std::srand(static_cast<unsigned int>(time(nullptr)));

    auto cards = get_cards(100);
    std::unordered_map<Card, int> counter;

    for (auto const &card : cards)
    {
        counter[card]++;
    }

    for (auto const &[card, count] : counter)
    {
        std::cout << card_name(card) << " : " << count << '\n';
    }

    return 0;
}
