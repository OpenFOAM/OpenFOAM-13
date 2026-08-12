# rotating

## 一句话

Joint with a specified rotational speed
c++
// 见父字典 Usage；type 名须与 RTS 一致
rotating
{
    type    rotating;
}

```

## 参数表

主要入口以源码 `Usage` 为准。常见关键字见字典示例；完整列表与默认值见对应 `.H`。

| 说明 | |
|------|--|
| 选择关键字 | `type`（须与 RTS 注册名一致） |
| 配置位置 | 见适用条件 |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Joint with a specified rotational speed
> 
> Reference:
>     >     Featherstone, R. (2008).
>     >     Rigid body dynamics algorithms.
>     >     Springer.
>     >     Chapter 4.
>     > 

## 文献与源码依据

- 源码：[`src/rigidBodyMotion/rigidBodyDynamics/joints/rotating/rotating.H`](../../../../../src/rigidBodyMotion/rigidBodyDynamics/joints/rotating/rotating.H)
- 实现：同目录 `.C`

## 教程与模板

- rigidBody / multiBody 动网格教程

## 注意事项

- 在 joints 列表中按 type 选用
```
