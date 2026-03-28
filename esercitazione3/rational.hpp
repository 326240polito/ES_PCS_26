#pragma once
#include <concepts>
#include <iostream>
#include <numeric>
template<typename I> requires std::integral<I>
class rational {
    I num_;
    I den_;
    void simplify(){
        if (den_ == 0) return;  //se il denominatore è 0, non semplifichiamo (inf o NaN)
        if (den_ <0) {          //se il meno è sotto, lo porto sopra
            num_ = -num_ ;
            den_ = -den_ ;
        }
        I comune = std::gcd(num_, den_);  //calcolo il massimo comun divisore
        num_ /= comune; //diviso numeratore per il MCD
        den_ /= comune; //divido il denominatore per il MCD
    }
public:
    rational() : num_(I{0}), den_(I{1})
    {}
    rational(I n, I d) : num_(n), den_(d)
    {
        simplify();  //appena creo il numero lo semplifico
    }
    I num() const {return num_;}  
    I den() const {return den_;}
    rational& operator+=(const rational& other) {       //"operator+=" modifica l'oggetto su cui viene chiamato
        num_ = num_ * other.den_ + other.num_ * den_;   //uso la formula (a*d + b*c)
        den_ = den_ * other.den_;                       // denominatore comune: b*d
        simplify();                                     //semplifico il risultato
        return * this;                                  //torna semplificato 
    }
    rational operator+(const rational& other) const {   //"operator+" crea un nuovo oggetto senza modifica requello originale
        rational ret = *this;           //creo una copia dell'oggetto attuale
        ret += other;                   //uso l'operatore sulla copia
        return ret;                     //ritorna la copia (risultato della somma)
    }
    rational& operator-=(const rational& other) {       
        num_ = num_ * other.den_ - other.num_ * den_;   
        den_ = den_ * other.den_;                       
        simplify();                                     
        return * this;                                   
    }
    rational operator-(const rational& other) const {   
        rational ret = *this;           
        ret -= other;                   
        return ret;
    }
    rational& operator*=(const rational& other) {
        num_ *= other.num_;      //moltiplico attuale numeratore per quello dell'altro numero
        den_ *= other.den_;      //moltiplico attuale denominatore per quello dell'altro numero
        simplify();              
        return * this;          //semplifico e restituisco l'oggetto aggiornato
    }
    rational operator*(const rational& other) const {  //discorso analogo alla somma, ma per moltiplicazione
        rational ret = *this;
        ret *= other;
        return ret;
    }
    rational& operator/=(const rational& other){  //(a/b) / (c/d) = (a*d) / (b*c)
        num_ *= other.den_; 
        den_ *= other.num_;
        simplify();
        return *this;
    }
    rational operator/(const rational& other) const{
        rational ret = *this;
        ret /= other;
        return ret;
    }
};

template<typename I> requires std::integral<I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
    if (r.den() == 0) {    //gestisco i casi limite, se denominatore 0
        if (r.num() == 0) os << "NaN";
        else os << (r.num() > 0 ? "Inf" : "-Inf");
    } else {
        os << r.num();
        os << "/" << r.den();  
    }
    return os;
}



