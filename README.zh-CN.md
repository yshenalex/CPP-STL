<div align="center">

# 🧰 CPPSTL

**从零开始的轻量级 C++ STL 实现**

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](LICENSE)
[![C++](https://img.shields.io/badge/C%2B%2B-11%7C14-blue.svg?logo=cplusplus)](https://zh.cppreference.com/)
[![Header Only](https://img.shields.io/badge/类型-Header--Only-orange.svg)]()
[![Platform](https://img.shields.io/badge/平台-跨平台-lightgrey.svg)]()

[**🇬🇧 English**](README.md) | **🇨🇳 中文文档**

</div>

---

## 📖 项目简介

**CPPSTL** 是一个教学性质的 C++ 项目，从零开始重新实现了 C++ 标准模板库（STL）的一个子集。该项目旨在帮助开发者深入理解 STL 容器、迭代器、适配器和算法的内部工作原理——遵循 **SGI STL** 的命名规范和设计哲学。

> 💡 **目标**：通过阅读和编写真实实现，帮助开发者深入理解 STL 内部机制，而不仅仅是把标准库当作黑盒使用。

---

## ✨ 特性一览

| 类别 | 组件 | 亮点 |
|:----:|:----:|:----:|
| 📦 **顺序容器** | `vector`、`list`、`string` | 移动语义、自定义迭代器 |
| 🔌 **容器适配器** | `stack`、`queue`、`priority_queue` | 适配器模式、可配置底层容器 |
| #️⃣ **哈希容器** | `unordered_map`、`unordered_set`、`HashTable` | 链地址法、自动 rehash 至素数桶数量 |
| 🧮 **算法** | `make_heap`、`push_heap`、`pop_heap`、`sort_heap` | 基于模板的堆操作 |
| 📊 **工具类** | `bitset` | 编译期定长位数组 |

---

## 📁 项目结构

```
CPPSTL/
├── vector/
│   ├── mystl_vector.hpp          # vector<T> — 支持移动语义的动态数组
│   ├── simulation_vector.cpp     # 早期独立实现版本
│   └── test_vector.cpp
├── list/
│   ├── mystl_list.hpp            # list<T> — 带哨兵节点的双向链表
│   └── test.cc
├── string/
│   ├── simulation_string.cpp     # string 类（完整实现）
│   └── test_string.cpp
├── stack/
│   ├── mystl_stack.hpp           # stack<T> — 容器适配器
│   └── test.cc
├── queue/
│   ├── mystl_queue.hpp           # queue<T>、priority_queue<T>、Less/Greater
│   ├── mystl_heap.hpp            # 堆算法
│   └── test.cc
├── unordered_map_set/
│   ├── mystl_hashtable.hpp       # HashTable — 链地址法哈希表（带迭代器）
│   ├── mystl_unordered_map.hpp   # unordered_map<K, V>
│   ├── mystl_unordered_set.hpp   # unordered_set<T>
│   └── test.cc
├── bitset/
│   ├── mystl_bitset.hpp          # bitset<N> — 定长位数组
│   └── test.cc
├── LICENSE                        # Apache License 2.0
└── README.zh-CN.md
```

---

## 🚀 快速开始

### 环境要求

- 支持 **C++11** 或更高标准的 C++ 编译器（GCC 4.8+、Clang 3.3+、MSVC 2015+）

### 使用方式

这是一个 **header-only** 库，直接引入所需的头文件即可：

```cpp
#include "vector/mystl_vector.hpp"
#include "list/mystl_list.hpp"
#include "queue/mystl_queue.hpp"
#include "unordered_map_set/mystl_unordered_map.hpp"

int main() {
    // 支持移动语义的 vector
    mystl::vector<int> v = {1, 2, 3, 4, 5};
    v.push_back(6);
    v.push_back(42);

    // 双向链表
    mystl::list<int> lst;
    lst.push_back(10);
    lst.push_front(5);

    // 优先队列（默认最大堆）
    mystl::priority_queue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(4);
    // pq.top() == 4

    // 哈希映射
    mystl::unordered_map<std::string, int> map;
    map["apple"] = 3;
    map["banana"] = 5;

    return 0;
}
```

### 编译与运行测试

每个组件都有独立的测试文件，单独编译即可：

```bash
# 测试 vector
g++ -std=c++11 -o test_vector vector/test_vector.cpp && ./test_vector

# 测试 queue 与 priority_queue
g++ -std=c++11 -o test_queue queue/test.cc && ./test_queue

# 测试 unordered_map 与 unordered_set
g++ -std=c++11 -o test_map unordered_map_set/test.cc && ./test_map

# 测试 stack
g++ -std=c++11 -o test_stack stack/test.cc && ./test_stack

# 测试 bitset
g++ -std=c++11 -o test_bitset bitset/test.cc && ./test_bitset
```

---

## 📚 API 参考

### `mystl::vector<T>`

| 方法 | 说明 |
|:-----|:-----|
| `push_back(const T&)` | 追加元素（拷贝） |
| `push_back(T&&)` | 追加元素（移动） |
| `pop_back()` | 移除末尾元素 |
| `insert(pos, val)` | 在迭代器位置插入 |
| `erase(pos)` | 在迭代器位置删除 |
| `reserve(n)` | 预留容量 |
| `resize(n)` | 调整大小 |
| `operator[]` | 随机访问 |
| `begin()` / `end()` | 迭代器访问 |
| `size()` / `empty()` | 容量查询 |

### `mystl::list<T>`

| 方法 | 说明 |
|:-----|:-----|
| `push_back(val)` | 尾部追加 |
| `push_front(val)` | 头部插入 |
| `pop_back()` | 移除尾部 |
| `pop_front()` | 移除头部 |
| `insert(pos, val)` | 在迭代器前插入 |
| `erase(pos)` | 在迭代器位置删除 |
| `clear()` | 清空所有元素 |
| `size()` / `empty()` | 大小查询 |

### `mystl::priority_queue<T, Compare>`

| 方法 | 说明 |
|:-----|:-----|
| `push(const T&)` | 插入元素（拷贝） |
| `push(T&&)` | 插入元素（移动） |
| `pop()` | 弹出堆顶元素 |
| `top()` | 访问堆顶元素 |
| `size()` / `empty()` | 大小查询 |

### `mystl::unordered_map<K, V, Hash>`

| 方法 | 说明 |
|:-----|:-----|
| `operator[key]` | 访问或插入元素 |
| `insert(pair)` | 插入键值对 |
| `erase(key)` | 按键删除元素 |
| `find(key)` | 按键查找迭代器 |
| `begin()` / `end()` | 迭代器访问 |
| `size()` / `empty()` | 大小查询 |

### `mystl::unordered_set<T, Hash>`

| 方法 | 说明 |
|:-----|:-----|
| `insert(val)` | 插入元素 |
| `erase(val)` | 删除元素 |
| `find(val)` | 查找迭代器 |
| `begin()` / `end()` | 迭代器访问 |
| `size()` / `empty()` | 大小查询 |

### `mystl::bitset<N>`

| 方法 | 说明 |
|:-----|:-----|
| `set(pos)` | 将位设为 1 |
| `reset(pos)` / `reset()` | 将位清零 |
| `test(pos)` | 获取位值 |
| `count()` | 统计置位数量 |
| `size()` | 总位数 |
| `toString()` | 转为字符串 |

### 堆算法

| 函数 | 说明 |
|:-----|:-----|
| `mystl::make_heap(first, last)` | 将区间构建为最大堆 |
| `mystl::push_heap(first, last)` | 将元素推入堆中 |
| `mystl::pop_heap(first, last)` | 弹出堆顶元素 |
| `mystl::sort_heap(first, last)` | 对堆排序（升序） |

---

## 🏗️ 设计理念

- **SGI STL 风格**：成员命名遵循 SGI STL 惯例（`_M_start`、`_M_finish`、`_M_end_of_storage`）
- **自定义迭代器**：每个容器提供独立的迭代器类型——`vector` 使用原生指针，`list` 使用双向迭代器，哈希容器使用前向迭代器
- **移动语义**：全面使用 C++11 右值引用和 `std::move`，实现高效的资源转移
- **链地址法**：哈希表采用链地址法，配合自动 rehash 至素数桶数量（取自 SGI STL 的素数表）
- **适配器模式**：`stack`、`queue`、`priority_queue` 均以容器适配器方式实现

---

## 📋 实现进度

| 组件 | 状态 |
|:-----|:----:|
| `vector` | ✅ |
| `list` | ✅ |
| `string` | ✅ |
| `stack` | ✅ |
| `queue` | ✅ |
| `priority_queue` | ✅ |
| `HashTable` | ✅ |
| `unordered_map` | ✅ |
| `unordered_set` | ✅ |
| `bitset` | ✅ |
| 堆算法 | ✅ |
| `deque` | 🔜 |
| `set` / `map` | 🔜 |
| `array` | 🔜 |
| `forward_list` | 🔜 |
| 泛型算法（`sort`、`find`、`copy`） | 🔜 |
| 智能指针 | 🔜 |
| 内存分配器 | 🔜 |

---

## 📄 开源许可

本项目基于 **Apache License 2.0** 开源——详情请参阅 [LICENSE](LICENSE) 文件。

---

<div align="center">
**⭐ 如果本项目帮助你理解了 STL，请给它一个 Star！⭐**

</div>
