from statistics import mean
import csv
import sys

def generate_csv(path:str, count:int)->None:
    """
    生成一个包含随机整数的CSV文件。

    参数：
    path (str)：CSV文件的路径。
    count (int)：要生成的随机整数的数量。

    返回：
    None
    """
    exention = ['.csv']
    if not any(path.endswith(ext) for ext in exention):
        print(f"文件路径必须以 {exention} 结尾。")
        return
    data = []
    for i in range(count):
        data.append(i%10)
    with open(path, 'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['value'])
        writer.writerows([[value] for value in data])
    print(f"csv文件已创建，包含数据: {data}")

def main():
    generate_csv(sys.argv[1], int(sys.argv[2]))

if __name__ == "__main__":
    main()
    