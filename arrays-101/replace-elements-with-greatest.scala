object Solution {
    def replaceElements(arr: Array[Int]): Array[Int] = {
        var new_arr = arr
        var max = new_arr.last
        new_arr(new_arr.length - 1) = -1
        ((new_arr.length - 2) to 0 by -1) foreach { i =>
            var pretend = new_arr(i)
            new_arr(i) = max
            if (pretend > max) {
                max = pretend
            }
        }
        new_arr
    }
}