# coefficientPhaseChange

## 一句话
This simple model generates a phase change between two phases calculated

## 适用条件（求解器 / 场 / 前提）
- 通用相变 fvModel；可用区域依赖链接的 `fvModels` 库
- **族**: 通用相变（基类 `fvModel`）
- **注册名**: `coefficientPhaseChange`

## 字典示例
```
coefficientPhaseChange
{
type            coefficientPhaseChange;

phases          (liquid vapour);

C               [kg/m^2/s] 0.1;
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `coefficientPhaseChange`
- 基类: `fvModel`


## 控制方程与关联式
This simple model generates a phase change between two phases calculated
from the following expression:

[
{m}/V = C ]

{m}/V | mass transfer rate per unit volume
C         | coefficient
| volume fraction of the source phase

## 文献与源码依据
- 类: `Foam`::fv::coefficientPhaseChange`
- 源码路径: `src/fvModels/general/phaseChange/coefficientPhaseChange.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`coefficientPhaseChange`。
