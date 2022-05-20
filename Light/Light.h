#pragma once

#include "../Tool/Vector3.h"
#include "../Shape/Object.h"


struct LightSampleResult{
    float PDF;
    Point3 position;
};

struct Light{
    std::shared_ptr<Sphere> shape;

    Light(std::shared_ptr<Sphere> _shape):shape(_shape){}

    void Sample(HitResult& result){

        float theta = 2.0 * PI * RandomFloat();
        float phi = PI * RandomFloat();
        Vec3 direction(
                std::cos(phi),
                std::sin(phi)*std::cos(theta),
                std::sin(phi)*std::sin(theta)
                );

        result.point = shape->center + direction * shape->radius;
        result.normal = direction;
        result.material = shape->material;
    }

    float PDF(){
        return shape->PDF();
    }

};