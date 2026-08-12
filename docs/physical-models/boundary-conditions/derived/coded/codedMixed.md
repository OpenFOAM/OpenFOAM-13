# codedMixed

## 一句话
运行时编码边界（需 `code`/`codeInclude`）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`codedMixed`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            codedMixed;

    refValue        uniform (0 0 0);
    refGradient     uniform (0 0 0);
    valueFraction   uniform 1;

    name    rampedMixed;   // name of generated BC

    code
    #{
        this->refValue() =
            vector(1, 0, 0)
           *min(10, 0.1*this->db().time().value());
        this->refGrad() = Zero;
        this->valueFraction() = 1.0;
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
        this->refValue() = min(10, 0.1*this->db().time().value());
        this->refGrad() = Zero;
        this->valueFraction() = 1.0;
    #};
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
运行时编码边界（需 `code`/`codeInclude`）。

类头 `Description` 原文：

> Constructs on-the-fly a new boundary condition (derived from
> mixedFvPatchField) which is then used to evaluate.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/codedMixed/codedMixedFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/codedMixed/codedMixedFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/codedMixed/codedMixedFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/codedMixed/codedMixedFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            codedMixed`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
