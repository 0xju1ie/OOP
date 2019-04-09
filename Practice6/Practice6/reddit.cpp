//
//  reddit.cpp
//  Practice6
//
//  Created by Aichinger,Julie.
//  Copyright © 2019 Aichinger,Julie. All rights reserved.
//

#include "reddit.hpp"

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;


Data::Data(string Title, string Author, bool TrueOrFalse)
{
    title = Title;
    author = Author;
    trueOrFalse = TrueOrFalse;
}

string Reddit::remove(std::string str)
{
    str.pop_back();
    str.erase(str.begin());
    
    return str;
}

Reddit::Reddit(json::Value* v)
{
    int counter = 0;
    
    while(v->direct("\"data\"")->direct("\"children\"")->index(counter) != nullptr)
    {
        string title = remove(v->direct("\"data\"")->direct("\"children\"")->index(counter)->direct("\"data\"")->direct("\"title\"")->getString());
        string author = remove(v->direct("\"data\"")->direct("\"children\"")->index(counter)->direct("\"data\"")->direct("\"author\"")->getString());
        bool t = v->direct("\"data\"")->direct("\"children\"")->index(counter)->direct("\"data\"")->direct("\"stickied\"")->getBool();
        
        Data displayData(title, author, t);
        data.insert(data.begin(), displayData);
        
        ++counter;
    }
}

void Reddit::print()
{
    for(long counter = data.size() - 1; counter > 0; --counter)
    {
        Data d = data.at(counter);
        cout << "Title:  " << d.title << std::endl << "Author: " << d.author << std::endl;
    }
}
