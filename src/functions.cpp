#include "../inc/functions.h"

size_t strlen(const std::string &str) {
    size_t size = 0;
    for (auto byte : str) {
        size += (((byte & 0x80) == 0) || ((byte & 0xC0) == 0xC0));
    }
    return size;
}