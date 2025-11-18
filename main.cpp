// =============================================================================
// FILE: main.cpp
// DESKRIPSI: Main program yang mengintegrasikan semua kelas.
// =============================================================================

#include <iostream>
// Include semua kelas yang dibutuhkan
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

    // --- INISIALISASI ---

    // Menggunakan Template Class Kontainer<T>
    Kontainer<Daging> kontainerDaging("Stok Bahan Daging");
    Kontainer<BaksoSiapJual> kontainerBakso("Stok Bakso Jadi");

    // Hardcode Data: 
    kontainerDaging.tambah(Daging("Sapi Pilihan", 9));
    kontainerDaging.tambah(Daging("Ayam Broiler", 6));
    
    // Inisialisasi Adonan (Friend Class Target)
    Adonan adonanGiling(3); // 3 Kg Adonan
    std::cout << "   Adonan Gilingan Awal: " << adonanGiling.getJumlah() << " Kg" << std::endl;

    // Inisialisasi Friend Class PencetakBakso
    PencetakBakso mesinCetak("Mesin Cetak Super");
    
    // Inisialisasi PenjualBakso (Pengguna Kontainer dan Exception Handler)
    PenjualBakso tokoAdi("Toko Bakso Adi", kontainerBakso);
    
    // --- SIMULASI ---

    // A. Penggunaan Friend Class: Mencetak Bakso
    // PencetakBakso memodifikasi anggota private Adonan
    mesinCetak.cetak(adonanGiling, kontainerBakso); 
    mesinCetak.cetak(adonanGiling, kontainerBakso); 
    
    std::cout << "\n[STOK HASIL PRODUKSI]" << std::endl;
    // Total 20 Bakso dihasilkan (10x2)
    std::cout << "   Stok Bakso Siap Jual: " << kontainerBakso.getStok() << " buah" << std::endl; 

    // B. Penggunaan Exception Handling: Jual Bakso
    std::cout << "\n[SIMULASI PENJUALAN DAN EXCEPTION]" << std::endl;
    
    // Skenario 1: Penjualan yang melebihi stok (jual 30, stok hanya 20)
    tokoAdi.jualBakso(30); 
    
    // C. Demonstrasi Template (Mengambil Daging)
    std::cout << "\n[DEMONSTRASI EXCEPTION PADA KONTAINER DAGING]" << std::endl;
    try {
        kontainerDaging.ambil();
        kontainerDaging.ambil();

        // Ambil yang ke-3: harusnya gagal dan throw StokHabisException
        kontainerDaging.ambil(); 

    } catch (const StokHabisException& e) {
        std::cerr << "   [ERROR TERTANGKAP] " << e.what() << std::endl;
    }

    std::cout << "\n======================================================" << std::endl;
    std::cout << "Program Selesai Dieksekusi." << std::endl;
    std::cout << "======================================================" << std::endl;

    return 0;
}