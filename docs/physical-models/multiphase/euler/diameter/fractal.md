# fractal

## 一句话
Class for modelling the shape of particle aggregates using the concept of

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（velocityGroup）
- **族**: 粒径组形状（基类 `shapeModel`）
- **注册名**: `fractal`

## 字典示例


```c++
// `tutorials/multiphaseEuler/titaniaSynthesisSurface/constant/phaseProperties`
{
    type            purePhaseModel;

    diameterModel   velocityGroup;
    velocityGroupCoeffs
    {
        populationBalance   aggregates;

        shapeModel          fractal;

        sizeGroups
        (
            { dSph 4.000E-10; Df 1.8; alphaC 1; }
            { dSph 5.769E-10; Df 1.8; alphaC 1; }
            { dSph 8.320E-10; Df 1.8; alphaC 1; }
            { dSph 1.200E-09; Df 1.8; alphaC 1; }
            { dSph 1.731E-09; Df 1.8; alphaC 1; }
            { dSph 2.496E-09; Df 1.8; alphaC 1; }
            { dSph 3.600E-09; Df 1.8; alphaC 1; }
            { dSph 5.192E-09; Df 1.8; alphaC 1; }
            { dSph 7.488E-09; Df 1.8; alphaC 1; }
            { dSph 1.080E-08; Df 1.8; alphaC 1; }
            { dSph 1.558E-08; Df 1.8; alphaC 1; }
            { dSph 2.246E-08; Df 1.8; alphaC 1; }
            { dSph 3.240E-08; Df 1.8; alphaC 1; }
            { dSph 4.673E-08; Df 1.8; alphaC 1; }
            { dSph 6.739E-08; Df 1.8; alphaC 1; }
            { dSph 9.720E-08; Df 1.8; alphaC 1; }
            { dSph 1.402E-07; Df 1.8; alphaC 1; }
            { dSph 2.022E-07; Df 1.8; alphaC 1; }
            { dSph 2.916E-07; Df 1.8; alphaC 1; }
            { dSph 4.206E-07; Df 1.8; alphaC 1; }
            { dSph 6.066E-07; Df 1.8; alphaC 1; }
            { dSph 8.748E-07; Df 1.8; alphaC 1; }
            { dSph 1.262E-06; Df 1.8; alphaC 1; }
            { dSph 1.820E-06; Df 1.8; alphaC 1; }
            { dSph 2.624E-06; Df 1.8; alphaC 1; }
            { dSph 3.785E-06; Df 1.8; alphaC 1; }
            { dSph 5.459E-06; Df 1.8; alphaC 1; }
            { dSph 7.873E-06; Df 1.8; alphaC 1; }
            { dSph 1.136E-05; Df 1.8; alphaC 1; }
        );
    }

    residualAlpha   1e-15;
}

vapour
{
    type            reactingPhaseModel;

    diameterModel   none;
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `Df` | Fractal dimension | yes | — |
| `alphaC` | Scaling prefactor | yes | — |


## 控制方程与关联式
Class for modelling the shape of particle aggregates using the concept of
fractal geometry. Returns a collisional diameter

[
d_{c_i} =
{6}{_i}
(
{v_i _i^3}{36 _c}
)^{1/D_{f_i}}\,,
]

computed from a constant fractal dimension $D_{f_i}$ and a
field-dependent surface area to volume ratio $_i$, assuming that
the primary particles in an aggregate have the same size.

## 文献与源码依据
- 类: `Foam`::diameterModels::shapeModels::fractal`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/diameterModels/velocityGroup/sizeGroup/shapeModels/fractal/fractal.C`

## 教程与模板
- `tutorials/multiphaseEuler/titaniaSynthesisSurface/constant/phaseProperties`
- `tutorials/multiphaseEuler/titaniaSynthesis/constant/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`fractal`。
