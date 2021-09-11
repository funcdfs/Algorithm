a = input('提示：')

# 返回输入的对象，可以输入数字，字符串，和其他任意类型的对象
# 返回值都是字符串

int(a) # 强制类型转换


for i in range(10, 20):
    print(i, end=' ')

# 无参数时， print 函数输出一个空行
# 用逗号 分隔，可以输出一个或者多个对象
print(123, 'abc', 45, 'book')
# 在输出对象的时候，对象之间用默认的空格分隔

print(2, 3, 5, sep=' ')
# 使用 sep 参数可以指定特定的符号替代默认的 空格 作为新的分隔符

# end 用来 指定 输出的结尾符号  end = '\n'




# 输出到文件

file1 = open('data.txt', 'w') # 打开文件
print('123', 'abc', '45', 'book', file = file1)  # 用 file 参数指定输出到文件
file1.close() # 关闭文件
print(open('data.txt').read()) # 输出从文件中读出来的内容 
