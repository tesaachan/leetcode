object Solution {
    def dominantIndex(nums: Array[Int]): Int = {
        val (max, ind) = (nums.max, nums.indexOf(nums.max))
        if (nums.indices.forall { i => 
            if (i == ind) true else max >= 2 * nums(i)
        }) ind else -1
    }
}