# 编译器
CXX = g++

# 编译选项
CXXFLAGS = -Wall -std=c++11

# 目标文件
TARGET = main

# 源文件
SRCS = sort_algo.cc main.cc

# 依赖文件
DEPS = sort_algo.h

# 目标规则
$(TARGET): $(SRCS) $(DEPS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# 清理规则
clean:
	rm -f $(TARGET)
