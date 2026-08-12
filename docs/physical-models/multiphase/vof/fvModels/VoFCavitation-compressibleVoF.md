# VoFCavitation

## 一句话
Cavitation fvModel

## 适用条件（求解器 / 场 / 前提）
- 适用: **compressibleVoF**（`Foam`::fv::compressible::VoFCavitation`）；不适用: incompressibleVoF
- **族**: VoF 专用 fvModel（基类 `fvModel`）
- **注册名**: `VoFCavitation`

## 字典示例
```
VoFCavitation
{
type    VoFCavitation;

model   SchnerrSauer;

KunzCoeffs
{
pSat    2300;   // Saturation pressure

UInf    20.0;
tInf    0.005; // L = 0.1 m
Cc      1000;
Cv      1000;
}

MerkleCoeffs
{
pSat    2300;   // Saturation pressure

UInf    20.0;
tInf    0.005;  // L = 0.1 m
Cc      80;
Cv      1e-03;
}

SchnerrSauerCoeffs
{
pSat    2300;   // Saturation pressure

n       1.6e+13;
dNuc    2.0e-06;
Cc      1;
Cv      1;
}
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `VoFCavitation`
- 基类: `fvModel`


## 控制方程与关联式
Cavitation fvModel

## 文献与源码依据
- 类: `Foam`::fv::compressible::VoFCavitation`
- 源码路径: `applications/modules/compressibleVoF/fvModels/VoFCavitation/VoFCavitation.C`

## 教程与模板
- `tutorials/incompressibleVoF/propeller/constant/fvModels`
- `tutorials/incompressibleVoF/cavitatingBullet/constant/fvModels`
- `tutorials/compressibleVoF/throttle/constant/fvModels`
- `tutorials/compressibleVoF/ballValve/constant/fvModels`

## 注意事项
- 类型名必须与 RTS 注册名一致：`VoFCavitation`。
