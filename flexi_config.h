/* 
 * File:   flexi_config.h
 * Author: tomas
 *
 * Created on April 8, 2014, 10:18 AM
 */

#ifndef FLEXI_CONFIG_H
#define	FLEXI_CONFIG_H
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <map>

using namespace std;
class flexi_config {
public:
    flexi_config() : current_section("") {};
    // Config is not copyable
    flexi_config(const flexi_config& orig)=delete;
    // Read INI style config from file
    bool load_config(string filename);
    // Try to retrieve config parameter value from a particular section
    string get_value(string section, string param);
    // Get a complete configuration section
    std::map<string, string> get_section(string section_name);
private:
    ifstream _handle;
    string filename;
    string current_section;
    struct cfg {
        cfg(std::pair<string,string> _conf, string _section_name) : 
                configuration(_conf), section_name(_section_name) {};
        std::pair<string,string> configuration;
        string section_name;
    };
    std::vector<cfg> configurations;
    bool read_file(string filename);
    void parse_line(string line);
    std::vector<string> tokenize(string text, string delimiters);
};

#endif	/* FLEXI_CONFIG_H */

