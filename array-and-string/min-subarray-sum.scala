object Solution {
    def minSubArrayLen(target: Int, nums: Array[Int]): Int = {
        var (i, j) = (0, 0)
        var sum = 0
        var saved_sum = 0
        var count = 0
        var min_count = nums.length + 1

        while (i < nums.length)
        {
            sum += nums(i)
            count += 1
            while (sum >= target) {
                if (count < min_count) {
                    min_count = count
                    saved_sum = sum
                }
                sum -= nums(j)
                count -= 1
                j += 1
            }
            i += 1
        }
        if (saved_sum >= target) min_count
        else 0
    }
}
