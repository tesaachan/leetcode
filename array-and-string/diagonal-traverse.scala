import scala.collection.mutable.ArrayBuffer
object Solution {
    def findDiagonalOrder(mat: Array[Array[Int]]): Array[Int] = {
        var ans = Array.fill(mat.length * mat(0).length)(ArrayBuffer[Int]())
        for (i <- 0 until mat.length)
            for (j <- 0 until mat(i).length) {
                ans(i + j) :+= mat(i)(j)
            }
        for (i <- 0 until ans.length) {
            if (i % 2 == 0) 
                ans(i) = ans(i).reverse
        }
        ans.flatten.toArray
    }
}