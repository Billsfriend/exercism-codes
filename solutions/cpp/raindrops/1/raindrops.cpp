#include "raindrops.h"

namespace raindrops {
std::string convert(int number) {
        std::string str1 = "";
        std::string str2 = "";
        std::string str3{""};
        
        if (number % 3 == 0) {
            str1 = "Pling";
        }
        if (number % 5 == 0) {
            str2 = "Plang";
        }
        if (number % 7 == 0) {
            str3 = "Plong";
        }
        if (str1 == str2 and str2 == str3) {
            return std::to_string(number);
        }
        return str1 + str2 + str3;

    }

}  // namespace raindrops
