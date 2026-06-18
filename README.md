<div align="center">

# 🧰 CPPSTL

**A Lightweight C++ STL Reimplementation from Scratch**

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](LICENSE)
[![C++](https://img.shields.io/badge/C%2B%2B-11%7C14-blue.svg?logo=cplusplus)](https://en.cppreference.com/)
[![Header Only](https://img.shields.io/badge/Type-Header--Only-orange.svg)]()
[![Platform](https://img.shields.io/badge/Platform-Cross--Platform-lightgrey.svg)]()

[**🇨🇳 中文文档**](README.zh-CN.md) | **🇬🇧 English**

</div>

---

## 📖 Overview

**CPPSTL** is an educational C++ project that reimplements a subset of the C++ Standard Template Library (STL) from scratch. It is designed as a learning resource for understanding the internal workings of STL containers, iterators, adapters, and algorithms — following the naming conventions and design philosophy of **SGI STL**.

> 💡 **Goal**: Help developers deeply understand STL internals by reading and writing real implementations, not just using the standard library as a black box.

---

## ✨ Features

| Category | Components | Highlights |
|:--------:|:----------:|:----------:|
| 📦 **Sequential Containers** | `vector`, `list`, `string` | Move semantics, custom iterators |
| 🔌 **Container Adapters** | `stack`, `queue`, `priority_queue` | Adapter pattern, configurable underlying container |
| #️⃣ **Hash Containers** | `unordered_map`, `unordered_set`, `HashTable` | Separate chaining, auto rehashing to prime bucket counts |
| 🧮 **Algorithms** | `make_heap`, `push_heap`, `pop_heap`, `sort_heap` | Template-based heap operations |
| 📊 **Utilities** | `bitset` | Compile-time fixed-size bit array |

---

## 📁 Project Structure

```
CPPSTL/
├── vector/
│   ├── mystl_vector.hpp          # vector<T> — dynamic array with move semantics
│   ├── simulation_vector.cpp     # Earlier standalone implementation
│   └── test_vector.cpp
├── list/
│   ├── mystl_list.hpp            # list<T> — doubly-linked list with sentinel node
│   └── test.cc
├── string/
│   ├── simulation_string.cpp     # string class (full implementation)
│   └── test_string.cpp
├── stack/
│   ├── mystl_stack.hpp           # stack<T> — container adapter
│   └── test.cc
├── queue/
│   ├── mystl_queue.hpp           # queue<T>, priority_queue<T>, Less/Greater
│   ├── mystl_heap.hpp            # Heap algorithms
│   └── test.cc
├── unordered_map_set/
│   ├── mystl_hashtable.hpp       # HashTable — separate chaining with iterator
│   ├── mystl_unordered_map.hpp   # unordered_map<K, V>
│   ├── mystl_unordered_set.hpp   # unordered_set<T>
│   └── test.cc
├── bitset/
│   ├── mystl_bitset.hpp          # bitset<N> — fixed-size bit array
│   └── test.cc
├── LICENSE                        # Apache License 2.0
└── README.md
```

---

## 🚀 Quick Start

### Prerequisites

- A C++ compiler supporting **C++11** or later (GCC 4.8+, Clang 3.3+, MSVC 2015+)

### Usage

This is a **header-only** library. Simply include the header file you need:

```cpp
#include "vector/mystl_vector.hpp"
#include "list/mystl_list.hpp"
#include "queue/mystl_queue.hpp"
#include "unordered_map_set/mystl_unordered_map.hpp"

int main() {
    // vector with move semantics
    mystl::vector<int> v = {1, 2, 3, 4, 5};
    v.push_back(6);
    v.push_back(42);

    // doubly-linked list
    mystl::list<int> lst;
    lst.push_back(10);
    lst.push_front(5);

    // priority queue (max-heap by default)
    mystl::priority_queue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(4);
    // pq.top() == 4

    // hash map
    mystl::unordered_map<std::string, int> map;
    map["apple"] = 3;
    map["banana"] = 5;

    return 0;
}
```

### Compile & Run Tests

Each component has its own test file. Compile individually:

```bash
# Test vector
g++ -std=c++11 -o test_vector vector/test_vector.cpp && ./test_vector

# Test queue & priority_queue
g++ -std=c++11 -o test_queue queue/test.cc && ./test_queue

# Test unordered_map & unordered_set
g++ -std=c++11 -o test_map unordered_map_set/test.cc && ./test_map

# Test stack
g++ -std=c++11 -o test_stack stack/test.cc && ./test_stack

# Test bitset
g++ -std=c++11 -o test_bitset bitset/test.cc && ./test_bitset
```

---

## 📚 API Reference

### `mystl::vector<T>`

| Method | Description |
|:-------|:------------|
| `push_back(const T&)` | Append element (copy) |
| `push_back(T&&)` | Append element (move) |
| `pop_back()` | Remove last element |
| `insert(pos, val)` | Insert at iterator position |
| `erase(pos)` | Erase at iterator position |
| `reserve(n)` | Reserve capacity |
| `resize(n)` | Resize container |
| `operator[]` | Random access |
| `begin()` / `end()` | Iterator access |
| `size()` / `empty()` | Capacity queries |

### `mystl::list<T>`

| Method | Description |
|:-------|:------------|
| `push_back(val)` | Append to tail |
| `push_front(val)` | Prepend to head |
| `pop_back()` | Remove tail |
| `pop_front()` | Remove head |
| `insert(pos, val)` | Insert before iterator |
| `erase(pos)` | Erase at iterator |
| `clear()` | Remove all elements |
| `size()` / `empty()` | Size queries |

### `mystl::priority_queue<T, Compare>`

| Method | Description |
|:-------|:------------|
| `push(const T&)` | Insert element (copy) |
| `push(T&&)` | Insert element (move) |
| `pop()` | Remove top element |
| `top()` | Access top element |
| `size()` / `empty()` | Size queries |

### `mystl::unordered_map<K, V, Hash>`

| Method | Description |
|:-------|:------------|
| `operator[key]` | Access or insert element |
| `insert(pair)` | Insert key-value pair |
| `erase(key)` | Remove element by key |
| `find(key)` | Lookup iterator |
| `begin()` / `end()` | Iterator access |
| `size()` / `empty()` | Size queries |

### `mystl::unordered_set<T, Hash>`

| Method | Description |
|:-------|:------------|
| `insert(val)` | Insert element |
| `erase(val)` | Remove element |
| `find(val)` | Lookup iterator |
| `begin()` / `end()` | Iterator access |
| `size()` / `empty()` | Size queries |

### `mystl::bitset<N>`

| Method | Description |
|:-------|:------------|
| `set(pos)` | Set bit to 1 |
| `reset(pos)` / `reset()` | Clear bit(s) to 0 |
| `test(pos)` | Get bit value |
| `count()` | Count set bits |
| `size()` | Total bit count |
| `toString()` | Convert to string |

### Heap Algorithms

| Function | Description |
|:---------|:------------|
| `mystl::make_heap(first, last)` | Build max-heap from range |
| `mystl::push_heap(first, last)` | Push element into heap |
| `mystl::pop_heap(first, last)` | Pop top element from heap |
| `mystl::sort_heap(first, last)` | Sort heap into ascending order |

---

## 🏗️ Design Philosophy

- **SGI STL Style**: Member naming follows SGI STL conventions (`_M_start`, `_M_finish`, `_M_end_of_storage`)
- **Custom Iterators**: Each container provides its own iterator type — raw pointers for `vector`, bidirectional iterators for `list`, forward iterators for hash containers
- **Move Semantics**: C++11 rvalue references and `std::move` are used throughout for efficient resource transfer
- **Separate Chaining**: The hash table uses separate chaining with auto-rehashing to prime bucket counts (borrowed from SGI STL's prime table)
- **Adapter Pattern**: `stack`, `queue`, and `priority_queue` are implemented as container adapters

---

## 📋 Implemented vs. Planned

| Component | Status |
|:----------|:------:|
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
| Heap algorithms | ✅ |
| `deque` | 🔜 |
| `set` / `map` | 🔜 |
| `array` | 🔜 |
| `forward_list` | 🔜 |
| Generic algorithms (`sort`, `find`, `copy`) | 🔜 |
| Smart pointers | 🔜 |
| Allocators | 🔜 |

---

## 📄 License

This project is licensed under the **Apache License 2.0** — see the [LICENSE](LICENSE) file for details.

---

<div align="center">
**⭐ If this project helps you understand STL, please give it a star! ⭐**

</div>
