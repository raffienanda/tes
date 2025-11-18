#ifndef ADONAN_H
#define ADONAN_H

class PencetakBakso; 

class Adonan {
private:
    int jumlahAdonanKg; 

public:
    Adonan(int jumlah) : jumlahAdonanKg(jumlah) {} 

    int getJumlah() const { return jumlahAdonanKg; }

    friend class PencetakBakso; 
};

#endif // ADONAN_H