object Solution {
    def pivotIndex(nums: Array[Int]): Int = {
        var leftSum = 0
        var rightSum = nums.slice(1, nums.length).foldLeft(0)(_ + _)
        var (i, j) = (0, nums.length)
        while (i < nums.length)
        {
            if (leftSum != rightSum) {
                leftSum += nums(i)
                if (i < nums.length - 1)
                    rightSum -= nums(i + 1)
                else
                    rightSum = 0
                i += 1
            } else {
                return i
            }
        }
        return -1
    }
}