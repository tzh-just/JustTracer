#pragma once

#include <memory>

#include "../Math/Vector.h"
#include "Material.h"

struct HitResult {
    Point3 point;
    Vector3 normal;
    bool isLight;

    union{
        float distance;
        float time;
    };

    std::shared_ptr<Material> material = nullptr;

    HitResult() : point(Point3()), normal(Vector3()), distance(0.0), isLight(false) {}

    HitResult(const HitResult& other){
        //暂时只需要材质的智能指针
        material = other.material;
    }
};