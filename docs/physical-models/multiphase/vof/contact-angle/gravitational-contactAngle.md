# gravitational

## 一句话
Gravitational acceleration based contact angle model.

## 适用条件（求解器 / 场 / 前提）
- 适用: VoF
- **族**: 接触角模型（基类 `contactAngleModel`）
- **注册名**: `gravitational`

## 字典示例
```
contactAngle
{
type           gravitational;
gTheta         0.1;
theta0         70;
thetaAdv       100;
thetaRec       50;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `theta0` | Equilibrium contact angle | yes | — |
| `gTheta` | Gravitational acceleration scale | yes | — |
| `thetaAdv` | Limiting advancing contact angle | yes | — |
| `thetaRec` | Limiting receding contact angle | yes | Example: |


## 控制方程与关联式
Gravitational acceleration based contact angle model.

## 文献与源码依据
- 类: `Foam`::contactAngleModels::gravitational`
- 源码路径: `src/twoPhaseModels/interfaceProperties/contactAngleModels/gravitational/gravitationalContactAngle.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`gravitational`。
