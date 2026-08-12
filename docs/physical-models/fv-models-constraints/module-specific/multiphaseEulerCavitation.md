# multiphaseEulerCavitation

## 一句话

Euler 空化

## 适用条件（求解器 / 场 / 前提）

适用: multiphaseEuler

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
cavitation
    {
        type            multiphaseEuler::cavitation;
        libs            ("libmultiphaseEulerFvModels.so");

        // Note: Order is important. The liquid should be specified first.
        phases          (liquid gas);

        energySemiImplicit no;

        model           Kunz;

        pSat            79995.75943;

        UInf            5.33;
        tInf            0.028142589;
        Cc              100;
        Cv              100;
    }
```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| （见源码 Usage） | 以头文件为准 | — |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Model for cavitation phase change between two phases.
>
> Example usage:
>     > cavitation
>     > {
>     >     type            multiphaseEuler::cavitation;
>     >     libs            ("libmultiphaseEulerFvModels.so");
>     >
>     >     // Note: Order is important. The liquid should be specified first.
>     >     phases          (liquid gas);
>     >
>     >     energySemiImplicit no;
>     >
>     >     model           Kunz;
>     >
>     >     pSat            79995.75943;
>     >
>     >     UInf            5.33;
>     >     tInf            0.028142589;
>     >     Cc              100;
>     >     Cv              100;
>     > }
>     > 

## 文献与源码依据

- 源码：[`applications/modules/multiphaseEuler/fvModels/multiphaseEulerCavitation/multiphaseEulerCavitation.H`](../../../../applications/modules/multiphaseEuler/fvModels/multiphaseEulerCavitation/multiphaseEulerCavitation.H)
- 实现：同目录 `.C`

## 教程与模板

- 见对应求解器 tutorials；物理方程细目由 Phase 3/4 目录承接

## 注意事项

- 本页为 Phase 5 **入口目录**（fvModel 类型与字典位置）
- 多相/燃烧物理细节见 `multiphase`/` 或 `combustion`-radiation/` / `lagrangian`/`
