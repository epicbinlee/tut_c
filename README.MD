# 笔记

## C++ 自带的 #include 包含的内容

在C++中，`#include`是预处理器指令，用于将指定的头文件（header
files）包含到源代码中。C++标准库提供了一些常见的头文件，这些头文件包含了各种库函数和标准类型的定义，使得编程更加方便和高效。以下是C++自带的一些常见头文件：

1. C++标准库的头文件：
    - `<iostream>`：输入输出流，包含`cin`、`cout`、`cerr`、`clog`等。
    - `<iomanip>`：用于格式化输入输出。
    - `<fstream>`：文件输入输出流，用于文件的读写操作。
    - `<string>`：字符串处理，包含字符串类的定义和操作。
    - `<vector>`：动态数组，包含`vector`容器的定义和操作。
    - `<list>`：双向链表，包含`list`容器的定义和操作。
    - `<map>`：映射，包含`map`容器的定义和操作。
    - `<set>`：集合，包含`set`容器的定义和操作。
    - `<algorithm>`：常用算法，例如`sort`、`find`等。
    - `<cmath>`：数学函数，例如数学常量和数学运算函数。
    - `<ctime>`：时间和日期函数，例如获取当前时间等。
    - `<cstdlib>`：C标准库函数，例如动态内存分配和随机数生成等。
    - `<cassert>`：断言，用于调试时进行条件检查。

2. C标准库的头文件：
    - `<cstdio>`：C风格的输入输出，例如`printf`、`scanf`等。
    - `<cstdlib>`：C风格的标准库函数，例如`malloc`、`free`等。

除了以上列出的常见头文件，C++还提供了很多其他的标准库头文件，用于不同的功能和需求。每个头文件都定义了一系列相关的函数、类和数据结构，使得开发者可以更轻松地实现各种功能和处理各种数据类型。在编程过程中，根据实际需要添加适当的头文件，以便使用相应的功能和库函数。

## 将CMake编译输出到output目录

若要将CMake的构建输出定向到名为"output"的目录中，你可以在执行CMake时使用`CMAKE_BINARY_DIR`或`CMAKE_CURRENT_BINARY_DIR`
变量，并指定生成的二进制文件输出路径。以下是一种常见的方法：

1. 创建一个名为"output"的目录，用于存储构建输出。

2. 在项目的根目录中创建一个`CMakeLists.txt`文件，并在其中编写CMake配置脚本。

3. 在`CMakeLists.txt`中设置输出路径，将构建的二进制文件指定到"output"目录。

以下是一个示例的`CMakeLists.txt`文件：

```cmake
# 设置CMake的最低版本要求
cmake_minimum_required(VERSION 3.12)

# 设置项目名称
project(MyProject)

# 指定输出路径为 "output" 目录
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/output)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# 添加可执行文件
add_executable(my_executable main.cpp)

```

```shell
# 将CMake编译输出定向到output目录
# 在上述`CMakeLists.txt`中，我们通过`set`命令指定了`CMAKE_BINARY_DIR`和`EXECUTABLE_OUTPUT_PATH`（和`LIBRARY_OUTPUT_PATH`）的值为项目根目录下的"output"目录。这样，生成的可执行文件和库文件就会被放置在"output"目录中。
# 接下来，你可以在项目根目录中执行以下命令：
mkdir output     # 创建 output 目录
cd output        # 进入 output 目录
cmake ..         # 执行 CMake，并指定上层目录为 CMakeLists.txt 所在目录
make             # 编译项目
```

## 许可说明

| 许可证名称                      | 传染性（Copyleft） | 允许闭源使用 | 要求公开源代码 | 原作者/版权声明 | 声明更改 | 分发方式 | 使用商标 | 专利许可 | 法律适用 | 版本 | 权利限制 |
|--------------------------------|-------------------|--------------|--------------|-----------------|---------|---------|---------|---------|---------|------|---------|
| MIT许可证                       | 否                | 是           | 否           | 否              | 否      | 无      | 无      | 无      | 无      | 无   | 无      |
| Apache许可证                    | 否                | 是           | 否           | 是              | 否      | 无      | 无      | 无      | 无      | 无   | 无      |
| BSD许可证                       | 否                | 是           | 否           | 是              | 否      | 无      | 无      | 无      | 无      | 多个 | 无      |
| GPL（GNU通用公共许可证）        | 是                | 否           | 是           | 是              | 否      | 无      | 无      | 无      | 美国法律 | 多个 | 商业使用受限 |
| LGPL（GNU较宽松通用公共许可证） | 是                | 部分         | 是           | 是              | 否      | 无      | 无      | 无      | 美国法律 | 多个 | 商业使用受限 |
| Mozilla公共许可证               | 否                | 是           | 是           | 是              | 是     | 无      | 无      | 无      | 美国法律 | 多个 | 无      |
| Eclipse公共许可证               | 否                | 是           | 是           | 是              | 是     | 无      | 无      | 无      | 美国法律 | 多个 | 无      |
| CDDL                           | 否                | 是           | 是           | 是              | 否      | 无      | 无      | 无      | 美国法律 | 1.0  | 无      |
| Artistic License                | 否                | 是           | 是           | 是              | 是     | 无      | 无      | 无      | 美国法律 | 1.0  | 无      |
| WTFPL                          | 否                | 是           | 否           | 是              | 是     | 无      | 无      | 无      | 法国法律 | 无   | 无      |
| Unlicense                      | 否                | 是           | 是           | 是              | 是     | 无      | 无      | 无      | 无      | 无   | 无      |

## 常见的命令

```
source /usr/local/miniconda3/bin/activate && conda activate /usr/local/python3.10
conda install -c rapidsai -c conda-forge -c nvidia cudf=23.10 python=3.10 cuda-version=11.8
```








