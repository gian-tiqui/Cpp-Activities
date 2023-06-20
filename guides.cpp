#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <unordered_map>

using std::cout;
using std::string;

#define ARRAYSIZEM(b) (sizeof(b) / sizeof(b[0]))

template<typename T>
void print_new_line(T &num) {
    for (int i = num; i >= 0; --i) cout << '\n';
}

class Guides {
public:
    struct Values {
        int x, y;
    };

    void print_range(int start, int end) {
        for (auto i = start; i != end; i++)
            cout << i << '\n';
    }

    void print_data(const std::vector<int> &data) {
        for (auto i : data)
            cout << i << ' ';
    }

    bool find_positive(const std::vector<int> &data) {
        const auto is_positive = [](int x) { return x > 0; };
        auto it = std::find_if(data.cbegin(), data.cend(), is_positive);
        return (it != data.cend());
    }

    void c_style(int *arr, int n) {
        
    }

    template <std::size_t size>
    void std_style(std::array<int, size> &arr) {
    }

    void use_std_array() {
        const int n = 256;
        int arr_c_style[n] = {0};
        std::array<int, n> arr_std_style{};
    }

    void loop_map_items() {
        std::unordered_map<string, int> nums = {
            {"one", 1},
            {"two", 2},
            {"three", 3},
        };

        for (const auto &entry : nums) cout << entry.first << " " << entry.second << '\n';
    }

    Values get_values_return_struct(int n) {
        return {n, n + 1};
    }

    void use_values() {
        auto values = get_values_return_struct(2);
        cout << values.x << " " << values.y;
    }

    constexpr int sum_of_1_to_n(int n) {
        return n * (n + 1) / 2;
    }

    void uses_sum() {
        const int limit = 1000;
        auto triangle_n = sum_of_1_to_n(limit);
        cout << triangle_n;
    }

    string *holder(string str) {
        string *ptr = &str;

        return ptr;
    }

    void use_holder() {
        std::vector<string> v;

        string s = *holder("meow");

        cout << *(&s) << '\n';

        v.push_back(s);

        for (auto i : v)
            cout << &i << '\n';
    }

    int get_min_using_set_notation() {
        cout << std::min({1, 2, 3, 4, 5});
    }

    template <typename T, size_t N>
    size_t ARRAYSIZET(T (&a)[N]) {
        return N;
    }

    void use_func_above_me() {
        int a[] = {1, 2, 3, 4, 5, 6};

        std::cout << ARRAYSIZEM(a) << '\n';
        std::cout << ARRAYSIZET(a) << '\n';
    }

    void try_catch() {
        int n;

        while (true) {
            try {
                std::cin >> n;
                if (!std::cin.fail())       
                    break;
                else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::runtime_error("Invalid input");
                }
            } catch (const std::exception &e) {
                std::cout << "This is not a number" << '\n';
            }
        }

        cout << n;
    }

    int find_index(std::vector<int> &vec, int &target) {
        auto it = std::find(vec.begin(), vec.end(), target);

        if (it != vec.end()) {
            int index = std::distance(vec.begin(), it);

            return index;
        }

        return -1;
    }
};

int main() {

    return 0;
}