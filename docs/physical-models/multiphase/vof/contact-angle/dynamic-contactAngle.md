# dynamic

## 一句话
Dynamic contact angle model.

## 适用条件（求解器 / 场 / 前提）
- 适用: VoF
- **族**: 接触角模型（基类 `contactAngleModel`）
- **注册名**: `dynamic`

## 字典示例
```
contactAngle
{
type           dynamic;
uTheta         1;
theta0         70;
thetaAdv       100;
thetaRec       50;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `theta0` | Equilibrium contact angle | yes | — |
| `uTheta` | Velocity scale | yes | — |
| `thetaAdv` | Limiting advancing contact angle | yes | — |
| `thetaRec` | Limiting receding contact angle | yes | Example: |


## 控制方程与关联式
Dynamic contact angle model.

## 文献与源码依据
- 类: `Foam`::contactAngleModels::dynamic`
- 源码路径: `src/twoPhaseModels/interfaceProperties/contactAngleModels/dynamic/dynamicContactAngle.C`

## 教程与模板
- `tutorials/XiFluid/stratified/constant/physicalProperties`
- `tutorials/XiFluid/moriyoshiHomogeneous/moriyoshiHomogeneous/constant/physicalProperties`
- `tutorials/XiFluid/kivaTest/constant/physicalProperties`
- `tutorials/XiFluid/1D/constant/physicalProperties`
- `tutorials/shockFluid/wedge15Ma5/constant/physicalProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`dynamic`。
