#include <armadillo>

#include <iostream>

int main()
{
    using namespace std;
    using namespace arma;
    auto A = mat(4, 5, fill::randu);
    auto B = mat(4, 5, fill::randu);

    cout << A * B.t() << endl;
    cout << "Test PASSED.\n";
}
