/* 
 * File:   flexi_config.cpp
 * Author: tomas
 * 
 * Created on April 8, 2014, 10:18 AM
 */

#include "flexi_config.h"
#include "string_features.h"
#include <vector>

bool flexi_config::load_config(string _filename){
    this->filename = _filename;
    return this->read_file(filename);
}

bool flexi_config::read_file(string _filename){
    string line;
    this->filename = _filename;
    _handle.open(filename.c_str());
    if(!_handle.is_open()){
        return false;
    }
    while(std::getline(_handle, line)){
        if(trim(line).length() != 0){
            this->parse_line(line);
        }
    }
    //assume success
    return true;
}

void flexi_config::parse_line(string line){
    //search for comments
    if(line.find("#") == string::npos){
        //Search for section
        std::string::size_type pos1, pos2 = 0;
        if((pos1 = line.find_first_of("[")) != string::npos){
            if((pos2 = line.find_last_of("]")) != string::npos){
                this->current_section = line.substr(pos1+1, pos2 - pos1 -1);
            }
        }
        // No sections in this line, parse config
        else{
            auto tokens = this->tokenize(line, "=\n");
            if(tokens.size() == 2){
                this->configurations.push_back(
                        cfg(std::pair<string, string>(tokens.at(0), tokens.at(1)), 
                            this->current_section)
                );
            }
        }
    }
}
/**
 * Improved tokenizer with trimming
 * @param text
 * @param delimiters
 */
std::vector<string> flexi_config::tokenize(string text, string delimiters){
    std::vector<string> tokens;
    std::string::size_type pos, last_pos = 0;
    pos = text.find_first_not_of(delimiters,0);
    while(pos != string::npos && last_pos != string::npos){
        last_pos = text.find_first_of(delimiters, pos);
        tokens.push_back(trim(text.substr(pos, last_pos - pos)));
        pos = text.find_first_not_of(delimiters, last_pos);
        while((text.find_first_of(delimiters, last_pos+1) - last_pos) == 1){
            tokens.push_back("");
            last_pos++;
        }
        //if delimiter is the last symbol in the string
    }
    if(delimiters.find((*text.rbegin())) != string::npos)
        tokens.push_back("");
    return tokens;
}
/**
 * Returns a whole section of configuration my the section name
 * @param section_name
 * @return map with configuration
 */
std::map<string, string> flexi_config::get_section(string section_name){
    std::map<string, string> section_config;
    for(auto const &item : this->configurations){
        if(section_name.compare(item.section_name) == 0){
            section_config.insert(item.configuration);
        }
    }
    return section_config;
}

