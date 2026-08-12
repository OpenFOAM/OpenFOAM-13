# `lambdaThixotropic`

## 一句话

触变性 λ 模型

## 适用条件（求解器 / 场 / 前提）
- 注册：incompressible / compressible / phaseIncompressible / phaseCompressible / film（子集）
- `simulationType` laminar;` + `model` lambdaThixotropic;`

## 字典示例

```c++
// constant/momentumTransport simulationType laminar;
laminar
{
model lambdaThixotropic;
turbulence on;
// RAS/LES
}

```
## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

Thixotropic viscosity momentum transport model based on the evolution of the structural parameter $ \lambda $: $$ \frac{D\lambda}{Dt} = a(1
- \lambda)^b
- c \lambda \dot{\gamma}^d $$ The viscosity is then calculated using the expression $$ u = \frac{ u_{\infty}}{{1
- K \lambda}^2} $$ Where the parameter K is given by: $$ K = 1
- \sqrt{\frac{ u_{\infty}}{ u_{0}}} $$ Here:  \lambda
| structural parameter a | model coefficient b | model coefficient c | model coefficient d | model coefficient \dot{\gamma} | stress rate [1/s] u_{0} | limiting viscosity when $ \lambda = 1 $ u_{\infty} | limiting viscosity when $ \lambda = 0 $  |
|------|------|------|------|------|------|------|------|



## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/laminar/lambdaThixotropic/lambdaThixotropic.H`](../../../src/MomentumTransportModels/momentumTransportModels/laminar/lambdaThixotropic/lambdaThixotropic.H)

## 教程与模板

- 仓库 tutorials 中未检索到 `lambdaThixotropic` 字面配置；可参考同类 `simulationType` 案例并改 `model`。
- 注册见 [`README`](../README.md) 工厂表。


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
