//
//  reddit.hpp
//  Practice6
//
//  Created by Aichinger,Julie.
//  Copyright © 2019 Aichinger,Julie. All rights reserved.
//

#ifndef reddit_hpp
#define reddit_hpp
#include "json.hpp"

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

struct Data
{
    bool trueOrFalse = false;
    string title = "", author = "";
    
    Data(string Title, string Author, bool TrueOrFalse);
};

struct Reddit
{
    string remove(string);
    vector<Data> data;
    
    void print();
    Reddit(json::Value *v);
};
#endif /* reddit_hpp */
