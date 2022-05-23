#pragma once

#include "Global.h"
#include "Vector.h"

enum class MaterialType {
    DIFFUSE,
    REFRACT,
    LIGHT,
};

struct Material {
    Color3f emission;
    Color3f base_color;
    MaterialType type;

    Material(const Color3f &_color, const Color3f &_emission, const MaterialType &_type)
            : base_color(_color), emission(_emission), type(_type) {}

    virtual float PDF(const Vector3f &wi, const Vector3f &wo, const Vector3f &N) = 0;

    virtual Vector3f Eval(const Vector3f &wi, const Vector3f &wo, const Vector3f &N) = 0;

    virtual Vector3f SampleDirection(const Vector3f &V, const Vector3f &N) = 0;
};