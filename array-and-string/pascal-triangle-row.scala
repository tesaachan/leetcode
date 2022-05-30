object Solution {
    def getRow(rowIndex: Int): List[Int] = {
        val n = rowIndex + 1
        var triangle = Array.ofDim[Int](n, n)
        for (i <- 0 until n) {
            triangle(i)(0) = 1
            triangle(i)(i) = 1
        }
        for (i <- 1 until n) {
            for (j <- 1 until i) {
                triangle(i)(j) = triangle(i - 1)(j) + triangle (i - 1)(j - 1)
            }
        }
        triangle(rowIndex).toList
    }
}