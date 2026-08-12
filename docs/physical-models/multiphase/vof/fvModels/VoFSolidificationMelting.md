# VoFSolidificationMelting

## 一句话
Solidification and melting model for VoF simulations.

## 适用条件（求解器 / 场 / 前提）
- 适用: **compressibleVoF**（`libVoFSolidificationMelting`）；**不适用: incompressibleVoF**
- **族**: VoF 专用 fvModel（基类 `fvModel`）
- **注册名**: `VoFSolidificationMelting`

## 字典示例
```
VoFSolidificationMelting1
{
type            VoFSolidificationMelting;

cellZone        solidZone;

alphaSolidT     table
(
(330 1)
(335 0)
);

L               334000;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `alphaSolidT` | Solid fraction as function of temperature | yes | — |
| `L` | Latent heat of fusion [J/kg] | yes | — |
| `relax` | Relaxation coefficient [0-1] | no | 0.9 |
| `Cu` | Model coefficient | no | 100000 |
| `q` | Model coefficient | no | 0.001 |


## 控制方程与关联式
Solidification and melting model for VoF simulations.

The presence of the solid phase in the flow field is incorporated into the
model as a momentum porosity contribution; the energy associated with the
phase change is added as an enthalpy contribution.  The solid fraction as a
function of temperature `alphaSolidT` is specified as a Foam::Function1.

The model writes the field `alpha`[01].solid which can be visualised to to
show the solid distribution.

## 文献与源码依据
- 类: `Foam`::fv::VoFSolidificationMelting`
- 源码路径: `applications/modules/compressibleVoF/fvModels/VoFSolidificationMelting/VoFSolidificationMelting.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`VoFSolidificationMelting`。
