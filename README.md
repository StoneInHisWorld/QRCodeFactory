 ## QRCodeFactory
利用`zint库`和`pyzbar库`进行二维码的生成和识别

## 二维码生成
`Generator`项目可根据特定的输入文本生成一系列二维码
### 使用之前
1. 这是一个C++项目，请[安装Visual Studio](https://visualstudio.microsoft.com/zh-hans/)来进行编译和运行。使用其他编译方式将会使得使用过程变得极其复杂
2. 安装[CMake](https://cmake.org/download/)
3. 安装[Git](https://git-scm.com/downloads)
4. 确保你已经安装zint库：
    1. 下载[zint库源代码](https://github.com/zint/zint)
    2. 根据[编译说明](https://github.com/zint/zint/blob/master/win32/README)编译zint库。如果不需要图形界面，可以跳过其中包含**Qt**的部分
5. 具体使用说明[请见](./Generator/README.md)

## 二维码识别
 `Scanner`项目可以识别给定的二维码图片，具体使用说明[请见](./Scanner/README.md)
