# Stokes5

## 一句话

五阶 Stokes 波

## 适用条件（求解器 / 场 / 前提）

waveModel

## 字典示例

```c++
// constant/fvModels 或相应字典
Stokes51
{
    type    Stokes5;
    // 其余参数见源码头文件 Usage
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

> Fifth-order wave model.
>
> Reference:
>     >     Fenton, J. D. (1985).
>     >     A fifth-order Stokes theory for steady waves.
>     >     Journal of waterway, port, coastal, and ocean engineering, 111(2),
>     >     216-234.
>     > 

## 文献与源码依据

- 源码：[`src/waves/waveModels/Stokes5/Stokes5.H`](../../../../src/waves/waveModels/Stokes5/Stokes5.H)
- 实现：同目录 `.C`

## 教程与模板

- VoF 波浪教程；`etc/caseDicts/annotated/setWavesDict`

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
