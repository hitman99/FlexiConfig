/* 
 * File:   string_features.h
 * Author: tomas
 *
 * Created on April 8, 2014, 4:34 PM
 */

#ifndef STRING_FEATURES_H
#define	STRING_FEATURES_H

#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include <sstream>
#include <string>

// trim from start
static inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
static inline std::string trim(std::string s) {
        return ltrim(rtrim(s));
}
template <class T>
std::string stringify(T x){ std::ostringstream o; if (!(o << x)) return "0"; return o.str(); }
static int integerify(string num){
    int x = 0;
    try{
        istringstream(num) >> x;
    }
    catch(...){
        
    }
    return x;
}

#endif	/* STRING_FEATURES_H */

