#pragma once

#include "../Ray.h"
#include "../Tool/Global.h"
#include "../Tool/Vector.h"

struct Camera {
    virtual Ray GetRay(const float &s, const float &t) const = 0;
};