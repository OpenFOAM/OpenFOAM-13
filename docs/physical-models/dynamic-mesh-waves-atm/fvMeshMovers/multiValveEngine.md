# multiValveEngine

## 一句话

多气门发动机网格运动

## 适用条件（求解器 / 场 / 前提）

dynamicMeshDict → mover；内燃机

## 字典示例

```c++
// constant/dynamicMeshDict
mover
{
    type    multiValveEngine;
    // libs / 子字典见源码
}

```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| （见源码 Usage） | 以头文件为准 | — |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> A mesh mover using explicit node translation based on scaled distance
> functions per moving object. The mover supports any number of valves
> together with piston motion and following features:
>
> - Piston motion: Function1 of user-time, may be set to
>   crankConnectingRodMotion for standard crank and connecting rod motion.
>
> - Valve motion: Function1, may be set to table if the valve lift date is
>   provided in the form of a table.
>
> - Smooth mesh motion between a moving object and other patches.
>
> - linerPatches: the set of patches corresponding to the cylinder liner
>   Used by zoneGenerators::cylinderHeadPoints
>
> - slidingPatches: a set of patches along which mesh is allowed
>   to deform. For example, on the cylinder liner, it is desired to
>   slide mesh nodes while piston is moving.
>
> - frozenZones: list of pointZones the points of which are frozen,
>   i.e. do not move with respect to any moving object.
>
> - Run-time clearance estimation based on patch-to-patch distances printed.
>
> - Supports cellZone definitions to restrict mesh motion.
>
> - Supports domains with nonConformalCoupling (NCC) interfaces,
>   enabling e.g. nodes to slide along with the interface.
>
> - Closing the valve can be achieved by meshToMesh mapping onto a new
>   grid with closed valve geometry at user given time.
>
> - Mesh motion can be controlled per moving object by setting:
>
>     - patches: list of patches defining the object.
>
>     - motion: a Function1 which returns the object position
>       as a function of time.
>
>     - movingZones: list of pointZones the points of which move with the
>       object.
>
>     - frozenZones: list of pointZones the points of which are frozen,
>       i.e. do not move with respect to this moving object.
>
>     - maxMotionDistance: a distance away from the moving object
>       after nodes are not allowed to move. (Default inf.)
>
>     - movingFrozenLayerThickness: thickness of layer in which points move
>       with the moving object. (Default 0)
>
>     - staticFrozenLayerThickness: thickness of layer in which points
>       are fixed with respect to static patches (e.g. walls). (Default 0)
>
>     - cosineScale: scaling factor between 0 and 1 for cosine scaling applied
>       to the motion. A value of 0 means linear weighting, a value of 1 means
>       full cosine scaling (much less deformation near the moving object) and
>       sustains e.g. boundary layer.  (Default 0, i.e. linear weighting)
>
>     - travelInterval: part of the stroke travelled after
>       which the cached motion scaling weights are recalculated
>
>     For valve object only:
>
>         - minLift: a minimum valve lift value after considered closed.
>
>
> Some of the above parameters are highlighted in a given schematic
> piston-valve configuration w.r.t entries used to control piston motion.
> Furthermore, an example dictionary entries are provided below.
>     >                   |             |         |             |
>     >                   |             |         |             |
>     >                   |             |    S    |             |
>     >                   |             |    T    |             |
>     >                   |             |    E    |             |
>     >                   |             |    M    |             |
>     >                  /              |         |              \
>     >                 /               |         |               \
>     >                /                |         |                \
>     >  _____________/                 |         |                 \_____________
>     > |        :                      |         |                      :        |
>     > |        :      /````````````           `\      :        |
> |        :     /                VALVE HEAD                 \     :        |
> | L      :    /_____________________________________________\    :        |
> | I      :                         /\                            :        |
> | N      :                         || staticFrozenLayerThickness :        |
> | E      : NCC (optional)          \/ (w.r.t. piston motion)     :        |
> | R      :                      ``````````                       :        |
> |        :                                                       :        |
> |        :                                                       :        |
> |........:.......................................................:........|
> |        :                         /\                            :        |
> |        :                         || movingFrozenLayerThickness :        |
> |________:_________________________\/____________________________:________|
>                                    PISTON
>     >
>     > 
> mover
> {
>     type                multiValveEngine;
>     libs                ("libfvMeshMoversMultiValveEngine.so");
>
>     frozenZones         (frozenZone1 frozenZone2);
>
>     slidingPatches
>     (
>         liner
>         valveStem
>         "nonCouple.*"
>     );
>
>     linerPatches        (liner);
>
>     piston
>     {
>         patches             (piston);
>         axis                (0 0 1);
>
>         motion
>         {
>             type                crankConnectingRodMotion;
>
>             conRodLength        1e3;
>             stroke              1.0;
>         }
>
>         // Move the points in the piston bowl with the piston
>         movingZones         (pistonBowl);
>
>         // Freeze the points in the cylinder head
>         frozenZones         (cylinderHead);
>
>         // Optional
>         maxMotionDistance    1e30;
>         movingFrozenLayerThickness  0;
>         staticFrozenLayerThickness  0;
>
>         travelInterval      0.1;
>
>         cosineScale         0.5;
>     }
>
>     valves
>     {
>         iv
>         {
>             patches     (valveHead);
>             axis        (0 0 1);
>
>             // Optional
>             maxMotionDistance   1e30;
>             movingFrozenLayerThickness  0;
>             staticFrozenLayerThickness  0;
>
>             travelInterval      0.01;
>
>             cosineScale         1;
>
>             minLift     0.001;
>
>             motion
>             {
>                 type    table;
>                 values
>                 (
>                     (0      0)
>                     (480    0.1)
>                     (720    0)
>                 );
>                 // For multi-cycle simulations, use repeat
>                 outOfBounds     repeat;
>                 interpolationScheme linear;
>             }
>         }
>     }
> }
> ```
>
> Note:
>   The implementation utilises pointDist objects for distance computation,
>   resulting distance fields do not propagate through NCC interfaces.  Hence,
>   there should be no horizontal NCC interface separating piston from
>   cylinder head as it would result in potentially ill defined mesh
>   deformation. Due to same feature, in a schematic case setup above, valve
>   motion affects only cells between NCC patches even though no cellZone is
>   explicitly defined.

## 文献与源码依据

- 源码：[`src/fvMeshMovers/multiValveEngine/multiValveEngine.H`](../../../../src/fvMeshMovers/multiValveEngine/multiValveEngine.H)
- 实现：同目录 `.C`

## 教程与模板

- `movingMesh` 模块与含 `dynamicMeshDict` 的流体教程

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
