object Solution {
    def rotate(nums: Array[Int], k: Int): Unit = {
        var _k = k % nums.size
        val cnums = nums.clone
        for (i <- 0 until _k) {
            nums(i) = cnums(cnums.length - _k + i)
        }
        for (i <- _k until nums.length) {
            nums(i) = cnums(i - _k)
        }
    }
}