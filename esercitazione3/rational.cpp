#include <iostream>
#include "rational.hpp"

int main(void) {
    rational<int> a(7,3); //creo la frazione
    rational<int> b(2,5);
    rational<int> c = a + b; //sommo le frazioni
    std::cout << "Numeratore di a: " << a.num() << " " << "Denominatore di a: " << a.den() << "\n"; //stampo numeratore e denominatore di a
    std::cout << "Numeratore di b: " << b.num() << " " << "Denominatore di b: " << b.den() << "\n"; //stampo numeratore e denominatore di b
    std::cout << "Somma: " << c << "\n"; //stampo c
    rational<int> d = a - b;  //sottraggo le frazioni
    std::cout << "Sottrazione: " << d << "\n";
    rational<int> e = a  * b;  //moltiplico le frazioni
    std::cout << "Moltiplicazione: " << e << "\n";
    rational<int> f = a / b;  //divido le frazioni
    std::cout << "Divisione: " << f << "\n";
    return 0;
}

