# MRF-boundary-conditions

## 一句话

MRF 专用速度边界条件概览（完整条目见 Phase 2 边界条件目录）。

## 适用条件（求解器 / 场 / 前提）

适用: 含 MRF 区的流体案例；场 `U`。

## 字典示例

```c++
// 0/U
rotorWall
{
    type            MRFnoSlip;
    value           uniform (0 0 0);
}

```

## 参数表

| 类型 | 作用 |
|------|------|
| `MRFnoSlip` | MRF 壁面无滑移 |
| `MRFslip` | MRF 滑移 |
| `MRFFreestreamVelocity` | MRF 自由流速度 |


## 控制方程与关联式

相对 MRF 旋转框架施加壁面/远场速度条件；实现见 `src/finiteVolume/cfdTools/general/MRF/derivedFvPatchFields/`。

## 文献与源码依据

- `src/finiteVolume/cfdTools/general/MRF/derivedFvPatchFields/`

## 教程与模板

- `tutorials/fluid/mixerVessel2DMRF`

## 注意事项

- Phase 2 将补全逐条 BC 字典；此处仅动网格/MRF 域交叉索引
