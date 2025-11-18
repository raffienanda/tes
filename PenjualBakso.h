#ifndef PENJUALBAKSO_H
#define PENJUALBAKSO_H

#include <iostream>
#include <string>
#include "Kontainer.h"
#include "Produk.h"
#include "Exception.h"

/**
 * @brief Entitas yang menjual produk dan menangani exception stok.
 */
class PenjualBakso {
private:
    std::string nama;
    Kontainer<BaksoSiapJual>& stokBakso; 

public:
    PenjualBakso(std::string n, Kontainer<BaksoSiapJual>& stok) : 
        nama(n), stokBakso(stok) {}

    void jualBakso(int jumlah) {
        std::cout << "\n=== Proses Penjualan oleh " << nama << " ===" << std::endl;
        std::cout << "   Stok Bakso Awal: " << stokBakso.getStok() << std::endl;
        int berhasilJual = 0;

        try {
            for (int i = 0; i < jumlah; ++i) {
                stokBakso.ambil();
                berhasilJual++;
            }
            std::cout << "   [SUKSES] Berhasil menjual " << jumlah << " buah bakso." << std::endl;

        } catch (const StokHabisException& e) {
            std::cerr << "   [Gagal Jual!] " << e.what() << std::endl;
            std::cout << "   Hanya berhasil menjual " << berhasilJual << " buah bakso." << std::endl;
            
        } catch (const std::exception& e) {
            std::cerr << "   [ERROR LAIN] " << e.what() << std::endl;
        }

        std::cout << "   Stok Bakso Akhir: " << stokBakso.getStok() << std::endl;
    }
};

#endif 