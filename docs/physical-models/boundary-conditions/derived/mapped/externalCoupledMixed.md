# externalCoupledMixed

## 一句话

通过文本文件与外部程序交换 `mixed` 边界数据的耦合 BC。

## 适用条件（求解器 / 场 / 前提）

- **字典 `type`**：`externalCoupled`（RTS `TypeName`；页面名含 Mixed 指其基类行为）
- **典型场**：任意模板场（与 `mixed` 兼容）
- **库**：核心 `libfiniteVolume`

## 字典示例

> （由源码头文件 Usage 推断，无官方教程实例）

```c++
// 0/<field>
<patchName>
{
    type            externalCoupled;

    commsDir        "$FOAM_CASE/comms";
    file            data;
    calcFrequency   1;
    initByExternal  yes;

    // 可选:
    // waitInterval   1;      // [s] 轮询间隔，默认 1
    // timeOut        100;    // [s] 默认 100*waitInterval
    // log            no;
}
```

OpenFOAM → 外部（写出）：每面 `magSf value snGrad`；外部 → OpenFOAM（读入）：`value gradient valueFraction`（即 `mixed` 三件套）。通信目录为 `$FOAM_CASE/<commsDir>`，用 `OpenFOAM.lock` 握手。

## 参数表

| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `commsDir` | 通信目录 | 是 | — |
| `file` | 传输文件基名 | 是 | — |
| `initByExternal` | 是否由外部初始化 | 是 | — |
| `waitInterval` | 文件检查间隔 [s] | 否 | 1 |
| `timeOut` | 超时 [s] | 否 | 100×waitInterval |
| `calcFrequency` | 计算频率 | 否 | 1 |
| `log` | 记录控制过程 | 否 | no |

## 控制方程与关联式

本 BC 不引入额外物理方程；边界值由外部程序经 `mixed` 三分量回填。

## 文献与源码依据

- [`src/finiteVolume/fields/fvPatchFields/derived/externalCoupledMixed/externalCoupledMixedFvPatchField.H`](../../../../src/finiteVolume/fields/fvPatchFields/derived/externalCoupledMixed/externalCoupledMixedFvPatchField.H)

## 教程与模板

- 仓库 tutorials / caseDicts 中极少字面命中；按 Usage 自建 `comms/` 与外部驱动

## 注意事项

- 字典写 `type externalCoupled;`（不是 `externalCoupledMixed`）。
- 外部必须按约定写 `.in` 并恢复 lock，否则求解器会在 `timeOut` 后报错。
