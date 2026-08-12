# multiValveEngineState

## 一句话

Writes the multi-valve engine motion state  providing details of the position and speed of the piston and valves.

## 适用条件（求解器 / 场 / 前提）

适用: functionObject；写出 multiValveEngine 状态

## 字典示例

```c++
multiValveEngineState
{
    type           multiValveEngineState;
    libs           ("libfvMeshMoversMultiValveEngine.so");
}
```

## 参数表

主要入口以源码 `Usage` 为准。常见关键字见字典示例；完整列表与默认值见对应 `.H`。

| 说明 | |
|------|--|
| 选择关键字 | `type`（须与 RTS 注册名一致） |
| 配置位置 | 见适用条件 |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Writes the multi-valve engine motion state
> 
> providing details of the position and speed of the piston and valves.

## 文献与源码依据

- 源码：[`src/fvMeshMovers/multiValveEngine/multiValveEngineState/multiValveEngineState.H`](../../../../src/fvMeshMovers/multiValveEngine/multiValveEngineState/multiValveEngineState.H)
- 实现：同目录 `.C`

## 教程与模板

- 发动机气门/活塞动网格教程

## 注意事项

- 随 multiValveEngine 使用
