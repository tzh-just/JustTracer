
<h1 align="center">Just Tracer</h1>
<p align="center"><img src="Resource/Output/Cornell_Box.jpg" alt="Logo" width="50%"></p>
<p align="center">软光线追踪渲染器 720p×720p | 5000spp 渲染结果</p>

## Reference

> 1. [Ray Tracing in One Weekend Series](https://raytracing.github.io/)
> 2. [smallpt - 99 行 C++ 代码实现全局光照](http://www.kevinbeason.com/smallpt/)
> 3. [smallpt魔改版 - vinjn 提供的合集](https://github.com/vinjn/learn-raytracing)
> 4. [smallpt改写为pbrt - infancy 的超长解析文章](https://infancy.github.io/smallpt2pbrt.html)
> 5. [Pursuit - ksgfk 的软光追渲染器](https://github.com/ksgfk/Pursuit)
> 6. [Nori - ksgfk 的作业解析](https://www.zhihu.com/column/c_1407025850030698496)
> 7. [TinyRenderer - 有些修改的中文教程](https://zhuanlan.zhihu.com/p/399056546)
> 8. [Filament - PBR 文档的中文翻译](https://jerkwin.github.io/filamentcn/Filament.md.html)
> 9. [GAME101 - liupeining 的作业7实现](https://github.com/liupeining/Games_101_homework/tree/main/a7)
> 10. [RenderHelp - 矢量模板类的设计值得学习](https://github.com/skywind3000/RenderHelp)
> 11. [恒星的离线渲染器](https://github.com/star-hengxing/cpu_offline_renderer)
> 12. [Mitsuba1/2 闫令琦推荐的科研渲染器](http://www.mitsuba-cornellBoxRenderer.org/) 
> 13. [pbrt - 众所周知的圣经](https://www.pbr-book.org/3ed-2018/contents)

## TODO
- 对光源采样
  - 多光源均匀采样（PS: 所有光源视为整体的积分域）
- 重要性采样
  - 混合BRDF

## Feature

- [x] Intersect 物体
    - [x] Sphere 球体
    - [x] Triangle 三角形
    - [x] Rectangle 矩形
- [ ] Model 模型
  - [ ] Mesh 网格
  - [ ] Texture 纹理
- [x] Ray 射线
- [x] HitResult 相交结果
- [x] Renderer 渲染器
  - [x] OpenMP多线程加速
- [x] Film 胶片
- [x] Scene 场景
- [x] Camera 相机
- [x] Sampler 采样器
  - [x] Trapezoidal 梯形分布
  - [x] Uniform 均匀分布
- [x] Integrator 积分器
  - [x] MonteCarloPathIntegrator 蒙特卡洛路径追踪
- [x] BxDF 双向X分布函数
  - [x] IdealDiffuseBxDF 漫反射分布函数
  - [x] IdealSpecularBxDF 理想镜面反射分布函数
  - [x] MircofacetBxDF 镜面（光泽）反射分布函数
- [x] Material 材质
  - [x] DiffuseMaterial 漫反射材质
  - [x] MirrorMaterial 镜面材质
  - [ ] GlossyMaterial 光泽材质
  - [x] MircofacetMaterial 微表面材质
- [x] Light 灯光：作为抽象类由继承该类的 Object 实现
- [ ] Accelerator 加速结构
  - [x] AABB 轴向包围盒
  - [ ] BVH 层次包围体
- [ ] Tool 工具 
  - [x] Vector 矢量模板类
  - [ ] Matrix 矩阵模板类
  - [ ] Math 数学工具类
  - [x] Global 全局定义类
  - [x] Random 随机数类
- [ ] Loader 文件加载与解析 
  - [x] ObjLoader 模型obj文件解析 
  - [ ] JsonLoader 场景json文件解析


##  

以后可能会加上 stb_image 头文件以支持输出其他格式图片
