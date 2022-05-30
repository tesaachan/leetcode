object Solution {
    def arrayPairSum(nums: Array[Int]): Int = {
        val snums = nums.sorted
        snums.zip(snums.indices)
        .map{ (x, i) =>
            if (i % 2 == 0) x else 0
        }
        .sum
    }
}