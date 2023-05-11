///////////////////////////////////////////////////////////////////////////////
/// A. Bhargave "Grokking Algorithms" -- Binary Search
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

bool binary_search(const vector<int> src, int item)
{
    unsigned int low = 0;
    unsigned int high = src.size() - 1;
    bool result = false; // Флаг поиска
    int midle_index; // Индек медианного элемента
    int current; // Текущее значение из вектора

    // Условие нужно только для последнего индекса,
    // т.к. округляем в меньшую сторону
    if ((src[low] == item) || (src[high] == item))
        return true;

    while (low < high)
    {
        midle_index = floor((low + high) / 2);
        current = src[midle_index];
        if (current == item)
        {
            result = true;
            break;
        }
        else if (current > item)
            high = midle_index - 1;
        else
            low = midle_index + 1;
    }

    return result;
}

int generator()
{
    return rand()%10;
}

int main()
{
    srand(unsigned(time(nullptr)));
    vector<int> src(10);
    generate(src.begin(), src.end(), generator);
    // Бинарный поиск работает только с отсортированным массивом
    sort(src.begin(), src.end());

    int item = 7;
    bool result = binary_search(src, item);

    for (auto &it: src) {
        cout << it << endl;
    }
    cout << "Result: " << result << endl;

    return 0;
}
