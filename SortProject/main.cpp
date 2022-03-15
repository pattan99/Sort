#include <bits/stdc++.h>
#include <SortAlgorithm.h>

using namespace std;

const string FOLDER_NAME = "TEST/";
const string TAIL = ".inp";
const int N = 1e6;

string FILE_NAME[] = {"Increasing", "Decreasing", "Random1", "Random2",
                      "Random3", "Random4", "Random5",
                      "Random6", "Random7", "Random8"};

vector<double> Time;

void sort_time(string NAME)
{
    ifstream cin((FOLDER_NAME + NAME + TAIL).c_str());

    vector<double> a;

    for (int i=0; i<N; ++i)
    {
        double x;
        cin >> x;
        a.push_back(x);
    }

    clock_t start_time, end_time;

    VectorSort = a;
    start_time = clock();
    sort(VectorSort.begin(), VectorSort.end());
    end_time = clock();
    Time.push_back(double(end_time - start_time) / double(CLOCKS_PER_SEC));

    VectorSort = a;
    start_time = clock();
    QSort(0, N-1);
    end_time = clock();
    Time.push_back(double(end_time - start_time) / double(CLOCKS_PER_SEC));

    VectorSort = a;
    start_time = clock();
    MSort(0, N-1);
    end_time = clock();
    Time.push_back(double(end_time - start_time) / double(CLOCKS_PER_SEC));

    VectorSort = a;
    start_time = clock();
    HSort(N);
    end_time = clock();
    Time.push_back(double(end_time - start_time) / double(CLOCKS_PER_SEC));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (auto NAME: FILE_NAME)
    {
        sort_time(NAME);
    }

    freopen("TimeReport.csv", "w", stdout);

    cout << "Test,Sort C++,Quick Sort,Merge Sort,Heap Sort\n";
    int i = 0;
    for (auto NAME: FILE_NAME)
    {
        cout << NAME << ",";
        for (int j=0; j<3; ++j)
            cout << Time[i++] * 1000.0 << ",";
        cout << Time[i++] * 1000.0 << "\n";
    }

    return 0;
}
