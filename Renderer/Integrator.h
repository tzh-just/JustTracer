#pragma once

#include "../Math/Global.h"
#include "../Math/Vector.h"
#include "../Common/Ray.h"
#include "Scene.h"

struct Integrator {
    virtual Color Li(const Ray &ray, std::shared_ptr<Scene> scene) = 0;
};

struct PathIntegrator : Integrator {
    int depth_max;

    PathIntegrator(int _depth = 5) : depth_max(_depth) {}

    virtual Color Li(const Ray &ray, std::shared_ptr<Scene> scene) = 0;

    virtual Color CastRay(const Ray &ray, std::shared_ptr<Scene> scene, int depth) = 0;
};


