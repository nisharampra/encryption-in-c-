#include <iostream>
#include <string>

// Function to generate extended key for Vigenère cipher
std::string generateKey(const std::string& plaintext, const std::string& key) {
    std::string extendedKey;
    extendedKey.reserve(plaintext.length());

    for (size_t i = 0, j = 0; i < plaintext.length(); ++i) {
        extendedKey += key[j];
        j = (j + 1) % key.length();
    }

    return extendedKey;
}

// Function to perform Vigenère cipher encryption
std::string cipherText(const std::string& plaintext, const std::string& key) {
    std::string ciphertext;
    ciphertext.reserve(plaintext.length());

    for (size_t i = 0; i < plaintext.length(); ++i) {
        char x = (plaintext[i] + key[i]) % 26;
        x += 'A';
        ciphertext += x;
    }

    return ciphertext;
}

int main() {
    std::string plaintext;
    std::string key;

    // Get plaintext from user
    std::cout << "Enter plaintext: ";
    std::getline(std::cin, plaintext);

    // Get key from user
    std::cout << "Enter key: ";
    std::getline(std::cin, key);

    // Convert plaintext and key to uppercase and remove spaces (if needed)
    for (char& c : plaintext) {
        if (std::isalpha(c))
            c = std::toupper(c);
    }

    for (char& c : key) {
        if (std::isalpha(c))
            c = std::toupper(c);
    }

    // Generate extended key and encrypt plaintext
    std::string extendedKey = generateKey(plaintext, key);
    std::string ciphertext = cipherText(plaintext, extendedKey);

    // Output the results
    std::cout << "Plaintext: " << plaintext << std::endl;
    std::cout << "Key: " << key << std::endl;
    std::cout << "Extended Key: " << extendedKey << std::endl;
    std::cout << "Ciphertext: " << ciphertext << std::endl;

    return 0;
