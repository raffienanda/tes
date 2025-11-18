#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <string>

/**
 * @brief Exception kustom untuk menandai stok/kontainer kosong.
 */
class StokHabisException : public std::runtime_error {
public:
    StokHabisException(const std::string& msg) : 
        std::runtime_error("ERROR STOK HABIS: " + msg) {}
};

#endif // EXCEPTION_H