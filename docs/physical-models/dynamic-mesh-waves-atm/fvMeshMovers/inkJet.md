# inkJet

## 一句话

喷墨式简单运动

## 适用条件（求解器 / 场 / 前提）

dynamicMeshDict → mover

## 字典示例

```c++
// constant/dynamicMeshDict
mover
{
    type    inkJet;
    // libs / 子字典见源码
}

```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| （见源码 Usage） | 以头文件为准 | — |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Mesh motion specifically for the "pumping" system of an ink-jet
> injector.
>
> The set of points in the "pumping" region are compressed and expanded
> sinusoidally to impose a sinusoidal variation of the flow at the
> nozzle exit.

## 文献与源码依据

- 源码：[`src/fvMeshMovers/inkJet/inkJet_fvMeshMover.H`](../../../../src/fvMeshMovers/inkJet/inkJet_fvMeshMover.H)
- 实现：同目录 `.C`

## 教程与模板

- `movingMesh` 模块与含 `dynamicMeshDict` 的流体教程

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
