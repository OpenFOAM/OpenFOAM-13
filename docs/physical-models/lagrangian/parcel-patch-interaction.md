# PatchInteractionModel（壁面/边界相互作用）

注册：`makeParcelPatchInteractionModels`.H`。

---

# localInteraction

## 一句话
按 patch 列表分别指定 escape / rebound / stick 等局部行为。

## 适用条件（求解器 / 场 / 前提）
最常用；需 `localInteractionCoeffs`.patches`。

## 字典示例

摘录 `tutorials/incompressibleDenseParticleFluid/GoldschmidtMPPIC/constant/cloudProperties`：

```cpp
patchInteractionModel localInteraction;

localInteractionCoeffs
{
    patches
    (
        top
        {
            type rebound;
            e    0.97;
            mu   0.09;
        }
        bottom
        {
            type rebound;
            e    0.97;
            mu   0.09;
        }
        walls
        {
            type rebound;
            e    0.97;
            mu   0.09;
        }
        frontAndBack
        {
            type rebound;
            e    0.97;
            mu   0.09;
        }
    );
}
```

简化通配写法：

```cpp
patchInteractionModel localInteraction;

localInteractionCoeffs
{
    patches
    (
        outlet { type escape; }
        ".*"
        {
            type rebound;
            e    1;
            mu   0;
        }
    );
}
```

## 参数表
| 入口 | 含义 | 量纲 |
|------|------|------|
| `type` escape/rebound/stick… | 交互类型 | — |
| `e` | 法向恢复系数 | 无量纲 |
| `mu` | 切向损失系数 | 无量纲 |

## 控制方程与关联式
碰撞后速度按 \(e,\mu\) 更新；escape 删除 parcel。

## 文献与源码依据
`PatchInteractionModel/LocalInteraction/`

## 教程与模板
几乎所有 `cloudProperties` 教程。

## 注意事项
- 通配 `".*"` 顺序：先匹配更具体 patch。

---

# Rebound

## 一句话
全局反弹模型。

## 适用条件
简单壁面反弹。

## 字典示例
`patchInteractionModel` rebound;` + coeffs。

## 参数表
`e`, `mu`。

## 控制方程与关联式
同恢复系数反弹。

## 文献与源码依据
`Rebound`/`

## 教程与模板
—
## 注意事项
—

---

# StandardWallInteraction

## 一句话
标准壁面相互作用（escape/rebound/stick 选项）。

## 适用条件
经典壁面交互。

## 字典示例
摘录 `tutorials/multicomponentFluid/aachenBomb` / `verticalChannel`：

```cpp
patchInteractionModel standardWallInteraction;

standardWallInteractionCoeffs
{
    type            rebound;
    // 可选 e / mu（simplifiedSiwek 煤粉案：e 1; mu 0;）
}
```

## 参数表
| 入口 | 含义 |
|------|------|
| `type` | `rebound` / `escape` / `stick` |
| `e`,`mu` | 恢复/切向系数（可选） |

---

# NoInteraction

## 一句话
无边界相互作用处理（或不改变）。

## 字典示例
`patchInteractionModel` none;`

## 参数表
无。

## 依据
`NoInteraction`/`

## 注意事项
颗粒可能穿过壁面——仅特殊用途。

---

## 覆盖计数
`LocalInteraction`, `Rebound`, `StandardWallInteraction`, `NoInteraction` → **4** = 宏全覆盖。
