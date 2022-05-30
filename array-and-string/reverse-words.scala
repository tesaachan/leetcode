import scala.collection.mutable.ArrayBuffer
object Solution {
    def reverseWords(s: String): String = {
        var ss = ArrayBuffer[String]()
        var (i, j) = (0, 0)
        
        while (i < s.length) {
            if (s(i) != ' ') {
                j = i
                while (j < s.length && s(j) != ' ')
                    j += 1
                ss +:= s.slice(i, j)
                i = j
            }
            i += 1
        }
        ss.mkString(" ")
    }
}