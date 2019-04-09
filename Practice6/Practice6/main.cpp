//
//  main.cpp
//  Practice6
//
//  Created by Aichinger,Julie.
//  Copyright © 2019 Aichinger,Julie. All rights reserved.
//
#include "json.hpp"
#include "reddit.hpp"

#include <iostream>
#include <iterator>
#include <string>
#include <typeinfo>
using std::istreambuf_iterator;
using std::string;

int main()
{
    istreambuf_iterator<char> first(std::cin);
    istreambuf_iterator<char> last;
    string s(first, last);
    
    json::Value* val = json::parse(s);
    
    Reddit reddit(val);
    reddit.print();
    
    return 0;
}
