# supersonicFreestream

## 一句话
自由来流：向外部参考状态松弛。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`supersonicFreestream`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例

摘自 `tutorials/fluid/nacaAirfoil/0/U`：

```cpp
INLE1
{
    type            supersonicFreestream;
    pInf            100000;        // [Pa]
    TInf            300;           // [K]
    UInf            (600 148.16 0); // [m/s] 矢量
    gamma           1.4;           // [-]
    // 可选场名: T p psi（默认 T / p / psi）
    value           uniform (600 148.16 0);
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `T` | Temperature field name | no | T |
| `p` | Pressure field name | no | p |
| `psi` | Compressibility field name | no | psi |
| `UInf` | free-stream velocity | yes |  |
| `pInf` | free-stream pressure | yes |  |
| `TInf` | free-stream temperature | yes |  |
| `gamma` | heat capacity ratio (cp/Cv) | yes |  |

## 控制方程与关联式
自由来流：向外部参考状态松弛。

类头 `Description` 原文：

> This boundary condition provides a supersonic free-stream condition.
> 
> - supersonic outflow is vented according to ???
> - supersonic inflow is assumed to occur according to the Prandtl-Meyer
>   expansion process.
> - subsonic outflow is applied via a zero-gradient condition from inside
>   the domain.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/supersonicFreestream/supersonicFreestreamFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/supersonicFreestream/supersonicFreestreamFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/supersonicFreestream/supersonicFreestreamFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/supersonicFreestream/supersonicFreestreamFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/fluid/prism/0/U`](../../../tutorials/fluid/prism/0/U)
- [`tutorials/fluid/nacaAirfoil/0/U`](../../../tutorials/fluid/nacaAirfoil/0/U)

## 注意事项
- This boundary condition is ill-posed if the free-stream flow is normal     to the boundary.
