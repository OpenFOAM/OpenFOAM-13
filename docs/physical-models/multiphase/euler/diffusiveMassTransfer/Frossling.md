# Frossling

## 一句话
Frossling correlation for turbulent mass transfer from the surface of a

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 扩散传质（基类 `diffusiveMassTransferModel`）
- **注册名**: `Frossling`

## 字典示例


```c++
// `tutorials/multiphaseEuler/bubbleColumnEvaporatingReacting/constant/fvModels`
gas_dispersedIn_liquid_inThe_gas
        {
            type            spherical;
        }

        liquid_dispersedIn_gas_inThe_gas
        {
            type            Frossling;
            Le              1.0;
        }
    }
}

// ************************************************************************* //
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `Frossling`
- 基类: `diffusiveMassTransferModel`


## 控制方程与关联式
Frossling correlation for turbulent mass transfer from the surface of a
sphere to the surrounding fluid.

## 文献与源码依据
- 类: `Foam`::diffusiveMassTransferModels::Frossling`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/diffusiveMassTransferModels/Frossling/Frossling.C`

## 教程与模板
- `tutorials/multiphaseEuler/bubbleColumnEvaporatingReacting/constant/fvModels`
- `tutorials/multiphaseEuler/bubbleColumnEvaporatingDissolving/constant/fvModels`
- `tutorials/multiphaseEuler/bubbleColumnEvaporating/constant/fvModels`

## 注意事项
- 类型名必须与 RTS 注册名一致：`Frossling`。
