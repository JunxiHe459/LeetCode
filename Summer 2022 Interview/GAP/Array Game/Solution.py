def ArrayGame(arr):
    least = min(arr)
    count = 0
    for i in arr:
        count += i - least
    return count