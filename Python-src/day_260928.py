from statistics import mean
import csv

def calculateStats(data):
    """
    计算给定数据列表的基本统计值，包括平均值、最大值和最小值。

    参数：
    data (list)：包含数值的数据列表。

    返回：
    非空时返回dict：包含平均值、最大值和最小值的字典。
    空时返回 None。
    """
    if not data:
        return None  # 如果数据为空，返回 None
    stats = {
        'mean': mean(data),
        'max': max(data),
        'min': min(data)
    }

    return stats

def main():
    # 示例数据
    data = [1,5,0,3,4,2,6,7,8,9]
    with open('../test_file/260928/data.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['value'])
        writer.writerows([[value] for value in data])
    print(f"csv文件已创建，包含数据: {data}")

    # 示例数据
    # data = [-2,0,2]
    # with open('../test_file/260930/data2.csv', 'w', newline='') as csvfile:
    #     writer = csv.writer(csvfile)
    #     writer.writerow(['value'])
    #     writer.writerows([[value] for value in data])
    # print(f"csv文件已创建，包含数据: {data}")

    # data = [1,'12abc',3]
    # with open('../test_file/260930/data1.csv', 'w', newline='') as csvfile:
    #     writer = csv.writer(csvfile)
    #     writer.writerow(['value'])
    #     writer.writerows([[value] for value in data])
    # print(f"csv文件已创建，包含数据: {data}")


    with open('../test_file/260928/data.csv', 'r') as csvfile:
        reader = csv.DictReader(csvfile)
        target_nums = []
        for row in reader:
            target_nums.append(int(row['value']))
            
        stats = calculateStats(target_nums)
        if stats is not None:
            print("统计结果：")
            print(f"平均值: {stats['mean']}")
            print(f"最大值: {stats['max']}")
            print(f"最小值: {stats['min']}")
        else:
            print("无法计算统计值。")
        print("-" * 30)
if __name__ == "__main__":
    main()
    