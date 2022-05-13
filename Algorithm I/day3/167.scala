object Solution {
    def twoSum(numbers: Array[Int], target: Int): Array[Int] = {
        var i = 0
        var j = numbers.length - 1
        while (j - i > 1) {
            var sum = numbers(i) + numbers(j)
            if (sum == target) return Array(i+1, j+1)
            if (sum > target) 
                j -= 1
            else
                i += 1
        }
        return Array(i+1, j+1)
    }
}