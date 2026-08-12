# codedFixedValue

## 一句话
给定固定边界值（Dirichlet）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`codedFixedValue`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            codedFixedValue;
    value           uniform 0;
    name    rampedFixedValue;   // name of generated BC

    code
    #{
        operator==(min(10, 0.1*this->db().time().value()));
    #};

    // codeInclude
    //#{
    //    #include ".H"
    //#};

    // codeOptions
    //#{
    //    -I$(LIB_SRC)/finiteVolume/lnInclude
    //#};
}
```

```
<patchName>
{
    code
    #{
        operator==(min(10, 0.1*this->db().time().value()));
    #};
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
给定固定边界值（Dirichlet）。

类头 `Description` 原文：

> Constructs on-the-fly a new boundary condition (derived from
> fixedValueFvPatchField) which is then used to evaluate.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/codedFixedValue/codedFixedValueFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/codedFixedValue/codedFixedValueFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/codedFixedValue/codedFixedValueFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/codedFixedValue/codedFixedValueFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/incompressibleFluid/pipeCyclic/0/U`](../../../tutorials/incompressibleFluid/pipeCyclic/0/U)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
