# 编译器
CXX = g++

# 编译选项
CXXFLAGS = -Wall -std=c++11

# 目标文件
TARGET = main

# 源文件
SRCS = map_usage.cc main.cc

# 依赖文件
DEPS = map_usage.h

# 目标规则
$(TARGET): $(SRCS) $(DEPS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# 清理规则
clean:
	rm -f $(TARGET)
