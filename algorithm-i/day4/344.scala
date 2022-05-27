object Solution {
    def reverseString(s: Array[Char]): Unit = {
        var i = 0
        var j = s.length - 1
        while (j - i > 0) {
            var tmp = s(i)
            s(i) = s(j)
            s(j) = tmp
            i += 1
            j -= 1
        }
    }
}