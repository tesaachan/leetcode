object Solution {
    def strStr(haystack: String, needle: String): Int = {
        if (needle.length == 0)
            0
        else {
            var i = 0
            while (i < haystack.length) {
                var j = 0
                val old_i = i
                if (haystack(i) == needle(j)) {
                    while (i < haystack.length && j < needle.length &&
                        haystack(i) == needle(j))
                    {
                        i += 1
                        j += 1
                    }
                    if (j == needle.length)
                        return (i - j)
                    i = old_i
                }
                i += 1
            }
        }
        -1
    }
}
