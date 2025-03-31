#include <iostream>
#include <cmath>

using namespace std;

#define STACK_SIZE 8

template<typename T>
class complex_number {
private:
	T parte_reale;
    T parte_immaginaria;
public:
    complex_number() : parte_reale(0), parte_immaginaria(0)   // Costruttore di default  
	{}
	complex_number(T reale, T immaginaria): parte_reale(reale), parte_immaginaria(immaginaria)   // Costruttore user-defined
	{}
    complex_number<T> metodo_coniugato() const {
        return complex_number<T>(parte_reale, - parte_immaginaria);      // Metodo per il coniugato del numero complesso
    }
    T metodo_parte_reale() const {
        return parte_reale;     // Metodo che restituisce la parte reale
    }
    T metodo_parte_immaginaria() const {
        return parte_immaginaria;     // Metodo che restituisce la parte immaginaria
    }	
    complex_number<T>& operator+=(const complex_number<T>& other) {       // Overload operatore +=
        parte_reale += other.parte_reale;
        parte_immaginaria += other.parte_immaginaria;
        return *this;
    }
    complex_number<T> operator+(const complex_number<T>& other) const {      // Overload operatore +
        return complex_number<T>(parte_reale + other.parte_reale, parte_immaginaria + other.parte_immaginaria);
    }
    complex_number<T>& operator*=(const complex_number<T>& other) {      // Overload operatore *=
        T real = parte_reale * other.parte_reale - parte_immaginaria * other.parte_immaginaria;
        T imag = parte_reale * other.parte_immaginaria + parte_immaginaria * other.parte_reale;
        parte_reale = real;
        parte_immaginaria = imag;
        return *this;
    }
    complex_number<T> operator*(const complex_number<T>& other) const {       // Overload operatore *
        return complex_number<T>(
            parte_reale * other.parte_reale - parte_immaginaria * other.parte_immaginaria,
            parte_reale * other.parte_immaginaria + parte_immaginaria * other.parte_reale
        );
    }
    template<typename P>
    friend ostream& operator<<(ostream& os, const complex_number<P>& c);	 // Dichiarazione di friend per l'operatore << per permettere l'accesso ai membri privati
};
template<typename T>
ostream& operator << (ostream& os, const complex_number<T>& c) {
    os << c.parte_reale;
    if (c.parte_immaginaria >= 0)               	// Overload dell'operatore << per la stampa
        os << "+";
    os << c.parte_immaginaria << "i";
    return os;
}

    
int main() {
    complex_number<double> cn(3.5, -2.1);  // Specificato il tipo, rimosso il template errato

    complex_number<double> cn_coniugato = cn.metodo_coniugato();  // Corretta la chiamata a metodo_coniugato()

    cout << cn << endl;
    cout << cn_coniugato << endl;  

    return 0;
}