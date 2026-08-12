# `specie`

## 一句话

组分基本属性（分子量等），几乎所有 thermoType 的底层。

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.specie specie;`
- 所有 `for`*` 宏均以 `specie` 为模板参数

## 字典示例

```c++
mixture
{
    specie
    {
        molWeight   28.9;
    }
}
```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| `molWeight` | 分子量 | [1 0 0 0 0 0 0] g/mol 量级（OpenFOAM 用 kg/kmol 一致约定） |

## 控制方程与关联式

提供气体常数所需的摩尔质量：$R = R_u / W$。

## 文献与源码依据

- `src/thermophysicalModels/specie/specie/`

## 教程与模板

- 所有 `physicalProperties`

## 注意事项

- 分子量错误会直接扭曲密度与声速。
