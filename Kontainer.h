#ifndef KONTAINER_H
#define KONTAINER_H

#include <iostream>
#include <vector> 
#include <string>
#include "Exception.h" 

/**
 * @brief Kelas template untuk mengelola stok (T) secara generik.
 */
template <typename T>
class Kontainer {
private:
    std::vector<T> inventori; 
    std::string namaKontainer;

public:
    Kontainer(std::string nama) : namaKontainer(nama) {}

    void tambah(const T& item) {
        inventori.push_back(item);
        std::cout << "-> " << namaKontainer << " [ADD] 1 Item berhasil ditambahkan." << std::endl;
    }

    T ambil() {
        if (inventori.empty()) {
            throw StokHabisException("Kontainer " + namaKontainer + " kosong.");
        }
        
        T item = inventori.back(); 
        inventori.pop_back();
        std::cout << "-> " << namaKontainer << " [TAKE] 1 Item berhasil diambil." << std::endl;
        return item;
    }

    size_t getStok() const {
        return inventori.size();
    }
};

#endif 