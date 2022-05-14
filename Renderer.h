#pragma once

#include <string>
#include <iostream>
#include <fstream>

#include "Scene.h"
#include "Tool/Global.h"
#include "Camera/PerspectiveCamera.h"
#include "Film.h"
#include "Sampler/Sampler.h"
#include "Integrator/Integrator.h"

class Renderer {
private:
    Scene *scene = nullptr;
    Camera *camera = nullptr;
    Sampler *sampler = nullptr;
    Film *film = nullptr;
    Integrator *integrator = nullptr;

    int spp;

public:
    explicit Renderer(int _spp) : spp(_spp) {}

    void SetScene(Scene *_scene) { scene = _scene; }

    void SetCamera(Camera *_camera) { camera = _camera; }

    void SetSampler(Sampler *_sample) { sampler = _sample; }

    void SetFilm(Film *_film) { film = _film; }

    void SetIntegrator(Integrator *_integrator) { integrator = _integrator; }

    void Render() const;
};


void Renderer::Render() const {

    std::vector<Color> pixels(film->width * film->height);
    Color color(0.0);

    //多线程计算每个像素的颜色
#pragma omp parallel for schedule(dynamic, 1) private(color)
    for (int y = film->height - 1; y >= 0; --y) {
        std::cout << 100.0 * (film->height - 1 - y) / (film->height - 1) << "%" << std::endl;
        for (int x = 0; x < film->width; x++) {
            color = Color(0.0);
            for (int index = 0; index < spp; index++) {
                //根据采样分布计算投射的光线方向参数
                auto position = sampler->CastRayByDistribution(x, y);
                double s = position.x / (film->width - 1);
                double t = position.y / (film->height - 1);
                //投射光线并累计颜色
                Ray ray = camera->GetRay(s, t);
                color += integrator->Li(ray, scene);
            }
            //将颜色处理后写入像素
            pixels[(film->height - y - 1) * film->width + x] = color * (1 / static_cast<double>(spp));
        }
    }

    //冲洗胶卷
    film->Develop(pixels);
}