#define _USE_MATH_DEFINES

#include <iostream>
#include <random>
#include <cmath>

using namespace std;

constexpr auto N = 40000000000;

int main()
{
    double l = 1, d = 2, k = 0, r = l / 2;
    mt19937 rng;
    rng.seed(random_device{}());
    uniform_real_distribution<double> dist1(0.0, d / 2.0);
    uniform_real_distribution<double> dist2(0.0, M_PI);
    for (int i = 1; i <= N; i++)
    {
        double kozepponttav = dist1(rng);
        double alfa = dist2(rng);
        if (kozepponttav <= r * sin(alfa))
        {
            k++;
        }

    }

    double kozelites = (2 * l * N) / (d * k);
    cout << kozelites << endl;
    
    return 0;
}
