#ifndef PRODUK_H
#define PRODUK_H

#include <iostream>
#include <string>

class Daging {
public:
    std::string tipe;
    int kualitas; 

    Daging(std::string t, int k) : tipe(t), kualitas(k) {}
    void info() const { 
        std::cout << "[Daging: " << tipe << ", Kualitas: " << kualitas << "]"; 
    }
};

class BaksoSiapJual {
public:
    std::string nama;
    int beratGram;

    BaksoSiapJual(std::string n, int b) : nama(n), beratGram(b) {}
    void info() const { 
        std::cout << "[Bakso: " << nama << ", Berat: " << beratGram << "g]"; 
    }
};

#endif // PRODUK_H