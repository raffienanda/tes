#ifndef ADONAN_H
#define ADONAN_H

// Deklarasi maju (forward declaration) untuk friend class
class PencetakBakso; 

class Adonan {
private:
    // Variabel private yang akan diakses oleh friend class
    int jumlahAdonanKg; 

public:
    Adonan(int jumlah) : jumlahAdonanKg(jumlah) {} 

    int getJumlah() const { return jumlahAdonanKg; }

    // Mendefinisikan PencetakBakso sebagai kelas friend
    friend class PencetakBakso; 
};

#endif // ADONAN_H