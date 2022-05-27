object Solution {
    def validMountainArray(arr: Array[Int]): Boolean = {
        if (arr.length < 3) {
            return false
        }
        var (left, right) = arr.splitAt(arr.indexOf(arr.max))
        left = left :+ right(0)
        if (left.length == arr.length || right.length == arr.length) {
            return false
        }
        (0 until left.length - 1) foreach { i =>
            if (left(i) >= left(i + 1)) return false
        }
        (0 until right.length - 1) foreach { i =>
            if (right(i) <= right(i + 1)) return false
        }
        true
    }
}