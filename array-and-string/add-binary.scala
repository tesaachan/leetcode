object Solution {
    def addBinary(a: String, b: String): String = {
        var max = a
        var min = b
        if (a.length < b.length) {
            var tmp = max
            max = min
            min = tmp
        }
        var s1 = max.map(_.toInt - 48).toArray
        val s2 = min.map(_.toInt - 48).toArray
        println(s1.toList)
        val dif = s1.length - s2.length
        for (i <- s1.length - 1 to 0 by -1) {
            if (i - dif >= 0)
                s1(i) += s2(i - dif)
            if (s1(i) > 1) {
                s1(i) -= 2
                if (i != 0) {
                    s1(i - 1) += 1
                } else {
                    s1 = Array(1) ++ s1
                }
            }
        }
        println(s1.toList)
        s1.mkString
    }
}