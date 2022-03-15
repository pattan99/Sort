#include <bits/stdc++.h>

using namespace std;

const string FOLDER_NAME = "";
const string TAIL = ".inp";
const int N = 1e6;

string FILE_NAME[] = {"Increasing", "Decreasing", "Random1", "Random2",
                      "Random3", "Random4", "Random5",
                      "Random6", "Random7", "Random8"};

double fRand(double fMin, double fMax)
{
    double f1 = (double)rand() * rand();
    double f2 = (double)RAND_MAX * RAND_MAX;
    double f = f1 / f2;
    return fMin + f * (fMax - fMin);
}

void CreateFile(string NAME)
{
    freopen((FOLDER_NAME + NAME + TAIL).c_str(), "w", stdout);

    cout.precision(3);

    vector<double> a;

    for (int i=0; i<N; ++i)
    {
        double bound = fRand(0.0, N);
        a.push_back(fRand(-bound, bound));
    }

    if (NAME == "Increasing")
        sort(a.begin(), a.end());
    else if (NAME == "Decreasing")
        sort(a.begin(), a.end(), greater<double>());

    for (auto i: a)
        cout << fixed << i << " ";
}

int main()
{
    srand(time(NULL));

    for (auto NAME: FILE_NAME)
    {
        CreateFile(NAME);
    }

    return 0;
}
