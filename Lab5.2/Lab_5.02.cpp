#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
double S(const double x, const double eps, int& n, double s, double& arth);
double A(const double x, const int n, double a);

int main()
{
    double xp, xk, x, dx, eps, s = 0, arth = 0;
    int n = 0;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;
    cout << fixed;
    cout << "-----------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << "   |"
        << setw(10) << "Arth x " << " |"
        << setw(7) << "S" << "    |"
        << setw(5) << "n" << " |"
        << endl;
    cout << "-----------------------------------------" << endl;
    x = xp;
    if (abs(xk) < 1 && abs(xp) < 1) {
        while (x <= xk)
        {
            s = S(x, eps, n, s, arth);
            cout << "|" << setw(7) << setprecision(2) << x << " |"
                << setw(10) << setprecision(5) << arth << " |"
                << setw(10) << setprecision(5) << s << " |"
                << setw(5) << n << " |"
                << endl;
            x += dx;
        }
        cout << "-------------------------------------------------" << endl;
    }
    else
        cout << "end";

    return 0;
}

double S(const double x, const double eps, int& n, double s, double& arth)
{
    n = 0;
    double a = x;
    s = a;
    do {
        n++;
        a = A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
    arth = (1.0 / 2 * log((1 + x) / (1 - x)));
    return s;
}

double A(const double x, const int n, double a)
{
    double R = (2 * n * x * x - x * x) / (2 * n + 1);
    a *= R;
    return a;
}