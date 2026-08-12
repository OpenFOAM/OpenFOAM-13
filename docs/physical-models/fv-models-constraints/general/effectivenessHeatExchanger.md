# effectivenessHeatExchanger

## 一句话

效能法换热器源

## 适用条件（求解器 / 场 / 前提）

适用: 有能量方程的流体；常需 cellZone

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
effectivenessHeatExchanger1
    {
        type                    effectivenessHeatExchanger;

        cellZone                porosity;

        secondaryMassFlowRate   1.0;
        secondaryInletT         336;
        primaryInletT           293;

        faceZone                facesZoneInletOriented;

        effectiveness           <function2>;
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

> Heat exchanger model, based on an effectiveness
>
> The total heat exchange source is given by:
> $$
>     Q_t = e(\phi, \dot{m}_2) (T_2 - T_1) \phi c_p
> $$
>
> where:
> 
>     Q_t       | total heat source
>     e(\phi,\dot{m}_2) | effectiveness table
>     \phi      | net mass flux entering heat exchanger [kg/s]
>     \dot{m}_2 | secondary mass flow rate [kg/s]
>     T_1       | primary inlet temperature [K]
>     T_2       | secondary inlet temperature [K]
>     c_p       | specific heat capacity [J/kg/K]
> 
>
> The distribution inside the hear exchanger is given by:
> $$
>     Q_c = \frac{V_c |U_c| (T_c - T_{ref})}{\sum(V_c |U_c| (T_c - T_{ref}))}
> $$
>
> where:
> 
>     Q_c     | source for cell
>     V_c     | volume of the cell [m^3]
>     U_c     | local cell velocity [m/s]
>     T_c     | local call temperature [K]
>     T_{ref} | min or max(T) in cell zone depending on the sign of Q_t [K]
> 

## 文献与源码依据

- 源码：[`src/fvModels/general/effectivenessHeatExchanger/effectivenessHeatExchanger.H`](../../../../src/fvModels/general/effectivenessHeatExchanger/effectivenessHeatExchanger.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvModels/`
- 例：`tutorials/fluid/angledDuct`（porosity）、`tutorials/incompressibleFluid/rotorDisk`（转子类）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
