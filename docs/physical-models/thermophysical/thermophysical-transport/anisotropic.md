# `anisotropic`

## 一句话

固体各向异性热输运（带坐标系/分区）

## 适用条件（求解器 / 场 / 前提）

- 适用：`solid` / `solidDisplacement` / 相固体
- `constant/thermophysicalTransport` 中 `model anisotropic;`
- 物性字典中需提供各向异性 `kappa`

## 字典示例

> （由源码头文件 Usage 推断；仓库 tutorials 中完整坐标分区示例较少）

```c++
// constant/thermophysicalTransport
model anisotropic;

// 强制边界对齐处理（与 patch 对齐因子无关）
boundaryAligned true;

// 默认坐标系
coordinateSystem
{
    type        cartesian;
    origin      (0 0 0);
    coordinateRotation
    {
        type        cylindrical;
        e3          (1 0 0);
    }
}

// 可选：按 cellZone 覆盖坐标系
zones
{
    coil1
    {
        type        cartesian;
        origin      (0.1 0.2 0.7);
        coordinateRotation
        {
            type        cylindrical;
            e3          (0.5 0.866 0);
        }
    }

    coil2
    {
        type        cartesian;
        origin      (0.4 0.5 1);
        coordinateRotation
        {
            type        cylindrical;
            e3          (0.866 0.5 0);
        }
    }
}
```

## 参数表

| 参数 | 必需 | 说明 |
|------|------|------|
| `model` | 是 | `anisotropic` |
| `boundaryAligned` | 否 | 边界对齐处理开关 |
| `coordinateSystem` | 常用 | 默认材料坐标 |
| `zones` | 否 | 分区坐标系字典 |

各向异性 `kappa` 本身在 `physicalProperties` / solid thermo 中指定，本字典负责坐标变换。

## 控制方程与关联式

Solid thermophysical transport model for anisotropic thermal conductivity：将材料坐标系下的 $\kappa$ 变换到全局系后组装热传导。

## 文献与源码依据

- 固体热输运 anisotropic 实现（见 `src/ThermophysicalTransportModels/` 固体各向异性模型）

## 教程与模板

- 对照 `solid` / 多区域 CHT 固体域的 `thermophysicalTransport`

## 注意事项

- 与流体侧 `eddyDiffusivity` 等湍流热输运模型无关；勿混用 `Prt`。
