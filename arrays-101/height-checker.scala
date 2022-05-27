object Solution {
    def heightChecker(heights: Array[Int]): Int = {
        val end = heights.length
        val expected = heights.sorted
        println(expected.toList)
        def loop(ans: Int, i: Int): Int = {
            i match {
                case _ if i == end => ans
                case _ => loop(if (expected(i) != heights(i)) 
                                    ans + 1 else ans, i + 1)
            }
        }
        loop(0, 0)
    }
}
