#ifndef DEBUGHELPER_H
#define DEBUGHELPER_H

#include <QDebug>
#include <QString>

// 自定义 DebugHelper 类，支持流式写法
class DebugHelper
{
public:
    // 构造函数，传入文件、行号、函数信息
    DebugHelper(const char* file, int line, const char* function)
    {
        buffer = QString("[QDebug] File: %1 | Function: %2 | Line: %3 | ")
                     .arg(file)
                     .arg(function)
                     .arg(line);
    }
     //，如果继续使用模板函数，所有模板相关的实现都应该放在头文件中，以避免链接错误。
    // 重载 << 操作符，用于处理模板类型
    template<typename T>
    DebugHelper& operator<<(const T& value)
    {
        buffer += QString::number(value);  // 处理数值类型
        return *this;
    }

    // 重载 << 操作符，用于处理 QString 类型
    DebugHelper& operator<<(const QString& value)
    {
        buffer += value;
        return *this;
    }

    // 重载 << 操作符，用于处理 const char* 类型
    DebugHelper& operator<<(const char* value)
    {
        buffer += QString(value);
        return *this;
    }

    // 析构函数，输出最终的调试信息
    ~DebugHelper()
    {
        qDebug().noquote() << buffer;
    }

private:
    QString buffer; // 缓存所有要输出的信息
};

// 宏简化调用，传递文件名、行号和函数名
#define DEBUG DebugHelper(__FILE__, __LINE__, __FUNCTION__)

#endif // DEBUGHELPER_H
