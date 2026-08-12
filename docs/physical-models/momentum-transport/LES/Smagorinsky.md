# `Smagorinsky`

## 一句话

Smagorinsky SGS

## 适用条件（求解器 / 场 / 前提）

- 注册：incompressible + compressible
- phase* 子集：`Smagorinsky`/`kEqn`（见 phase*Models.C）

## 字典示例

```c++
// tutorials/multiphaseEuler/bubbleColumnLES/constant/momentumTransport.air
simulationType  LES;

LES
{
    model           Smagorinsky;

    turbulence      on;

    printCoeffs     on;

    delta           cubeRootVol;

    cubeRootVolCoeffs
    {
        deltaCoeff      1;
    }

    // 默认系数（源码头文件；可覆盖）:
    SmagorinskyCoeffs
    {
        Ck              0.094;
        Ce              1.048;
    }
}
```

## 参数表

| 参数 | 默认 | 含义 |
|------|------|------|
| `Ck` | 0.094 | SGS 涡粘系数：$\nu_\mathrm{sgs}=C_k\sqrt{k}\Delta$ |
| `Ce` | 1.048 | 局部平衡耗散系数 |
| `delta` | （子模型） | 滤波宽度模型，如 `cubeRootVol` |

## 控制方程与关联式

The Smagorinsky SGS model. Implemented form is obtained from the k-equation
model assuming local equilibrium:

$$
B = \frac{2}{3}k I - 2\nu_\mathrm{sgs}\mathrm{dev}(D),\quad
D=\mathrm{symm}(\nabla U)
$$

with $k$ from $D:B + C_e k^{3/2}/\Delta = 0$ and
$\nu_\mathrm{sgs}=C_k\sqrt{k}\Delta$.

See also：`Foam::LESModels::kEqn`

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/LES/Smagorinsky/Smagorinsky.H`](../../../../src/MomentumTransportModels/momentumTransportModels/LES/Smagorinsky/Smagorinsky.H)

## 教程与模板

- `tutorials/multiphaseEuler/bubbleColumnLES/constant/momentumTransport.air`
- `tutorials/multiphaseEuler/bubbleColumnLES/constant/momentumTransport.water`
- `tutorials/multiphaseEuler/LBend/constant/momentumTransport.gas`
- `tutorials/multiphaseEuler/fluidisedBed/constant/momentumTransport.air`

## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
