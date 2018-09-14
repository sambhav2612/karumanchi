#include <bits/stdc++.h>

bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int calc(std::string str) {
    int hard_wprds = 0, easy_words = 0;
    int count_vowels = 0, count_consonants = 0, count_consec_consonants = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] != ' ' && isVowel(str[i])) {
            count_vowels++;
            count_consec_consonants = 0;
        }
        else if (str[i] != ' ') {
            count_consonants++;
            count_consec_consonants++;
        }

        if (count_consec_consonants == 4) {
            hard_wprds++;
            while (str[i] != ' ' && i < str.length())
                i++;
        }
        else if ((str[i] == ' ' || i == str.length()-1) && i < str.length())
            count_consonants > count_vowels ? hard_wprds++ : easy_words++;
        
        // reset all counters
        count_consec_consonants = 0;
        count_consonants = 0;
        count_vowels = 0;
    }

    return 5 * hard_wprds + 3 * easy_words;
}

int main() {
    std::string str = "";
    getline(std::cin, str);
    std::cout << "\n" << calc(str);
    return 0;
}