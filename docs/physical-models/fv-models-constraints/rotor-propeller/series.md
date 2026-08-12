# series

## 一句话

用余弦/正弦级数给出翼型 $C_d$、$C_l$（rotorDisk `profiles`）

## 适用条件（求解器 / 场 / 前提）

- 适用：`rotorDisk` 的 `profiles` 子模型
- `type series;`

## 字典示例

> （由源码构造函数推断，无官方教程字面 `series` 实例；`lookup` 教程可对照改 type）

```c++
profiles
{
    profile1
    {
        type        series;

        // Cd = Σ CdCoeffs_i * cos(i*AOA)
        // Cl = Σ ClCoeffs_i * sin(i*AOA)   （AOA 内部为 rad）
        CdCoeffs    (0.02 0.0 0.01);
        ClCoeffs    (0.0  5.7 0.0);
    }
}
```

## 参数表

| 参数 | 必需 | 说明 |
|------|------|------|
| `type` | 是 | `series` |
| `CdCoeffs` | 是 | 阻力余弦级数系数列表 |
| `ClCoeffs` | 是 | 升力正弦级数系数列表 |

## 控制方程与关联式

$$
C_d=\sum_i C_{d,i}\cos(i\alpha),\quad
C_l=\sum_i C_{l,i}\sin(i\alpha)
$$

其中 $\alpha$ 为攻角（输入 deg，内部 rad）。

## 文献与源码依据

- [`src/fvModels/rotorDisk/profileModel/series/seriesProfile.C`](../../../../src/fvModels/rotorDisk/profileModel/series/seriesProfile.C)

## 教程与模板

- 对照 `tutorials/incompressibleFluid/rotorDisk`（官方示例为 `lookup`）

## 注意事项

- 列表长度任意，但须与期望谐波阶数一致。
