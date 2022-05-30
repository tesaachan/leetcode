object Solution {
    def plusOne(digits: Array[Int]): Array[Int] = {
        var peak = digits.length
        while (peak != 0)
        {
            if (digits(peak - 1) + 1 != 10) {
                digits(peak - 1) += 1
                return digits
            } else {
                digits(peak - 1) = 0
                peak -= 1
            }
        }
        return Array(1) ++ digits
    }
}