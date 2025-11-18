
#include <iostream>
#include "Exception.h"
#include "Produk.h"
#include "Kontainer.h"
#include "Adonan.h"
#include "PencetakBakso.h"
#include "PenjualBakso.h"

int main() {
    std::cout << "======================================================" << std::endl;
    std::cout << "   PROGRAM SIMULASI DISTRIBUSI PRODUKSI BAKSO" << std::endl;
    std::cout << "   (Multi-File Integration Demo)" << std::endl;
    std::cout << "======================================================" << std::endl;


    Kontainer<Daging> kontainerDaging("Stok Bahan Daging");
    Kontainer<BaksoSiapJual> kontainerBakso("Stok Bakso Jadi");

    kontainerDaging.tambah(Daging("Sapi Pilihan", 9));
    kontainerDaging.tambah(Daging("Ayam Broiler", 6));
    
    Adonan adonanGiling(3);
    std::cout << "   Adonan Gilingan Awal: " << adonanGiling.getJumlah() << " Kg" << std::endl;

    PencetakBakso mesinCetak("Mesin Cetak Super");
    
    PenjualBakso tokoAdi("Toko Bakso Adi", kontainerBakso);
    

    mesinCetak.cetak(adonanGiling, kontainerBakso); 
    mesinCetak.cetak(adonanGiling, kontainerBakso); 
    
    std::cout << "\n[STOK HASIL PRODUKSI]" << std::endl;
    std::cout << "   Stok Bakso Siap Jual: " << kontainerBakso.getStok() << " buah" << std::endl; 

    std::cout << "\n[SIMULASI PENJUALAN DAN EXCEPTION]" << std::endl;
    
    tokoAdi.jualBakso(30); 
    
    std::cout << "\n[DEMONSTRASI EXCEPTION PADA KONTAINER DAGING]" << std::endl;
    try {
        kontainerDaging.ambil();
        kontainerDaging.ambil();

        kontainerDaging.ambil(); 

    } catch (const StokHabisException& e) {
        std::cerr << "   [ERROR TERTANGKAP] " << e.what() << std::endl;
    }

    std::cout << "\n======================================================" << std::endl;
    std::cout << "Program Selesai Dieksekusi." << std::endl;
    std::cout << "======================================================" << std::endl;

    return 0;
}