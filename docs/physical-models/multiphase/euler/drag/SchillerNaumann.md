# SchillerNaumann

## 一句话
分散相气泡/颗粒阻力的 Schiller–Naumann 关联（返回 `Cd`·Re`）。

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（`dispersedDragModel`）
- **族**: 阻力（基类 `dragModel`）
- **注册名**: `SchillerNaumann`

## 字典示例
```
drag
{
    air_dispersedIn_water
    {
        type    SchillerNaumann;
        residualRe  1e-3;   // 基类 residualRe（若字典提供）
    }
}
```
（具体写在 `constant/momentumTransfer` 的 `drag` 子字典（OpenFOAM-13）；相界面键名依 blending/相名。）

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `type` | 必须为 `SchillerNaumann` | yes | — |
| （基类）`residualRe` 等 | 见 `dispersedDragModel` | 视基类 | — |

本模型 `.C` 构造函数无额外系数。

## 控制方程与关联式
实现返回 \(C_D Re\)（`CdRe`()`）：

\[
C_D Re =
\begin{cases}
24\,(1 + 0.15\,Re^{0.687}) & Re < 1000 \\
0.44\,Re & Re \ge 1000
\end{cases}
\]

其中 \(Re\) 为界面相对雷诺数 `interface_`.Re()`（见 `SchillerNaumann`.C`）。

## 文献与源码依据
- 类: `Foam`::dragModels::SchillerNaumann`
- 源码: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/dragModels/SchillerNaumann/SchillerNaumann.C`

## 教程与模板
- `tutorials/multiphaseEuler/bubbleColumn/constant/momentumTransfer`（及同类气泡柱案例）

## 注意事项
- 适用于球形分散相假设；高空隙率需配合 swarm 修正或改用其他阻力模型。
- 类型名必须与 RTS 注册名一致：`SchillerNaumann`。
