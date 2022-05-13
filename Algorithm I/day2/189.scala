object Solution {
    def rotate(nums: Array[Int], k: Int): Unit = {
        var sk = k % nums.length
        var (a, b) = nums.splitAt(nums.length - sk)
        var rotated = b ++ a
        for (i <- 0 until nums.length)
            nums(i) = rotated(i)
    }
}