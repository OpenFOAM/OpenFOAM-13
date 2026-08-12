# SDA

## 一句话

船舶 SDA 运动

## 适用条件（求解器 / 场 / 前提）

solidBodyMotionFunction

## 字典示例

```c++
solidBodyMotionFunction    SDA;
SDACoeffs
{
    // 见源码
}

```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| （见源码 Usage） | 以头文件为准 | — |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Ship design analysis (SDA) 3DoF motion function.
>
> Comprising sinusoidal roll (rotation about x), heave (z-translation)
> and sway (y-translation) motions with changing amplitude and phase.

## 文献与源码依据

- 源码：[`src/motionSolvers/displacement/solidBody/solidBodyMotionFunctions/SDA/SDA.H`](../../../../src/motionSolvers/displacement/solidBody/solidBodyMotionFunctions/SDA/SDA.H)
- 实现：同目录 `.C`

## 教程与模板

- 见仓库 `tutorials`/` 中含该 `type` 的案例
- `etc/caseDicts/` 若有同名模板一并对照

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
