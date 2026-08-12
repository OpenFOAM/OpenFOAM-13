# powerLaw

## 一句话

幂律孔隙阻力模型（经 `porosityForce` 选用）

## 适用条件（求解器 / 场 / 前提）

- 作为 `porosityModel` RTS 类型，挂在 `fvModels` → `type porosityForce` 的 `porosityForceCoeffs` 内
- 需要 `cellZone`

## 字典示例

> （由源码构造函数推断，无官方教程实例；骨架对照 `porosityForce` + Darcy 教程）

```c++
// constant/fvModels
porosity1
{
    type            porosityForce;

    porosityForceCoeffs
    {
        cellZone        porosity;

        type            powerLaw;

        // Foam::porosityModels::powerLaw 必读:
        C0              500;    // 线性系数（与密度相乘）
        C1              2;      // 速度幂指数

        // 可选:
        // rho             rho; // 密度场名，默认 "rho"
    }
}
```

阻力源项形式（头文件 Description）：

$$
S = -\rho C_0 |U|^{(C_1-1)} U
$$

## 参数表

| 参数 | 必需 | 默认 | 说明 |
|------|------|------|------|
| `C0` | 是 | — | 模型线性系数 |
| `C1` | 是 | — | 速度幂指数 |
| `rho` | 否 | `rho` | 密度场名 |
| `cellZone` | 是（父级） | — | 作用区域 |

## 控制方程与关联式

Power law porosity model：$S=-\rho C_0 |U|^{(C_1-1)}U$。

## 文献与源码依据

- [`src/finiteVolume/cfdTools/general/porosityModel/powerLaw/powerLaw.C`](../../../../src/finiteVolume/cfdTools/general/porosityModel/powerLaw/powerLaw.C)
- 父模型：[porosityForce](../general/porosityForce.md)

## 教程与模板

- 模板：`etc/caseDicts/fvModels/porosity/porousZone`（官方示例多为 DarcyForchheimer / fixedCoeff）
- 教程对照：`tutorials/*/angledDuct*` 的 `porosityForce` 写法，将 `type` 改为 `powerLaw` 并提供 `C0`/`C1`

## 注意事项

- 旧文档/第三方示例中的关键字 `power` **不是**本实现入口；源码只 `lookup` `C0`/`C1`。
