#ifndef LUMIEREDIRECTIONNELLE_H
#define LUMIEREDIRECTIONNELLE_H
#include"Lumiere.h"

class LumiereDirectionnelle : public Lumiere {
    Vec3 direction;
public:
    LumiereDirectionnelle(Vec3 dir): direction(dir.normalized()) {}
    float intensite(const Vec3& position) const override {
        // Simule Lambert : on éclaire tout pareil, ici intensité constante
        // version plus réaliste : dot(N, -direction)
        (void)position;
        return 0.8f;
    }
};

#endif // LUMIEREDIRECTIONNELLE_H
