# lookup

## 一句话

按攻角查表插值给出翼型 $C_d$、$C_l$（rotorDisk `profiles`）

## 适用条件（求解器 / 场 / 前提）

- 适用：`rotorDisk` fvModel 的 `profiles` 子模型
- `type lookup;`

## 字典示例

```c++
// tutorials/incompressibleFluid/rotorDisk/constant/fvModels
profiles
{
    profile1
    {
        type lookup;
        data
        (
            // (AOA[deg]  Cd  Cl)
            (-90 0.21 1.45)
            (-18 0.21 1.45)
            (-16 0.165 1.3)
            (-14 0.125 1.1)
            (-12 0.092 0.95)
            (-10 0.07 0.8)
            (-8 0.05 0.64)
            (-6 0.04 0.5)
            (-4 0.028 0.32)
            (-2 0.022 0.18)
            (0 0.02 0)
            (2 0.022 0.18)
            (4 0.028 0.32)
            (6 0.04 0.5)
            (8 0.05 0.64)
            (10 0.07 0.8)
            (12 0.092 0.95)
            (14 0.125 1.1)
            (16 0.165 1.3)
            (18 0.21 1.45)
            (90 0.21 1.45)
        );
    }
}
```

## 参数表

| 参数 | 必需 | 说明 |
|------|------|------|
| `type` | 是 | `lookup` |
| `data` | 是 | 列表 `(AOA Cd Cl)`；AOA 单位 deg，内部转 rad；线性插值 |

## 控制方程与关联式

对给定攻角在表中线性插值 $C_d$、$C_l$。

## 文献与源码依据

- [`src/fvModels/rotorDisk/profileModel/lookup/lookupProfile.H`](../../../../src/fvModels/rotorDisk/profileModel/lookup/lookupProfile.H)

## 教程与模板

- `tutorials/incompressibleFluid/rotorDisk`

## 注意事项

- 攻角范围应覆盖运行工况；表外行为取决于实现的外推/夹紧。
