object Solution {
    def search(nums: Array[Int], target: Int): Int = {
        var left: Int = 0
        var right: Int = nums.length - 1
        while (right - left >= 0) {
            var m = (left + right) / 2
            if (nums(m) == target) 
                return m
            if (nums(m) < target) left = m + 1
            else right = m - 1
        }
        return -1
    }
}