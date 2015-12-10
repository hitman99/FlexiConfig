FlexiConfig
==

About
--

FlexiConfig is a very simple and lightweight library for INI style config file reading. It is written in pure C++11.

Features
--

  + Multiple section support
  + Single parameter retrieval from particular section
  + Complete section retrieval with all parameters in the section

Config file example
--
```sh
[database]
db_user = postgres
db_pass = postgres%1
db_name = public
db_host = localhost
db_port = 5432
db_schema = public

[network]
host = localhost
port = 38383
```

Compilation
--
### Linux (g++ 4.8+)
```sh
g++ -std=c++11 -o flexi_config.o flexi_config.cpp
ar -rv libflexiconfig.a flexi_config.o
```
### Windows (Visual Studio 2015)
1. Import source and header files into the new Win32 console application project
2. Compile the static library

Usage
--

It is possible to use this library in two ways:
1.  Import source and header files into your porject anc compile the code as part of the project
2.  Compile the code as static (or dynamic) library and link you program to it (see compilation section)


License
--
[GPLv3](http://www.gnu.org/licenses/gpl.html)