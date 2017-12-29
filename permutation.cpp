#include <iostream>
#include <vector>

using namespace std;

void permutationWithRepetition(const vector<int> &array, const int n, const int r)
{
    vector<int> chosen(r + 1);

    for (int i = 0; i < r + 1; i++)
        chosen[i] = 0;

    while (chosen[r] == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0 ; j < r; j++)
            {
                cout << array[chosen[j]] << " ";
            }
            chosen[0]++;
            cout << endl;
        }

        for (int i = 0; i < r; i++)
        {
            if (chosen[i] == n)
            {
                chosen[i] = 0;
                chosen[i + 1]++;
            }
        }
    }
}

int main(int argc, char **argv)
{
    vector<int> array = {0, 1, 2, 3, 4};
    permutationWithRepetition(array, 5, 3);

    return 0;
}