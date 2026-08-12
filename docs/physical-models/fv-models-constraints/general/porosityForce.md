# porosityForce

## 一句话

多孔介质阻力（挂接 porosityModel）

## 适用条件（求解器 / 场 / 前提）

适用: 流体求解器；需 cellZone

## 字典示例



```c++
// `tutorials/compressibleVoF/angledDuct/constant/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

porosity1
{
    type            porosityForce;

    porosityForceCoeffs
    {
        cellZone        porosity;

        type            DarcyForchheimer;

        d   (2e8 -1000 -1000);
        f   (0 0 0);

        coordinateSystem
        {
            type    cartesian;
            origin  (0 0 0);
            coordinateRotation
            {
                type    axesRotation;
                e1  (0.70710678 0.70710678 0);
                e2  (0 0 1);
            }
        }
    }
}


// ************************************************************************* //
```

## 参数表

主要入口以源码 `Usage` 为准。常见关键字见字典示例；完整列表与默认值见对应 `.H`。

| 说明 | |
|------|--|
| 配置位置 | 通常 `constant/fvModels` 或 `constant/fvConstraints` / `constant/dynamicMeshDict` |
| 选择关键字 | `type`（须与 RTS 注册名一致） |
| 区域选择 | 多数源/约束需要 `cellZone` 或等价选择 |


## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> This model applies the force exerted on the fluid by a porous media

## 文献与源码依据

- 源码：[`src/fvModels/general/porosityForce/porosityForce.H`](../../../../src/fvModels/general/porosityForce/porosityForce.H)
- 实现：同目录 `.C`

## 教程与模板

- 模板：`etc/caseDicts/fvModels/porosity/porousZone`
- 教程：`tutorials/incompressibleFluid/porousBlockage`、`tutorials/fluid/angledDuct*`、`*/angledDuct`

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
