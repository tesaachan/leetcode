object Solution {
    def thirdMax(nums: Array[Int]): Int = {
        val elems = nums.toSet
        val max = elems.max
        def without_max(iter: Int, elems: Set[Int]): Int = { 
            if (elems.isEmpty) max 
            else iter match {
                case 0 => elems.max
                case _ => without_max(iter - 1, elems - elems.max)
            }
        }
        without_max(2, elems)
    }
}