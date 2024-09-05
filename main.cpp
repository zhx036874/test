#include "widget.h"

#include <QApplication>
#include <QDebug>

#include <QDebug>

#include <QDebug>

// 自定义 DebugHelper 类，支持流式写法
class DebugHelper
{
public:
    // 构造函数，传入文件、行号、函数信息
    DebugHelper(const char* file, int line, const char* function)
    {
        // 拼接文件、函数、行号信息为一个字符串
        buffer = QString("[QDebug] File: %1 | Function: %2 | Line: %3 | ")
                     .arg(file)
                     .arg(function)
                     .arg(line);
    }

    // 重载 << 操作符，用于打印任意类型的参数
    template<typename T>
    DebugHelper& operator<<(const T& value)
    {
        // 将非 QString 类型的值转换为 QString 并追加到 buffer
        buffer += QString::number(value);
        return *this; // 返回自身以支持链式调用
    }

    // 重载 << 操作符，用于处理 QString 类型
    DebugHelper& operator<<(const QString& value)
    {
        buffer += value; // 直接拼接 QString 类型
        return *this;
    }

    // 重载 << 操作符，用于处理 const char* 类型
    DebugHelper& operator<<(const char* value)
    {
        buffer += QString(value); // 将 const char* 转换为 QString
        return *this;
    }

    // 析构函数，最终输出所有内容
    ~DebugHelper()
    {
        qDebug().noquote() << buffer;
    }

private:
    QString buffer; // 缓存所有要输出的信息
};

// 宏简化调用，传递文件名、行号和函数名
#define DEBUG DebugHelper(__FILE__, __LINE__, __FUNCTION__)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;//测试下上传项目
    w.show();


    int userId = 123;
    QString userName = "John Doe";
    double userScore = 99.5;

    // Use custom DEBUG stream-style writing
    DEBUG << "User ID:" << userId << " Name:" << userName << " Score:" << userScore ;

    return a.exec();
}
