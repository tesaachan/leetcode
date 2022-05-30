object Solution {
    def twoSum(numbers: Array[Int], target: Int): Array[Int] = {
        var (i, j) = (0, numbers.length - 1)
        while (i != j) {
            if (numbers(i) + numbers(j) < target)
                i += 1
            else if (numbers(i) + numbers(j) > target)
                j -= 1
            else
                return Array(i + 1, j + 1)
        }
        Array(i + 1, j + 1)
    }
}