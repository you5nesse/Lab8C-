#ifndef TRADUCTEURANGLAIS_H
#define TRADUCTEURANGLAIS_H


#pragma once
#include "Plugin.h"

class TraducteurAnglais : public Plugin {
public:
    std::string nom() const override { return "TraducteurAnglais"; }

    std::string traiter(const std::string& texte) override {
        std::string res = texte;
        auto replace = [](std::string& s, const std::string& from, const std::string& to){
            size_t pos=0;
            while((pos=s.find(from,pos))!=std::string::npos){ s.replace(pos,from.length(),to); pos+=to.length(); }
        };
        replace(res, "bonjour", "hello");
        replace(res, "monde", "world");
        replace(res, "merci", "thanks");
        replace(res, "au revoir", "goodbye");
        replace(res, "texte", "text");
        return res;
    }
};

#endif // TRADUCTEURANGLAIS_H
