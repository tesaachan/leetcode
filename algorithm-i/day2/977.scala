// O(n) solution:

object Solution {
    def sortedSquares(nums: Array[Int]): Array[Int] = {
        var (a, b) = nums.span(_ < 0)
        a = a.map(math.pow(_, 2).toInt).reverse
        b = b.map(math.pow(_, 2).toInt)
        var res = Array.emptyIntArray
        var (i, j) = (0, 0)
        while (i < a.length && j < b.length) {
            if (a(i) < b(j)) { 
                res = res :+ a(i)
                i += 1
            } else {
                res = res :+ b(j)
                j += 1
            }
        }
        while (i < a.length) {
            res = res :+ a(i)
            i += 1
        }
        while (j < b.length) {
            res = res :+ b(j)
            j += 1
        }
        res
    }
}