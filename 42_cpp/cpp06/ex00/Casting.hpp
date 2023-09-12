#ifndef CASTING_HPP
# define CASTING_HPP

#include <iostream>
#include <string.h>

class Casting {
    
    private:
        Casting();
        Casting(Casting const &org);
        Casting &operator=(Casting const &other);

    public:
    
        ~Casting();
        static void checkValue(const std::string &str);
        static bool isStringEqual(const std::string& str);
     
        static void convert(const std::string &str);
        static void toChar(const std::string &str);
        static void toInt(const std::string &str);
        static void toFloat(const std::string &str);
        static void toDouble(const std::string &str);
        static int checkRange(std::string type, std::string input);
    
};

#endif