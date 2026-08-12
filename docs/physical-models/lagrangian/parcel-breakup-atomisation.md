# Breakup / Atomisation（喷雾）

仅 **spray** 类云启用。宏：`makeSprayParcelBreakupModels`.H`、`makeSprayParcelAtomisationModels`.H`。

---

# BreakupModel

## NoBreakup

### 一句话
关闭二次破碎。

### 适用条件
spray 云但不破碎。

### 字典示例
`breakupModel` none;`

### 参数表
无。

### 依据
`BreakupModel/NoBreakup/`

---

## ReitzDiwakar / ReitzKHRT / TAB / ETAB / SHF / PilchErdman

### 一句话（分型）
| 类型 | 一句话 |
|------|--------|
| `ReitzDiwakar` | Reitz–Diwakar 破碎 |
| `ReitzKHRT` | KH–RT 不稳定性破碎 |
| `TAB` | Taylor Analogy Breakup |
| `ETAB` | 增强 TAB |
| `SHF` | 液滴变形/破碎 SHF |
| `PilchErdman` | Pilch–Erdman |

### 适用条件（求解器 / 场 / 前提）
- **适用**: `sprayCloud` + `multicomponentFluid` 喷雾（如 `aachenBomb`）
- **前提**: 正确的液体物性与相对速度

### 字典示例

摘录 `tutorials/multicomponentFluid/aachenBomb/constant/cloudProperties`：

```cpp
breakupModel    ReitzDiwakar; // ReitzKHRT;

ReitzDiwakarCoeffs
{
    solveOscillationEq yes;
    Cbag            6;
    Cb              0.785;
    Cstrip          0.5;
    Cs              10;
}

/*
ReitzKHRTCoeffs
{
    solveOscillationEq yes;
    B0              0.61;
    B1              40;
    Ctau            1;
    CRT             0.1;
    msLimit         0.2;
    WeberLimit      6;
}
*/
TABCoeffs
{
    y0              0;
    yDot0           0;
    Cmu             10;
    Comega          8;
    WeCrit          12;
}
```

关闭：`breakupModel none;`

### 参数表
各模型有 `B*` / `C*` 或时间尺度系数——见对应 `.H`；上表为 aachenBomb 实测字典。

### 控制方程与关联式
当 Weber / 变形超过阈值时减小粒径、增加数量，守恒质量。

### 文献与源码依据
`submodels/Spray/BreakupModel/{ReitzDiwakar,ReitzKHRT,TAB,ETAB,SHF,PilchErdman}/`

### 教程与模板
`tutorials/multicomponentFluid/aachenBomb`

### 注意事项
- 系数敏感；与雾化 `atomisationModel` 分工：一次雾化 vs 二次破碎。

---

# AtomisationModel

| 类型 | 一句话 |
|------|--------|
| `NoAtomisation` | 关闭 |
| `BlobsSheetAtomisation` | 液丝/液片雾化 |
| `LISAAtomisation` | LISA 雾化 |

### 共用模板
- **适用**: spray 云一次雾化
- **方程**: 喷嘴出口液片破碎成滴的粒径/速度
- **依据**: `AtomisationModel/{BlobsSheetAtomisation,LISAAtomisation,NoAtomisation}/`
- **教程**: `aachenBomb`（该案为 `atomisationModel none;`）
- **注意**: 与 `ConeInjection` 联用常见

### 字典示例

```cpp
atomisationModel none;
// 或 LISA / BlobsSheetAtomisation + 对应 *Coeffs（见源码 Usage）
```

## 覆盖计数
Breakup **7**（含 No）+ Atomisation **3** = 宏全覆盖。
