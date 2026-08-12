# contactAngle

## 一句话
General alpha contact angle boundary condition.

## 适用条件（求解器 / 场 / 前提）
- 适用: VoF `alpha`.*` 壁面 BC
- **族**: 接触角边界（基类 `fvPatchScalarField`）
- **注册名**: `contactAngle`

## 字典示例
```
<patchName>
{
type            contactAngle;
limit           none;
contactAngle
{
type            constant;
theta0          70;
}
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `limit` | Limiting option | yes | — |
| `contantAngle` | Contact angle model settings | no | none |


## 控制方程与关联式
General alpha contact angle boundary condition.

The essential entry "limit" controls the gradient of alpha1 on the wall:
- none - Calculate the gradient from the contact-angle without limiter
- gradient - Limit the wall-gradient such that alpha1 remains bounded
on the wall
- alpha - Bound the calculated alpha1 on the wall
- zeroGradient - Set the gradient of alpha1 to 0 on the wall, i.e.
reproduce previous behaviour, the pressure BCs can be left as before.

Note that if any of the first three options are used the boundary condition
on `p_rgh` must set to guarantee that the flux is corrected to be zero at
the wall.

## 文献与源码依据
- 类: `Foam`::contactAngleFvPatchScalarField`
- 源码路径: `src/twoPhaseModels/interfaceProperties/contactAngle/contactAngleFvPatchScalarField.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`contactAngle`。
