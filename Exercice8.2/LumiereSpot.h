#pragma once
#include "Lumiere.h"
class LumiereSpot : public Lumiere {
    Vec3 pos, dir; float angleCos, k;
public:
    LumiereSpot(Vec3 p, Vec3 d, float angleDeg, float atten=0.1f)
        : pos(p), dir(d.normalized()), k(atten) {
        float rad = angleDeg * 3.14159f / 180.0f;
        angleCos = std::cos(rad);
    }
    float intensite(const Vec3& position) const override {
        Vec3 toPoint = (position - pos).normalized();
        float cosTheta = dir.dot(toPoint);
        if (cosTheta < angleCos) return 0.0f;
        float d = (position - pos).length();
        return (1.0f / (1.0f + k * d * d)) * cosTheta;
    }
};
