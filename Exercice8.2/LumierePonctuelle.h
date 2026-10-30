#ifndef LUMIEREPONCTUELLE_H
#define LUMIEREPONCTUELLE_H
#include"Lumiere.h"


class LumierePonctuelle : public Lumiere {
    Vec3 pos;
    float k; // atténuation
public:
    LumierePonctuelle(Vec3 p, float atten=0.1f): pos(p), k(atten) {}
    float intensite(const Vec3& position) const override {
        float d = (position - pos).length();
        return 1.0f / (1.0f + k * d * d);
    }
};

#endif // LUMIEREPONCTUELLE_H
