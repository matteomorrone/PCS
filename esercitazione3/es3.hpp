#include <iostream>
#include <concepts> // Per std::integral
#include <numeric> // Per std::gcd

template<typename I> requires std::integral<I> // ∀I tale che I è un intero
class rational
{
    I num_;
    I den_;

    /* Semplificazione */
    void semp() 
    {
        if (den_ == I{0}) return; 
        I comune = std::gcd(num_, den_);
        num_ = num_ / comune;
        den_ = den_ /  comune;
        if (den_ < I{0}) // Metto il - sopra
        {
            num_ = -num_;
            den_ = -den_;
        }
    }

public:
    /* Costruttore di default */
    rational()
        : num_(I{0}), den_(I{1}) // Inizializza num_ a 0 e den_ a 1
    {}

    /* Costruttore user-defined */
    rational(const I& n, const I& d)
        : num_(n), den_(d)
    { 
        // Caso denominatore zero
        if (den_ == I{0})
        {
            if (num_ > I{0}) num_ = I{1}; // Caso +Inf
            else if (num_ < I{0})  num_ = I{-1}; // Caso -Inf
            else num_ = I{0}; // Caso NaN
        }
        else
        {
            semp();
        }
    }

    /* Restituiscono i valori di numeratore e denominatore */
    I num() const { return num_; }
    I den() const { return den_; }

    /* Operazione +=  */
    rational& operator+=(const rational& other) // a +=b è equivalente ad a = a + b
    {
        num_ = (num_ * other.den_) + (other.num_ * den_);
        den_ = den_ * other.den_;
        semp();
        return *this;
    }

    /* Operazione + */
    rational operator+(const rational& other) const // const perché non tocco i valori di num_ e den_
    {
        rational risultato = *this; // "rational" perché creo un nuovo oggetto "risultato" di tipo frazione
        risultato += other; 
        return risultato;
    }

    /* Operazione -=  */
    rational& operator-=(const rational& other) 
    {
        num_ = (num_ * other.den_) - (other.num_ * den_);
        den_ = den_ * other.den_;
        semp();
        return *this;
    }

    /* Operazione - */
    rational operator-(const rational& other) const 
    {
        rational risultato = *this; 
        risultato -= other; 
        return risultato;
    }

    /* Operazione *=  */
    rational& operator*=(const rational& other) 
    {
        num_ = num_ * other.num_;
        den_ = den_ * other.den_;
        semp();
        return *this;
    }

    /* Operazione * */
    rational operator*(const rational& other) const 
    {
        rational risultato = *this;
        risultato *= other;
        return risultato;
    }

    /* Operazione /=  */
    rational& operator/=(const rational& other) 
    {
        num_ = num_ * other.den_;
        den_ = den_ * other.num_;
        semp();
        return *this;
    }

    /* Operazione / */
    rational operator/(const rational& other) const 
    {
        rational risultato = *this;
        risultato /= other;
        return risultato;
    }
};
  
/* Operatore << per la stampa di un oggetto della classe rational */
template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& v)
{
    if (v.den() == I{0} && v.num() == I{0}) os << "NaN";
    else if (v.den() == I{0}) 
    {
        if (v.num() > I{0}) os << "+Inf";
        else os << "-Inf";
    }
    else os << v.num() << "/" << v.den();
    return os;
}
