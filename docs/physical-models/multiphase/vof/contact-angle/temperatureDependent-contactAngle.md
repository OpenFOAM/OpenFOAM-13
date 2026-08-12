# temperatureDependent

## 一句话
Temperature-dependent contact angle model.

## 适用条件（求解器 / 场 / 前提）
- 适用: VoF
- **族**: 接触角模型（基类 `contactAngleModel`）
- **注册名**: `temperatureDependent`

## 字典示例
```
contactAngle
{
type                temperatureDependent;
contactAngle        constant 0.07;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `T` | Temperature field name | no | T |
| `contactAngle` | contact angle function | yes | Example of the contact angle specification: |


## 控制方程与关联式
Temperature-dependent contact angle model.

The contact angle is evaluated from the specified Foam::Function1 for the
temperature field looked-up from the mesh database the name of which
may optionally be provided.

## 文献与源码依据
- 类: `Foam`::contactAngleModels::temperatureDependent`
- 源码路径: `src/twoPhaseModels/interfaceProperties/contactAngleModels/temperatureDependent/temperatureDependentContactAngle.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`temperatureDependent`。
