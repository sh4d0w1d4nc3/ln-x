#include <iostream>
#include <fstream>
using namespace std;
double lnx(double x, double e)
{
    double p, rez;
    int i;
    x--;
    p = rez = x;
    i = 2;
    while (fabs(p) >= e)
    {
        p *= -x;
        rez += p / i;
        i++;
    }
    return rez;
}
int main() {
    setlocale(LC_ALL, "Ru");
    long double x, e;
    cout << "введите точность ";
    cin >> e;
    ifstream in("in.txt");
    ofstream out("out.txt");
    in >> x;
    if (x == 1) {
        out << 0 << endl;
    }
    if (x < 0 || e < 0) {
        out << "ОШИБКА" << endl;
    }
    if (x < 1 && e > 0)
    {
        out << lnx(x, e);
    }
    if (x > 1) {
        x = 1 / x;
        out << -lnx(x, e) << endl;
    }
    return 0;
}
