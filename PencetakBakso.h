#ifndef PENCETAKBAKSO_H
#define PENCETAKBAKSO_H

#include <iostream>
#include <string>
#include "Adonan.h"
#include "Kontainer.h"
#include "Produk.h" // Untuk BaksoSiapJual

/**
 * @brief Kelas yang bertanggung jawab mengubah Adonan menjadi Bakso.
 * Merupakan FRIEND dari kelas Adonan, dan menggunakan kelas template Kontainer.
 */
class PencetakBakso {
private:
    std::string namaPencetak;

public:
    PencetakBakso(std::string nama) : namaPencetak(nama) {}

    // Fungsi ini mengakses anggota private Adonan
    void cetak(Adonan& adonan, Kontainer<BaksoSiapJual>& kontainerBakso) {
        std::cout << "\n=== Proses Pencetakan oleh " << namaPencetak << " ===" << std::endl;
        // Akses anggota private
        std::cout << "   Stok Adonan saat ini (friend access): " << adonan.jumlahAdonanKg << " Kg." << std::endl;

        if (adonan.jumlahAdonanKg >= 1) {
            adonan.jumlahAdonanKg -= 1; // Memodifikasi anggota private Adonan

            // Hardcode: 1 Kg Adonan menghasilkan 10 Bakso
            for (int i = 0; i < 10; ++i) {
                kontainerBakso.tambah(BaksoSiapJual("Bakso Premium", 100));
            }

            std::cout << "   [SUKSES] 1 Kg Adonan digunakan. Dihasilkan 10 Bakso." << std::endl;
            std::cout << "   Stok Adonan sisa: " << adonan.jumlahAdonanKg << " Kg." << std::endl;
        } else {
            std::cout << "   [GAGAL] Adonan tidak cukup untuk mencetak." << std::endl;
        }
    }
};

#endif // PENCETAKBAKSO_H