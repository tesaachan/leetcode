object Solution {
    def strStr(haystack: String, needle: String): Int = {
        if (needle.length == 0)
            0
        else {
            val len = needle.length
            for (i <- 0 until haystack.length) {
                if (haystack.slice(i, i + len) == needle)
                    return i
            }
        }
        -1
    }
}