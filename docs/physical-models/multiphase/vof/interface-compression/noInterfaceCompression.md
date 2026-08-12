# noInterfaceCompression

## 一句话
Wrapper scheme to allow VoF solvers to run efficiently without interface

## 适用条件（求解器 / 场 / 前提）
- 适用: VoF 家族；关闭额外压缩
- **族**: 界面压缩格式（基类 `surfaceInterpolationScheme`）
- **注册名**: `noInterfaceCompression`

## 字典示例


> （由源码构造函数推断，无官方教程实例）

```c++
// system/fvSchemes — divSchemes
div(phi,alpha)  Gauss noInterfaceCompression;
```

## 参数表

| 参数 | 说明 |
|------|------|
| `type` | 必须为 `noInterfaceCompression` |
| （基类） | 部分模型继承 `residualRe` / `residualAlpha` 等，见对应基类 ctor |

本模型构造函数通常无额外专用系数。

## 控制方程与关联式
Wrapper scheme to allow VoF solvers to run efficiently without interface
compression, e.g. for cavitation simulations.

Example:
```
divSchemes
{
.
.
div(phi,alpha)     Gauss noInterfaceCompression vanLeer;
.
.
}
```

## 文献与源码依据
- 类: `Foam`::noInterfaceCompression`
- 源码路径: `src/twoPhaseModels/interfaceCompression/noInterfaceCompression/noInterfaceCompression.C`

## 教程与模板
- `tutorials/incompressibleVoF/propeller/system/fvSchemes`

## 注意事项
- 类型名必须与 RTS 注册名一致：`noInterfaceCompression`。
