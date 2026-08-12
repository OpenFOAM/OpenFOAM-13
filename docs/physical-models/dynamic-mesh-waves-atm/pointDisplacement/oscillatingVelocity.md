# oscillatingVelocity

## 一句话

振荡速度 point BC

## 适用条件（求解器 / 场 / 前提）

pointMotionU 等

## 字典示例

```c++
// 0/pointDisplacement 边界
<patch>
{
    type    oscillatingVelocity;
    value   uniform (0 0 0);
}

```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| （见源码 Usage） | 以头文件为准 | — |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Foam::oscillatingVelocityPointPatchVectorField

## 文献与源码依据

- 源码：[`src/fvMotionSolver/pointPatchFields/derived/oscillatingVelocity/oscillatingVelocityPointPatchVectorField.H`](../../../../src/fvMotionSolver/pointPatchFields/derived/oscillatingVelocity/oscillatingVelocityPointPatchVectorField.H)
- 实现：同目录 `.C`

## 教程与模板

- 动网格教程中的 `0/pointDisplacement`；BC 全谱见 Phase 2

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
