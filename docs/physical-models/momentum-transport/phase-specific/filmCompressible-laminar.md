# `filmCompressibleMomentumTransportModels`

## 一句话

液膜可压动量输运：仅注册层流子集（Stokes/generalisedNewtonian/lambdaThixotropic/Maxwell/Giesekus/PTT）。

## 适用条件（求解器 / 场 / 前提）

- 适用: `isothermalFilm` / `film`
- 无 RAS/LES 注册

## 字典示例

```c++
simulationType laminar;
laminar
{
    model           Stokes; // 或粘弹性子集
}
```

## 参数表

—

## 控制方程与关联式

见 `applications/modules/isothermalFilm/filmCompressibleMomentumTransportModels/filmCompressibleMomentumTransportModels.C`。

## 文献与源码依据

- 上述 `.C` 工厂文件

## 教程与模板

- `tutorials/multiRegion/film/**`

## 注意事项

- 勿在 film 区域选择 kEpsilon 等未注册模型。
