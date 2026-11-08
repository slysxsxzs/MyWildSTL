# MyWildSTL (野生底层库)

这是一个由高一学生在手机端纯手搓的 C++ 底层工具库。
因为觉得标准库（STL）太臃肿、模板太难懂，所以决定从零开始造轮子，主打一个“零依赖、纯裸指针、无黑盒”。

## 📦 包含功能

* `my_vector_fq.h` : 动态数组容器，支持自动两倍扩容、指定位置插入、内存自动释放。
* `my_sort_fq.h` : 内省排序 (Introsort)，结合了三数取中、小区间插入和堆排兜底，在洛谷 P1177 荣获全绿 AC。
* `my_unique_ptr_fq.h` : 零依赖的独占智能指针，物理封杀浅拷贝，杜绝 Double Free。

## ⚡ 性能测试

* **环境**：手机沙盒编译器（开启 -O3 优化）。
* **测试**：生成 500 万个随机数，存入容器并完成内省排序 + 智能指针析构。
* **成绩**：**0.33 秒** 跑完全程，且安全检查完美有序，零内存泄漏。

---

## 🌍 English Introduction

This is a C++ low-level library written by a high school student entirely on a mobile phone. 
Because I find the standard STL too heavy and the templates too complex, I decided to build my own wheels from scratch. 

### Features
* `my_vector_fq.h`: A dynamic array container with auto-doubling capacity and memory auto-release.
* `my_sort_fq.h`: Introsort (median-of-three + insertion sort for small arrays + heap sort fallback). Achieved full AC on Luogu P1177.
* `my_unique_ptr_fq.h`: A zero-dependency exclusive smart pointer. Physically kills shallow copies to prevent Double Free.

### ⚡ Performance
* **Environment**: Mobile Sandbox Compiler (-O3 optimization).
* **Test**: Generating 5,000,000 random numbers, pushing them into `my_vector`, sorting with `my_sort`, and destructing with `my_unique_ptr`.
* **Result**: Finished in **0.33 seconds**, perfectly sorted, zero memory leaks!

---

## 🚀 Combined Quick Start (三合一综合使用示例)

无需 CMake，无需任何配置。只需将三个 `.h` 文件放入项目目录，直接 `#include` 即可无缝联动使用。

    #include <iostream>
    #include "my_vector_fq.h"
    #include "my_sort_fq.h"
    #include "my_unique_ptr_fq.h"

    using namespace std;

    int main() {
        cout << "=== MyWildSTL Combined Test ===" << endl;

        // 1. 使用动态容器存放乱序数据
        my_vector mv;
        mv.push_back(50);
        mv.push_back(10);
        mv.push_back(40);
        mv.push_back(20);
        mv.push_back(30);

        // 2. 调用内省排序对容器底层的裸指针直接进行排序
        my_sort(mv.get_data(), mv.get_size());
        
        cout << "Sorted Array: ";
        for(int i = 0; i < mv.get_size(); i++) {
            cout << mv.get_data()[i] << " ";
        }
        cout << endl;

        // 3. 使用独占智能指针管理内存且直接把要指向的值输入括号即可，无需手动 delete和new
        my_unique_ptr ptr(999);
        *ptr = 1000; // 使用重载的 * 直接修改值
        cout << "Smart Pointer Value: " << *ptr << endl;

        // 离开作用域时，my_vector 和 my_unique_ptr 会自动触发析构，清理所有内存。
        return 0;
    }

---

## 🚀 Combined Quick Start 

No CMake or configuration required. Just drop the three .h files into your project directory and #include them to use seamlessly.

    #include <iostream>
    #include "my_vector_fq.h"
    #include "my_sort_fq.h"
    #include "my_unique_ptr_fq.h"

    using namespace std;

    int main() {
        cout << "=== MyWildSTL Combined Test ===" << endl;

        // 1. Use dynamic array to store unsorted data
        my_vector mv;
        mv.push_back(50);
        mv.push_back(10);
        mv.push_back(40);
        mv.push_back(20);
        mv.push_back(30);

        // 2. Call Introsort on the raw pointer of the container
        my_sort(mv.get_data(), mv.get_size());
        
        cout << "Sorted Array: ";
        for(int i = 0; i < mv.get_size(); i++) {
            cout << mv.get_data()[i] << " ";
        }
        cout << endl;

        // 3. Use unique pointer for automatic memory management,(value)
        my_unique_ptr ptr(999);
        *ptr = 1000; // Modify value using overloaded operator*
        cout << "Smart Pointer Value: " << *ptr << endl;

        // my_vector and my_unique_ptr will automatically clean up memory 
        // when they go out of scope here.
        return 0;
    }
