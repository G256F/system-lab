from statistics import mean

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
    data = [
        [],
        [3.72],
        [3.6, 3.6, 3.6],
        [3.7, 3.65, 3.80, 3.75],
        [4.2, 4.0, 3.8],
    ]

    for i,data_set in enumerate(data):
        print(f"数据集 {i+1}: {data_set}")
        stats = calculateStats(data_set)
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
    