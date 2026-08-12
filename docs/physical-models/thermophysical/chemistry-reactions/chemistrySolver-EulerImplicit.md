# `EulerImplicit`

## 一句话

欧拉隐式化学求解器。

## 适用条件（求解器 / 场 / 前提）

- `chemistryType`.solver EulerImplicit;`
- 适用: `multicomponentFluid` 等

## 字典示例

```c++
chemistryType
{
solver EulerImplicit;
}
EulerImplicitCoeffs
{
    cTauChem        1;
}
```

## 参数表

| 关键字 | 含义 |
|--------|------|
| `cTauChem` | 化学时间尺度系数（见源码 `read`） |

## 控制方程与关联式

Euler implicit chemistry solver（见源码头文件 Description）。

## 文献与源码依据

- [`src/thermophysicalModels/chemistryModel/chemistrySolver/EulerImplicit/EulerImplicit.H`](../../../src/thermophysicalModels/chemistryModel/chemistrySolver/EulerImplicit/EulerImplicit.H)

## 教程与模板

- 多数官方火焰教程用 `ode`；本求解器可用于较便宜的隐式积分

## 注意事项

- 刚性处理弱于完整 ODE 库求解器。
