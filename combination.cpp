#include <iostream>

using namespace std;

void combinationWithRepetitionUtil(int *chosen, int *array, 
    int index, int r, int start, int end)
{
    if (index == r)
    {
        for (int i = 0; i < r; i++)
            cout << array[chosen[i]] << " ";
        cout << endl;
        return;
    }

    for (int i = start; i <= end; i++)
    {
        chosen[index] = i;
        combinationWithRepetitionUtil(chosen, array, index + 1, r, i, end);
    }
}

void combinationWithRepetition(int *array, int n, int r)
{
    int chosen[r + 1];

    combinationWithRepetitionUtil(chosen, array, 0, r, 0, n - 1);
}

int main(int argc, char **argv)
{
    int array[] = {0, 1, 2, 3, 4};
    combinationWithRepetition(array, 5, 3);

    return 0;
}