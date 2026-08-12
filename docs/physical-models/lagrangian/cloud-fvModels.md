# clouds（fvModel）与云激活

## 一句话
向单相求解器挂接任意数量 Lagrangian parcel 云，并与欧拉场交换源项。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `multicomponentFluid`, `fluid`, `incompressibleFluid`（经 fvModels）, 多区域 fluid 等
- **内建替代**: `incompressibleDenseParticleFluid` 直接链 parcel 库，仍通常配置 `cloudProperties`
- **前提**: `constant/cloudProperties`（单云）或 `constant/clouds` + `constant/<name>Properties`（多云）；不可压时 `physicalProperties` 提供密度

## 字典示例

```cpp
// tutorials/multicomponentFluid/aachenBomb/constant/fvModels
clouds
{
    type    clouds;
    libs    ("liblagrangianParcel.so");
}
```

头文件说明：`solution`.coupled true` 时向欧拉相施加力/热/质量源；`false` 则单向。

## 参数表
| 入口 | 含义 |
|------|------|
| `type` | `clouds` |
| `libs` | `liblagrangianParcel`.so`（模块未静态链接时） |

云物理参数全部在 `cloudProperties`，见 [cloudProperties-patterns.md](cloudProperties-patterns.md)。

## 控制方程与关联式
颗粒跟踪；源项以 `semiImplicit` 等格式反馈连续相（见 cloud `solution`.sourceTerms`）。

## 文献与源码依据
- `src/Lagrangian/parcel/fvModels/clouds/clouds.H`（Description 完整）

## 教程与模板
| 案例 | 说明 |
|------|------|
| `aachenBomb` | 喷雾燃烧 |
| `verticalChannel`*` / `filter` / `parcelInBox` | 云 + 可选 steady/LTS |
| `multiRegion/film/cylinder*` | fluid 侧 `clouds` + film 侧 `filmCloudTransfer` |
| `Goldschmidt` / `cyclone` | 稠密颗粒求解器 |

## 注意事项
- 忘记 `libs` → Unknown fvModel `clouds`。
- 多云必须先写 `constant/clouds` 名称列表。
