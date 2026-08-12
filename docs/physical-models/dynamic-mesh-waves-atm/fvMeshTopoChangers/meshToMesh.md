# meshToMesh

## 一句话

网格序列映射（mesh-to-mesh）

## 适用条件（求解器 / 场 / 前提）

dynamicMeshDict → topoChanger

## 字典示例

```c++
topoChanger
{
    type    meshToMesh;

    libs    ("libmeshToMeshTopoChanger.so");

    times   (0.0015 0.003);

    cycle   #calc "1.0/300.0";
    begin   0;

    timeDelta 1e-6;
}
```

## 参数表

主要入口以源码 `Usage` 为准。常见关键字见字典示例；完整列表与默认值见对应 `.H`。

| 说明 | |
|------|--|
| 配置位置 | 通常 `constant/fvModels` 或 `constant/fvConstraints` / `constant/dynamicMeshDict` |
| 选择关键字 | `type`（须与 RTS 注册名一致） |
| 区域选择 | 多数源/约束需要 `cellZone` 或等价选择 |


## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> fvMeshTopoChanger which maps the fields to a new mesh or sequence of meshes
>
> which can optionally be mapped to repeatedly for example in multi-cycle
> engine cases or cycled through for symmetric forward and reverse motion.

## 文献与源码依据

- 源码：[`src/fvMeshTopoChangers/meshToMesh/meshToMesh_fvMeshTopoChanger.H`](../../../../src/fvMeshTopoChangers/meshToMesh/meshToMesh_fvMeshTopoChanger.H)
- 实现：同目录 `.C`

## 教程与模板

- 见仓库 `tutorials`/` 中含该 `type` 的案例
- `etc/caseDicts/` 若有同名模板一并对照

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
