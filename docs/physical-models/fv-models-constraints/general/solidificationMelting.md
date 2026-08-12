# solidificationMelting

## 一句话

凝固熔化焓-孔隙率模型

## 适用条件（求解器 / 场 / 前提）

适用: 有能量的流体（如 fluid）；需 cellZone

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
solidificationMelting1
    {
        type            solidificationMelting;

        cellZone        iceZone;

        Tsol            273;
        L               334000;
        thermoMode      thermo;
        beta            50e-6;
        rhoRef          800;
    }
```

## 参数表

主要入口以源码 `Usage` 为准。常见关键字见字典示例；完整列表与默认值见对应 `.H`。

| 说明 | |
|------|--|
| 配置位置 | 通常 `constant/fvModels` 或 `constant/fvConstraints` / `constant/dynamicMeshDict` |
| 选择关键字 | `type`（须与 RTS 注册名一致） |
| 区域选择 | 多数源/约束需要 `cellZone` 或等价选择 |


## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> This source is designed to model the effect of solidification and melting
> processes, e.g. windshield defrosting.
>
> The isotherm phase change occurs at the melting temperature, \c Tsol (= \c
> Tliq). The not isotherm phase change occurs between solidus and liquidus
> temperature, \c Tsol < \c Tliq respectively, as long as the melt fraction is
> greater than the max eutectic melt fraction, \c alpha1e (0 = pure_substance,
> 1 = eutectic_mixture is not permitted), where a linear eutectic melt
> fraction to temperature relation is considered; e.g. given a specific
> quantity of a binary system, \c alpha1 is its melt fraction and \c alpha0 is
> its solid fraction, such that \c alpha0 = 1 - \c alpha1 therefore, assuming
> infinite solute diffusion, the quantity of a component in solid phase is
> (1 - \c alpha1) * \c CS where \c CS is the solid concentration of the
> considered component and the quantity of a component in liquid phase is \c
> alpha1 * \c CL where \c CL is the melt concentration of the considered
> component; considering that the total quantity of a component must be equal
> to the sum of the quantities of the considered component in the liquid and
> solid phases, if \c C0 is the initial concentration of the considered
> component before the phase change, then:
> \c C0 = (1 - \c alpha1) * \c CS + \c alpha1 * \c CL      (lever rule)
> from which: \c alpha1 = (\c C0 - \c CS) / (\c CL - \c CS)
> and thus:
> - for a miscible binary system \c alpha1e = 0;
> - for a binary system not miscible at solid state
>   \c alpha1e = \c C0 / \c CLE where \c CLE is eutectic melt concentration;
> - for a binary system partially-miscible at solid state
>   \c alpha1e = (\c C0 - \c CSE) / (\c CLE - \c CSE) where \c CSE is eutectic
>   solid concentration of the relative solid solution.
>
> The presence of the solid phase in the flow field is incorporated into the
> model as a momentum porosity contribution; the energy associated with the
> phase change is added as an enthalpy contribution.
>
> References:
>     >     Voller, V. R., & Prakash, C. (1987).
>     >     A fixed grid numerical modelling methodology for convection-diffusion
>     >     mushy region phase-change problems.
>     >     International Journal of Heat and Mass Transfer, 30(8), 1709-1719.
>     >
>     >     Swaminathan, C. R., & Voller, V. R. (1992).
>     >     A general enthalpy method for modeling solidification processes.
>     >     Metallurgical transactions B, 23(5), 651-664.
>     > 
>
> The model generates the field \c \<name\>:alpha1 which can be visualised to
> to show the melt distribution as a fraction [0-1].

## 文献与源码依据

- 源码：[`src/fvModels/general/solidificationMelting/solidificationMelting.H`](../../../../src/fvModels/general/solidificationMelting/solidificationMelting.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvModels/`
- 例：`tutorials/fluid/angledDuct`（porosity）、`tutorials/incompressibleFluid/rotorDisk`（转子类）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
