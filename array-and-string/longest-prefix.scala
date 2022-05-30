object Solution {
    def longestCommonPrefix(strs: Array[String]): String = {
        var i = 1
        val len = strs.map(_.length).min
        while (i < len + 1) {
            val prefix = strs(0).slice(0, i)
            if (!strs.forall(prefix == _.slice(0, i))) 
                return strs(0).slice(0, i - 1)
            i += 1
        }
        strs(0).slice(0, i - 1)
    }
}