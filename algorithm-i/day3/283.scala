// O(1) additional memory solution

object Solution {
    def moveZeroes(nums: Array[Int]): Unit = {
        var i = 0
        for (j <- 0 until nums.length) {
            if (nums(j) != 0) {
                nums(i) = nums(j)
                i += 1
            }
        }
        for (j <- i until nums.length) {
            nums(j) = 0
        }
        nums foreach (print(_))
    }
}
