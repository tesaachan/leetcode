object Solution {
    def generate(numRows: Int): List[List[Int]] = {
        var triangle = Array.ofDim[Int](numRows, numRows)
        for (i <- 0 until numRows) {
            triangle(i)(0) = 1
            triangle(i)(i) = 1
        }
        for (i <- 1 until numRows) {
            for (j <- 1 until i) {
                triangle(i)(j) = triangle(i - 1)(j) + triangle (i - 1)(j - 1)
            }
        }
        (for (i <- 0 until numRows)
            yield triangle(i).slice(0, i + 1).toList).toList
    }
}