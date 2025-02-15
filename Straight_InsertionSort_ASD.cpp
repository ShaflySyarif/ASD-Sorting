#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
int *generate_random_int(int n)
{
    int *data = new int[n];

    for (int i = 0; i < n; i++)
    {
        data[i] = rand();
    }
    return data;
}

bool is_sorted(int *data, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (data[i - 1] > data[i])
        {
            return false;
        }
    }
    return true;
}

void sort(int *data, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = data[i];
        int j = i - 1;

        // Move elements of data[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}

int main()
{
    int num_of_experiments = 100;
    int *data;
    int n;
    // DEBUG
    // The program will stop if the sorting is incorrect
    n = 100;
    data = generate_random_int(n);
    sort(data, n);
    if (!is_sorted(data, n))
    {
        throw runtime_error("Sorting function ERROR.");
    }
    // EXPERIMENTS
    cout << "data, time (ms)\n";
    cout << " \n";
    for (int i = 1; i <= num_of_experiments; i++)
    {
        n = i * 1000;
        data = generate_random_int(n);
        auto start = chrono::high_resolution_clock::now();
        sort(data, n);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

        cout << n << ", " << duration.count() << "\n";

        delete data;
    }

    return 0;
}