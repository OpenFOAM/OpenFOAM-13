# coefficientMassTransfer

## 一句话
This simple model generates a mass transfer between two phases calculated

## 适用条件（求解器 / 场 / 前提）
- 通用传质源项
- **族**: 通用传质（基类 `fvModel`）
- **注册名**: `coefficientMassTransfer`

## 字典示例
```
coefficientMassTransfer
{
type            coefficientMassTransfer;

phases          (liquid vapour);

C               [kg/m^2/s] 0.1;
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `coefficientMassTransfer`
- 基类: `fvModel`


## 控制方程与关联式
This simple model generates a mass transfer between two phases calculated
from the following expression:

[
{m}/V = C ]

{m}/V | mass transfer rate per unit volume
C         | coefficient
| volume fraction of the source phase

## 文献与源码依据
- 类: `Foam`::fv::coefficientMassTransfer`
- 源码路径: `src/fvModels/general/massTransfer/coefficientMassTransfer.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`coefficientMassTransfer`。
