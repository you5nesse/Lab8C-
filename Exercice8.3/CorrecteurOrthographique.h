#ifndef CORRECTEURORTHOGRAPHIQUE_H
#define CORRECTEURORTHOGRAPHIQUE_H


#pragma once
#include "Plugin.h"

class CorrecteurOrthographique : public Plugin {
public:
    std::string nom() const override { return "CorrecteurOrthographique"; }

    std::string traiter(const std::string& texte) override {
        std::string res = texte;
        // petites corrections simples
        auto replace = [](std::string& s, const std::string& from, const std::string& to){
            size_t pos=0;
            while((pos=s.find(from,pos))!=std::string::npos){ s.replace(pos,from.length(),to); pos+=to.length(); }
        };
        replace(res, "je sui ", "je suis ");
        replace(res, "il et ", "il est ");
        replace(res, "sa va", "ca va");
        replace(res, "bonjourr", "bonjour");
        return res;
    }
};

#endif // CORRECTEURORTHOGRAPHIQUE_H
