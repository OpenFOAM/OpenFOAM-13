# sixDoFMotion

## 一句话

查表/函数六自由度运动

## 适用条件（求解器 / 场 / 前提）

solidBodyMotionFunction（规定运动，非动力求解）

## 字典示例

```c++
solidBodyMotionFunction    sixDoFMotion;
sixDoFMotionCoeffs
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

> Tabulated 6DoF motion function.
>
> Obtained by interpolating tabulated data for surge (x-translation),
> sway (y-translation), heave (z-translation), roll (rotation about x),
> pitch (rotation about y) and yaw (rotation about z).

## 文献与源码依据

- 源码：[`src/motionSolvers/displacement/solidBody/solidBodyMotionFunctions/sixDoFMotion/sixDoFMotion.H`](../../../../src/motionSolvers/displacement/solidBody/solidBodyMotionFunctions/sixDoFMotion/sixDoFMotion.H)
- 实现：同目录 `.C`

## 教程与模板

- 见仓库 `tutorials`/` 中含该 `type` 的案例
- `etc/caseDicts/` 若有同名模板一并对照

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
